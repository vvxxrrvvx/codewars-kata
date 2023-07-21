function transpile(input) {
    const regex = /\s*(->|[()<>.,*]|[A-Za-z_][A-Za-z_0-9]*)\s*/g
    const toks = input.replace(regex, ":$1").substring(1).split(':')
    let curTok = 0
    const raise = msg => { throw new Error(msg) }
    const next = () => toks[curTok++]
    const peek = () => toks[curTok]
    const match = v => peek() !== undefined && peek() === v
    const expect = v => next() === v || raise(`${v} expected`)
    const expectRe = re => {
        const tok = next();
        if (!tok || !re.test(tok)) {
            raise(`Unexpected token`);
        }
        return tok;
    }

    function name() {
        const tok = expectRe(/^[A-Za-z_][A-Za-z_0-9]*$/);
        switch (tok) {
            case 'Int': return 'Integer';
            case 'Unit': return 'Void';
        }
        return tok;
    }

    function typeParam() {
        const tok = peek();
        switch (tok) {
            case '*': next(); return '?';
            case 'in':
            case 'out':
                next();
                if (match('>')) {
                    return tok;
                }                
                const n = name();
                return tok === 'in' ? `? super ${n}` : `? extends ${n}`;
        }
        return type();
    }

    function typeParams() {
        const params = [];
        expect('<');
        while (true) {
            params.push(typeParam());
            const tok = expectRe(/^[,>]$/);
            if (tok === '>') {
                break;
            }
        }
        return params.join(',');
    }

    function simpleUserType() {
        const n = name();
        if (match('<')) {
            return `${n}<${typeParams()}>`;
        }
        return n;
    }

    function userType() {
        const types = [];
        while (true) {
            types.push(simpleUserType());
            if (!match('.')) {
                break;
            }
            next();
        }
        return types.join('.');
    }

    function parameters() {
        const params = [];
        while (!match(')')) {
            params.push(type());
            if (!match(',')) {
                break;
            }
            next();
        }
        return params;
    }

    function functionType() {
        expect('(');
        const pars = match(')') ? [] : parameters();
        expect(')');
        expect('->');
        pars.push(type());
        return `Function${pars.length - 1}<${pars.join(',')}>`;
    }

    function type() {
        return match('(') ? functionType() : userType();
    }

    try {
        const result = type();
        if (curTok < toks.length) {
            throw new Error('Unexpected tokens at the end');
        }
        return result;
    }
    catch (e) {
        console.log(e.message);
        return null;
    }
}