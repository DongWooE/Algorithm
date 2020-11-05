#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main() {

	vector<pair<int, int>>node;

	int n;  //노드의 개수
	cin >> n;

	for (int i = 0; i < n; i++) {  //여기서 입력받는다
		int num;
		int frequency;
		cin >> num >> frequency;
		node.push_back(make_pair(num, frequency));
	}

	vector<vector<int>>C(n, vector<int>(n));  //2차원 배열 C생성
	
	
	//C 배열에서 0이 되는 것과 i==j가 되는 것을 사전 작업한다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) C[i][j] = 0;
			else if (i == j) C[i][j] = node[i].second;
		}
	}

	int index = 1;
	int i = 0;
	int j;
	cout << "\n";
	while (index < n) {
		for (i = 0; i + index < n; i++) {
			j = i + index;
			int min, k = i;
			int frequency = 0;
			for (int a = i; a <= j; a++) frequency += node[a].second;	//int frequency = node[i].second + node[j].second;
			if(k == 0) min = 0 + C[k + 1][j] + frequency;
			else min = C[i][k - 1] + C[k + 1][j] + frequency;
			cout << " " << min;
			for (k = i + 1; k <= j; k++) {
				int value;
				if (k >= n - 1) value = C[i][k - 1] + 0 + frequency;
				else value = C[i][k - 1] + C[k + 1][j] + frequency;
				cout << " " << value;
				if (min > value) min = value;  //min값을 다시 구한다
			}
			cout << "\n";
			C[i][j] = min;
		}
		index++;
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << " " << C[i][j];
		}
		cout << "\n";
	}

}
