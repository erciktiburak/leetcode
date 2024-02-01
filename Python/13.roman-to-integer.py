class Solution:
    def romanToInt(self, s: str) -> int:
        # Create a dictionary to store the values of Roman numerals.
        roman_to_int_mapping = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        
        # Initialize a variable to store the total value.
        total = 0
        
        # Iterate through Roman numerals from left to right.
        for i in range(len(s)):
            # If the current numeral is smaller than the previous one, subtraction rules apply.
            if i > 0 and roman_to_int_mapping[s[i]] > roman_to_int_mapping[s[i - 1]]:
                # According to the subtraction rule, subtract twice the value of the previous numeral.
                total += roman_to_int_mapping[s[i]] - 2 * roman_to_int_mapping[s[i - 1]]
            else:
                # Otherwise, simply add the value to the total.
                total += roman_to_int_mapping[s[i]]
        
        # Return the result.
        return total

# Example usage:
solution = Solution()
print(solution.romanToInt("III"))     # 3
print(solution.romanToInt("LVIII"))   # 58
print(solution.romanToInt("MCMXCIV")) # 1994