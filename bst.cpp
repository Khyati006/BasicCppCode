#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    // q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
Node* insertintobst(Node* root, int d){
    //base case
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertintobst(root->right,d);
    }
    else{
        root->left=insertintobst(root->left,d);
    }
    return root;

}

void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertintobst(root,data);
        cin>>data;
    }
}
int main(){
    
    Node* root=NULL;
    cout<<"Enter the data to create BST"<<endl;
    takeinput(root);

    cout<<"The tree is:"<<endl;
    levelorder(root);

    //10 8 21 7 27 5 4 3 -1
    return 0;
}