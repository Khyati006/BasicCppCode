#include<iostream>
using namespace std;
void sortarr(int *arr,int n){
    //base case already sorted
    if (n==0||n==1)
    {
        return;
    }
    //1 case solved
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    sortarr(arr,n-1);
    
}
void insertionSort(int arr[], int n)
    {
        //code here
        // Base case
    if (n <= 1)
        return;
  
    // Sort first n-1 elements
    insertionSort( arr, n-1 );
  
    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n-1];
    int j = n-2;
  
    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
    }
int main(){
    int arr[5]={20,56,2,3,1};
    sortarr(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}