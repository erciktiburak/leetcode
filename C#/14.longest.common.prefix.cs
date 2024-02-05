public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0) {
            return "";
        }

        // Sort the array of strings
        Array.Sort(strs);

        // Take the first and last strings after sorting
        string first = strs[0];
        string last = strs[strs.Length - 1];

        // Find the common prefix between the first and last strings
        StringBuilder commonPrefix = new StringBuilder();
        for (int i = 0; i < first.Length && i < last.Length; i++) {
            if (first[i] == last[i]) {
                commonPrefix.Append(first[i]);
            } else {
                break;
            }
        }

        return commonPrefix.ToString();
    }
}