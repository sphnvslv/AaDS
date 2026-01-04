#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int main() {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    int* mSize = new int[n + 1]; 

    for (int i = 0; i < n; ++i) {

        int rows;
        int cols;
        in >> rows >> cols;
        mSize[i] = rows;

        if (i == 0) {
            mSize[i + 1] = cols; 
        }
        else {
            mSize[i + 1] = cols;
        }
    }

    long long** dp = new long long*[n];

    for (int i = 0; i < n; ++i) {
        dp[i] = new long long[n];
    }

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0; 
        }
    }

    for (int len = 2; len <= n; ++len) { 

        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX; 
            
            for (int k = i; k < j; ++k) {
                long long oper = dp[i][k] + dp[k + 1][j] + (long long)mSize[i] * mSize[k + 1] * mSize[j + 1];
                dp[i][j] = min(dp[i][j], oper);
            }
        }
    }

    out << dp[0][n - 1] << endl;

    for (int i = 0; i < n; ++i) {
        delete[] dp[i];
    }

    delete[] dp;
    delete[] mSize;

    in.close();
    out.close();

    return 0;
}