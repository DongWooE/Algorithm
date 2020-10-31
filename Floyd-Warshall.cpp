#include<iostream>
#include<vector>
#include<utility>
#include<limits>
using namespace std;

int main() {
	
	int limit;
	limit = numeric_limits<int>::max();


	int n, m;
	cout << " input number of vertices and edges : ";
	cin >> n >> m;

	vector<vector<pair<int, int>>>E(n);

	vector<vector<int>>dist(n, vector<int>(n, limit));  //2차원 벡터 생성

	for (int i = 0; i < n; i++){
		dist[i][i] = 0;
	}

	cout << "Input edges (vertex1, vertex2, weight)" << "\n";
	for (int i = 0; i < m; i++) {
		int t1, t2, weight;
		cin >> t1 >> t2 >> weight;
		E[t1].push_back(make_pair(t2, weight));
		dist[t1][t2] = weight;  //테이블을 정리
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] != limit && dist[k][j] != limit) {
					if (dist[i][j] > (dist[i][k] + dist[k][j]))
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	cout << "\n ===== Print the matrix =====\n";
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			cout << " " << dist[a][b] << " ";
		}
		cout << "\n";
	}
	
}
