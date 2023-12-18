//this program will remove the occurance in string
//erase() function is used to remove elements from a container from the specified position or range. 
//Parameters: Position of the element to be removed in the form of an iterator. 
//The range specified using start and end iterators
//clear() will remove all the element both are the vector function
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()!=0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main(){
    string k="My name is khyati";
    string part1="My";
    Solution one;
    string x=one.removeOccurrences(k,part1);
    cout<<x;
}