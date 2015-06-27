#include <iostream>

using namespace std;
void bubble_sort(int arr[], int len) {
	if(len==1)
		return;
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
void Swap(int& a, int& b){
	int temp = b;
	b = a;
	a = temp;
}
void quickSort(int *A, int left, int right){
	if(right - left >= 2){
		//select the pivot
		int center = (left + right) / 2;
		if(A[left] > A[center]){
			Swap(A[left], A[center]);
		}
		if(A[left] > A[right]){
			Swap(A[left], A[right]);
		}
		if(A[center] > A[right]){
			Swap(A[center], A[right]);
		}
		int pivot = A[center];
		swap(A[center], A[right-1]);
		
		// start to sort
		int i = left, j = right -1;
		while(1){
			while(A[++i] < pivot){
			}
			while(A[--j] > pivot){
			}
			if(i < j)
				Swap(A[i], A[j]);
			else{
				break;
			}
		}
		Swap(A[i],A[right - 1]);
		quickSort(A, left, i-1);
		quickSort(A, i+1, right); 
	}
	else{
		if(A[left] > A[right]){
			Swap(A[left], A[right]);
		}
		return;
	}
}

int main(){
	int i, N;	
	cin >> N;
	int a[N];
	for(i = 0; i < N; i++){
		cin >> a[i];
	}
	quickSort(a, 0, N-1);
	for(i = 0; i < N-1; i++){
		cout << a[i] << " ";
	}
	cout << a[i];
	return 0;
}
