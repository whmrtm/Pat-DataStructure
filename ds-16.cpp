#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int visited[10000];
queue<int> Q;
class node{
	public:
		int key;
		node* next = NULL;
};
void Insert_node(node* N, int value){
	node *current = N;
	while(current->next != NULL){
		current = current->next;
	}	
	node* temp = new node();
	temp->key = value;
	temp->next = current->next;
	current->next = temp;
}

int connect(int i, int j, vector<node> graph){
	node* current = &graph[i];
	while(current){
		if(current->key == j)
			return 1;
		current = current->next;
	}
	return 0;
}
void DFS(vector<node> graph, int* visited, int i){
		if(visited[i])
			return;
		visited[i] = 1;
		cout << i << " ";
		int j;
		for(j = 0; j < graph.size(); j++){
			if(connect(i,j,graph) == 1 && visited[j] == 0){
				DFS(graph, visited, j);
			}
		}	
}
void BFS(vector<node> graph, int i){
	if(visited[i])
		return;
	visited[i] = 1;
	Q.push(i);
	while(Q.size()!=0){
		cout << Q.front() << " ";
		i = Q.front();
		Q.pop();
		for(int j = 0; j < graph.size(); j++){
			if(connect(i, j, graph) == 1 && visited[j] == 0){
				visited[j] = 1;
				Q.push(j);
			}
		}
	}
}
int main(){
	int i, N, E, A, B;
	vector<node> graph;
	cin >> N >> E;
	for(i = 0; i < N; i++){
		node temp;
		temp.key = i;
		graph.push_back(temp);
		visited[i] = 0; 
	}
	for(i = 0; i < E; i++){
		cin >> A >> B;
		Insert_node(&graph[A], B);
		Insert_node(&graph[B], A);
	}
	
//	 test the input
//	for(i = 0; i < N; i++){
//		node* out;
//		out = &graph[i]; 
//		while(out != NULL){
//			cout << out->key << " ";
//			out = out->next;	
//		}
//		cout << endl;
//	}

	for(i = 0; i < graph.size(); i++){
		if(visited[i] == 0){
			cout << "{ ";
			DFS(graph, visited, i);
			cout << "}" << endl;
		}
	}
	
	// re-initialize
	for(i = 0; i < graph.size(); i++){
		visited[i] = 0;
	}
	
	for(i = 0; i < graph.size(); i++){
		if(visited[i] == 0){
			cout << "{ ";
			BFS(graph, i);
			cout << "}" << endl;
		}
	}
} 
