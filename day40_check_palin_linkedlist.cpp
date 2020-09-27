/*
 * =====================================================================================
 *
 *       Filename:  day40_check_palin_linkedlist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 02:24:43 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
Node* reverse(Node* slow)
   {
       Node* curr=slow;
       Node* next;
       Node* prev=NULL;
       while(curr!=NULL)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           
       }
       return prev;
   }
bool isPalindrome(Node *head)
{
    Node* slow=head;
          Node*  fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
          slow=slow->next;
            fast=fast->next->next;
        } 
        fast=head;
        
        slow=reverse(slow);
       
        while(slow!=NULL && fast!=NULL)
        {
             cout << slow->data << endl;
            if(fast->data!=slow->data)
            {
                return false;
            }  
            slow=slow->next;
            fast=fast->next;
        } 
        return true;
}

