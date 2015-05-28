#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

using namespace std;

float f(float a3, float a2, float a1, float a0, float x){
	return a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * pow(x, 1) + a0;
}

int main(){
	float err = 0.0001;
	float a3, a2, a1, a0;
	float mid, left, right;
	int i;
	cin >> a3 >> a2 >> a1 >> a0;
	cin >> left >> right;
	float result;
	while(right-left > err){
		mid = (right + left)/2;
		if(f(a3,a2,a1,a0,left) * f(a3, a2, a1, a0, right) < 0){
			result = f(a3,a2,a1,a0,mid);
			if(result == 0)
				break;
			else if(result * f(a3,a2,a1,a0,left) > 0){
				left = mid;
			}
			else{
				right = mid;
			}
		}
		else{
			if(f(a3,a2,a1,a0,left)==0)
			mid=left;
			else
			mid=right;
			break;
		}
	}
	
	printf("%0.2f", mid);
	return 0;
}
