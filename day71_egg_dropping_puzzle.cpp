/*
 * =====================================================================================
 *
 *       Filename:  day71_egg_dropping_puzzle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2020 10:15:39 PM
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

int find_way(int n,int k)
{
    int dp[n+1][k+1];
        
        for(int i=0;i<=k;i++)
            dp[1][i]=i;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
            dp[i][1]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                dp[i][j]=INT_MAX;
                for(int x=1;x<=j;x++){
                    int rr=1+max(dp[i-1][x-1],dp[i][j-x]);
                    if(rr<dp[i][j])
                        dp[i][j]=rr;
                }
            }
        }
        return dp[n][k];
// 		if(k==0||k==1)
// 				return k;
// 		if(n==1)
// 				return k;
// 		if(dp[n][k]!=-1)
// 				return dp[n][k];
// 		int ans=INT_MAX;
// 		for(int i=1;i<=k;i++)
// 		{
// 				int temp=1+max(find_way(n-1,i-1,dp),find_way(n,k-i,dp));
// 				ans=min(ans,temp);
// 		}
// 		return dp[n][k]=ans;
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n,k;
				cin >> n >> k;
				// int dp[n+1][k+1];
				// int **dp = (int **)malloc(n+1 * sizeof(int *));
				// for (int r = 0; r <n+1; r++)
				// 		dp[r] = (int *)malloc(k+1 * sizeof(int));
				// for(int i=0;i<=n;i++)
				// 		for(int j=0;j<=k;j++)
				// 				dp[i][j]=-1;
				cout <<find_way(n,k) << endl;
		}
}
