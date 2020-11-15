#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int W;  //전체 weight
int check = 0;
vector<int>w;  //전체 weight 집합
vector<int>include;

void sos(int i, int weight, int total);
bool promising(int i, int weight, int total);


int main() {

	int n;
	cin >> n >> W;
	
	include.resize(n);  //n값이 받아졌으므로 include를 n개의 size만큼으로 다시 만든다
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		w.push_back(number);
	}

	sort(w.begin(), w.end());  //오름차순으로 정렬
	int sum = 0;  //모든 w 배열의 원소를 더한 값
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