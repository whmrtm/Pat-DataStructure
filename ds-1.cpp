#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int num,i;
	cin>>num;
	int sequence[num];
	int sum=0,mymax=0;
	
	for(i=0;i<num;i++){
		cin>>sequence[i];
	}
	
	for(i=0;i<num;i++){
		sum += sequence[i];
		if(sum<0){
			sum=0;
		}
		mymax = max(sum,mymax);
	}
	cout<<mymax<<endl;
	return 0;
}
