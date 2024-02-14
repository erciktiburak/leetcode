class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        factors = []
        for i in range(1, n+1):
            if n % i == 0:
                factors.append(i)
        return factors[k-1] if k <= len(factors) else -1

# Example usage
solution = Solution()
print(solution.kthFactor(12, 3))  # Output: 3
print(solution.kthFactor(7, 2))   # Output: 7
print(solution.kthFactor(4, 4))   # Output: -1
