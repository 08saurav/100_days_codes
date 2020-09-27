/*
 * =====================================================================================
 *
 *       Filename:  day74_RelativeSorting.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 01:45:25 AM
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

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n,m;
				cin >> n >> m;
				int a[n],b[m];
				map<int,int>ma;
				for(int i=0;i<n;i++)
				{
						cin >> a[i];
						ma[a[i]]++;
				}
				for(int i=0;i<m;i++)
						cin >>b[i];
				for(int i=0;i<m;i++)
				{
						if(ma.find(b[i])!=ma.end())
						{
								while(ma[b[i]]--)
								{
										cout << b[i] << " ";
								}
						}	
				}
				for(auto& i:ma)
				{
						int k=0;
						while(i.second>k){
								cout << i.first << " ";
								k++;
						}
				}
				cout << endl;
		}
}
