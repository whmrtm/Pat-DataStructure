#include <iostream>
#include <vector>
using namespace std;

void Swap(int& a, int& b){
	int temp;
	temp = b;
	b = a;
	a = temp;
}

int Find(int item, vector<int> A){
	int i;
	for(i = 0; i < A.size(); i++){
		if(A[i] == item){
			return i;
		}
	}
	return -1;
}

int check(vector<int> A){
	int i;
	for(i = 0; i < A.size(); i++){
		if(A[i] != i){
			return i;
		}
	}
	return i;
}

int main(){
	int ind, i, N, flag, temp, times;
	cin >> N;
	vector<int> A;
	for(i = 0; i < N; i++){
		cin >> temp;
		A.push_back(temp);
	}
	times = 0;
	for(i = 0; i < A.size(); i++){
		if(A[i] != i){
			if(i != 0){
				Swap(A[i], A[0]);
				times++;
			}
			temp = A[0];
			A[0] = 0;
			while(A[temp] != temp){
				int x = A[temp];
				A[temp] = temp;
				temp = x;
				times++;
			}
		}
	}	
	cout << times;	
}
