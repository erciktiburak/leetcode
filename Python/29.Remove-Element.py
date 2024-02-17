from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0  # Initialize a counter for elements not equal to val
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k

# Custom Judge
def sort(nums: List[int], start: int, end: int):
    nums[start:end] = sorted(nums[start:end])

# Test cases
nums1 = [3,2,2,3]
val1 = 3
expectedNums1 = [2,2]
sol = Solution()
k1 = sol.removeElement(nums1, val1)
assert k1 == len(expectedNums1)
sort(nums1, 0, k1)
assert nums1[:k1] == expectedNums1

nums2 = [0,1,2,2,3,0,4,2]
val2 = 2
expectedNums2 = [0,1,4,0,3]
k2 = sol.removeElement(nums2, val2)
assert k2 == len(expectedNums2)
sort(nums2, 0, k2)
assert nums2[:k2] == expectedNums2

print("All test cases passed.")
