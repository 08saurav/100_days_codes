/*
 * =====================================================================================
 *
 *       Filename:  day38_merge_two_sorted_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/03/2020 03:10:25 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    // code here
    if(head_A==NULL)
        return head_B;
    if(head_B==NULL)
        return head_A;
    Node *result;
    if(head_A->data<head_B->data)
    {
        result=head_A;
        result->next=sortedMerge(head_A->next,head_B);
    }
    else
    {
        result=head_B;
        result->next=sortedMerge(head_A,head_B->next);
    }
    return result;
}  
