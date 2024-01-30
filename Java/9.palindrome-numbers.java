class Solution {
    public boolean isPalindrome(int x) {
          // Negative numbers and numbers ending with 0 (except 0 itself) are not palindromic
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNumber = 0;

        // Reverse only the second half of the number
        while (x > reversedNumber) {
            int digit = x % 10;
            reversedNumber = reversedNumber * 10 + digit;
            x /= 10;
        }

        // For odd-length numbers, remove the middle digit from the reversed number
        return x == reversedNumber || x == reversedNumber / 10;
    }
}