/*
 * Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. For
 * example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40.
 * Assume that k is smaller than the count of nodes in linked list.
 */
 

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    class node *next;
    public:
    node(int x){
        data=x;
        next=NULL;
    }
    
};

class linked_list{ 
    node *head,*rear;
    int size;
    public:
    linked_list(){
        head=NULL;
        rear=NULL;
        size=0;
    }
    node* root(){
        return head;
    }
    void insert(int x){
        node *temp=new node(x);
        temp->next=head;
        if(head==NULL){
            rear=temp;
        }
        head=temp;
        size++;
    }
    void push_back(int x){
        node *temp=new node(x);
        if(rear==NULL){
            rear=temp;
            head=temp;
        }
        else{
            rear->next=temp;
            rear=rear->next;           
        }
        size++;
    }
    void print(){
        node *root=head;
        while(root!=NULL){
            cout<<root->data<<" ";
            root=root->next;
        }
        cout<<endl;
    }
    void set_head(node *_head){
        head=_head;

    }
    int length(){
        return size;
    }
};

linked_list reverse_linked_list_by_k_nodes(linked_list &list, int k){
    node *root=list.root();
    for(int i=0;i<k-1;i++){
        root=root->next;
    }
    node *temp=root;
    while(root->next!=NULL)
        root=root->next;
    root->next=list.root();
    list.set_head(temp->next);
    temp->next=NULL;
    return list;

}


int main(){
    linked_list list;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        list.push_back(x);
    }
    list.print();
    cin>>k;
    list=reverse_linked_list_by_k_nodes(list,k);
    list.print();   
}
