//#include <iostream>
//#include <fstream>
//using namespace std;
//
//struct Node {
//    int ver;
//    Node* next;
//};
//
//int main() {
//
//    ifstream in("input.txt");
//    ofstream out("output.txt");
//
//    int n, m;
//    in >> n >> m;
//
//    Node** adjList = new Node * [n + 1]();
//    int* sizes = new int[n + 1]();
//
//    for (int i = 0; i < m; i++) {
//        int u, v;
//        in >> u >> v;
//
//        Node* n1 = new Node{ v, adjList[u] };
//        adjList[u] = n1;
//        sizes[u]++;
//
//        Node* n2 = new Node{ u, adjList[v] };
//        adjList[v] = n2;
//        sizes[v]++;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        out << sizes[i];
//
//        Node* cur = adjList[i];
//        while (cur != nullptr) {
//            out << " " << cur->ver;
//            cur = cur->next;
//        }
//        out << endl;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        Node* cur = adjList[i];
//        while (cur != nullptr) {
//            Node* temp = cur;
//            cur = cur->next;
//            delete temp;
//        }
//    }
//    delete[] adjList;
//    delete[] sizes;
//
//    return 0;
//}