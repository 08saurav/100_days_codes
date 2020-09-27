/*
 * =====================================================================================
 *
 *       Filename:  day68_maximizeCutSegment.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2020 01:33:19 PM
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
#define ll long long
int dp[4001];
int maximumSegement(int n,int x,int y,int z)
{
		//cout << n << " " << x << " " << y << " " << z << endl;
		if(n<=0)
				return 0;
		if(n<x && n<y && n<z)
				return 0;
		//cout << n << " " << x << " " << y << " " << z << endl;
		if(dp[n])
				return dp[n];
		cout << n << " " << x << " " << y << " " << z << endl;
		return dp[n]=max(max(1+maximumSegement(n-x,x,y,z),1+maximumSegement(n-y,x,y,z)),1+maximumSegement(n-z,x,y,z));
}

int  main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n;
				cin >> n;
				int x,y,z;
				cin >> x>>y >> z;
				for(int i=0;i<=n;i++)
						dp[i]=0;
				//cout <<maximumSegement(n,x,y,z) << endl;
				for(int i=0;i<=n;i++)
				{
						if(i==x||i==y||i==z)
								dp[i]=1;
						if(i>x && dp[i-x]!=0){dp[i]=max(dp[i],dp[i-x]+1);}
						if(i>y && dp[i-y]!=0){dp[i]=max(dp[i],dp[i-y]+1);}
						if(i>z && dp[i-z]!=0){dp[i]=max(dp[i],dp[i-z]+1);}
				}
				cout << dp[n] << endl;
		}
		return 0;
}


