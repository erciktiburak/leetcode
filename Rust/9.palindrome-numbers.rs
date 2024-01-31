impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        // Negative numbers are not palindromic
        if x < 0 {
            return false;
        }

        let original_number = x;
        let mut reversed_number = 0;

        let mut x_mut = x;
        while x_mut > 0 {
            // Extract the last digit of the number
            let digit = x_mut % 10;

            // Reverse the number by adding one digit at a time
            reversed_number = reversed_number * 10 + digit;

            // Remove the rightmost digit from the number
            x_mut /= 10;
        }

        // Check if the reversed number is equal to the original number
        original_number == reversed_number
    }
}

fn main() {
    // Example usage
    println!("{}", Solution::is_palindrome(121));  // true
    println!("{}", Solution::is_palindrome(-121)); // false
    println!("{}", Solution::is_palindrome(10));   // false
}