class Solution {
public:
    // Function to check if a given integer is a palindrome
    bool isPalindrome(int x) {
        // Negative numbers are not palindromic, as the negative sign is on the left.
        if (x < 0) {
            return false;
        }

        // Variables to store the original and reversed numbers
        int originalNumber = x;
        int reversedNumber = 0;

        while (x > 0) {
            // Extracting the last digit of the number
            int digit = x % 10;

            // Overflow check to ensure multiplication doesn't exceed INT_MAX
            if (reversedNumber > (INT_MAX - digit) / 10) {
                return false;
            }

            // Reversing the number by building it digit by digit
            reversedNumber = reversedNumber * 10 + digit;
            x /= 10; // Removing the last digit from the original number
        }

        // Checking if the reversed number is equal to the original number
        return originalNumber == reversedNumber;
    }
};