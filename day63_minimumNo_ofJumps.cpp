/*
 * =====================================================================================
 *
 *       Filename:  day63_minimumNo_ofJumps.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2020 02:53:42 AM
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
int min_jump(int a[],int n,int dp[])
{
	//	cout << l << " " << prev << endl;
	dp[0]=0;
	for(int i=1;i<n;i++)
	{
			dp[i]=10000001;
			for(int j=0;j<i;j++)
			{
					if(a[j]+j>=i)
							dp[i]=min(dp[i],dp[j]+1);
			}
			//cout << dp[i] << " ";
	}
	//cout << endl;
	if(dp[n-1]==10000001)
			return -1;
	else
			return dp[n-1];
	
}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				int n;
				cin >> n;
				int a[n];
				int dp[n];
				for(int i=0;i<n;i++){
						cin >> a[i];
						dp[i]=0;
				}
				cout << min_jump(a,n,dp) << endl;
		}
		return 0;
}
