#include<iostream>
using namespace std;
int main(){
    //Given an string S, representing a large interger. 
    //Return the largest-valued odd integer (as a string) that is substring of the given string S. ex="123"=123 and '504'=5
    string maxOdd(string s) {
        // your code here
        for(char i=s.length()-1;i>=0;i--){
            if(s[i]%2!=0){
                return s.substr(0,i+1);
            }
        }
        return "";
    }
    return 0;
}
//arr[] = {geeksforgeeks, geeks, geek,geezer} out=gee
string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        sort(arr,arr+N);
        string res="";
        string first=arr[0];
        string last=arr[N-1];
        for(int i=0;i<first.size();i++){
            if(first[i]==last[i]){
                res+=first[i];
            }
            else{
                break;
            }
        }
        if(res.size()==0){
            return "-1";
        }
        else{
            return res;
        }
    }
int firstNum(char ch)
  {
        if(ch == 'I')
            return 1;
        else if(ch == 'V')
            return 5;
        else if(ch == 'X')
            return 10;
        else if(ch == 'L')
            return 50;
        else if(ch == 'C')
            return 100;
        else if(ch == 'D')
            return 500;
        else if(ch == 'M')
            return 1000;
    }
    int romanToDecimal(string &str) {
        // code here
        int n = str.length();
        int num = firstNum(str[0]);
        for(int i = 1; i < n; i++)
        {
            int temp = firstNum(str[i]);
            int temp2 = firstNum(str[i-1]);
            if(temp <= temp2)
                num += temp;
            else
                num += abs(temp - 2*temp2);
                
            // cout<<num<<endl;
        }
        
        return num;
    }