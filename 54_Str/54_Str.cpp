#include <iostream>;
#include <fstream>
#include <algorithm>
#include <climits> 
#include <string>

using namespace std;

const int MAX_N = 301;

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");
	
	string s;
	in >> s;

	int n = s.length();

	if (n == 0) {
		out << 0 << endl;
		return 0;
	}

	int dp[MAX_N][MAX_N];

	for (int i = 0; i < MAX_N; i++) { 
		for (int j = 0; j < MAX_N; j++) {
			dp[i][j] = 0;
		}
	}

	for (int subLen = 1; subLen <= n; subLen++) {
		for (int i = 0; i <= n - subLen; i++) {

			int j = i + subLen - 1;

			if (subLen == 1) {
				dp[i][j] = 1;
				continue;
			}

			dp[i][j] = 1 + dp[i + 1][j]; 

			for (int k = i + 1; k <= j; k++) {
				if (s[i] == s[k]) {

					int midDel = 0;

					if (k > i + 1) {
						midDel = dp[i + 1][k - 1];
					}

					dp[i][j] = min(dp[i][j], midDel + dp[k][j]);
				}
			}
		}
	}

	out << dp[0][n - 1] << endl;

	in.close();
	out.close();
	return 0;

}
