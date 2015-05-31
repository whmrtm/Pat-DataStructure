#include <iostream>
#include <queue> 
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class x{
	public:
		int left;
		int right;
};


int main(){
	int i, num, root;
	string a, b;
	x node[20];
	cin >> num;
	root = 0;
	int test[10];
	
	queue<int> leaf;
	vector<int> res;
	
	for(i = 0; i < num; i++){
		test[i] = 0;
		cin >> a >> b;
		if (a == "-") 
			node[i].left = -1;
		else{
			stringstream s;
			s<<a; 
			s>>node[i].left;
		}
		
		if (b == "-") 
			node[i].right = -1;
		else{
			stringstream s;
			s<<b; 
			s>>node[i].right;
		}
		
	//	cout << node[i].left <<" "<< node[i].right << endl;
	}
	
	// to find the root
	for(i = 0; i < num; i++){
		if(node[i].left >= 0){
			test[node[i].left] = 1;
		}
		if(node[i].right >= 0){
			test[node[i].right] = 1;
		}
		
	}
	for(i = 0; i < num; i++){
		if(test[i] == 0)
			root = i;
	}
	
	leaf.push(root); 
	while(root != -1){
		if(leaf.size() == 0)
			break;
		root = leaf.front();
		if(node[root].left == -1 && node[root].right == -1){
			res.push_back(root); 
		}
		leaf.pop();
		if(node[root].left != -1)
			leaf.push(node[root].left);
		if(node[root].right != -1)
		    leaf.push(node[root].right);
		 
	}
	
	
	
	
	//cout << "the root is : " << root;
	for(i = 0; i < res.size() - 1 ; i++){
		cout<< res[i] <<" ";
	}	
	cout<< res.back();
}
