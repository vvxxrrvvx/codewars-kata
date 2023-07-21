using System.Collections.Generic;
using System.Text;

public class Kata
{
    public static string DuplicateEncode(string word)
    {
        // Convert the input string to lowercase to ignore capitalization
        word = word.ToLower();
        
        // Create a dictionary to store the count of each character in the input string
        Dictionary<char, int> charCount = new Dictionary<char, int>();
        
        // Iterate through each character in the input string and count how many times it appears
        foreach (char c in word)
        {
            if (charCount.ContainsKey(c))
            {
                charCount[c]++;
            }
            else
            {
                charCount.Add(c, 1);
            }
        }
        
        // Create an output string by iterating through each character in the input string again
        // and adding "(" if the character appears only once or ")" if it appears more than once
        StringBuilder result = new StringBuilder();
        foreach (char c in word)
        {
            if (charCount[c] > 1)
            {
                result.Append(")");
            }
            else
            {
                result.Append("(");
            }
        }
        
        return result.ToString();
    }
}
