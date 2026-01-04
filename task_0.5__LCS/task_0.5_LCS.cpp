#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int** dp = new int* [n + 1];

    for (int i = 0; i <= n; i++) {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }

            else if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int k = dp[n][n];

    int* poslA = new int[k];
    int* poslB = new int[k];

    int iInd = n;
    int jInd = n;
    int ind = k - 1;

    while (iInd > 0 && jInd > 0) {

        if (A[iInd - 1] == B[jInd - 1]) {
            poslA[ind] = iInd - 1;
            poslB[ind] = jInd - 1;

            ind--;
            iInd--;
            jInd--;
        }

        else if (dp[iInd - 1][jInd] > dp[iInd][jInd - 1]) {
            iInd--;
        }

        else {
            jInd--;
        }
    }

    cout << k << endl;

    for (int i = 0; i < k; i++) {
        cout << poslA[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < k; i++) {
        cout << poslB[i] << " ";
    }
    cout << endl;

    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    
    delete[] A;
    delete[] B;
    delete[] dp;
    delete[] poslA;
    delete[] poslB;

    return 0;
}