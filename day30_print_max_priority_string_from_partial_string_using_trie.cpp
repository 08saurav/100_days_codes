/*
 * =====================================================================================
 *
 *       Filename:  day30_print_max_priority_string_from_partial_string_using_trie.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 03:18:59 AM
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
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

using namespace std;
struct trie{
	// bool isend;
	int weight;
	unordered_map<char,trie *>m;
};
trie *getNewNode()
{
	trie *node = new trie;
	// node->isend=false;
	node->weight=-1;
	return node;
}
void insert(trie *&root,string s,int w){
	if(root == nullptr)
		root=getNewNode();
	trie* temp=root;
	for(int i=0;i<s.length();i++)
	{
		if(temp->m.find(s[i])==temp->m.end())
			temp->m[s[i]]=getNewNode();
		temp=temp->m[s[i]];
		temp->weight=max(temp->weight,w);
	}
	// temp->isend=true;
}
int search(trie* root,string s)
{
	if(root==nullptr)
		return -1;
	trie *temp=root;
	for(int i=0;i<s.length();i++)
	{
		temp=temp->m[s[i]];
		if(temp==nullptr)
			return -1;
		// cout << temp->weight << endl;
	}
	return temp->weight;
}
int main()
{
	int n,q;
	cin >> n>>q;
	trie *root=nullptr;
	for(int i=0;i<n;i++)
	{
		string s;
		int w;
		cin >> s >> w;
		insert(root,s,w);
	}
	for(int i=0;i<q;i++){
		string s;
		cin >> s;
		cout << search(root,s) <<endl;
	}
}
