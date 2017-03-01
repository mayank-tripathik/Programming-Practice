#include<iostream>
using namespace std;

template<class T>
class node{
    public:
    T data;
    node *next;
    node(T x){
        data=x;
        next=NULL;
    }
};


template<class T>
class linked_list{
    node<T> *head,*rear;
    int size;
    public:
    linked_list(){
        head=NULL;
        rear=NULL;
        size=0;
    }
    int length(){
        return size;
    }
    void insert_front(T x){
        node<T> *temp=new node<T> (x);
        if(head==NULL){
            rear=temp;
        }
        temp->next=head;
        head=temp;
        size++;
    }
    void insert_back(T x){
        node<T> *temp=new node<T> (x);
        if(rear=NULL){
            head=temp;
            rear=temp;
        }
        else{
            rear->next=temp;
            rear=rear->next;
        }
        size++;
    }
    void print()
    {
        node<T> *root=head;
        while(root!=NULL)     
        {
            cout<<root->data<<" ";
            root=root->next;
        }
    }
};

int main(){
    linked_list<float> mylist;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        float x;
        cin>>x;
        mylist.insert_front(x);
    }
    mylist.print();
}
