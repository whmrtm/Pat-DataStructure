#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
//
//class tree{
//	public:
//		int data;
//		tree left, right;
//};
//tree tree;
//void make_tree(int root, int start, int end, vector<int> a){
//	if(start > end){
//		return;
//	}
//	else{
//		tree.data = a[root]; 
//		tree.left = make_tree((root + start)/2, start, root - 1, a);
//		tree.right = make_tree((int)((root + 1 + end)/2 + 0.5), root + 1, end, a);
//		return  
//	}
//}

int main(){
	int i, j, N, num_temp, level, sum;
	cin >> N;
	vector<int> a;
	vector<int> temp;
	vector<int> b;
	for(i = 0; i < N; i++){
		cin >> num_temp;
		a.push_back(num_temp); 
	}
	sort(a.begin(), a.end());
//	for(i = 0; i < a.size(); i++){
//		cout << a[i] << endl;
//	}
	sum = 0; level = 0;
	while(sum + pow(2,level) < N){
		sum += pow(2, level);
		level++;
	}
//	cout << level << " " << N-sum << endl; 
	int start_root = (N - sum + N - 1) / 2;
	cout << a[start_root] << " ";
	b.push_back(start_root);
	b.push_back(0);
	b.push_back(a.size() - 1);
	sort(b.begin(), b.end());   
	
	int ind = 0;
	for(i = 2; i <= level; i++){
		for(j = 1; j <= (i-1)<<1; j++){
			if((b[j] - b[j-1]) % 2 && j != 1){
				ind = (b[j-1] + b[j] + 1) / 2;
			} 
			else {
				ind = (b[j-1] + b[j]) / 2;
			}
			cout << a[ind] << " ";
			temp.push_back(ind); 
		}
		for(j = 1; j <= (i-1)<<1; j++){
			if(temp[j-1] != a.size()-1)
				b.push_back(temp[j-1]); 
		}
		temp.clear();
		sort(b.begin(), b.end());
	}
	
//	for(i = 0; i < b.size(); i++){
//		cout << b[i] << " ";
//	}
//	cout << endl;
	for(i = 0; i < N-sum; i++){
		if(i == 0){
			ind = 0;
		}
		else if((b[i] - b[i-1]) % 2){
			ind = (b[i-1] + b[i] + 1) / 2;
		} 
		else {
			ind = (b[i-1] + b[i]) / 2;
		}
		
		if(i == N-sum)
			cout << a[ind];
		else
			cout << a[ind] << " ";
	}		
}
