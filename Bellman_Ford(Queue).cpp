//Bellman - Ford algorithm using queue
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
		E[t1].push_back(make_pair(t2, weight));
	}


	int limit;
	limit = numeric_limits<int>::max();

	vector<int>dist(n, limit);  
	vector<int>prev(n, -1);  

	int start;  
	cout << "Input starting node (that dosen't make cycle) : ";
	cin >> start;

	queue<int>Q;

	dist[start] = 0;  
	for (int i = 0; i < E[start].size(); i++) {  //check the starting node's adjacent node
		dist[E[start][i].first] = E[start][i].second; 
		Q.push(E[start][i].first);
		prev[E[start][i].first] = start;  
	}


	while (!Q.empty()) {
		int v = Q.front();  //save the vertex number of queue's front
		Q.pop();
		for (int i = 0; i < E[v].size(); i++) {  //search the adjacency list of nodes extracted from the queue 
			if (dist[E[v][i].first] > dist[v] + E[v][i].second) {
				dist[E[v][i].first] = dist[v] + E[v][i].second;
				Q.push(E[v][i].first);
				prev[E[v][i].first] = v;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << " " << dist[i] << " ";
	}
}