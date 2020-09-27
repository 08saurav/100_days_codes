/*
 * =====================================================================================
 *
 *       Filename:  day69_minimumSumPartition.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2020 03:34:38 PM
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
				int n;
				cin >> n;
				int a[n];
				int sum=0;
				for(int i=0;i<n;i++){
						cin >> a[i];
						sum+=a[i];
				}
				int sum1=sum/2;
				bool dp[n+1][sum1+1];
				for(int i=0;i<=sum1;i++)
						dp[0][i]=false;
				for(int i=0;i<=n;i++)
						dp[i][0]=true;
				for(int i=1;i<=n;i++)
				{
						for(int j=1;j<=sum1;j++)
						{
								if(j>=a[i-1])
								{
										dp[i][j]=(dp[i-1][j-a[i-1]]|dp[i-1][j]);
								}
								else
										dp[i][j]=dp[i-1][j];
						}
				}
				int mini=INT_MAX;
				for(int i=0;i<=sum1;i++)
				{
						if(dp[n][i])
								mini=min(mini,sum-2*i);
				}
				cout << mini << endl;
		}
}
