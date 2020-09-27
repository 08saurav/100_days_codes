/*
 * =====================================================================================
 *
 *       Filename:  day64_coin_change.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2020 12:24:36 PM
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
				int m;
				cin >>m;
				int a[m];
				for(int i=0;i<m;i++)
						cin >> a[i];
				int n;
				cin >> n;
				int dp[n+1];
				for(int i=0;i<=n;i++)
						dp[i]=0;
				dp[0]=1;
				for(int i=0;i<m;i++)
				{
					for(int j=1;j<=n;j++)
					{
							if(a[i]<=j)
									dp[j]=dp[j]+dp[j-a[i]];

					}
				}
				cout << dp[n] << endl;
		}
}
