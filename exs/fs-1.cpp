#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(){
	ofstream output;
	output.open("store.txt");
	
	
	output << setw(20) <<"What the fuck " << 30 << endl;
	output.close();
	
	cout << "Done" << endl;
	return 0;
} 
