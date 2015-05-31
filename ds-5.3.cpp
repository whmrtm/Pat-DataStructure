#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
using namespace std;
vector<int> visited;

int Num = 0;
class node{
	public:
		int value;
		node* next = NULL;
};

void Inse(node* N, int value){
	node* current = N;
	while(current->next != NULL){
		current = current->next;
	}
	node* temp = new node();
	temp->value = value;
	temp->next = current->next;
	current->next = temp;
	
}

int connect(vector<node> graph, int i, int j){
	node* current = &graph[i];
	while(current){
		if(current->value == j){
			return 1;
		}
		current = current->next;
	}
	return 0;
}

void BFS(vector<node> graph, int i){
	visited[i] = true;
    Num = 1;
    int level = 0;
    int last = i;
    int tail;
    queue<int> Q;
    Q.push(i);
    while(Q.size())
    {
        int V = Q.front();
        Q.pop();
        node* p = &graph[V];
        while( p!= NULL)
        {
            int W = p -> value;
            if ( !visited[W])
            {
                visited[W] = true;
                Q.push(W);
                Num++;
                tail = W;
            }
            p = p -> next;
        }

        if ( V == last )
        {
            level++;
            last = tail;
        }
        if ( level == 6 )
            break;
    }
}
int main(){
	int i, N, M, A, B;
	cin >> N >> M;
	vector<node> graph;
	node temp;
	temp.value = -1;
	graph.push_back(temp);
	visited.push_back(0); 
	for(i = 1; i <= N; i++){
		visited.push_back(0);
		node temp;
		temp.value = i;
 		graph.push_back(temp);
	}
	// add eages to the graph
	for(i = 0; i < M; i++){
		cin >> A >> B;
		Inse(&graph[A], B);
		Inse(&graph[B], A);
	}
	for(i = 1; i <= N; i++){
		BFS(graph, i);
		printf("%d: %4.2f%%\n", i, (float)100*Num/N);
		for(int j = 0; j <= N; j++){
			visited[j] = 0;
		}
	}
	
	//	 test the input
//	for(i = 1; i <= N; i++){
//		node* out;
//		out = &graph[i]; 
//		while(out != NULL){
//			cout << out->value << " ";
//			out = out->next;	
//		}
//		cout << endl;
//	}
	return 0;
}
