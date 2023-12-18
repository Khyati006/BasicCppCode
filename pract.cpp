#include<iostream> 
using namespace std;
//pivot is simply the element where the list is started. like here 1 is pivot.
int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return arr[s];
}

int main() {
    int arr[5] = {4,5, 1, 2, 3};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}