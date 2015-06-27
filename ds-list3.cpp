#include <iostream>
#include <vector>

using namespace std;
int main(){
	int i, j, k, M, N, num;
	int test[1500];
	int top;
	vector<int> sta;


	cin >> M >> N >> num;

	for(i = 0; i < num; i++){
		for(j = 0; j < N; j++){
			cin >> test[j]; 
		}		
		
		top = test[0];
		
		for(j = 0; j < N && sta.size() < M; j++){
			if(j == 0){
				for(k = 1; k <= test[j]; k++){
					sta.push_back(k); 
				}
				
				sta.pop_back();
			}
				
			else{
				if(test[j] < test[j-1] ){
					if(test[j] != sta.back()){
//						cout << "test[j] is: " <<test[j] <<" the number is "<< sta.back() << " " ;
						break;
					}
					else{
						sta.pop_back();
					}
				}
					
				if(test[j] >= top + 1){
					for(k = top + 1; k <= test[j]; k++){
						sta.push_back(k); 
					}	
						sta.pop_back();
				}
			}
			top = test[j] > top ? test[j] : top;
		}
		
		if(j < N){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
		
		sta.clear();
	}
	
	
	
	
	return 0;
} 
