#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> table;
vector<int> res;

int IsPrime(int M){
	if(M < 2){
		return 1;
	}
	if(M == 2){
		return 0;
	}
	if(M%2 == 0){
		return 1;
	}
	int i;
	for(i = 3; i < M; i += 2){
		if(M % i == 0)
			return 1;
	}
	return 0;
}

void Insert(int data, int Msize){
	int i, ind, temp;
	ind = data % Msize;
	if(table[ind] == -1){
		table[ind] = data;
		res.push_back(ind);
	}
	else{
		i = 0;
		temp = (ind + i*i) % Msize;
		while(table[temp] != -1){
			// if the data cannot be inserted, res gets -1
			i += 1;
			if(i >= Msize){
				res.push_back(-1);
				return;
			}
			temp = (ind + i*i) % Msize;
		}
		table[temp] = data;
		res.push_back(temp);
	}
}
int main(){
	int i, Msize, N, temp, ind;
	cin >> Msize >> N;
	if(IsPrime(Msize)){
		while(IsPrime(Msize)){
			Msize++;
		}
	}
	table = vector<int>(Msize);
	// initialize elements in the table as -1;
	for(i = 0; i < Msize; i++){
		table[i] = -1;
	}
	for(i = 0; i < N; i++){
		cin >> temp;
		Insert(temp, Msize);
	}
//  just for test	
//	cout << Msize << endl;
//	for(i = 0; i < table.size(); i++){
//		cout << table[i] << endl;
//	}
	
	for(i = 0; i < res.size(); i++){
		if(res[i] == -1){
			cout << "-";
		}
		else{
			cout << res[i];
		}
		
		//no extra space at the end
		if(i + 1 != res.size()){
			cout << " ";
		}
	}
	return 0;
}
