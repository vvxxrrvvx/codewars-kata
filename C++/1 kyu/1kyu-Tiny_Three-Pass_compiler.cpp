#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

class Expr;

struct AST {
    string op;
    AST *a;
    AST *b;
    int n;

    AST(string Type, AST *LVal, AST *RVal):
        op(Type), a(LVal), b(RVal) {}

    AST(string Type, int Val):
        op(Type), n(Val) {}

    void dump(ostream &out, unsigned level) {
        string Type(op);
        AST *LVal = a;
        AST *RVal = b;
        int Idx = n;
        int Val = n;
        for (unsigned i = 0; i < level; i++) {
            cout << "\t";
        }
        if (Type == "/" || Type == "*" || Type == "+" || Type == "-") {
            out << Type << endl;
            LVal->dump(out, level + 1);
            RVal->dump(out, level + 1);
        } else if (Type == "arg") {
            out << Type << Idx << endl;
        } else if (Type == "imm") {
            out << Type << Val << endl;
        }
    }

    Expr * ConvertToExpr();
};


class IRBuilder {
    vector<string> Instructions;

    void CreateInstruction(const string &Ins) {
        Instructions.push_back(Ins);
    }
    void CreateInstruction(const string &Ins, int Val) {
        Instructions.push_back(string(Ins) + string(" ") + to_string(Val));
    }

public:
    IRBuilder() {}

    vector<string> getInstructions() {
        return Instructions;
    }
    
    void IM(int Val) { CreateInstruction("IM", Val); }
    void AR(int Val) { CreateInstruction("AR", Val); }
    void SW() { CreateInstruction("SW"); }
    void PU() { CreateInstruction("PU"); }
    void PO() { CreateInstruction("PO"); }
    void AD() { CreateInstruction("AD"); }
    void SU() { CreateInstruction("SU"); }
    void MU() { CreateInstruction("MU"); }
    void DI() { CreateInstruction("DI"); }
};

struct AST;

class Expr {
public:
    virtual ~Expr() {};
    virtual AST * toAST() = 0;
    virtual Expr * Optimize() = 0;
    virtual void codegen(IRBuilder &B, bool L) = 0;
};

class Function {
    vector<string> Args;
    Expr * Body;

public:
    Function(vector<string> Args, Expr *Body): Args(Args), Body(Body) {}

    AST * toAST() {
        return Body->toAST();
    }

    void Optimize() {
        auto NewBody = Body->Optimize();
        if (NewBody != Body) {
            delete Body;
            Body = NewBody;
        }
    }

    void codegen(IRBuilder &B) {
        Body->codegen(B, true);
    }
};

class ImmExpr : public Expr {
    int Val;

public:
    ImmExpr(int Val): Val(Val) {}

    AST * toAST() override {
        return new AST("imm", Val);
    }

    Expr * Optimize() override {
        return this;
    }

    int getVal() const {
        return Val;
    }

    void codegen(IRBuilder &B, bool L) override {
        B.IM(Val);
    }
};

class ArgExpr : public Expr {
    unsigned Idx;

public:
    ArgExpr(unsigned Idx): Idx(Idx) {}

    AST * toAST() override {
        return new AST("arg", Idx);
    }

    Expr * Optimize() override {
        return this;
    }

    void codegen(IRBuilder &B, bool L) override {
        B.AR(Idx);
    }
};

class BinaryExpr : public Expr {
    char Op;
    Expr *LeftVal;
    Expr *RightVal;

public:
    BinaryExpr(char Op, Expr *LeftVal, Expr *RightVal):
        Op(Op), LeftVal(LeftVal), RightVal(RightVal) {}

    AST * toAST() override {
        return new AST(string(1, Op), LeftVal->toAST(), RightVal->toAST());
    }

    Expr * Optimize() override {
        auto LO = LeftVal->Optimize();
        if (LO != LeftVal) {
            delete LeftVal;
            LeftVal = LO;
        }

        auto RO = RightVal->Optimize();
        if (RO != RightVal) {
            delete RightVal;
            RightVal = RO;
        }

        if (ImmExpr *LIE = dynamic_cast<ImmExpr *>(LeftVal)) {
            if (ImmExpr *RIE = dynamic_cast<ImmExpr *>(RightVal)) {
                switch (Op)
                {
                case '+':
                    return new ImmExpr(LIE->getVal() + RIE->getVal());
                case '-':
                    return new ImmExpr(LIE->getVal() - RIE->getVal());
                case '*':
                    return new ImmExpr(LIE->getVal() * RIE->getVal());
                case '/':
                    return new ImmExpr(LIE->getVal() / RIE->getVal());
                default:
                    break;
                }
            }
        }

        return this;
    }

