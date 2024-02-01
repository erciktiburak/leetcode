public class Solution {
    public int romanToInt(String s) {
        // Create a HashMap to store the values of Roman numerals.
        HashMap<Character, Integer> romanToIntMapping = new HashMap<>();
        romanToIntMapping.put('I', 1);
        romanToIntMapping.put('V', 5);
        romanToIntMapping.put('X', 10);
        romanToIntMapping.put('L', 50);
        romanToIntMapping.put('C', 100);
        romanToIntMapping.put('D', 500);
        romanToIntMapping.put('M', 1000);

        // Initialize a variable to store the total value.
        int total = 0;

        // Iterate through Roman numerals from left to right.
        for (int i = 0; i < s.length(); i++) {
            // If the current numeral is smaller than the next one, subtraction rules apply.
            if (i < s.length() - 1 && romanToIntMapping.get(s.charAt(i)) < romanToIntMapping.get(s.charAt(i + 1))) {
                // According to the subtraction rule, subtract the value of the current numeral.
                total -= romanToIntMapping.get(s.charAt(i));
            } else {
                // Otherwise, simply add the value to the total.
                total += romanToIntMapping.get(s.charAt(i));
            }
        }

        // Return the result.
        return total;
    }

    // Example usage:
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.romanToInt("III"));     // 3
        System.out.println(solution.romanToInt("LVIII"));   // 58
        System.out.println(solution.romanToInt("MCMXCIV")); // 1994
    }
}