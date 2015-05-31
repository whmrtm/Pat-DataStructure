#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef struct point{
	int x;
	int y;
}pos;

const int dia = 15;
int visited[100] = {0};
int answer = 0;

// calculate the distance
double distance(vector<pos> p, int i, int j);
int DFS(vector<pos> p, int i);
int IsSafe(vector<pos> p, int i, int D);


double distance(vector<pos> p, int i, int j){
	int deltaX = abs(p[i].x - p[j].x);
	int deltaY = abs(p[i].y - p[j].y);
	return (double)(sqrt(pow(deltaX,2) + pow(deltaY,2)));
}
int DFS(vector<pos> p, int i, int D){
	if(visited[i]){
		return 0;
	}
	if(IsSafe(p, i, D)){
		return 1;
	}
	visited[i] = 1;
	int j;	
	for(j = 0; j < p.size(); j++){
		if(visited[j] == 0 && distance(p, i , j) <= D){
			answer = DFS(p, j, D);
			if(answer)
				break;
		}
	}
	return answer;
}
int IsSafe(vector<pos> p, int i, int D){
	if(abs(p[i].x) >= 50 - D ||
	abs(p[i].y) >= 50 -D){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int i, N, D;
	int A, B;
	cin >> N >> D;
	vector<pos> p;
	for(i = 0; i < N; i++){
		cin >> A >> B;
		pos temp;
		temp.x = A;
		temp.y = B;
		p.push_back(temp); 
		visited[i] = 0;
	}
//	cout << distance(p,0,1);
	if(dia + D >= 50){
		cout << "Yes";
	} else {
		
		for(i = 0; i < N; i++){
			if(visited[i] == 0 && sqrt(pow(p[i].x, 2) + pow(p[i].y, 2)) <= dia + D ){
				if(DFS(p, i, D)){
					break;
				}
				
			}
		}
		if(i == N){
			cout << "No";
		}
		else{
			cout << "Yes";
		}
	}
	
	
	return 0;
}
