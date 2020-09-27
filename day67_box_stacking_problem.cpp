/*
 * =====================================================================================
 *
 *       Filename:  day67_box_stacking_problem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2020 12:55:42 AM
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

bool comp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
		return (a.first.first*a.first.second)<(b.first.first*b.first.second);
}
int main()
{
		int n;
		cin >> n;
		int h[n],b[n],l[n];
		for(int i=0;i<n;i++)
				cin >> l[i] >> b[i] >> h[i];
		/*for(int i=0;i<n;i++)
				cin >> b[i];
		for(int i=0;i<n;i++)
				cin >> h[i];*/
		vector<pair<pair<int,int>,int>>v;
		for(int i=0;i<n;i++)
		{
				v.push_back({{max(l[i],b[i]),min(l[i],b[i])},h[i]});
				v.push_back({{max(l[i],h[i]),min(l[i],h[i])},b[i]});
				v.push_back({{max(b[i],h[i]),min(b[i],h[i])},l[i]});
		}
		sort(v.begin(),v.end(),comp);
		n=3*n;
		int dp[n];
		for(int i=0;i<n;i++)
				dp[i]=v[i].second;
		int maxi=dp[0];
		for(int i=1;i<n;i++)
		{
				for(int j=0;j<i;j++)
				{
						if(v[i].first.first>v[j].first.first && v[i].first.second>v[j].first.second){
							//	cout << dp[i] << " old " << endl;
								dp[i]=max(dp[i],dp[j]+v[i].second);
								maxi=max(maxi,dp[i]);
								//cout << dp[i] << " ";
						}
						//cout << dp[j] << " ";
				}
			//	cout << endl;
		}
		cout << maxi << endl;
		return 0;
}
