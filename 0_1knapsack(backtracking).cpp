#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int n, W;  //items의 개수, 배낭의 무게
vector<bool>include;  //상태공간트리를 만들때 해당 node가 들어가는지 들어가지않는지를 판별해주는 vector
vector<pair<int, int>>items;  //items의 profit과 weight가 저장되는 vector

int numbest;
vector<int>bestset;
int check = 0;
int maxprofit = 0;

bool sortbyvalue(const pair<int, int>& a,	const pair<int, int>& b)  //items 배열에 p/w 순으로 정렬하기위한 함수
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
	
	items.push_back(make_pair(0, 0)); // 0,0의 노드 만들기
	for (int i = 0; i < n; i++) {
		int weight, profit;
		cin >> profit >> weight;

		items.push_back(make_pair(profit, weight));
	}

	include.resize(n+1);
	bestset.resize(n + 1);
	sort(items.begin()+1, items.end(), sortbyvalue);  //items의 value순으로 정렬

	knapsack(0, 0, 0);
	check++;
	cout << "\noptimal set : ";
	for (int i = 0; i < n; i++)
		if(bestset[i] ==1)
			cout << i << " ";

	cout << "\n" << "count : " << check;
}