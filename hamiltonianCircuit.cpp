#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>W;
int n, m;
int space = 0;
vector<int>vindex;
int checkCount = 0;

bool promising(int i) {
	int j = 0;
	bool check = true;
	
	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
		check = false;
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
		check = false;
	else {
		while (j < i && check) {
			if (vindex[i] == vindex[j]) check = false;
			j++;
		}
	}

	return check;

}

void hamiltonian(int i) {
	int j;
	if (promising(i)) {
		if (i == n-1 ) {
			for (int a = 0; a <= n; a++) {
				cout << vindex[a] << " ";
				space++;
				if (space == n+1) {
					space = 0;
					cout << "\n";
				}
			}
		}
		else {
			for (j = 1; j < n; j++) {
				vindex[i + 1] = j;
				checkCount++;
				hamiltonian(i + 1);
			}
		}
	}
}


int main() {
	cin >> n >> m;

	W.resize(n, vector<int>(n));
	vindex.resize(n+1);
	vindex[0] = 0;  //처음 경로와 마지막 경로를 정해주어야한다
	
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		W[t1][t2] = 1;
		W[t2][t1] = 1;
	}

	hamiltonian(0);  //처음 시작점을 보낸다
	
	cout << "count : " << checkCount;

}

