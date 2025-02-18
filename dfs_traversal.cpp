#include<iostream>
#include<list>
#include<vector>
using namespace std;

class graph {
    int numNode;
    vector<list<int>> adjlist;
public:
    graph(int n) {
        this->numNode = n;
        adjlist.resize(n);
    }
    void addedge(int start, int end) {
        adjlist[start].push_back(end);
        adjlist[end].push_back(start);
    }

    void dfs() {
        vector<bool> visited(numNode, false);

        for (int i = 0; i < numNode; i++) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }

    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjlist[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    graph obj(5);
    obj.addedge(0, 1);
    obj.addedge(0, 2);
    obj.addedge(1, 3);
    obj.addedge(1, 4);

    cout << "DFS traversal: ";
    obj.dfs();

    return 0;
}
