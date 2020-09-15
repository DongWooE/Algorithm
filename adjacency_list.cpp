//adjacent list
// show the time complexity for each case
#include<iostream>
#include<vector>
constexpr auto number = 5;;
using namespace std;

typedef struct Vertex {  
	int num;
	struct Vertex* link;
}Vertex;
void check(Vertex *i, int x);  //checking the adjacent vertex
void degree(Vertex *i);  //print the degree
void add(Vertex *i, int x);  //add the edge
void search(Vertex *i);  //check all vertex
void free(vector<Vertex>&data);  //free the array
int m = 0;  //|E(G)|

int main() {  
	vector<Vertex>graph;
	for (int i = 0; i<number; i++) {
		Vertex temp;
		temp.num = i;
		temp.link = NULL;
		graph.push_back(temp);
		m++;
	}
	
	//making edges
	add(&graph[0], 1); add(&graph[1], 0); m++;  //make edge for 0 - 1
	add(&graph[0], 3); add(&graph[3], 0); m++;
	add(&graph[1], 2); add(&graph[2], 1); m++;
	add(&graph[2], 3); add(&graph[3], 2); m++;
	add(&graph[4], 3); add(&graph[3], 4); m++;

	cout << "making space : " << m << "\n";
	check(&graph[4], 0);  
	degree(&graph[3]);
	search(&graph[3]);

	free(graph);
	}
void free(vector<Vertex>& data) {
	for (int i = 0; i < data.size(); i++) {
		Vertex* lead = data.at(i).link;
		Vertex* tail = NULL;

		while(lead){
		tail = lead;
		lead = lead->link;
		delete tail;
		}
	}
}
void add(Vertex* i, int x) {
	Vertex* temp = new Vertex;
	temp->num = x; temp->link = NULL;
	Vertex* lead = i->link; Vertex* prev = NULL;
	if (!lead) {
		i->link = temp;
		return;
	}
	while(lead->link) {
		lead = lead->link;
	}
	lead->link = temp;
}
void check(Vertex* i, int x) {
	cout << "\n=====Checking Adjacency=====\n";
	int count = 0;
	cout << "check adjacent of " << i->num << ", " << x << "\n";
	for (Vertex* temp = i->link; temp != NULL; temp = temp->link){
		count++;
		if (temp->num == x){
			cout << " 'find' " << "\n";
			cout << " count :  " << count << "\n";
			return;
		}
	}
	cout << " not find " << "\n";
	cout << " count :  " << count << "\n";
}
void search(Vertex* i) {
	cout << "\n=====Searching All Vertex=====\n";
	int count = 0;
	cout << "search every vertex of " << i->num << "\n";
	cout << "vertex : ";
	for (Vertex* temp = i->link; temp != NULL; temp = temp->link) {
		cout << " " << temp->num << " ";
		count++;
	}
	cout << "\n";
	cout << "count : " << count << "\n";
}
void degree(Vertex* i) {
	cout << "\n=====Printing Degrees=====\n";
	int deg = 0;
	int count = 0;
	cout << "print the degree of " << i->num << "\n";
	for (Vertex* temp = i->link; temp != NULL; temp = temp->link) {
		deg++;
		count++;
	}
	cout << "degree : " << deg << "\n";
	cout << "cout : " << count << "\n";
}
