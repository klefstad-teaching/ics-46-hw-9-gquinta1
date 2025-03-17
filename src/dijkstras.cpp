#include "dijkstras.h"

using namespace std;
void dijikstra(int source, Graph& G){
    int n = G.adjencyList.size();
    G.distance.resize(n, INF);
    G.previous.resize(n, -1);
    G.visited.resize(n, false);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(Node(source, 0));
	G.distance[source] = 0;

	while (!pq.empty()){
		Node current = pq.top();
		pq.pop();
		int u = current.vertex;
		if (G.visited[u]){
			continue;
		}
		G.visited[u] = true;
		for (Node neighbor: G.adjencyList[u]){
			int v = neighbor.vertex;
			int weight = neighbor.weight;

			if (!G.visited[v] && G.distance[u] + weight < G.distance[v]){
				G.distance[v] = G.distance[u] + weight;
				G.previous[v] = u;
				pq.push(Node(v,G.distance[v]));
			}
		}
	}
}

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	Graph gg = G; 
	dijikstra(source, gg);
	return gg.distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
	vector<int> shortest_path;
	if (distances[destination] == INF){
		return shortest_path;
	}
	for (int i = destination; i!=-1; i = previous[i]){

		shortest_path.push_back(i);
	}
	reverse(shortest_path.begin(), shortest_path.end());
	return shortest_path;
}


void print_path(const vector<int>& v, int total){
	for (int num: v){
		cout << num<< " ";
	}
	cout<< "\nTotal cost is "<< total<< endl;
}