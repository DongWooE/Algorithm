//prim algorithm using priority queue
//made by chungbuk-university lee dong woo
#include<iostream>
#include<vector>
#include<utility>
#include<limits>
using namespace std;

void swap(vector<pair<int, int>>& H, int x, int y) {
	pair<int, int>temp = H[x];
	H[x] = H[y];
	H[y] = temp;
}

int deleteMin(vector<pair<int, int>>& H) {  //return highest priority vertex and delete it based on heap 
	int result = H[0].second;  //highest priority vertex
	int last = H.size() - 1;
	
	swap(H, 0, last);	
	H.pop_back();  

	int n = 0;
	for (int i = 1; i < H.size(); i++) {  
		if (H[n].first < H[i].first) break;
		else {
			swap(H, n, i);
			n = i;
		}
	}
	return result;
}
void deleteQueue(vector<pair<int, int>>& H, int item) {  //delete the specific vertices
	int last = H.size() - 1;
	swap(H, last, item);
	H.pop_back();

	int n = item;
	for (int i = item +1; i < H.size(); i++) {  
		if (H[n].first < H[i].first) break;
		else {
			swap(H, n, i);
			n = i;
		}
	}
}
void insertQueue(vector<pair<int, int>>& H, pair<int,int>&item) {  //insert the specific vertices
	H.push_back(item);
	int last = H.size();
	int value = (last / 2) - 1;
	int cur = last - 1;
	while (value >=0) {
		if (H[value].first > H[cur].first) {
			swap(H, value, cur);
			cur = value;
			value = ((value+1) / 2) - 1;
		}
		else break;
	}
}
void decreaseKey(vector<pair<int, int>>& H, pair<int, int>& item) {
	for (int i = 0; i < H.size(); i++) {
		if (H[i].second == item.second) {
			deleteQueue(H, i); break;
		}
	}
	insertQueue(H, item);
}
int main() {

	int n, m;
	cout << " input number of vertices and edges : ";
	cin >> n >> m;

	vector<vector<pair<int,int>>>E(n);
	
	cout << "Input edges (vertex1, vertex2, weight)" << "\n";
	for (int i = 0; i < m; i++) {
		int t1, t2, weight;
		cin >> t1 >> t2 >> weight;
		E[t1].push_back(make_pair(t2, weight));
		E[t2].push_back(make_pair(t1, weight));
	}
	int limit;
	limit = numeric_limits<int>::max();
	vector<int>cost(n, limit);  //insert infinity to express not visiting yet
	vector<int>prev(n, -1); //-1 as nil
	vector<pair<int, int>>T;
	
	int v;
	cout << " pick any initial node : ";
	cin >> v;
	cost[v] = 0;

	//makequeue
	vector<pair<int, int>>H;	//priority queue H
	pair<int, int>temp = make_pair(0, v);
	H.push_back(temp);	//push root node
	for (int i = 0; i < n; i++) {
		if (i == v) continue;
		temp = make_pair(cost[i], i);
		H.push_back(temp);
	}

	while (!H.empty()) {
		v = deleteMin(H);
		cost[v] = 0; // To prevent duplicate vertices from appearing again
		pair<int, int>temp;
		for (int i = 0; i < E[v].size(); i++) {
			int index = E[v][i].first;
			if (cost[index] > E[v][i].second) {
				cost[index] = E[v][i].second;
				prev[index] = v;
				temp = make_pair(cost[index], index);
				decreaseKey(H, temp);
			}
		}
		T.push_back(make_pair(prev[v], v));

	}
	cout << " spanning tree's edges : ";
	for (int i = 1; i < T.size(); i++) {
		cout << " (" <<T[i].first << ", " << T[i].second << ") ";
	}
}
