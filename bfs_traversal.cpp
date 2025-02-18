#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(n);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graph
    }

    void BFS() {
        vector<bool> visited(numVertices, false);

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                queue<int> q;
                visited[i] = true;
                q.push(i);

                while (!q.empty()) {
                    int currentVertex = q.front();
                    q.pop();

                    cout << currentVertex << " ";

                    for (int neighbor : adjList[currentVertex]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 3);
    graph.addEdge(3, 1);
    graph.addEdge(1, 2);

    // Disconnected component
    graph.addEdge(4, 4); // Self-loop to create a disconnected component

    cout << "Graph diagram:" << endl;
    cout << "0 -- 3 -- 1 -- 2" << endl;
    cout << "4" << endl; // Disconnected component

    cout << "BFS traversal: ";
    graph.BFS();

    return 0;
}

