//kruskal algorithm using union-find data structure
//made by chungbuk-university lee dong woo
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void swap(vector<pair<int, pair<int, int>>>&E, int x, int y) {  //swap edges 
	pair<int,pair<int, int>>temp = E[x];
	E[x] = E[y];
	E[y] = temp;
}

int partitioning(vector<pair<int, pair<int, int>>>& E, int begin, int end) {  
	int pivot, left, right;
	left = begin;
	right = end;
	pivot = (int)((begin + end) / 2.0);

	while (left < right) {
		while ((E[left].first < E[pivot].first) && (left < right)) left++;
		while ((E[right].first >= E[pivot].first) && (left < right)) right--;
		if (left < right) {
			swap(E, left, right);
			if (left == pivot) pivot = right;
		}
	}
	swap(E, pivot, right);
	return right;
}

void quickSort(vector<pair<int, pair<int, int>>>&E, int begin, int end) {  //quicksort algorithm
	int p; //pivot
	if (begin < end) {
		p = partitioning(E, begin, end);
		quickSort(E, begin, p - 1);
		quickSort(E, p + 1, end);
	}
}

int find(vector<pair<int,int>>set, int num) {  //return parent's index
	int index=num;
	while (set[index].first != set[index].second) {
		index = set[index].second;
	}
	return index;
}

void unionSet(vector<pair<int, int>>& set, vector<int>& rank, int x, int y) {  //union the set
	int rootx = find(set, x);
	int rooty = find(set, y);
	if(rootx == rooty) return;
	if (rank[rootx] > rank[rooty])	set[rooty].second = rootx;
	else {
		set[rootx].second = rooty;
		if (rank[rootx] == rank[rooty])	rank[rooty] = rank[rooty] + 1;
	}
}

int main() {

	int n, m;
	cout << " input number of vertices and edges : ";
	cin >> n >> m;

	vector<pair<int, pair<int, int>>>E;

	cout << "Input edges (vertex1, vertex2, weight)" << "\n";
	for (int i = 0; i < m; i++) {	
		int t1, t2, weight;
		cin >> t1 >> t2 >> weight;
		E.push_back(make_pair(weight, make_pair(t1, t2)));
	}
	
	//makeset
	vector<pair<int, int>>set;
	for (int i = 0; i < n; i++) {
		set.push_back(make_pair(i, i));  //first element is node number, second element is parent number
	}
	
	vector<pair<int, int>>X;  //spanning tree's edges
	vector<int>rank(n, 0);  //rank of each vertex

	quickSort(E, 0, E.size() - 1);  //sort

	for (int i = 0; i < E.size(); i++) {
		int x = find(set, E[i].second.first);	
		int y = find(set, E[i].second.second);	
		if (x!= y) {
			//unoin 
			X.push_back(E[i].second);
			unionSet(set, rank, x, y);
		}
	}
	cout << " spanning tree's edges : " << "\n";
	for (int i = 0; i < X.size(); i++)
		cout << " (" << X[i].first << ", " << X[i].second << ") ";
}