#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i, j, N, M;
	int root_ind, leaf_ind;
	vector<int> a;
	int temp;
	cin >> N >> M;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			cin >> temp;
			a.push_back(temp);  
		}
		
		for(j = 2; j < M; j++){
			leaf_ind = j;
			root_ind = j - 1;
			if(a[j] > a[j-1]){
				while(root_ind > 0 && a[root_ind] > a[root_ind - 1]){
					root_ind--;
				}
				if(root_ind > 0 && a[leaf_ind] > a[root_ind-1]){
					cout << "NO" << endl;
					break;
				}
			}
			else{
				while(root_ind > 0 && a[root_ind] < a[root_ind - 1]){
					root_ind--;
				}
				if(root_ind > 0 && a[leaf_ind] < a[root_ind-1]){
					cout << "NO" << endl;
					break;
				}
			}
		}
		if(j == M){
			cout << "YES" << endl;
		}
		if(M == 1){
			cout << "YES" << endl;
		}
		a.clear(); 
	}
	
	return 0;
}
