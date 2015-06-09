#include <iostream>
#include <string>
#include <map> 
using namespace std;
int main(){
	int i, N;
	char a;
	string b,c;
	map<string, string> qq;
	cin >> N;
	
	for(i = 0; i < N; i++){
		cin >> a >> b >> c;
		if(a == 'L'){
			if(qq.find(b) == qq.end()){
				cout << "ERROR: Not Exist" << endl;
			}
			else if(qq[b] != c){
				cout << "ERROR: Wrong PW" << endl;
			}
			else{
				cout << "Login: OK" << endl;
			}
		}
		else if(a == 'N'){
			if(qq.find(b) == qq.end()){
				qq[b] = c;
				cout << "New: OK" << endl;
			} else{
				cout << "ERROR: Exist" << endl;
			}
		}
	}
	return 0;
}
