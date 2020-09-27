/*
 * =====================================================================================
 *
 *       Filename:  day43_sort_012_using_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 03:41:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    
    // Add code here
    Node *temp=head,*two=NULL,*one=NULL,*zero=NULL;
    while(temp){
    // {   cout << 1 << endl;
        if(temp->data==0)
        {
            Node *t=new Node(0);
            if(zero==NULL)
                zero=t;
            else
            {
                t->next=zero;
                zero=t;
            }
        }
        else if(temp->data==1)
        {
            Node *t=new Node(1);
            if(one==NULL)
                one=t;
            else
            {
                t->next=one;
                one=t;
            }
        }
        else if(temp->data==2)
        {
            Node *t=new Node(2);
            if(two==NULL)
                two=t;
            else
            {
                t->next=two;
                two=t;
            }
        }
        temp=temp->next;
    }
    Node *o=one;
    while( o &&o->next)
        o=o->next;
    Node *z=zero;
    while(z&&z->next)
        z=z->next;
    if(z && one)
        z->next=one;
    else if(z && two)
        z->next=two;
    if(o)
        o->next=two;
    return zero;
    
    
}

