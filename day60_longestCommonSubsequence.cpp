/*
 * =====================================================================================
 *
 *       Filename:  day60_longestCommonSubsequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2020 11:06:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
/* just think of it as simple recursion and then to reduce time using a matrix dp to store previous results. this way its easy to understand.
if(s1[n1-1]==s2[n2-1])
return dp[n1][n2]=1+lcs(s1,s2,n1-1,n2-1);
here if last element equal then increse length by one and recure for remaining
similary if not equal then either ans if from lcs(s1,s2,n1,n2-1); this orlcs(s1,s2,n1-1,n2);
take max of these;
as in abcd and bcad first is not same then check for bcd and bcad or(abcd and cad) */

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
				cin>> n >> m;
				string s1,s2;
				cin >> s1>> s2;
				int dp[n+1][m+1];
				for(int i=0;i<=n;i++)
						dp[i][0]=0;
				for(int i=0;i<=m;i++)
						dp[0][i]=0;
				for(int i=1;i<=n;i++)
				{
						for(int j=1;j<=m;j++)
						{
								if(s1[i-1]==s2[j-1])
										dp[i][j]=dp[i-1][j-1]+1;
								else
										dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
						}
				}
				/*for(int i=0;i<=n;i++)
				{
						for(int j=0;j<=m;j++)
								cout << dp[i][j] << " ";
						cout << endl;
				}*/

				cout << dp[n][m] << endl;
		}
		return 0;
}
