class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_dict = {}

        for i, num in enumerate(nums):
            complement = target - num

            # Check if the complement is already in the dictionary
            if complement in num_dict:
                return [num_dict[complement], i]

            # Add the current number and its index to the dictionary
            num_dict[num] = i

        # If no solution is found
        return None

# Example:
solution = Solution()

nums1 = [2, 7, 11, 15]
target1 = 9
print(solution.twoSum(nums1, target1))  # output: [0, 1]

nums2 = [3, 2, 4]
target2 = 6
print(solution.twoSum(nums2, target2))  # output: [1, 2]

nums3 = [3, 3]
target3 = 6
print(solution.twoSum(nums3, target3))  # output: [0, 1]
