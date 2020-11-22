#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>W;
int n, m; //����� ����� ����
vector<int>vcolor;
int space = 0;
int check = 0;

bool promising(int i) {
	int j = 0;
	bool check = true;
	while (j < i && check) {
		if (W[j][i] && vcolor[i] == vcolor[j]) 
			check = false;
			j++;
		
	}
	return check;
}

void m_coloring(int i) {
	int color;
	if (promising(i)) {
		if (i == n-1) {
			for (int a = 0; a < n; a++) {
				cout << vcolor[a] << " ";
				space++;
				if (space == n) { 
					space = 0;
					cout << "\n"; }
			}
		}
		else{
			for (color = 0; color < m; color++) {
				vcolor[i + 1] = color;
				check++;
				m_coloring(i + 1);
			}
		}
	}
}

int main() {

	int e;  //n : ����� ����, e : ������ ����
	cin >> n >> e;

	cout << "color : ";
	cin >> m; //������ ���� �Է�

	W.resize(n, vector<int>(n));
	vcolor.resize(n);

	for (int i = 0; i < e; i++) {  //������� ����
		int t1, t2;
		cin >> t1 >> t2;
		W[t1][t2] = 1;
		W[t2][t1] = 1;
	}

	check++; //���۳�嵵 count�� �߰�
	m_coloring(-1);

	cout << "count : " << check;
}
