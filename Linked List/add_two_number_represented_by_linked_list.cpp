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
    public:
    node *head,*rear;
    int size;
    public:
    linked_list(){
        head=NULL;
        rear=NULL;
        size=0;
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

int main(){
    linked_list llone,lltwo,summed;
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
    llone.print();
    lltwo.print();
    int small_size=((llone.length()<lltwo.length())?llone.length():lltwo.length());
    int large_size;
    node *root;
    if(lltwo.length()>llone.length()){
        large_size=lltwo.length();
        root=lltwo.head;
    }    
    else{
        large_size=llone.length();
        root=llone.head;
    }
    int carry=0;
    int sum;
    node *root1=llone.head;
    node *root2=lltwo.head;
    for(int i=0;i<small_size;i++){
        sum=carry+(root1->data)+(root2->data);
        cout<<sum<<endl;
        if(sum>=10){
            carry=sum/10;
            sum=sum%10;
        }
         else
            carry=0;
        root->data=sum;
        cout<<root->data<<endl;
        summed.push_back(sum);
        root=root->next;
        root1=root1->next;
        root2=root2->next;
    }
    cout<<"iside"<<endl;
    for(int i=small_size;i<large_size;i++){
        sum=carry+(root->data);
        cout<<sum<<endl;
        if(sum>=10){
            carry=sum/10;
            sum=sum%10;
        }
        else
            carry=0;
        root->data=sum;
        cout<<root->data<<endl;
        summed.push_back(sum);
        root=root->next;
    }
    if(carry)
        summed.push_back(carry);
    summed.print();
    
}
