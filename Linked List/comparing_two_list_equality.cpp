/*
 * Check if two list are equal. List are equal if they have equal and same number of elements
 */

int CompareLists(Node *headA, Node* headB)
{
  bool flag=true;
  while(headA!=NULL && headB!=NULL){
      if(headA->data!=headB->data){
          flag=false;
          break;
      }
      headA=headA->next;
      headB=headB->next;
  }
  if(headA==NULL && headB==NULL && flag)
      return 1;
   else
       return 0;
  
}
