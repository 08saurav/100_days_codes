/*
 * =====================================================================================
 *
 *       Filename:  day33_reverse_k_group.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 11:37:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
		node *next;
		int data;
};
node *getNewNode()
{
		node *n=new node;
		n->data=-1;
		return n;
}
void insert(node *&root,int a[],int n)
{
		for(int i=n-1;i>=0;i--)
		{
			node *temp=new node;
			temp->data=a[i];
			temp->next=root;
			root=temp;
		}
}
node *reverse_list(node *root,int k)
{
	node *curr=root,*prev=nullptr,*next1=nullptr;
	int count =0;
		//cout << curr->data << endl;
	while(curr!=NULL && count<k)
	{
			//cout << curr->data << endl;
		next1=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next1;
		count++;
	}
	if(next1!=NULL)
			root->next=reverse_list(next1,k);
	return prev;
}
void printlist(node *root)
{
		node *temp=root;
		while(temp!=NULL)
		{
				cout << temp->data << " " ;
				temp=temp->next;
		}
		cout<< endl;
}
int main()
{
		int n,k;
		cin >> n;
		int a[n];
		node *root=nullptr;
		for(int i=0;i<n;i++)
				cin >> a[i];
		insert(root,a,n);
		cin >> k;
		root=reverse_list(root,k);
		printlist(root);
		return 0;
}
