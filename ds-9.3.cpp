#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> visited;
vector<int> res;
vector<int> sorted;

int Find(int item){
	int i;
	for(i = 0; i < sorted.size(); i++){
		if(sorted[i] == item){
			return i;
		}
	}
	return -1;
}

void transverse(vector<int> in, int i, int N){
	if(visited[i] || sorted[i] == -1)
		return;	
	int j;
	//check elements in their supposed position
	for(j = 0; j < i; j++){
		if(visited[j] == 0 && 
		in[sorted[j]%N] == sorted[j]){
			res.push_back(sorted[j]);
			visited[j] = 1;
		}
	}
	// check elements that have been shifted
	j = sorted[i] % N;
	int temp = sorted[i];
//	cout << "in[j]: " << in[j] << " " << "Find: " << Find(in[j]) << endl;
	while(in[j] != temp){
		if(in[j]%N != j && visited[Find(in[j])] == 0){
			transverse(in, Find(in[j]), N);
		}
		else if(visited[Find(in[j])] == 0){
			res.push_back(in[j]);
			visited[Find(in[j])] = 1;
		}
		j = (j + 1) % N;
	}
	// itself
	res.push_back(sorted[i]);
	visited[i] = 1;
}

int main(){
	int N, i, j, temp;
	cin >> N;
	vector<int> in;
	for(i = 0; i < N; i++){
		cin >> temp;
		in.push_back(temp);
		visited.push_back(0);
	}
	// sorted is the sorted array, for the convenince of finding element;
	sorted = in;
	sort(sorted.begin(), sorted.end());
//	for(vector<int>::iterator it = sorted.begin(); it < sorted.end(); it++){
//		cout << *it << endl;
//	}
	for(i = 0; i < N; i++){
		if(in[sorted[i]%N] != sorted[i]
		 && visited[i] == 0 && sorted[i] != -1){
			transverse(in, i ,N);
		}
	}
	
	
	for(i = 0; i < res.size() - 1; i++){
		cout << res[i] << " ";
	}
	cout <<  res[i];
	return 0;
} 
