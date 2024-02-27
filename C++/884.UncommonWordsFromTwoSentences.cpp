#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;

        // Tokenize s1
        istringstream iss1(s1);
        string word;
        while (iss1 >> word) {
            count[word]++;
        }

        // Tokenize s2
        istringstream iss2(s2);
        while (iss2 >> word) {
            count[word]++;
        }

        // Collect uncommon words
        vector<string> uncommonWords;
        for (auto& entry : count) {
            if (entry.second == 1) {
                uncommonWords.push_back(entry.first);
            }
        }

        return uncommonWords;
    }
};

int main() {
    Solution solution;
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    vector<string> result = solution.uncommonFromSentences(s1, s2);
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;  // Output: sweet sour

    s1 = "apple apple";
    s2 = "banana";
    result = solution.uncommonFromSentences(s1, s2);
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;  // Output: banana

    return 0;
}
