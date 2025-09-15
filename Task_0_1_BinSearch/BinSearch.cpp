#include <iostream>

using namespace std;

int lowerInd(int arr[], int size, int x) {

    if (size == 0) {
        return 0;
    }

    int left = -1;
    int right = size;

    while (right - left > 1) {

        int mid = left + (right - left) / 2;

        if (arr[mid] < x) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return right;
}

int upperInd(int arr[], int size, int x) {

    if (size == 0) {
        return 0;
    }

    int left = -1;
    int right = size;

    while (right - left > 1) {

        int mid = left + (right - left) / 2;

        if (arr[mid] <= x) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return right;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int* requests = new int[k];

    for (int i = 0; i < k; i++) {
        cin >> requests[i];
    }

    for (int i = 0; i < k; i++) {

        int x = requests[i];
        int l = lowerInd(arr, n, x);
        int r = upperInd(arr, n, x);
        int b = (l < r) ? 1 : 0;

        cout << b << " " << l << " " << r << endl;
    }

    delete[] arr;
    delete[] requests;

    return 0;
}