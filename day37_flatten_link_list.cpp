/*
 * =====================================================================================
 *
 *       Filename:  day37_flatten_link_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/03/2020 03:01:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
Node *merge(Node *a,Node *b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node *result;
    if(a->data<b->data)
    {
        result=a;
        result->bottom=merge(a->bottom,b);
    }
    else
    {
        result=b;
        result->bottom=merge(a,b->bottom);
    }
    return result;
}
Node *flatten(Node *root)
{
    // if(root->next==NULL)
    //     return root;
    // Node *t1=root;
    // Node *t2=root->next;
    // while(t1 && t2)
    // {
    //     Node *down=t1->bottom;
    //     Node *next1=t1->next;
    //     if(t1->data<t2->data)
    //     {
    //         t1->bottom=t2;
    //         t1->next=t2->next;
    //         t2->next=NULL;
    //     }
    //     else
    //     {
    //         while( t2->bottom && t2 && t1->data>t2->bottom->data)
    //             t2=t2->bottom;
    //         Node *p=t2->bottom;
    //         t1->bottom=p;
    //         t2->bottom=t1;
    //     }
    //     if(down)
    //             down->next=next1;
    // }
    // return flatten(root->next); 
    // // Your code here
    if(root==NULL || root->next==NULL)
        return root;
    return merge(root,flatten(root->next));
}


