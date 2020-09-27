/*
 * =====================================================================================
 *
 *       Filename:  day39_sum_of_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/03/2020 05:11:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
struct Node* reverse(struct Node *head)
{
    // code here
    // return head of reversed list
    Node* current = head; 
        Node *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        } 
    return prev;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
    first=reverse(first);
    second =reverse(second);
    int carry=0;
     Node *res=NULL,*prev=NULL,*p;
    while(first && second){
        int a = first->data+second->data+carry;
        // cout << a%10 << " ";
        p=new Node(a%10);
        if(res==NULL)
        res=p;
       else
        prev->next=p;
       prev=p;
        carry=a/10;
       first=first->next;
       second=second->next;
    }
    while(first)
    {
        int a = first->data+carry;
        // cout << a%10 << " "; 
       Node *p=new Node(a%10);
       prev->next=p;
       prev=p;
        carry=a/10;
        first=first->next;
    }
    while(second)
    {
        int a = second->data+carry;
        // cout << a%10 << " ";
       Node *p=new Node(a%10);
       prev->next=p;
       prev=p;
        carry=a/10;
        second=second->next;
    }
    if(carry)
    {
        int a = carry;
        // cout << a%10 << " ";
        Node *p=new Node(a%10);
        prev->next=p;
        prev=p;
        
    }
    // cout << endl;
    // cout << res->data << endl;
    return reverse(res);    
}

