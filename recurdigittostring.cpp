#include<iostream>
using namespace std;
void digittostr(int num){
    string arr[10]={"zero","one","Two","Three","four","five","six","seven","Eight","nine"};
    if(num==0){
        return;
    }
    int d=num%10;

    num=num/10;

    digittostr(num);

    cout<<arr[d]<<" ";

}
int main(){
    int num;
    cout<<"Enter thee number"<<endl;
    cin>>num;
    cout<<endl<<endl<<endl;
    digittostr(num);
    cout<<endl<<endl<<endl;
    return 0;
}