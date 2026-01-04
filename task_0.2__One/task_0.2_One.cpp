#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long fact(int n) {
    long long res = 1;

    for (int i = 2; i <= n; ++i) {
        res = (res * i) % MOD;
    }

    return res;
}

long long binomCoeff(int N, int K) {

    if (K < 0 || K > N) {
        return 0;
    }

    long long num = fact(N);
    long long denom = (fact(K) * fact(N - K)) % MOD;

    long long denomObrat = 1;
    long long temp = denom;
    long long pow = MOD - 2; 

    while (pow) {
        if (pow % 2) {
            denomObrat = (denomObrat * temp) % MOD;
        }
        temp = (temp * temp) % MOD;
        pow /= 2;
    }

    long long res = (num * denomObrat) % MOD;

    return res;
}

int main() {

    int N, K;
    cin >> N >> K;

    cout << binomCoeff(N, K);

    return 0;
}