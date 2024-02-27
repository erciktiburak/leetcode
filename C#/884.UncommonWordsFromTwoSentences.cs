using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string[] UncommonFromSentences(string s1, string s2) {
        var count = new Dictionary<string, int>();

        // Split the sentences into words
        var words1 = s1.Split(' ');
        var words2 = s2.Split(' ');

        // Count the frequency of words in s1
        foreach (var word in words1) {
            if (!count.ContainsKey(word)) {
                count[word] = 0;
            }
            count[word]++;
        }

        // Count the frequency of words in s2
        foreach (var word in words2) {
            if (!count.ContainsKey(word)) {
                count[word] = 0;
            }
            count[word]++;
        }

        // Collect uncommon words
        var uncommonWords = new List<string>();
        foreach (var pair in count) {
            if (pair.Value == 1) {
                uncommonWords.Add(pair.Key);
            }
        }

        return uncommonWords.ToArray();
    }

    public static void Main(string[] args) {
        var solution = new Solution();
        var s1 = "this apple is sweet";
        var s2 = "this apple is sour";
        Console.WriteLine(string.Join(", ", solution.UncommonFromSentences(s1, s2)));  // Output: sweet, sour

        s1 = "apple apple";
        s2 = "banana";
        Console.WriteLine(string.Join(", ", solution.UncommonFromSentences(s1, s2)));  // Output: banana
    }
}
