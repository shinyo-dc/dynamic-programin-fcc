#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> memo;
int countConstruct(string target, vector<string> wordBank, unordered_map<string, int> &memo)
{
    if (memo.find(target) != memo.end())
        return memo[target];
    if (target == "")
        return 1;
    
    int totalCount = 0;
    for (int i = 0; i < wordBank.size(); i++) {
        size_t pos = target.find(wordBank[i]);
        if (pos == 0) {
            string suffix = target;
            suffix.erase(pos, wordBank[i].size());
            int numWaysForRest = countConstruct(suffix, wordBank, memo);
            totalCount += numWaysForRest;
        }
    }
    memo[target] = totalCount;
    return totalCount;
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

int main(int argc, char **argv)
{
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << "\n";
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo) << "\n";
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, memo) << "\n";
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}, memo);
    return 0;
}