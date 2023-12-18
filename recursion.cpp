#include<iostream>
using namespace std;
bool issorted(int *arr, int size){
 //base case
 if(size==0||size==1){
    return true;
 }
 if(arr[0]>arr[1]){
    return false;
 }
 else{
    bool remainingpart=issorted(arr+1,size-1);
    return remainingpart;
 }
}
int sumofarray(int *arr,int size){
    //base case
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int repart=sumofarray(arr+1,size-1);
    int sumx=arr[0]+repart;
    return sumx;
}
bool linearsearch(int *arr,int size,int key){
    //basecas
    if(size==0)
        return false;
    if(arr[0]==key){
        return true;
    }
    bool re=linearsearch(arr+1,size-1,key);
    return re;
}

int main(){
    //checking the array is sorted or not by recurrsion
    int arr[5]={2,4,9,9,9};
    int size=5;
    int key=2;
    bool ans=issorted(arr,size);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Not sorted";
    }
    int sumx=sumofarray(arr,size);
    cout<<sumx<<endl;
    bool ans1=linearsearch(arr,size,key);

    if(ans1){
        cout<<"element is found!";
    }
    else{
        cout<<"element is not found";
    }
    
    return 0;

}