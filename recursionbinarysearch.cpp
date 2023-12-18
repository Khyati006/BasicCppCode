#include<iostream>
using namespace std;

bool binarsearch(int *arr,int s,int e,int key){
    //base case
    //element not found
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    //element found
    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]<key){
        return binarsearch(arr,mid+1,e,key);
    }
    else{
         return binarsearch(arr,s,mid-1,key);
    }
}
int main(){
    int arr[5]={2,4,9,9,9};
    int size=5;
    int key=2;
    bool ans=binarsearch(arr,0,5,key);
    if(ans){
        cout<<"element is found";
    }
    else{
        cout<<"element is not found";
    }
    return 0;
}