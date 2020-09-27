/*
 * =====================================================================================
 *
 *       Filename:  day64_edit_distance.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2020 09:40:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
/*replace  |insert
 *     	   |
 *---------|-----------
 *delete   |you here
 *         |           */
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
				cin >> n>>m;
				string s1 ,s2;
				cin >> s1 >> s2;
				int dp[n+1][m+1];
				for(int i=0;i<=n;i++)
						dp[i][0]=i;
				for(int i=0;i<=m;i++)
						dp[0][i]=i;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
					{
							if(s1[i-1]!=s2[j-1])
								dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
							else
									dp[i][j]=dp[i-1][j-1];
					}
				}
				cout << dp[n][m] << endl;
		}
}
