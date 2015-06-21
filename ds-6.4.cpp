#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

using namespace std;
typedef struct point{
	int x;
	int y;
	int ind;
	bool visited;
}pos;

const int dia = 15;
int visited[100] = {0};
int answer = 0;

// calculate the distance
double Distance(pos p1, pos p2);
int DFS(vector<pos> p, int i);
int IsSafe(vector<pos> p, int i, int D);
struct CompareDis{
	bool operator()(const pos& p1, const pos& p2){
		return (p1.x*p1.x + p1.y*p1.y) > (p2.x*p2.x + p2.y*p2.y);
	}
};


int main(){
	int i, N, D;
	int A, B;
	cin >> N >> D;
	vector<pos> p;
	priority_queue<pos, vector<pos>, CompareDis> dots;
		
	for(i = 0; i < N; i++){
		cin >> A >> B;
		pos temp;
		temp.x = A;
		temp.y = B;
		temp.visited = false;
		temp.ind = i;
		p.push_back(temp); 
		visited[i] = 0;
		dots.push(p[i]);
	}
//	cout << distance(p,0,1);
	while(!dots.empty()){
		cout << dots.top().x << " " << dots.top().y << endl;
		dots.pop();
	}	
// dijkstra method 
	// define all the structures needed
	int *dist = new int[N];
	int *path = new int[N];
	int mindist = 0;
	for(i = 0; i < N; i++){
		dist[i] = -1;
		path[i] = -1;
	}
	pos start;
	start.x = 0;
	start.y = 0;
	
	queue<int> bfsQueue;
// push elements that fit the first step
	int flag = 1;
	while(!dots.empty()){
		pos s = dots.top();
		if(dots.empty())
			break;
		s.visited = true;
		dots.pop();
		if{
		
		}
		else{
			for(i = 0; i < p.size(); i++){
				if(dist[i] == -1 && Distance(s, p[i]) < D){
					bfsQueue.push(i);
					dist[i] = dist[s.data] + 1;
					path[i] = s.data; 
				} 
			}
		}
	}
		
	

	return 0;
}


double Distance(pos p1, pos p2){
	int deltaX = abs(p1.x - p2.x);
	int deltaY = abs(p1.y - p2.y);
	return (double)(sqrt(pow(deltaX,2) + pow(deltaY,2)));
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

