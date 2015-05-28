#include <iostream>
#include <string>

using namespace std;

int main(){
	int i, j, N, M;
	cin >> N;
	string c[N+15];
	int f[N+15];
	string code[N+15]; 
	for(i = 0; i < N; i++){
		cin >> c[i] >> f[i]; 
	}
	cin >> M;
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			cin >> c[i] >> code[i]; 
		}
	}
	cout << "bingo!";
	return 0;
}
