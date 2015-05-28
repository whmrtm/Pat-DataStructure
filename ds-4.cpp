#include <iostream>
#include <vector>


using namespace std;
int main(){
	int a, b, i, j,size;
	vector<int> x;
	b=1,size=0;
	while(cin>>a>>b){
		x.push_back(a);
		x.push_back(b);  
	}	
	
	for(i = 0; i < x.size(); i = i + 2){
		a = x[i];
		b = x[i+1];
		if(a!=0 && b!=0){
			size+=2;	
		}
	}
	for(i = 0; i < x.size(); i = i + 2){
		a = x[i];
		b = x[i+1];
		if(a!=0 && b!=0 && i != size-2){
			cout<<a*b<<" "<<b-1<<" ";	
		}
		else{
			if(a!=0 && b!=0)
			cout<<a*b<<" "<<b-1;
		}
	}	
	
	if(size==0){
		cout<<"0 0";
	}
	return 0;
}
