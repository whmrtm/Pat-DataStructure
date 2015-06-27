#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;
typedef struct point{
	int x;
	int y;
}pos;

// dia -> diameter, p -> store all the points
double dia = 7.5;
vector<pos> p;

// calculate the distance
double Distance(pos p1, pos p2);
int DFS(vector<pos> p, int i);

// check whether bond is safe
int IsSafe(pos p, double D);
vector<int> getPath(int t, int p[]);

struct CompareDis{
	bool operator()(int a, int b){
		pos p1 = p[a];
		pos p2 = p[b];
		return (p1.x*p1.x + p1.y*p1.y) > (p2.x*p2.x + p2.y*p2.y);
	}
};

int main(){
	int i, j, N;
	double D;
	int A, B;
	cin >> N >> D;
//	priority_queue<int, vector<int>, CompareDis> dots;
	if(D + dia >= 50){
		cout << 1 << endl;
		return 0;
	}
	
		
	for(i = 0; i < N; i++){
		cin >> A >> B;
		pos temp;
		temp.x = A;
		temp.y = B;
		p.push_back(temp); 
//		dots.push(p[i]);
	}
// build the maximum heap	
//	cout << distance(p,0,1);
//	while(!dots.empty()){
//		cout << dots.top().x << " " << dots.top().y << endl;
//		dots.pop();
//	}	
// build the graph
//	pos start;
//	start.x = 0;
//	start.y = 0;
//	p.push_back(start);
//	vector<int> graph[(N+2)*(N+1)/2];
//	for(i = 0; i < (N+2)*(N+1)/2; i++){
//		graph.push_back(-1);
//	}
//	
//	for(i = 0; i < N+1; i++){
//		for(j = 0; j < N; j++){
//			if(i != j){
//				if(distance(p[i],p[j]) <= D){
//					graph[i*(i+1)/2+j] = distance(p[i], p[j]);
//				}
//			}
//		}
//	}

	
// dijkstra method 
	// define all the structures needed
	int *dist = new int[N];
	int *path = new int[N];
	
	priority_queue<int, vector<int>, CompareDis> myQueue;
	
	vector<int> pathVec;
	// push elements that fit the first step
	pos start;
	start.x = 0;
	start.y = 0;
	for(i = 0; i < N; i++){
		if(Distance(p[i], start) <= D + dia){
			myQueue.push(i);
		}
	}
	
	queue<int> bfsQueue;
	int flag = 1;
	int minDist = 0;
	
	while(!myQueue.empty()){
		
		
		for(i = 0; i < N; i++){
			dist[i] = -1;
			path[i] = -1;
		}
		
		int w = myQueue.top();
		dist[w] = 0;
		myQueue.pop();
		bfsQueue.push(w);
//		dots.pop();
		while(!bfsQueue.empty()){
			int s = bfsQueue.front();
			bfsQueue.pop();
			if(IsSafe(p[s], D)){
				if(flag){
					minDist = dist[s];
					flag = 0;
					pathVec = getPath(s, path);
				}
				else if(dist[s] < minDist){
					minDist = dist[s];
					pathVec = getPath(s, path);
				}		
					
			}
			else{
				for(i = 0; i < p.size(); i++){
					if(dist[i] == -1 && Distance(p[s], p[i]) < D){
						bfsQueue.push(i);
						dist[i] = dist[s] + 1;
						path[i] = s; 
					}
					 
				}
			}	
		}
		
	}
	// for the test
//	cout << endl;
//	for(i = 0; i < p.size(); i++){
//		cout << p[i].x << " " << p[i].y << endl;
//	}	
//	cout << endl;
//	
	if(pathVec.size() == 0){
		cout << "0" << endl;
	}
	else{
		cout << pathVec.size()+1 << endl;
		for(i = 0; i < pathVec.size(); i++){
			cout << p[pathVec[i]].x << " " << p[pathVec[i]].y << endl;
		}
	}

	return 0;
}

vector<int> getPath(int t, int p[]){
	vector<int> path;
	for(;t != -1; t = p[t]){
		path.push_back(t);
	}
	reverse(path.begin(), path.end());
	return path;
}


double Distance(pos p1, pos p2){
	int deltaX = abs(p1.x - p2.x);
	int deltaY = abs(p1.y - p2.y);
	if((p1.x == 0 && p1.y == 0) || (p2.x == 0 && p2.y == 0)){
		return (double)(sqrt(pow(deltaX,2) + pow(deltaY,2)) - dia);
	}
	else{
		return (double)(sqrt(pow(deltaX,2) + pow(deltaY,2)));
	}
}
int IsSafe(pos p, double D){
	if(abs(p.x) >= 50 - D ||
	abs(p.y) >= 50 -D){
		return 1;
	}
	else{
		return 0;
	}
}

