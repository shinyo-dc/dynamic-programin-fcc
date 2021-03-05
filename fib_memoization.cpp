#include<bits/stdc++.h>
using namespace std;

// memorization

// recursive one
int64_t fib(int n, map<int, int64_t> &memo) {
    if (memo.find(n) != memo.end())
        return memo[n];
    if (n <= 2)
        return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

// optimizing:
/*
find out the recursive pattern, try to memorize the duplicate case to use it for later.
*/


int main(int argc, char** argv) {
    map<int, int64_t> memo;
    cout << fib(6, memo) << "\n";
    cout << fib(7, memo) << "\n";
    cout << fib(8, memo) << "\n";
    cout << fib(50, memo) << "\n";
    return 0;
}