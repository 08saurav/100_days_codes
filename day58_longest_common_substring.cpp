/*
 * =====================================================================================
 *
 *       Filename:  day58_longest_common_substring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2020 08:52:35 PM
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
		cin>> t;
		while(t--)
		{
				int n,m;
				cin >> n>>m;
				int dp[n+1][m+1];
				string s1,s2;
				cin >> s1 >> s2;
				for(int i=0;i<=n;i++)
						dp[i][0]=0;
				for(int i=0;i<=m;i++)
						dp[0][i]=0;
				int maxi=0;
				for(int i=1;i<=n;i++)
				{
						for(int j=1;j<=m;j++)
						{
								if(s1[i-1]==s2[j-1]){
										dp[i][j]=dp[i-1][j-1]+1;
										maxi=max(dp[i][j],maxi);
								}
								else
										dp[i][j]=0;
						}
				}
			    /*for(int i=1;i<=n;i++)
				{
						for(int j=1;j<=m;j++)
								cout << dp[i][j] << " ";
						cout << endl;
				}*/
				cout << maxi << endl;
		}
		return 0;
}
