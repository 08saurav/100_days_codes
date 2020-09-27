/*
 * =====================================================================================
 *
 *       Filename:  day32_reverse_group.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 04:34:53 AM
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
void reverse_list(node *root,int k,int k2)
{
		node *prev=NULL,*next1=NULL,*curr=root;
		while(k2--)
		{
			int k1=k;
			while(k1>0 && curr!=NULL)
			{
					next1=nullptr;
					if(curr->next!=nullptr)
						next1=curr->next; 
					curr->next=prev;
					prev=curr;
					//if(curr->next!=nullptr)
					curr=next1;
			//		cout << prev->data << " k1 " << k1<<endl;
					k1--;
			}
			node *temp=prev;
			//cout << k1 << endl;
			if(k1==0)
			{
				k1=k;
				while(k1--)
				{
						cout << temp->data <<  " ";
						temp=temp->next;
				}
			}
			else if(k1!=0)
			{
					//cout << "xxxx" << endl;
					//curr->next=prev;
					//if(curr->next==NULL)
					//	k1=k-k1+1;
					//else
					k1=k-k1;
					//temp=curr;
					while(k1--)
					{
						cout << temp->data << " ";
						temp=temp->next;
					}
			}
		}
		cout << endl;
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
		int k1;
		if(n%k!=0)
				k1=(n/k)+1;
		else
			k1=	n/k;
		reverse_list(root,k,k1);
		return 0;
}
