/*
 * Given a linked list. Reverse it.
 * O(n) solution
 */

Node* Reverse(Node *head)
{
  if(head==NULL || head->next==NULL)
      return head;
    else
    {
        Node *current=Reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return current;
    }
}
