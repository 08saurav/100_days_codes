/*
 * =====================================================================================
 *
 *       Filename:  day86_minimumIndexCharacter.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2020 01:47:33 AM
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

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string pat,str;
	    cin >> pat>>str;
	    unordered_map<char,int>m;
	    for(int i=0;i<pat.length();i++)
	        m.insert({pat[i],i});
	   int mini=INT_MAX;
	   for(int i=0;i<str.length();i++)
	   {
	        if(m.find(str[i])!=m.end())
	        {
	            mini=min(mini,m[str[i]]);
	        }
	   }
	   if(mini==INT_MAX)
	        cout << "$" << endl;
	   else
	        cout << pat[mini] << endl;
	}
	return 0;
}
