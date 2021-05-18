#include<iostream>

using namespace std;

void merge(int A[], int left, int right, int mid){

    int n = right - left + 1; //  4 - 0 + 1 = 5
    int B[n];

    int i = left, j = mid + 1, k = 0;

    while( i <= mid && j <= right){
        if(A[i] < A[j] ){
            B[k] = A[i];
            i++;
        }
        else{
            B[k] = A[j];
            j++; 
        }
        k++;
    }

    while(i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }

    while( j <= right){
        B[k] = A[j];
        j++;
        k++;
    }

    k = 0;
    for(i = left; i <= right; i++){
        A[i] = B[k];
        k++;
    }

}



void mergesort( int A[], int left, int right){

    if( left < right ){
        int mid = (left + right)/2;
        mergesort(A, left, mid); // left array
        mergesort(A, mid+1, right); // right array
        merge(A, left, right, mid); // merge 2 array
    }
}


int main(){ 

    int A[]={11,13,7,12,16,9,24,5,10,3}, n=10;

    cout << "Before Sort: ";
    for(int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    mergesort(A, 0, n-1);
    cout << "After Sort: ";
    for(int i = 0; i < n; i++) cout << A[i] << " ";

    return 0;

}
