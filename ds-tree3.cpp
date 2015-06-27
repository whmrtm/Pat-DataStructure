#include <iostream>
#include <string>

using namespace std;
int fint_root(int *a, int ind);
int connect(int *a, int a1, int a2);

int find_root(int *a, int ind){
	if(a[ind] == -1){
		return ind;
	}
	
	return a[ind] = find_root(a, a[ind]);
}

int connect(int *a, int a1, int a2){
	int root1, root2;
	root1 = find_root(a, a1);
	root2 = find_root(a, a2);
	
	if(root1 != root2){
		if(root1 < root2){
			a[root2] = root1;
		} else {
			a[root1] = root2;
		}
	}
}
int main(){
	int i, num;
	
	int c, d;
	int count;
	cin >> num;

	int* a;
	a = new int[num+1]; 
	
	
	string command;
	for(i = 0; i <= num; i++){
		a[i] = -1;
	}
	
	cin >> command;
	while(command != "S"){
		if(command == "I"){
			cin >> c >> d;
			connect(a, c ,d);
		}
		if(command == "C"){
			cin >> c >> d;
			if(find_root(a, c) == find_root(a, d)){
				cout << "yes" << endl;
			} else{
				cout << "no" << endl;
			}
		}
		cin >> command;
	}
	
	
	
	count = 0;
	
	for(i = 1; i <= num ; i++ ){
		if(a[i] == -1){
			count++;	
		}
	}
	if(count == 1){
		cout << "The network is connected." << endl; 
	} else {
		cout << "There are " << count << " components." << endl;
	}
	return 0;
}
