#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter elemet"<<endl;
        cin>>arr[i]; 
    }

    //precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }


    int q;
    cout<<"Enter q"<<endl;
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter number"<<endl;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }

    //for string 
    string s;
    cin>>s;

    //pre compute
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<<hash[c-'a']<<endl;//asci value ..lets say fetch f then ascii of f is 105 so 105-97(asci of a)==5;
    }
    return 0;
}