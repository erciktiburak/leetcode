from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        merged = [0] * (n1 + n2)
        
        i, j, k = 0, 0, 0
        while i < n1 and j < n2:
            if nums1[i] < nums2[j]:
                merged[k] = nums1[i]
                i += 1
            else:
                merged[k] = nums2[j]
                j += 1
            k += 1
        
        while i < n1:
            merged[k] = nums1[i]
            i += 1
            k += 1
        
        while j < n2:
            merged[k] = nums2[j]
            j += 1
            k += 1
        
        if (n1 + n2) % 2 == 0:
            return (merged[(n1 + n2) // 2 - 1] + merged[(n1 + n2) // 2]) / 2
        else:
            return merged[(n1 + n2) // 2]

# Example usage
nums1 = [1, 3]
nums2 = [2]
sol = Solution()
print(sol.findMedianSortedArrays(nums1, nums2))  # Output: 2.0

nums1 = [1, 2]
nums2 = [3, 4]
print(sol.findMedianSortedArrays(nums1, nums2))  # Output: 2.5
