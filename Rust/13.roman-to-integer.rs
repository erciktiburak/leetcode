use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        // Create a HashMap to store the values of Roman numerals.
        let mut roman_to_int_mapping = HashMap::new();
        roman_to_int_mapping.insert('I', 1);
        roman_to_int_mapping.insert('V', 5);
        roman_to_int_mapping.insert('X', 10);
        roman_to_int_mapping.insert('L', 50);
        roman_to_int_mapping.insert('C', 100);
        roman_to_int_mapping.insert('D', 500);
        roman_to_int_mapping.insert('M', 1000);

        // Convert the input string to a sequence of characters.
        let chars: Vec<char> = s.chars().collect();

        // Initialize a variable to store the total value.
        let mut total = 0;

        // Iterate through Roman numerals from left to right.
        for i in 0..chars.len() {
            // If the current numeral is smaller than the next one, subtraction rules apply.
            if i < chars.len() - 1 && roman_to_int_mapping[&chars[i]] < roman_to_int_mapping[&chars[i + 1]] {
                // According to the subtraction rule, subtract the value of the current numeral.
                total -= roman_to_int_mapping[&chars[i]];
            } else {
                // Otherwise, simply add the value to the total.
                total += roman_to_int_mapping[&chars[i]];
            }
        }

        // Return the result.
        total
    }
}