/*
 * =====================================================================================
 *
 *       Filename:  day34_find_intersection.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 12:23:56 PM
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
void insert(node *&head,int n)
{
		node *temp=new node;
		temp->data=n;
		temp->next=head;
		head=temp;
}
int find_intersection(node *head1,node *head2) 
{
		unordered_map<node *,int>m;
		int temp=-1;
		while(head1!=nullptr)
		{
				m[head1]=1;
				head1=head1->next;
		}
		while(head2!=nullptr)
		{
				if(m.find(head2)!=m.end()){
						temp=head2->data;
						break;
				}
				head2=head2->next;
		}
		return temp;
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int m,n;
				cin >> m >>n;
				node *head1=nullptr,*head2=nullptr;
				for(int i=0;i<m;i++)
				{
						int temp;
						cin >> temp;
						insert(head1,temp);
				}
				for(int i=0;i<n;i++)
				{
						int temp;
						cin >> temp;
						insert(head2,temp);
				}
				cout << find_intersection(head1,head2) << "\n";
		}
}
