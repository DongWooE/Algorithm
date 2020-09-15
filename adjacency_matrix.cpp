//adjacient matirix
#include<iostream>
#include<vector>
constexpr auto N = 5;
using namespace std;

void add(vector<vector<int>>& data, int x, int y);
void check(vector<int>& data, int x, int y);
void search(vector<int>& data, int x);
void degree(vector<int>& data, int x);

int main() {

	vector<vector<int>>matrix( N, vector<int>(N, 0));  //2차원 행렬 초기화

	add(matrix, 0, 1);  //
	add(matrix, 0, 3);
	add(matrix, 1, 2);
	add(matrix, 2, 3);
	add(matrix, 3, 4);

	check(matrix[3], 3, 2);
	search(matrix[3], 3);
	degree(matrix[4], 4);

}

void add(vector<vector<int>>& data,int x, int y) {
	data[x][y] = 1;
	data[y][x] = 1;
}

void check(vector<int>& data, int x, int y) {
	cout << "\n=====Checking Adjacency=====\n";
	int count = 0;
	cout << "check adjacent of " << x << ", " << y << "\n";
	if (data.at(y) == 1) {
		count++;
		cout << " 'find' " << "\n";
		cout << " count :  " << count << "\n";
	}
	else {
		count++;
		cout << " 'not find' " << "\n";
		cout << " count :  " << count << "\n";
	}
}
void search(vector<int>& data, int x) {
	cout << "\n=====Searching All Vertex=====\n";
	int count = 0;
	cout << "search every vertex of " << x << "\n";
	cout << "vertex : ";
	for (int i =0; i < data.size(); i++) {
		count++;
		if (data.at(i) == 1) {
			cout << " " << i << " ";
			}
		}
	cout << "\n";
	cout << "cout : " << count << "\n";
	}
void degree(vector<int>& data, int x) {
	cout << "\n=====Printing Degrees=====\n";
	int count = 0;
	int deg = 0;
	cout << "print the degree of " << x << "\n";
	for (int i =0;i<data.size(); i++) {
		count++;
		if (data.at(i) == 1) {
			deg++;
		}
	}
	cout << "degree : " << deg;
	cout << "\n";
	cout << "cout : " << count << "\n";
}
