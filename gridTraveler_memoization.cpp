#include<bits/stdc++.h>
using namespace std;

// memoization
vector< vector<int64_t> >memo(100, vector<int64_t>(100,0));

// recursive function with memoization
int64_t gridTraveler(int m, int n, vector< vector<int64_t> >&memo) {
    if (m == 1 || n == 1)
        return 1;
    if (memo[m][n] != 0)
        return memo[m][n];
    if (memo[n][m] != 0)
        return memo[n][m];
    memo[m][n] = gridTraveler(m-1, n, memo) + gridTraveler(m, n-1, memo);
    return memo[m][n];
}

int main(int argc, char** argv) {
    cout << gridTraveler(2,3, memo) << "\n";
    cout << gridTraveler(2,2, memo) << "\n";
    cout << gridTraveler(4,3, memo) << "\n";
    cout << gridTraveler(50,50, memo) << "\n";
}