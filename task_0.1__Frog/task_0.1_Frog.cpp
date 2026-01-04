#include <iostream>

using namespace std;

const int MAX_N = 100000;

int main() {
    int n;
    cin >> n;

    if (n < 1) {
        cout << -1 << endl;
        return 0;
    }

    int* mosq = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> mosq[i];
    }

    if (n == 1) {
        cout << mosq[0] << endl;
        cout << 1 << endl;

        delete[] mosq;
        return 0;
    }

    int* dp = new int[n];
    int* pred = new int[n];

    for (int i = 0; i < n; i++) {
        dp[i] = -1;
        pred[i] = -1;
    }

    dp[0] = mosq[0];

    for (int i = 0; i < n; i++) {

        if (dp[i] != -1) {

            if (i + 2 < n) {
                int newSum = dp[i] + mosq[i + 2];

                if (newSum > dp[i + 2]) {
                    dp[i + 2] = newSum;
                    pred[i + 2] = i;
                }
            }

            if (i + 3 < n) {
                int newSum = dp[i] + mosq[i + 3];

                if (newSum > dp[i + 3]) {
                    dp[i + 3] = newSum;
                    pred[i + 3] = i;
                }
            }
        }
    }

    if (dp[n - 1] == -1) {
        cout << -1 << endl;
    }

    else {
        int path[MAX_N];
        int pathSize = 0;
        int cur = n - 1;

        while (cur != -1) {
            path[pathSize++] = cur + 1;
            cur = pred[cur];
        }

        cout << dp[n - 1] << endl;

        int i = pathSize - 1;

        while (i >= 0) {
            cout << path[i]; 

            if (i > 0) {
                cout << " ";
            }
            i--; 
        }

        cout << endl;
    }

    delete[] mosq;
    delete[] dp;
    delete[] pred;

    return 0;
}