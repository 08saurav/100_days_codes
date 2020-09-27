/*
 * =====================================================================================
 *
 *       Filename:  day66_subset_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2020 05:58:24 PM
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
		cin>>t;
		while(t--)
		{
				int n;
				cin>>n;
				int a[n];
				int sum=0;
				for(int i=0;i<n;i++){
						cin >>a[i];
						sum=sum+a[i];
				}
				if(sum%2==0){
				    sum=sum/2;
					bool dp[n+1][sum+1];
					for(int i=0;i<=sum;i++)
							dp[0][i]=false;
					for(int i=0;i<=n;i++)
							dp[i][0]=true;
					for(int i=1;i<=n;i++)
					{
						for(int j=1;j<=sum;j++)
						{
								if(a[i-1]<=j)
										dp[i][j]=dp[i-1][j-a[i-1]]|dp[i-1][j];
								else
										dp[i][j]=dp[i-1][j];
								//cout <<dp[i][j] << " ";
						}
						//cout << endl;
					}
					if(dp[n][sum])
							cout << "YES" << endl;
					else
							cout << "NO" << endl;
				}
				else
						cout << "NO" << endl;
		}
		return 0;
}
