/*
 * =====================================================================================
 *
 *       Filename:  day75_SortingElements.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 03:06:09 AM
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

bool comp(const pair<int,int>& a,const pair<int,int>& b)
{
		if(a.second==b.second)
				return a.first<b.first;
		return a.second>b.second;
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n;
				cin >> n;
				map<int,int>m;
				for(int i=0;i<n;i++)
				{
						int temp=0;
						cin >> temp;
						m[temp]++;
				}
				vector<pair<int,int>>v;
				copy(m.begin(),m.end(),	back_inserter(v));
				sort(v.begin(),v.end(),comp);
				for(int i=0;i<v.size();i++)
						for(int j=0;j<v[i].second;j++)
								cout << v[i].first << " ";
				cout << endl;
		}
		return 0;
}
