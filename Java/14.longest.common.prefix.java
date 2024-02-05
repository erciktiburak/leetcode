class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        
        // Sort the array of strings
        Arrays.sort(strs);
        
        // Take the first and last strings after sorting
        String first = strs[0];
        String last = strs[strs.length - 1];
        
        // Find the common prefix between the first and last strings
        StringBuilder commonPrefix = new StringBuilder();
        for (int i = 0; i < first.length() && i < last.length(); i++) {
            if (first.charAt(i) == last.charAt(i)) {
                commonPrefix.append(first.charAt(i));
            } else {
                break;
            }
        }
        
        return commonPrefix.toString();
    }
}