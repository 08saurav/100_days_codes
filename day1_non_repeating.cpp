/*
 * =====================================================================================
 *
 *       Filename:  day1_non_repeating.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2020 10:54:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		char temp='\0';
		bool flag=false;
		cin >> s;
		unordered_map<char,int>m;
		for(int i=s.size()-1;i>=0;i--)
			m[s[i]]++;
		for(int i=0;i<s.size();i++)
			if(m[s[i]]==1){
				temp=s[i];
				flag=true;
				break;
			}
		if(flag)
			cout << temp<< endl;
		else
			cout << -1 << endl;
	}
	return 0;
}


