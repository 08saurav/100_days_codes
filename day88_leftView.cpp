/*
 * =====================================================================================
 *
 *       Filename:  day88_leftView.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2020 08:43:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void leftViewUtil(Node *root,int l,bool level[])
{
    if(root==NULL)
        return;
    if(!level[l]){
        cout << root->data << " ";
        level[l]=true;
    }
    leftViewUtil(root->left,l+1,level);
    leftViewUtil(root->right,l+1,level);
}
void leftView(Node *root)
{
   // Your code here
   Node *temp=root;
   int ct=0;
   bool level[100]={false};
   leftViewUtil(temp,ct,level);
   
}

