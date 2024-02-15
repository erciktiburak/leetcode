class Solution:
    def partitionString(self, s: str) -> int:
        seen = set()
        count = 0

        for char in s:
            if char in seen:
                seen = {char}
                count += 1
            else:
                seen.add(char)

        return count + 1

# Example usage
solution = Solution()
print(solution.partitionString("abacaba"))  # Output: 4
print(solution.partitionString("ssssss"))   # Output: 6
