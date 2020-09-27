/*
 * =====================================================================================
 *
 *       Filename:  day72_optimal_Strategy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/14/2020 12:34:05 PM
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

int optimal(int a[],int l,int r)
{
	/* resucurive approch */	
		/*int sum1=0;
		if(l<r)
		{
			 int s1=a[l]+min(optimal(a,l+2,r),optimal(a,l+1,r-1));
			 int s2=a[r]+min(optimal(a,l+1,r-1),optimal(a,l,r-2));
			 sum1=max(s1,s2);
		}
		return sum1;*/
	/* iterative approch */
	int dp[r+1][r+1];
	for(int i=0;i<=r;i++)
	{
			for(int j=0;j<=r;j++)
					dp[i][j]=0;
	}
	for(int i=0;i<=r;i++)
			dp[i][i]=a[i];
	int i=0,j=1;
	while(i<=r&&j<=r)
	{
			dp[i][j]=max(a[i],a[j]);
			i++;
			j++;
	}
	i=0,j=2;
	while(i<=r&&j<=r)
	{
			int c=j;
		//	cout  << c << endl;
			while(i<=r&&j<=r){
						int s1=a[i]+min(dp[i+2][j],dp[i+1][j-1]);
						int s2=a[j]+min(dp[i+1][j-1],dp[i][j-2]);
						dp[i][j]=max(s1,s2);
						i++;
						j++;
			}
		//	cout << j << endl;
			j=c+1;
			i=0;

	}
	return dp[0][r];

}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n;
				cin >> n;
				int a[n];
				for(int i=0;i<n;i++)
						cin >> a[i];
				cout <<optimal(a,0,n-1) << endl;
		}
		return 0;
}
