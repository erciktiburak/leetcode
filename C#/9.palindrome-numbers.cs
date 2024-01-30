using System;

public class Solution {
    public bool IsPalindrome(int x) {
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

            // Reversing the number by building it digit by digit
            reversedNumber = reversedNumber * 10 + digit;
            x /= 10; // Removing the last digit from the original number
        }

        // Checking if the reversed number is equal to the original number
        return originalNumber == reversedNumber;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        Console.WriteLine(solution.IsPalindrome(121));  // True
        Console.WriteLine(solution.IsPalindrome(-121)); // False
        Console.WriteLine(solution.IsPalindrome(10));    // False
    }
}
