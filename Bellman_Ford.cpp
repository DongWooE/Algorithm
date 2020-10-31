#include<iostream>
#include<vector>
#include<utility>
#include<limits>
#include<queue>
using namespace std;

int main() {

	int n, m; 
	cout << " input number of vertices and edges : ";
	cin >> n >> m;

	vector<vector<pair<int, int>>>E(n);

	cout << "Input edges (vertex1, vertex2, weight)" << "\n";
	for (int i = 0; i < m; i++) {
		int t1, t2, weight;
		cin >> t1 >> t2 >> weight;
		E[t1].push_back(make_pair(t2, weight));  //digraph
	}


	int limit;
	limit = numeric_limits<int>::max();

	vector<int>dist(n, limit);  //array dist is that will show you the shortest path's cost
	vector<int>prev(n, -1);  //remember what vertex update the distance

	int start;  //starting node
	
	cout << "Input starting node : ";  
	cin >> start;

	dist[start] = 0;  //set the start node's distance 0
	
	int count = 0;
	while (count <= (n - 1)) {  //repeat (n-1) times
		count++;
		for (int v = 0; v < n; v++) {  //for all edges in E
			for (int i = 0; i < E[v].size(); i++) {
				if (dist[v] != limit) {  //if the current node's cost is limit , then pass
					if (dist[E[v][i].first] > dist[v] + E[v][i].second) {
						dist[E[v][i].first] = dist[v] + E[v][i].second;
						prev[E[v][i].first] = v;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {  //print the distance
		cout << " " << dist[i] << " ";
	}
}