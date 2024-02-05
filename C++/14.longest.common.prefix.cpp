#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        // Sort the vector of strings
        std::sort(strs.begin(), strs.end());

        // Take the first and last strings after sorting
        const std::string& first = strs.front();
        const std::string& last = strs.back();

        // Find the common prefix between the first and last strings
        size_t commonPrefixLength = 0;
        size_t minLength = std::min(first.length(), last.length());

        while (commonPrefixLength < minLength && first[commonPrefixLength] == last[commonPrefixLength]) {
            commonPrefixLength++;
        }

        // Return the common prefix
        return first.substr(0, commonPrefixLength);
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs = {"flower", "flow", "flight"};

    std::string result = solution.longestCommonPrefix(strs);

    std::cout << "Longest Common Prefix: " << result << std::endl;

    return 0;
}