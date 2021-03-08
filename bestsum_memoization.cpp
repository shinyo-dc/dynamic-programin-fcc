#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> *> memo;

/* the failed version 
vector<int> *bestSum(int targetSum, vector<int> numbers, unordered_map<int, vector<int> *> &memo)
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
    vector<int>* shorterComb = nullptr;
    for (int i = 0; i < numbers.size(); i++)
    {
        int remainder = targetSum - numbers[i];
        vector<int> *result = bestSum(remainder, numbers, memo);
        if (result != nullptr)
        {
            result->push_back(numbers[i]);
            if (shorterComb == nullptr || result->size() < shorterComb->size()) {
                shorterComb = result;
            }
        }
    }

    memo[targetSum] = shorterComb;
    return shorterComb;
}
*/

vector<int> *bestSum(int targetSum, vector<int> numbers, unordered_map<int, vector<int> *> &memo)
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
    vector<int> *shorterComb = nullptr;
    for (int i = 0; i < numbers.size(); i++)
    {
        int remainder = targetSum - numbers[i];
        vector<int> *result = bestSum(remainder, numbers, memo);
        if (result != nullptr)
        {
            vector<int>* remainderComb = new vector<int>;
            for (int i = 0; i < result->size(); i++)
                remainderComb->push_back(result->at(i));
            remainderComb->push_back(numbers[i]);
            if (shorterComb == nullptr || remainderComb->size() < shorterComb->size())
            {
                shorterComb = remainderComb;
            }
        }
    }
    memo[targetSum] = shorterComb;
    return memo[targetSum];
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
// Note:
//
// U have to actually create a new vector (literally) to store the new combination, like creating a new vect then u proceed to add a new value to it, dont reuse the old space, it will end up being like this:
// testing for the input vector<int> *res4 = bestSum(100, {1, 2, 5, 25}, memo); (the failed version, included below)
// 25 1 1 2 1 2 1 2 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25 1 2 5 25
//
// after actually making a new vect:
// 25 25 25 25
// it worked just fine.
// 

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
    vector<int> *res4 = bestSum(100, {1, 2, 5, 25}, memo);
    // vector<int> *res4 = bestSum(8, {2, 3 ,5}, memo);
    printVect(res4);
    return 0;
}