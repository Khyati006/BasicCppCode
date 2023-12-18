// This is the practice for linked list
// just go for it and belive in yourself that you can do it
class node{
    public:
    int data;
    node* next;

    // counstructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
    }

};

Insertion opeation

