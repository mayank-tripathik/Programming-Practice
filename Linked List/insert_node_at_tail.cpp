Node* Insert(Node *head,int data)
{
  // Complete this method
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->next=NULL;
    temp->data=data;
    if(head==NULL){
        head=temp;   
    }
    else
    {
        Node *traverse=head;
        while(traverse->next!=NULL){
            traverse=traverse->next;
        }
        traverse->next=temp;
    }
    return head;
}
