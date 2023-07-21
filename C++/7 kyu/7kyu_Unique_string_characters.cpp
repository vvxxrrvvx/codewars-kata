#include <string>
#include <unordered_set>

std::string solve(std::string a, std::string b) {
    std::unordered_set<char> uniqueCharsA;
    std::unordered_set<char> uniqueCharsB;

    for (char c : a) {
        uniqueCharsA.insert(c);
    }

    for (char c : b) {
        uniqueCharsB.insert(c);
    }

    std::string result;
    for (char c : a) {
        if (uniqueCharsB.count(c) == 0) {
            result += c;
        }
    }

    for (char c : b) {
        if (uniqueCharsA.count(c) == 0) {
            result += c;
        }
    }

    return result;
}