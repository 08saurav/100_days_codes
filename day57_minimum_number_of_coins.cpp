/*
 * =====================================================================================
 *
 *       Filename:  day57_minimum_number_of_coins.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2020 03:22:18 PM
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
				int coins[]={1,2,5,10,20,50,100,200,500,2000};
				int n;
				cin >> n;
				int dp[10][n+1];
				/*for(int i=0;i<9;i++)
						cout << coins[i] << " ";
				cout << endl;*/
				for(int i=0;i<=n;i++)
						dp[0][i]=i;
				for(int i=0;i<10;i++)
						dp[i][0]=0;
				for(int i=1;i<10;i++)
				{
						for(int j=1;j<=n;j++)
						{
								if(j>=coins[i])
										dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
								else
										dp[i][j]=dp[i-1][j];
						}
				}
			     /*for(int i=0;i<9;i++){
						for(int j=0;j<=n;j++)
								cout << dp[i][j] << " ";
				cout << endl;
				}*/
				cout << dp[9][n] << endl;
				int i=9,j=n;
				while(i>0 && j>0)
				{
						if(dp[i][j]==dp[i-1][j]) i--;
						else
						{
								cout << coins[i] << " ";
								j=j-coins[i];
						}
				}
				while(j>0)
				{
						cout << coins[0] << " ";
						j=j-coins[0];
				}
				cout << endl;
		}
		return 0;
}
