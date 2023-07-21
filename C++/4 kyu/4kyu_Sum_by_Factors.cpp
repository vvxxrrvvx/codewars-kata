#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <unordered_map>

class SumOfDivided {
public:
    static std::string sumOfDivided(std::vector<int> &lst) {
        std::unordered_map<int, int> primeFactors;
        
        for (auto num : lst) {
            int absNum = std::abs(num);
            for (int i = 2; i <= absNum; i++) {
                if (isPrime(i) && absNum % i == 0) {
                    primeFactors[i] += num;
                }
            }
        }
        
        std::vector<std::pair<int, int>> result;
        for (auto pair : primeFactors) {
            result.push_back(pair);
        }
        
        std::sort(result.begin(), result.end());
        
        std::stringstream ss;
        for (auto pair : result) {
            ss << "(" << pair.first << " " << pair.second << ")";
        }
        
        return ss.str();
    }
    
private:
    static bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= std::sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};