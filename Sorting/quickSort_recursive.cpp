#include<iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int position(int A[], int left, int right){

    int pivot = A[right];
    int i = left -1;

    for(int j = left; j < right; j++){
        if(A[j] < pivot ){
            i++;
            swap(&A[i], &A[j]);
        }

    }

    i++;
    swap(&A[i], &A[right] );
    return i;
}

void quicksort( int A[], int left, int right){

    if( left < right ){
        int pos = position(A, left, right);
        quicksort(A, left, pos-1);
        quicksort(A, pos+1, right);
    }
}


int main(){ 

    int A[]={10, 80, 30, 90, 40, 50, 70}, n=7;

    cout << "Before Sort: ";
    for(int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    quicksort(A, 0, n-1);
    cout << "After Sort: ";
    for(int i = 0; i < n; i++) cout << A[i] << " ";

    return 0;

}
