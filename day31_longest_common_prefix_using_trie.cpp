/*
 * =====================================================================================
 *
 *       Filename:  day31_longest_common_prefix_using_trie.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 03:21:23 AM
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

struct trie{
	unordered_map<char, trie *>m;
	bool isleaf;	
};
trie *getNewTrieNode()
{
		trie *node=new trie;
		node->isleaf=false;
		return node;
}
void insert(trie *&root,string s)
{
		if(root ==nullptr)
				root=getNewTrieNode();
		trie *temp=root;
		int n=s.length();
		for(int i=0;i<n;i++)
		{
				if(temp->m.find(s[i])==temp->m.end())
						temp->m[s[i]]=getNewTrieNode();
				temp=temp->m[s[i]];
		}
		temp->isleaf=true;
}
int countChild(trie *node,char *c)
{
		int ct=0;
		for(auto &a:node->m)
		{
				ct++;
				*c=a.first;
		}
		return ct;
}	
string longestPrefix(trie *root)
{
		trie *temp=root;
		char c;
		string prefix;
		while(countChild(temp,&c)==1&&temp->isleaf==false)
		{
			temp=temp->m[c];
			prefix.push_back(c);
		}
		return prefix;
}
int main()
{
		ios_base::sync_with_stdio(false);
  		cin.tie(NULL);
		cout.tie(NULL);
		int t;
		cin >> t;
		while(t--)
		{
			int n;
			cin >> n;
			trie *root=nullptr;
			for(int i=0;i<n;i++){
				string s;
				cin >> s;
				insert(root,s);	
			}
			
			string ans=longestPrefix(root) ;
			if(ans.length())
					cout << ans << endl;
			else
					cout << -1 << endl;
		}
		return 0;
}
