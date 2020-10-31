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

	vector<int>dist(n, limit);  //무한대 값을 넣어줌
	vector<int>prev(n, -1);  //nil로 초기화



	int start;  //starting node
	
	cout << "Input starting node (that dosen't make cycle) : ";  
	cin >> start;

	dist[start] = 0;
	
	int count = 0;
	while (count <= (n - 1)) {
		count++;
		for (int v = 0; v < n; v++) {
			for (int i = 0; i < E[v].size(); i++) {
				if (dist[v] != limit) {
					if (dist[E[v][i].first] > dist[v] + E[v][i].second) {
						dist[E[v][i].first] = dist[v] + E[v][i].second;
						prev[E[v][i].first] = v;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << " " << dist[i] << " ";
	}
}