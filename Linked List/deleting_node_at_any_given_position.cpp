Node* Delete(Node *head, int position)
{
  if(position==0){
      Node *temp=head;
      head=head->next;
      delete temp;
  }
  else
  {
      Node *root=head;
      while(position-1>0){
          root=root->next;
          position--;
      }
      Node *temp=root->next;
      root->next=root->next->next;
      delete temp;
  }
  return head;
}
