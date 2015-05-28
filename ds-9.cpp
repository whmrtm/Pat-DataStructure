#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
class node{
	public:
		int data;
		int times;
		node(int D, int T){
			data = D;
			times = T;
		}
};

int main(){
	int i, num, data;
	string com;
	vector<int> res;
	stack<node> x;
	
	cin >> num;
	
	for(i = 0; i < 2 * num; i++){
		cin >> com;
		if(com == "Push"){
			cin >> data;
			x.push(node(data, 1)); 
		}
		if(com == "Pop"){
			if(x.top().times == 1){
				x.top().times = 2; 
			} 
			else {
				res.push_back(x.top().data);
				x.pop();
				while(x.top().times == 2){
					res.push_back(x.top().data);
					x.pop();
				}
				if(x.size() != 0){
					x.top().times = 2;
				} 
			} 
		}	
	}

	for(i = 0; i< res.size(); i++){
		cout << res[i] << " "; 
	}	 
	while(x.size() != 0){
		cout << x.top().data;
		x.pop();
		if(x.size() != 0){
			cout << " ";
		} 
	}
	return 0;
}
