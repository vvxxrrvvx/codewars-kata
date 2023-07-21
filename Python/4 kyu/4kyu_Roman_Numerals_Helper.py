class RomanNumerals:
    
    @staticmethod
    def to_roman(num):
        roman = ""
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        
        for i in range(len(values)):
            while num >= values[i]:
                num -= values[i]
                roman += symbols[i]
                
        return roman
    
    @staticmethod
    def from_roman(roman):
        values = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        result = 0
        
        for i in range(len(roman)):
            if i > 0 and values[roman[i]] > values[roman[i-1]]:
                result += values[roman[i]] - 2 * values[roman[i-1]]
            else:
                result += values[roman[i]]
                
        return result