/*
 * =====================================================================================
 *
 *       Filename:  day81_Longest_Consecutive_Subsequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 10:33:54 PM
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
				int n;
				cin >> n;
				unordered_map<int,int>m;
				for(int i=0;i<n;i++)
				{
						int temp=0;
						cin >> temp;
						/*if(m.find(temp-1)!=m.end()){
								m[temp]=m[temp-1]+1;
								m[temp-1]++;
						}*/
							
						m[temp]=1;
				}
				int maxi=0;
				for(auto& i:m)
				{
						int ct=0;
						if(m.find(i.first-1)==m.end())
						{
							int j=i.first;
							while(m.find(j++)!=m.end())
									ct++;
						}
						maxi=max(ct,maxi);
				}
				cout << maxi<<endl;
		}
		return 0;
}
