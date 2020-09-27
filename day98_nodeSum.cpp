/*
 * =====================================================================================
 *
 *       Filename:  day98_nodeSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2020 01:02:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int nodeSum(Node *root)
{
    if(root==NULL)
        return 0;
    int sum=0;
    sum=root->data+nodeSum(root->left)+nodeSum(root->right);
    return sum;
}
bool isSumTree(Node* root)
{
    if(root==nullptr)
        return true;
    int leftSum=nodeSum(root->left);
    int rightSum=nodeSum(root->right);
    if(leftSum+rightSum==root->data)
        return true;
    return false;
     // Your code here
}
