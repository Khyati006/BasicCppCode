//building the binary tree
#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
    //this is constructor
    node(int d){
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
};

node* binarytree(node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data to be inserted into the left of tree"<<data<<endl;
    root->left=binarytree(root->left);
    cout<<"Enter the data to be inserted into the right of tree"<<data<<endl;
    root->right=binarytree(root->right);
    return root;
}

void levelordertraversal(node* root){
    //we will use queue to implement this.
    queue<node*>q;
    q.push(root);
    //this is separator when it get null it will separate the level
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            //1. level order completed.
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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    cout<<root->data<<" ";
    postorder(root->right);
}

void buildlevelorder(node * &root){
    queue<node*>q;

    cout<<"Enter the root data";
    int data;
    cin>>data;
    root=new node(data);

    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter the left data of :"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new node(temp->left);
            q.push(temp->left);
        }

        cout<<"Enter the right data of :"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new node(temp->right);
            q.push(temp->right);
        }

    }
}

int main(){
    
    node* root=NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    root=binarytree(root);

    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelordertraversal(root);

    cout << "Printing the inorder tracersal output ";
    inorder(root);

    cout << "Printing the preorder tracersal output ";
    preorder(root);

    cout << "Printing the postorder tracersal output ";
    postorder(root);


    return 0;
}