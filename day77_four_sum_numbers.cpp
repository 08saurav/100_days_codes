/*
 * =====================================================================================
 *
 *       Filename:  day77_four_sum_numbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 01:18:05 PM
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

bool alldist(int a,int b,int c,int d){
    if(a==b || a==c || a==d)
        return false;
    if(b==c|| b== d)
        return false;
    if(c==d)
        return false;
    return true;
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n,target;
				cin >> n >> target;
				int a[n];
				for(int i=0;i<n;i++)
						cin >> a[i];
				map<int,vector<pair<int,int>>>m;
				vector<pair<int,int>>v;
				for(int i=0;i<n;i++)
				{
						for(int j=i+1;j<n;j++){
							m[a[i]+a[j]].push_back({i,j});
							v.push_back({i,j});
						}
				}
				set<multiset<int>>s;
				int flag=0;
				for(auto& i:v)
				{
						int val=a[i.first]+a[i.second];
						for(auto& j:m[target-val])
						{
								if(alldist(i.first,i.second,j.first,j.second))
								{
										multiset<int>p;
										p.insert(a[i.first]);p.insert(a[i.second]);p.insert(a[j.first]);p.insert(a[j.second]);
										flag=1;
										s.insert(p);
								}
						}
				}
				if(!flag){
				    cout << -1 << endl;
				    continue;
				}
				for(auto& i:s){
						for(int j:i)
								cout << j << " ";
						cout << "$";
				}
				cout << endl;
		}
		return 0;
}
