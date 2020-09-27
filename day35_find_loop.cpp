/*
 * =====================================================================================
 *
 *       Filename:  day35_find_loop.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 01:57:36 PM
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

struct Node{
		int data;
		Node *next;
		Node(int val)
		{
				data=val;
				next=NULL;
		}
};
void loopHere(Node* head,Node* tail,int position)
{
		if(position==0) return;
		Node *walk=head;
		for(int i=1;i<position;i++)
				walk=walk->next;
		tail->next=walk;
}
bool detectLoop(Node *head)
{
		Node *slow=head,*fast=head;
		while(slow!=NULL&&fast!=NULL && fast->next!=NULL )
		{
				
				slow=slow->next;
				fast=fast->next->next;
				if(slow==fast)
						return true;
		}
		return false;
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n,num;
				cin >> n;
				Node *head,*tail;
				head = tail =new Node(num);
				for(int i=0;i<n-1;i++)
				{
						cin >> num;
						tail->next=new Node(num);
						tail=tail->next;
				}
				int pos;
				cin >> pos;
				loopHere(head,tail,pos);
				if(detectLoop(head))
						cout << "True\n";
				else
						cout << "False\n";
		}
		return 0;
}
