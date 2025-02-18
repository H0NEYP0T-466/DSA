#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
class Edge
{
	public:
		int vertex;
		int weight;
	Edge(int v,int w)
	{
		vertex=v;
		weight=w;
	}
	bool operator>(const Edge& other) const
	 {
        return weight > other.weight;  
    }
};

class Graph
{
private:
    vector<vector<Edge>> adjlist;  
	int V;  
public:
    Graph(int v)
    {
    	V=v;
    	adjlist.resize(v);
	}
    
    void addEdge(int start, int end, int weight) 
	{
        adjlist[start].push_back({ end, weight });
        adjlist[end].push_back({ start, weight }); 
    }
    void primMST()
	{
        vector<int> parent(V, -1);  
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false); 
         priority_queue<Edge, vector<Edge>,greater<Edge>> pq;
        key[0] = 0;
        pq.push(Edge(0, 0));  
        
        while (!pq.empty()) 
		{
            int u = pq.top().vertex;
            pq.pop();
            inMST[u] = true; 
            for (auto& edge : adjlist[u]) 
			{
                int v = edge.vertex;
                int weight = edge.weight;
                
                if (!inMST[v] && weight < key[v]) 
				{
                    key[v] = weight;
                    parent[v] = u;
                    pq.push(Edge(v, key[v])); 
                }
            }
        }
        cout << "Edge\tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << key[i] << endl;
        }
    }
};

int main() 
{
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.primMST();
    return 0;
}
