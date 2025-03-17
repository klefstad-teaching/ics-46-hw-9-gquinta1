#include "dijkstras.h"


void dijikstra(int source, Graph& G){
    n = graph.adjencyList.size();
    graph.distance.resize(n, INT_MAX);
    graph.previosu.resize(n, -1);
    graph.visited.resize(n, false);
    priorityQueue pq;
	pq.push(Node(source, 0));
	graph.distance[source] = 0;

	while !pq.empty(){
		current = pq.pop_top();
		u = current.vertex;
		if (graph.visited[u]){
			continue;
		}
		graph.visited[u] = true;
		for (String neighbor: graph.adjencyList[u]){
			v = neighbor.vertex;
			weight = neighbor.weight;
		}

		if (!graph.visited[v] && graph.distance[u] + weight < graph.distance[v]){
			graph.distance[v] = graph.distance[u] + weight;
			graph.previous[v] = u;
			pq.push(Node(v,graph.distance[v]));
		}
	}
}

void print_path(const vector<int>& v, int total){
	for (int num: v){
		cout << num<< " ";
	}
	cout<< "The total cost is "<< total<< endl;
}