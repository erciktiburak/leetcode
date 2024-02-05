from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        # Sort the array of strings
        strs.sort()

        # Take the first and last strings after sorting
        first = strs[0]
        last = strs[-1]

        # Find the common prefix between the first and last strings
        common_prefix = []
        for i in range(min(len(first), len(last))):
            if first[i] == last[i]:
                common_prefix.append(first[i])
            else:
                break

        return ''.join(common_prefix)