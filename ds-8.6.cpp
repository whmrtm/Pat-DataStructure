#include <iostream>
#include <vector>
using namespace std;


class pat{
public:
	int id;
	int Tsore;
	vector<int> Pscore;
};
int main(){
	int i, j, N, K, M;
	int A, B, C;
	cin >> N >> K >> M;
	vector<int> p(K);
	vector<int> s;
	vector<pat> mypat(N);
	for(i = 0; i < N; i++){
		mypat[i].Pscore = vector<int>(K);
	}
	
	for(i = 0 ; i < K; i++){
		cin >> p[i];
	}

	for(i = 0; i < M; i++){
		cin >> A >> B >> C; 
		mypat[A].Pscore[B] = C;	
	}
	for(i = 0; i < mypat.size(); i++){
		cout << i << " " << mypat[i].Pscore[0];	
	}
} 
