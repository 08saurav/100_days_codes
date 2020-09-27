/*
 * =====================================================================================
 *
 *       Filename:  day36_remove_loop.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 08:17:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void removeLoop(Node* head)
{
    if (head == NULL || head->next == NULL) 
        return; 
    Node *slow=head,*fast=head;
    fast=fast->next->next;
        slow=slow->next;
    while(slow && fast && fast->next)
    {
        if(fast==slow)
            break;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast){
        // cout << slow->data << " " << fast->data << endl;
        slow=head;
        if(slow==fast)
        {
                while(fast->next!=slow)
                    fast=fast->next;
        }
        else{
            while(slow->next!=fast->next)
            {
                // cout << slow->data <<" " <<fast->data << endl; 
                slow=slow->next;
                fast=fast->next;
            }
        }
            fast->next=NULL;
    }
}
