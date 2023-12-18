#include<iostream>
using namespace std;
void reverse(string &str,int i,int j){//here we pass the string as refrence variable as string will make its copy
    //base case
    if(i>j)
        return ;
    swap(str[i],str[j]);
    i++;
    j--;

    //recursive call
    reverse(str,i,j);
}
bool palindrome(string str,int i,int j){
    //base case
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        //recursive call
        return palindrome(str,i+1,j-1);
    }
}
int main(){
    //reverse the string using recurssion
    string name="abbccbba";
    //reverse(name,0,name.length()-1);
    //cout<<name<<endl;
    // bool palindrome1=palindrome(name,0,name.length()-1);
    // if(palindrome1){
    //     cout<<"string is palindrome"<<endl;
    // }
    // else{
    //     cout<<"not thee palindrome"<<endl;
    // }
    
    return 0;
}