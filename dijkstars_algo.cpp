#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <limits> // For INT_MAX
#include <algorithm> // For reverse
using namespace std;
class Graph {
	int numNode;
	vector<list<pair<int, int>>> adjlist; // Store weight along with adjacent node
//	vector<int> parent; // To store the shortest path
public:
	vector<int> distance; // Distance vector
	Graph(int n) {
		this->numNode = n;
		adjlist.resize(n);
		//parent.resize(n, -1); // Initialize parent with -1
		distance.resize(n, INT_MAX); // Initialize distance with infinity
	}

	void addEdge(int start, int end, int weight) {
		adjlist[start].push_back({ end, weight });
		adjlist[end].push_back({ start, weight }); // For undirected graph
	}

	void dijkstra(int source) {
		set<pair<int, int>> s; // Use set instead of priority_queue
		distance[source] = 0;
		s.insert({ 0, source });

		while (!s.empty()) {
			int u = s.begin()->second;
			s.erase(s.begin());

			for (auto& edge : adjlist[u]) {
				int v = edge.first;
				int weight = edge.second;
				if (distance[u] + weight < distance[v]) {
					if (distance[v] != INT_MAX) {
						s.erase({ distance[v], v }); // Remove old distance
					}
					distance[v] = distance[u] + weight;
					s.insert({ distance[v], v });
						//parent[v] = u; // Update parent for shortest path
				}
			}
		}
	}

/*	void printShortestPath(int source, int destination) {
		vector<int> path;
		int current = destination;

		while (current != -1) {
			path.push_back(current);
			current = parent[current];
		}

		reverse(path.begin(), path.end());

		cout << "Shortest path from " << source << " to " << destination << ": ";
		for (int node : path) {
			cout << node << " ";
		}
		cout << endl;
	}
	*/
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
		if (start == -1 && end == -1 && weight == -1) break; // Stop input on -1 -1 -1
		obj.addEdge(start, end, weight); // Add edge to the graph
	}

	int source;
	cout << "Enter the source node: ";
	cin >> source;
	obj.dijkstra(source);

	cout << "Shortest distances from node " << source << ":\n";
	for (int i = 0; i < n; ++i) {
		cout << "Distance to node " << i << " is " << obj.distance[i] << endl;
	}

/*	int destination;
	cout << "Enter the destination node: ";
	cin >> destination;
	obj.printShortestPath(source, destination);
*/
	return 0;
}

