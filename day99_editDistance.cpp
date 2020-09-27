/*
 * =====================================================================================
 *
 *       Filename:  day99_editDistance.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2020 01:02:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    // Code here
		    int n=s.length();
		    int m=t.length();
		    int dp[n+1][m+1];
		    for(int i=0;i<=n;i++)
                dp[i][0]=i;
            for(int j=0;j<=m;j++)
                    dp[0][j]=j;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(s[i-1]==t[j-1])
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
            return dp[n][m];
		}
};
