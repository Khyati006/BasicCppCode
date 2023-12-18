#include<iostream>
using namespace std;
// {{void solve(stack<int>&inputstack,int count, int size){
//     //base case
//     if(count==size/2){
//         inputstack.pop();
//         return;
//     }
//     int num=inputstack.top();
//     inputstack.pop();

//     //recursive call
//     solve(inputstack, count+1, size)
//     inputstack.push(num);
// }
// void deletemiddle(stack<int>&inputstack,int N){
//     int count=0;
//     solve(inputstack,count,N)
// }
// int main(){
    
//     return 0;
// }}} Delete the middle element from stack

//Insert an element at its bottom in a given stock-we will use recurrsion as above
void solve(stack<int>&s,int x){
    if(s.empty()){
        s.push(x)
        return ;
    }
    int num=s.top();
    s.pop();

    solve(s,x);

    s.push(num);

}

//reverse stack
//use recurssion in which we will assume that recursion will reverse the stack and then we will only insert the element in bottom

void reversestack(stack<int>&s){
    //base case
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();

    reversestack(stack);
    insertatbottom(num);//above code
}

//sort a stack
void sortstack(stack<int>&s){
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();

    sortstack(stack);
    sortedinsert(stack,num);

}
void sortedinsert(stack<int>&stack,int num){
    if(s.empty()|| )
}