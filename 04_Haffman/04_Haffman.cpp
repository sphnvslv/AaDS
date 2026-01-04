#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 2500000;
long long freq[MAXN];

int main() {
    ifstream in("huffman.in");
    ofstream out("huffman.out");

    int n;
    in >> n;

    for (int i = 0; i < n; i++) {
        in >> freq[i];
    }

    long long* merged = new long long[n]; 
    int head1 = 0;
    int tail1 = n;
    int head2 = 0;
    int tail2 = 0;

    long long totalBits = 0;

    for (int step = 0; step < n - 1; step++) {
        long long min1;
        long long min2;

        if (head2 < tail2 && (head1 >= tail1 || merged[head2] <= freq[head1])) {
            min1 = merged[head2++];
        }
        else {
            min1 = freq[head1++];
        }

        if (head2 < tail2 && (head1 >= tail1 || merged[head2] <= freq[head1])) {
            min2 = merged[head2++];
        }
        else {
            min2 = freq[head1++];
        }

        long long sum = min1 + min2;
        totalBits += sum;
        merged[tail2++] = sum;
    }

    out << totalBits << endl;

    delete[] merged;

    return 0;
}