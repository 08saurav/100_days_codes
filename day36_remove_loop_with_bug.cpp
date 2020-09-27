/*
 * =====================================================================================
 *
 *       Filename:  day36_remove_loop_with_bug.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 07:42:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void removeLoop(){
Node *slow=head,*fast=head,*temp=head;
    int ct=1;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        // cout << fast->data << " " << slow->data << endl;
        if(fast==slow)
            break;
    }
    while(slow->next!=fast){
        slow=slow->next;
        ct++;
    }
    slow=head;
    int n=0;
    while(n<ct){
        slow=slow->next;
        n++;
    }
    // cout << ct << endl;
    while(slow!=temp)
    {
        temp=temp->next;
        slow=slow->next;
    }
    while(slow->next!=temp)
        slow=slow->next;
    slow->next=NULL;
}
