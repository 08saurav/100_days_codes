/*
 * =====================================================================================
 *
 *       Filename:  day95_NodesAt_kDistance.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2020 08:19:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class solver
{
private:
unordered_map<Node *,Node *>m;
void getparent(Node *root)
{
    if(root==nullptr)
        return;
    if(root->left)
        m[root->left]=root;
    if(root->right)
        m[root->right]=root;
    getparent(root->left);
    getparent(root->right);
}
Node *getTargetNode(Node *root,int target)
{
    if(root==nullptr)
        return nullptr;
    if(root->data==target)
        return root;
   return (getTargetNode(root->left,target) ==nullptr)?getTargetNode(root->right,target):getTargetNode(root->left,target);
        
}
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>v;
        getparent(root);
        m[root]=nullptr;
        Node *t=getTargetNode(root,target);
        queue<pair<Node *,int>>q;
        q.push({t,k});
        unordered_map<Node *,int>m1;
        // cout << t->data <<" "<<k << endl;
        while(!q.empty())
        {
            pair<Node *,int>temp=q.front();
            q.pop();
            if(m1.find(temp.first)!=m1.end())
                continue;
            m1[temp.first]=1;
            if(temp.first->left&&m1.find(temp.first->left)==m1.end()){
                if(temp.second-1==0)
                    v.push_back(temp.first->left->data);
                else
                    q.push({temp.first->left,temp.second-1});
            }
            if(temp.first->right&&m1.find(temp.first->right)==m1.end()){
                if(temp.second-1==0)
                    v.push_back(temp.first->right->data);
                else
                    q.push({temp.first->right,temp.second-1});
            }
            if(m[temp.first]&&m1.find(m[temp.first])==m1.end()){
                if(temp.second-1==0)
                    v.push_back(m[temp.first]->data);
                else
                    q.push({m[temp.first],temp.second-1});
            }
            
           
        }
        sort(v.begin(),v.end());
        return v;
    }
};
