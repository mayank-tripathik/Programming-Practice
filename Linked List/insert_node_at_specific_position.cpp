Node* InsertNth(Node *head, int data, int position)
{
    Node *temp=new Node();
    temp->data=data;
    if(position==0){
        temp->next=head;
        head=temp;
    }
    else{
        Node *root=head;
        while(position-1>0){
            root=root->next;
            position--;
        }
        temp->next=root->next;
        root->next=temp;
    }
    return head;
}
