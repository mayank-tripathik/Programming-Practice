/*
 * Input:
 *  First List: 5->6->3  // represents number 365
 *  Second List: 8->4->2 //  represents number 248
 * Output
 *  Resultant list: 3->1->6  // represents number 613
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
    int length(){
        return size;
    }
};

linked_list sum_list(linked_list &list1, linked_list &list2){
    linked_list result;
    node *root1=list1.root();
    node *root2=list2.root();
    int sum,carry=0;
    while(root1!=NULL || root2!=NULL){
        sum=carry+(root1?root1->data:0)+(root2?root2->data:0);
        if(sum>9){
            carry=sum/10;
            sum=sum%10;
        }
        else
            carry=0;
        result.push_back(sum);
        if(root1)
            root1=root1->next;
        if(root2)
            root2=root2->next;
    }
    if(carry)
        result.push_back(carry);
    return result;
}


int main(){
    linked_list llone,lltwo,sum_of_list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        llone.insert(x);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        lltwo.insert(x);
    }
    sum_of_list=sum_list(llone,lltwo);
    sum_of_list.print();   
}
