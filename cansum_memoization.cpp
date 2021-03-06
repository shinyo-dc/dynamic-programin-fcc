#include<bits/stdc++.h>
using namespace std;

map<int, bool> memo;
bool canSum(int targetSum, vector<int> numbers, map<int, bool>& memo) {
    if (memo.find(targetSum) != memo.end())
        return memo[targetSum];
    if (targetSum == 0)
        return true;
    if (targetSum < 0)
        return false;

    for (int i = 0; i < numbers.size(); i++) {
        int remainder = targetSum - numbers[i];
        if (memo[remainder] == true) {
            memo[targetSum] = true;
            return true;
        }
    }

    memo[targetSum] = false;
    return false;
}

int main(int argc, char** argv) {
    int arr[] = { 7, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    cout << canSum(300, vect, memo) << "\n";
    return 0;
}