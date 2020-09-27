/*
 * =====================================================================================
 *
 *       Filename:  day70_CountNumberofHops.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2020 07:41:45 PM
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

int find_ways(int n,int x,int y,int z,int dp[])
{
	//	cout <<n <<" " << dp[n] << endl;
		if(n==0)
				return 1;
		if(n<0)
				return 0;
		if(dp[n]!=0)
			return dp[n];
		return dp[n]=find_ways(n-x,x,y,z,dp)+find_ways(n-y,x,y,z,dp)+find_ways(n-z,x,y,z,dp);
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n;
				cin >> n;
				int dp[n];
				for(int i=0;i<=n;i++)
						dp[i]=0;
				cout <<find_ways(n,1,2,3,dp) << endl;
		}
		return 0;
}

