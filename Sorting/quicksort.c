
/*

Simplest implementation of the Merge-Sort Algorithm in C

Author : Almeida-Domingues, Joao
Date: 28/09/20

TO-DO:
-- refactor so as not to use sentinels
-- tests
*/

#include <stdio.h>
#include <limits.h>


// HELPER : print array contents; len must be passed because arrays passed as arguments are converted to pointers
void printOut(int A[], int len){

	for(int i=0; i<len; ++i){
		printf("%d\n", A[i] );
	};
};

void merge(int A[], int lo, int mid, int hi){

	int sizeL = mid - lo + 1;
	int sizeR = hi - mid;

	int L[sizeL+1];
	int R[sizeR+1];

	for(int i=0; i<sizeL; ++i) L[i] = A[lo+i];
	for(int j=0; j<sizeR; ++j) R[j] = A[mid+1+j];


	// add sentinel to the end of each sub-array to avoid checking if exhausted with each iteration
	L[sizeL] = INT_MAX;
	R[sizeR] = INT_MAX;

	int i = 0;
	int j = 0;

	for(int k=lo; k<=hi; ++k){
		if(L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		} else {
			A[k] = R[j];
			++j;
		}
	}


}

void mergeSort(int A[], int lo, int hi){
	if(lo < hi){
		int mid = (lo+hi)/2;
		mergeSort(A,lo,mid);
		mergeSort(A,mid+1,hi);
		merge(A,lo,mid,hi);
	}

}

int main(){

	int A[7] = {0,5,6,3,2,1,3};
	mergeSort(A,0,6);
	printOut(A,7);

}