    void codegen(IRBuilder &B, bool L) override {
        if (!L) { // My Left Bro is in R1
            B.SW(); // My Left Bro is in R0
            B.PU(); // My Left Bro is in Stack
        }
        LeftVal->codegen(B, true); // My Left Value is in R0
        B.SW(); // My Left Value is in R1
        RightVal->codegen(B, false); // My Left Value is in R1 and Right is in R0
        B.SW(); // My Left Value is in R0 and Right is in R1
        switch (Op)
        {
        case '+':
            B.AD();
            break;
        case '-':
            B.SU();
            break;
        case '*':
            B.MU();
            break;
        case '/':
            B.DI();
            break;
        default:
            break;
        }
        if (!L) {
            // My Value is in R0 and My Left Bro is in Stack
            B.SW(); // My Value is in R1
            B.PO(); // My Left Bro is in R0
            B.SW(); // My Value is in R0 and My Left Bro is in R1
        }
    }
};

enum TokenType {
    TTId,
    TTAdd,
    TTSub,
    TTMul,
    TTDiv,
    TTLSq,
    TTRSq,
    TTLPr,
    TTRPr,
    TTInt,
    TTEOF,
};

static string tok_s(TokenType tt) {
    switch (tt)
    {
    case TTId:
        return "Id";
    case TTAdd:
        return "+";
    case TTSub:
        return "-";
    case TTMul:
        return "*";
    case TTDiv:
        return "/";
    case TTLSq:
        return "[";
    case TTRSq:
        return "]";
    case TTLPr:
        return "(";
    case TTRPr:
        return ")";
    case TTInt:
        return "Int";
    case TTEOF:
        return "EOF";
    default:
        return "Unkown";
    }
}

struct Token {
    TokenType Type;
    string IdVal;
    int IntVal;

    Token(TokenType Type, string IdVal = "", int IntVal = 0):
        Type(Type), IdVal(IdVal), IntVal(IntVal) {}
};

struct Parser {

    vector<string> &Tokens;
    unsigned Idx = 0;
    Token *Tok = nullptr;

public:
    Parser(vector<string> &Tokens):
        Tokens(Tokens) {}

    void GetTok() {
        if (Tokens.size() <= Idx) {
            Tok = new Token(TTEOF);
            return;
        }

        string &Val = Tokens[Idx++];
        char FirstChar = Val[0];
        if (FirstChar == '+') {
            Tok = new Token(TTAdd);
        } else if (FirstChar == '-') {
            Tok = new Token(TTSub);
        } else if (FirstChar == '*') {
            Tok = new Token(TTMul);
        } else if (FirstChar == '/') {
            Tok = new Token(TTDiv);
        } else if (FirstChar == '(') {
            Tok = new Token(TTLPr);
        } else if (FirstChar == ')') {
            Tok = new Token(TTRPr);
        } else if (FirstChar == '[') {
            Tok = new Token(TTLSq);
        } else if (FirstChar == ']') {
            Tok = new Token(TTRSq);
        } else if (isdigit(FirstChar)) {
            Tok = new Token(TTInt, "", stoi(Val));
        } else if (isascii(FirstChar)) {
            Tok = new Token(TTId, Val);
        } else {
            Tok = new Token(TTEOF);
        }
    }

    Function * ParseFunction() {
        vector<string> Args;
        Expr *Body;

        GetTok();
        while (true) {
            switch (Tok->Type) {
            case TTLSq:
                GetTok();
                Args = ParseArgList();
                GetTok();
                break;
            case TTEOF:
                goto end;
            default:
                Body = ParseExpr(Args);
                break;
            }
        }
    end:
        return new Function(Args, Body);
    }

    vector<string> ParseArgList() {
        vector<string> Args;
        if (Tok->Type == TTRSq) {
            return Args;
        } else if (Tok->Type == TTId) {
            Args.push_back(Tok->IdVal);
            GetTok();
        }
        auto Next = ParseArgList();
        Args.insert(Args.end(), Next.begin(), Next.end());
        return Args;
    }

    Expr * ParseExpr(vector<string> &Args) {
        cout << "ParseExpr" << endl;
        Expr *E = ParseTerm(Args);
        while (true) {
            switch (Tok->Type) {
            case TTAdd: {
                GetTok(); // eat +
                auto NE = ParseTerm(Args);
                E = new BinaryExpr('+', E, NE);
                break;
            }
            case TTSub: {
                GetTok(); // eat -
                auto NE = ParseTerm(Args);
                E = new BinaryExpr('-', E, NE);
                break;
            }
            default:
                return E;
            }
        }
    }

