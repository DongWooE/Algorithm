#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int n, W;  //items�� ����, �賶�� ����
vector<bool>include;  //���°���Ʈ���� ���鶧 �ش� node�� ������ �����ʴ����� �Ǻ����ִ� vector
vector<pair<int, int>>items;  //items�� profit�� weight�� ����Ǵ� vector

int numbest;
vector<int>bestset;
int check = 0;
int maxprofit = 0;

bool sortbyvalue(const pair<int, int>& a,	const pair<int, int>& b)  //items �迭�� p/w ������ �����ϱ����� �Լ�
{
	return (a.first/a.second > b.first/b.second);
}

bool promising(int i, int profit , int weight) {
	int j, k;
	int totweight=0;
	float bound=0;

	if (weight >= W) { 
		cout << "level : " << i << " profit :  " << profit<< " weight " << weight<< " bound:" << bound<< " maxprofit : " << maxprofit << " totweight : " << totweight << "\n";
		return false; }
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while ((j <= n) && (totweight + items[j].second <= W)) {
			totweight = totweight + items[j].second;
			bound = bound + items[j].first;
			j++;
		}
		k = j;
		if (k <= n) bound = bound + (W - totweight) * items[k].first / items[k].second;
		cout << "level : " << i << " profit :  " << profit << " weight " << weight << " bound:" << bound << " maxprofit : " << maxprofit << " totweight : " << totweight << "\n"; 
		return bound > maxprofit;

	}

}
void knapsack(int i, int profit, int weight) {

	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		numbest = i;
		for (int a = 0; a <= i; a++)
			bestset[a] = include[a];
	}
	if (promising(i, profit, weight)) {
			include[i + 1] = 1;
			check++;
			knapsack(i + 1, profit + items[i + 1].first, weight + items[i + 1].second);
			include[i + 1] = 0;
			check++;
			knapsack(i + 1, profit, weight);
		}
	
}

int main() {

	cin >> n >> W;
	
	items.push_back(make_pair(0, 0)); // 0,0�� ��� �����
	for (int i = 0; i < n; i++) {
		int weight, profit;
		cin >> profit >> weight;

		items.push_back(make_pair(profit, weight));
	}

	include.resize(n+1);
	bestset.resize(n + 1);
	sort(items.begin()+1, items.end(), sortbyvalue);  //items�� value������ ����

	knapsack(0, 0, 0);
	check++;
	cout << "\noptimal set : ";
	for (int i = 0; i < n; i++)
		if(bestset[i] ==1)
			cout << i << " ";

	cout << "\n" << "count : " << check;
}