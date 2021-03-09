#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> memo;
bool canConstruct(string target, vector<string> wordBank, unordered_map<string, bool>& memo) 
{
    if (memo.find(target) != memo.end())
        return memo[target];
    if (target == "")
        return true;
    for (int i = 0; i < wordBank.size(); i++) {
        // checking if the wordBank[i] is a prefix of target
        size_t pos = target.find(wordBank[i]);
        if (pos == 0) {
            string suffix = target;
            suffix.erase(pos, wordBank[i].size());
            if (canConstruct(suffix, wordBank, memo)) {
                memo[target] = true;
                return true;
            }
        }
    }
    memo[target] = false;
    return false;
}

//
// Brute force
// Time: O(n^m * m)
// Space: O(m*m)
//
// Memoized
// Time: O(n*m*m)
// Space: O(m*m)
//

int main(int argc, char** argv) {
    cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << "\n";
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo) << "\n";
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, memo);
    return 0;
}