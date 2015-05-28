	#include <iostream>
	#include <algorithm>
	
	using namespace std;
	int main(){
		//initialization
		int num,i;
		cin>>num;
		int sequence[num];
		int sum=0,mymax=-1;
		int first,last,temp;
		first = 0; last = 0; temp = 0;
		//input
		for(i=0;i<num;i++){
			cin>>sequence[i];
		}
		
		//use the linear algorithem
		for(i=0;i<num;i++){
			sum += sequence[i];
			if(sum<0){
				sum=0;
				temp = i+1; 
			}
			else if(sum > mymax ){
				mymax = sum; 
				last = i;
				first = temp;
			}
		}
		if(mymax < 0){
			cout<<0<<" "<<sequence[0]<<" "<<sequence[num-1];			
		}
		else{
			cout<<mymax<<" "<<sequence[first]<<" "<<sequence[last];	
		}	
		return 0;
	}