    Expr * ParseTerm(vector<string> &Args) {
        cout << "ParseTerm" << endl;
        Expr *E = ParseFactor(Args);
        while (true) {
            switch (Tok->Type) {
            case TTMul: {
                GetTok();
                auto NE = ParseFactor(Args);
                if (!NE) cout << "* get null factor" << endl;
                E = new BinaryExpr('*', E, NE);
                break;
            }
            case TTDiv: {
                GetTok();
                cout << "/ get factor" << endl;
                auto NE = ParseFactor(Args);
                if (!NE) cout << "/ get null factor" << endl;
                E = new BinaryExpr('/', E, NE);
                break;
            }
            default:
                return E;
            }
        }
    }

    Expr * ParseFactor(vector<string> &Args) {
        cout << "ParseFactor " << tok_s(Tok->Type) << endl;
        switch (Tok->Type)
        {
        case TTLPr: {
            GetTok(); // eat '('
            auto E = ParseExpr(Args);
            GetTok(); // eat ')'
            return E;
        }
        case TTInt:
            return ParseNumber();
        case TTId:
            return ParseVariable(Args);
        default:
            break;
        }
        cout << "return null factor" << endl;
        return nullptr;
    }

    Expr * ParseNumber() {
        auto IntVal = Tok->IntVal;
        cout << "ParseNumber " << IntVal << endl;
        GetTok();
        return new ImmExpr(IntVal);
    }

    Expr * ParseVariable(vector<string> &Args) {
        auto VarName = Tok->IdVal;
        cout << "ParseVariable " << VarName << endl;
        for (size_t i = 0; i < Args.size(); i++)
        {
            if (Args[i] == VarName)
            {
                GetTok();
                return new ArgExpr(i);
            }
        }
        
        return nullptr;
    }
};

class Optimizer {
    Function *F;

public:
    Optimizer(Function *F): F(F) {}

    void DoOpt() {
        F->Optimize();
    }
};

Expr * AST::ConvertToExpr() {
    string Type(op);
    AST *LVal = a;
    AST *RVal = b;
    int Idx = n;
    int Val = n;

    if (Type == "/" || Type == "*" || Type == "+" || Type == "-") {
        auto LE = LVal->ConvertToExpr();
        auto RE = RVal->ConvertToExpr();
        return new BinaryExpr(Type[0], LE, RE);
    } else if (Type == "arg") {
        return new ArgExpr(Idx);
    } else if (Type == "imm") {
        return new ImmExpr(Val);
    }
    return nullptr;
}

struct Compiler {

    vector <string> compile (string program) {
        return pass3 (pass2 (pass1 (program)));
    }

    // Turn a program string into a vector of tokens.  Each token
    // is either '[', ']', '(', ')', '+', '-', '*', '/', a variable
    // name or a number (as a string)
    vector <string> tokenize(string program) {
        static regex re ("[-+*/()[\\]]|[A-Za-z]+|\\d+");
        sregex_token_iterator it (program.begin (), program.end (), re);
        return vector <string> (it, sregex_token_iterator ());
    }

    // Returns an un-optimized AST
    AST *pass1(string program) {
        cout << program << endl;
        auto tokens = tokenize(program);
        Function *F = Parser(tokens).ParseFunction();
        cout << "Original AST" << endl;
        AST *ast = F->toAST();
        ast->dump(cout, 0);
        return ast;
    }

    // Returns an AST with constant expressions reduced
    AST *pass2(AST *ast) {
        Expr *E = ast->ConvertToExpr();
        E = E->Optimize();
        ast = E->toAST();
        cout << "Optimized AST" << endl;
        ast->dump(cout, 0);
        return ast;
    }
    
    vector <string> pass3(AST *ast) {
        Expr *E = ast->ConvertToExpr();
        IRBuilder B;
        E->codegen(B, true);
        auto v = B.getInstructions();
        int i = 0;
        for (auto s : v) {
            cout << ++i << ": " << s << endl;
        }
        return v;
    }
};

int Simulate(const vector <string> &assembly, const vector <int> &argv) {
    cout << "arg: " << argv[0] << endl;
    cout << "arg: " << argv[1] << endl;
    int r0 = 0, r1 = 0;
    stack <int> istack;
    int i = 0;
    for (auto &ins : assembly) {
        string code = ins.substr (0, 2);
        cout << ++i << ": " << code << endl;
        if (code == "IM") { r0 = stoi (ins.substr (3)); }
        else if (code == "AR") { r0 = argv.at (stoi (ins.substr (3))); }
        else if (code == "SW") { swap (r0, r1); }
        else if (code == "PU") { istack.push (r0); }
        else if (code == "PO") { r0 = istack.top (); istack.pop (); }
        else if (code == "AD") { r0 += r1; }
        else if (code == "SU") { r0 -= r1; }
        else if (code == "MU") { r0 *= r1; }
        else if (code == "DI") { 
            cout << "r0 " << r0 << ", r1 " << r1 << endl;
            r0 /= r1; }
    }
    return r0;
}