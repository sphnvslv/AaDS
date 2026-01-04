#include <iostream>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;

struct Shop {
    long long a, b;
};

struct MinRes {
    long long price;
    int index;
};

struct Tree {
    long long* minPrice;
    int* minIndex;
    int size;

    Tree(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }
        minPrice = new long long[2 * size];
        minIndex = new int[2 * size];

        for (int i = 0; i < 2 * size; i++) {
            minPrice[i] = LLONG_MAX;
            minIndex[i] = -1;
        }
    }

    ~Tree() {
        delete[] minPrice;
        delete[] minIndex;
    }

    void build(Shop* shops, int n) {

        for (int i = 0; i < n; i++) {
            minPrice[size + i] = shops[i].a;
            minIndex[size + i] = i;
        }
        for (int i = n; i < size; i++) {
            minPrice[size + i] = LLONG_MAX;
            minIndex[size + i] = -1;
        }
        for (int i = size - 1; i > 0; i--) {

            if (minPrice[2 * i] <= minPrice[2 * i + 1]) {
                minPrice[i] = minPrice[2 * i];
                minIndex[i] = minIndex[2 * i];
            }
            else {
                minPrice[i] = minPrice[2 * i + 1];
                minIndex[i] = minIndex[2 * i + 1];
            }
        }
    }

    MinRes get_min() {
        MinRes result;
        result.price = minPrice[1];
        result.index = minIndex[1];

        return result;
    }

    void update(int index, long long new_value) {
        int pos = size + index;
        minPrice[pos] = new_value;
        pos /= 2;

        while (pos > 0) {

            if (minPrice[2 * pos] <= minPrice[2 * pos + 1]) {
                minPrice[pos] = minPrice[2 * pos];
                minIndex[pos] = minIndex[2 * pos];
            }
            else {
                minPrice[pos] = minPrice[2 * pos + 1];
                minIndex[pos] = minIndex[2 * pos + 1];
            }
            pos /= 2;
        }
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, k;
    in >> n >> k;

    Shop* shops = new Shop[n];

    for (int i = 0; i < n; i++) {
        in >> shops[i].a >> shops[i].b;
    }

    Tree tree(n);
    tree.build(shops, n);

    long long cost = 0;

    for (int i = 0; i < k; i++) {
        MinRes min_info = tree.get_min();
        cost += min_info.price;

        shops[min_info.index].a += shops[min_info.index].b;
        tree.update(min_info.index, shops[min_info.index].a);
    }

    out << cost << endl;

    delete[] shops;
    return 0;
}