/*
 * Given a linked list. Reverse it.
 * O(n) solution
 */
 
 Node* Reverse(Node *head)
{
  struct Node *current,*previous,*further;
  current=head;
  previous=NULL;
  while(current!=NULL){
      further=current->next;
      current->next=previous;
      previous=current;
      current=further;
  }
  head=previous;
  return head;
}
