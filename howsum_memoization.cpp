#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> *> memo;

vector<int> *howSum(int targetSum, vector<int> numbers, unordered_map<int, vector<int> *> &memo)
{
    if (memo.find(targetSum) != memo.end())
        return memo[targetSum];
    if (targetSum == 0)
    {
        vector<int> *result = new vector<int>;
        return result;
    }
    if (targetSum < 0)
        return nullptr;
    for (int i = 0; i < numbers.size(); i++)
    {
        int remainder = targetSum - numbers[i];
        vector<int> *result = howSum(remainder, numbers, memo);
        if (result != nullptr)
        {
            result->push_back(numbers[i]);
            memo[targetSum] = result;
            return memo[targetSum];
        }
    }

    memo[targetSum] = nullptr;
    return nullptr;
}

// m = target sum
// n = numbers.size()
//
// Brute Force
// Time: O(n^m * m)
// Space: O(m)
// 
// Memoized
// time: O(n*m*m)
// Space: O(m*m)

void printVect(vector<int> *vect)
{
    if (vect == nullptr)
        cout << "Null";
    else
    {
        for (int i = 0; i < vect->size(); i++)
            cout << vect->at(i) << " ";
    }
    cout << "\n";
}
int main(int argc, char **argv)
{
    // vector<int> *res = howSum(7, {2, 3}, memo);
    // vector<int> *res1 = howSum(7, {5, 3, 4, 7}, memo);
    // vector<int> *res2 = howSum(7, {2, 4}, memo);
    // vector<int> *res3 = howSum(8, {2, 3, 5}, memo);
    // printVect(res);
    // printVect(res1);
    // printVect(res2);
    // printVect(res3);
    vector<int> *res4 = howSum(300, {7, 14}, memo);
    printVect(res4);
    return 0;
}