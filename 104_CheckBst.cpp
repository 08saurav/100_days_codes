/*
 * =====================================================================================
 *
 *       Filename:  104_CheckBst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 12:00:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int isbalanced(Node *root,Node *&prev)
    {
        if(!root)
            return true;
        if(!isbalanced(root->left,prev))
            return false;
        if(prev && prev->data>=root->data)
            return false;
        prev=root;
        return isbalanced(root->right,prev);
    }
bool isBST(Node* root) {
    // Your code here
    Node *prev=NULL;
    bool res =isbalanced(root,prev);
    return res;
}
