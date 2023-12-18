#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        //constructor
        heap(){
            arr[0]=-1;
            size=0;
        }

        void insertion(int data){
            //insert a data
            size=size+1;
            int index=size;
            arr[index]=data;

            //find parent and correct position
            while(index>1){
                int parent= index/2;

                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }


        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        

};

int main(){
    heap h;
    h.insertion(50);
    h.insertion(55);
    h.insertion(53);
    h.insertion(52);
    h.insertion(54);
    h.print();

    return 0;
}