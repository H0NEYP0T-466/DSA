#include <iostream>
#include <vector>
#include <list>
#include <limits>
using namespace std;
class Graph {
    int numNode;
    vector<list<pair<int, int>>> adjlist;
public:
	vector<int> distance;
    Graph(int n) {
        this->numNode = n;
        adjlist.resize(n);
        distance.resize(n, INT_MAX);
    }

    void addEdge(int start, int end, int weight) {
        adjlist[start].push_back({ end, weight });
    }

    void bellmanFord(int source) {
        distance[source] = 0;
        for (int i = 0; i < numNode - 1; i++) {
            for (int u = 0; u < numNode; u++) {
                for (auto& edge : adjlist[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                    }
                }
            }
        }

        // Check for negative cycles
        for (int u = 0; u < numNode; u++) {
            for (auto& edge : adjlist[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    cout << "Negative cycle detected!" << endl;
                    return;
                }
            }
        }
    }
};

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    Graph obj(n);
    cout << "Enter edges (start end weight), enter -1 -1 -1 to stop:\n";
    while (true) {
        int start, end, weight;
        cin >> start >> end >> weight;
        if (start == -1 && end == -1 && weight == -1)
            break;
        obj.addEdge(start-1, end-1, weight);
    }
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    obj.bellmanFord(source-1);
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Distance to node " << i+1<< " is " << obj.distance[i] << endl;
    }
    return 0;
}

