class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Negative numbers are not palindromic, as the negative sign is on the left.
        if x < 0:
            return False

        # Variables to store the original and reversed numbers
        original_number = x
        reversed_number = 0

        while x > 0:
            # Extracting the last digit of the number
            digit = x % 10

            # Reversing the number by building it digit by digit
            reversed_number = reversed_number * 10 + digit
            x //= 10  # Removing the last digit from the original number

        # Checking if the reversed number is equal to the original number
        return original_number == reversed_number


# Example usage
solution = Solution()
print(solution.isPalindrome(121))  # True
print(solution.isPalindrome(-121))  # False
print(solution.isPalindrome(10))    # False