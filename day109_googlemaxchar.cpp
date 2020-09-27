/*
 * =====================================================================================
 *
 *       Filename:  day109_googlemaxchar.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 03:20:59 PM
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

string solve(vector<int>cost,int W)
{
		int dp[27][W+1];
		string s="";
		for(int i=0;i<=26;i++)
				dp[i][0]=0;
		for(int j=0;j<=W;j++)
				dp[0][j]=0;
		for(int i=1;i<=26;i++)
		{
			string temp="";
			for(int j=1;j<=W;j++)
			{
				if(j>=cost[i-1]){
						dp[i][j]=max(i+dp[i][j-cost[i-1]],dp[i-1][j]);
						temp+=i-1+'a';
				}
				else 
						dp[i][j]=dp[i-1][j];
			}
			cout << temp << endl;
			s=min(s,temp);
		}
		/*for(int i=0;i<=26;i++)
		{
				for(int j=0;j<=W;j++)
						cout << dp[i][j] << " ";
				cout << endl;
		}*/
		return s;
}

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				vector<int>v;
				for(int i=0;i<26;i++)
				{
						int temp;
						cin >>temp;
						v.push_back(temp);
				}
				int w;
				cin >> w;
				cout << solve(v,w) << endl;
		}
}
