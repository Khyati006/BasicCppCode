#include<iostream>
// #include<stack>
using namespace std;

class stack{
    //properties
    public:
        int *arr;
        int top;
        int size;
    //behaviour
    stack(int size){
        this->size=size;
        arr =new int(size);
        this->top=-1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow";
        }
    }
    int peak(){
        if(top>=0 && top<size){
             return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(top=size-1){
            return true;
        }
        else{
            return false;
        }
    }


};
int main(){
    // stack<int>s; This is stl function;s
    // s.push(2);
    // s.push(3);
    // s.pop();
    // s.size()

    stack st(5);

    st.push(23);
    st.push(2);
    st.push(3);
    st.push(44);

    cout<<st.peak()<<endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout<<st.peak()<<endl;

     
    return 0;
}