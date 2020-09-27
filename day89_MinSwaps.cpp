/*
 * =====================================================================================
 *
 *       Filename:  day89_MinSwaps.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2020 11:42:26 AM
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

int totalSwaps(int n,int a[])
{
		pair<int,int>p[n];
		for(int i=0;i<n;i++)
		{
				p[i].first=a[i];
				p[i].second=i;
		}
		sort(p,p+n);
		vector<bool>vis(n,false);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(vis[i]||p[i].second==i)
					continue;
			int cy_size=0;
			int j=i;
			while(!vis[j])
			{
					vis[j]=1;
					j=p[j].second;
					cy_size++;
			}
			if(cy_size>0)
					sum+=(cy_size-1);
		}
		return sum;
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n;
				cin >> n;
				int a[n];
				for(int i=0;i<n;i++)
						cin >> a[i];
				cout <<totalSwaps(n,a) << endl; 
		}
		return 0;
}
