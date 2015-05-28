#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> min_heap;
	int i, j, N, M, temp;
	cin >> N >> M;
	min_heap.push_back(-100000);
	for(i = 1; i <= N; i++){
		cin >> temp;
		if(min_heap.size() == 1){
			min_heap.push_back(temp);
		}
		else{
			j = i;
			min_heap.push_back(temp);
			while(min_heap[j/2] > temp){
				min_heap[j] = min_heap[j/2];
				j /= 2;
			}
			min_heap[j] = temp;
		}
	}
	for(i = 0; i < M; i++){
		cin >> temp;
		j = temp;
		while(j / 2 > 0){
			cout << min_heap[j] << " ";
			j /= 2;
		}
		cout << min_heap[j] << endl;
	}	
	
} 
