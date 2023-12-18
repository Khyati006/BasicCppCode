#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    void reverseString(vector<char>& s) {
        int st=0;
        int e = s.size()-1;

        while(st<e) {
            swap(s[st++], s[e--]);
        }
    }
};
int main(){
    vector<char>vec;
    int n=5;
    for(int i=0;i<n;i++){
        cout<<"enter the char";
        cin>>vec[i];

    }
    cout<<"char is :";
    for(int i=0;i<n;i++){
        cout<<vec[i];
    }
}