#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<i;i++){
            if(i!=j){
                swap(A[i][j],A[j][i]);   
            }
        }
    }
    reverse(A.begin(),A.end());
}
int main(){
    vector<vector<int>>A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(A);

    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            cout<<A[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}