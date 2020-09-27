/*
 * =====================================================================================
 *
 *       Filename:  day61_01Knapsack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2020 11:24:56 PM
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

int dp[1001][1001];
int findMaxValue(int n,int W,int v[],int w[])
{

		//cout << n << " " << W << endl;
		//recursive and memoization approach		
		/*  if(n==0 || W==0)
			return 0;
		if(w[n-1]<=W)
				dp[n][W]=max(v[n-1]+findMaxValue(n-1,W-w[n-1],v,w),findMaxValue(n-1,W,v,w));
		else
				dp[n][W]=findMaxValue(n-1,W,v,w);
		return dp[n][W];*/
		/* Top down Approch iterative method */
		for(int i=1;i<=n;i++)
		{
				for(int j=1;j<=W;j++)
				{
						if(w[i-1]<=j)
								dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
						else
								dp[i][j]=dp[i-1][j];
						//cout << dp[i][j] << " ";
				}
				//cout << endl;
		}
		/*for(int i=0;i<=n;i++)
		{
				for(int j=0;j<=W;j++)
						cout << dp[i][j] << " ";
			   cout << endl;	
		}*/
		return dp[n][W];
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n,W;
				cin >> n>>W;
				int v[n],w[n];
				for(int i=0;i<n;i++)
						cin >> v[i];
				for(int i=0;i<n;i++)
						cin >> w[i];
				//int dp[n+1][W];
				for(int i=0;i<=n;i++){
						dp[i][0]=0;
				}
				for(int i=0;i<=W;i++) 
						dp[0][i]=0;
				cout << findMaxValue(n,W,v,w) << endl;;
		}
		return 0;
}
