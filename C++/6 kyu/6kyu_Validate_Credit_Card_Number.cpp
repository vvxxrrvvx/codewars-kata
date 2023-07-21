class Kata {
public:
    static bool validate(long long int n) {
        std::string numStr = std::to_string(n);

        int sum = 0;
        
        bool doubleDigit = false; 
        for (int i = numStr.size() - 1; i >= 0; i--) {
            int digit = numStr[i] - '0'; 

            if (doubleDigit) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
            }

            sum += digit;
            doubleDigit = !doubleDigit;
        }

        return sum % 10 == 0;
    }
};