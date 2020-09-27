/*
 * =====================================================================================
 *
 *       Filename:  day73_shotestCommonSubsequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/15/2020 11:57:04 PM
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

int lcs(string s1,string s2,int m,int n)
{
		/* recursive approch */
	/*	if(m==0 || n==0)
				return 0;
		int s=0;
		if(s1[m-1]==s2[n-1])
		{
				cout << s1[m-1] << " " << s2[n-1] << endl;
				 s=1+lcs(s1,s2,m-1,n-1);
		}
		else 
				s=max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
	//	cout << s << " ";
		return s;*/
		/* iterative approach*/
		int dp[m+1][n+1];
		for(int i=0;i<=n;i++)
				dp[0][i]=0;
		for(int i=0;i<=m;i++)
				dp[i][0]=0;
		for(int i=1;i<=m;i++)
		{
				//cout << s1[i-1] << endl;
				for(int j=1;j<=n;j++)
				{
						if(s1[i-1]==s2[j-1]){
								dp[i][j]=1+dp[i-1][j-1];
							//	cout << s1[i-1] << s2[j-1] << endl;
						}
						else
								dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
		}
		return dp[m][n];
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				string s1,s2;
				cin >> s1 >> s2;
				int n=s1.length();
				int m=s2.length();
				int r=lcs(s1,s2,n,m);
				cout << m+n-r << endl;
		}
		return 0;
}
