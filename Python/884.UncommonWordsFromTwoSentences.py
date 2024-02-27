from typing import List
from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words_s1 = s1.split()
        words_s2 = s2.split()
        
        count_s1 = Counter(words_s1)
        count_s2 = Counter(words_s2)
        
        uncommon_words = []
        for word, count in count_s1.items():
            if count == 1 and word not in count_s2:
                uncommon_words.append(word)
                
        for word, count in count_s2.items():
            if count == 1 and word not in count_s1:
                uncommon_words.append(word)
        
        return uncommon_words

# Example usage
solution = Solution()
s1 = "this apple is sweet"
s2 = "this apple is sour"
print(solution.uncommonFromSentences(s1, s2))  # Output: ["sweet","sour"]

s1 = "apple apple"
s2 = "banana"
print(solution.uncommonFromSentences(s1, s2))  # Output: ["banana"]