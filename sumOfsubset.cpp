#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int W;  //��ü weight
int check = 0;
vector<int>w;  //��ü weight ����
vector<int>include;

void sos(int i, int weight, int total);
bool promising(int i, int weight, int total);


int main() {

	int n;
	cin >> n >> W;
	
	include.resize(n);  //n���� �޾������Ƿ� include�� n���� size��ŭ���� �ٽ� �����
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		w.push_back(number);
	}

	sort(w.begin(), w.end());  //������������ ����
	int sum = 0;  //��� w �迭�� ���Ҹ� ���� ��
	for (int i = 0; i < w.size(); i++)
		sum += w[i];
	
	sos(-1, 0, sum);
	check++;
	cout << "\n" << check << " ";
}

void sos(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W) {
			for (int j = 0; j < include.size(); j++) {
				if (include[j] == 1)
					cout << " " << w[j];
			}
		}
		else {
			include[i + 1] = 1;
			check++;
			sos(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = 0;
			check++;
			sos(i + 1, weight, total - w[i + 1]);
			}
		}
	}


bool promising(int i, int weight, int total) {
	return ((weight + total) >= W) && (weight == W || ((weight + w[i + 1]) <= W));
}