import java.util.*;

class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> count = new HashMap<>();
        
        // Split the sentences into words
        String[] words1 = s1.split(" ");
        String[] words2 = s2.split(" ");
        
        // Count the frequency of words in s1
        for (String word : words1) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        
        // Count the frequency of words in s2
        for (String word : words2) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        
        // Collect uncommon words
        List<String> uncommonWords = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : count.entrySet()) {
            if (entry.getValue() == 1) {
                uncommonWords.add(entry.getKey());
            }
        }
        
        // Convert the list to an array
        return uncommonWords.toArray(new String[0]);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s1 = "this apple is sweet";
        String s2 = "this apple is sour";
        System.out.println(Arrays.toString(solution.uncommonFromSentences(s1, s2)));  // Output: ["sweet","sour"]

        s1 = "apple apple";
        s2 = "banana";
        System.out.println(Arrays.toString(solution.uncommonFromSentences(s1, s2)));  // Output: ["banana"]
    }
}