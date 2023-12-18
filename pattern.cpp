#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the n:";
	cin>>n;
	
	//upper triangle:
	for(int i=1;i<=n;i++){
		//first triangle
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		//spaces
		for(int s=1;s<=(n*2)-(i*2);s++){
			cout<<" ";
		}
		//second triangle
		for(int j=i;j>0;j--){
			cout<<"*";
		}
		cout<<endl;
	}
	//lower triangle
	for(int i=1;i<=n;i++){
		//first triangle
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		//spaces
		for(int s=1;s<=(n*2)-(i*2);s++){
			cout<<" ";
		}
		//second triangle
		for(int j=i;j>0;j--){
			cout<<"*";
		}
		cout<<endl;
	}

        return 0 ;
}
