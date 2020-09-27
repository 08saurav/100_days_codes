/*
 * =====================================================================================
 *
 *       Filename:  day62_maximum_sum_increasing_subsequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2020 01:58:30 AM
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
int dp[1000001];
int max_sum_increasing_subsequence(int a[],int n)
{
		/* recusion and memoisation */
		/*if(l==n)
				return prev;
		if(a[l]>prev){

				dp[l]= max(prev+max_sum_increasing_subsequence(a,n,l+1,a[l]),max_sum_increasing_subsequence(a,n,l+1,prev));
		}
		else
				dp[l]= max_sum_increasing_subsequence(a,n,l+1,prev);
		return dp[l];*/
		/* iterating approch, d[j]=prev,a[i]=max_sum_increasing_subsequence(a,n,l+1,a[l]),else condition settled by giving value d[i]=a[i] in main function*/
		int maxi=dp[0];
		for(int i=1;i<n;i++)
		{
				for(int j=0;j<i;j++)
				{

						if(a[i]>a[j])
								dp[i]=max(dp[i],dp[j]+a[i]);
						/*else
								dp[i]=a[i];*/
						cout << dp[i] <<" i " <<a[i] << " j " << a[j] << endl;;
						maxi=max(dp[i],maxi);
				}
		}
		return maxi;
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
				for(int i=0;i<n;i++){
						cin >> a[i];
						dp[i]=a[i];
				}
				cout << max_sum_increasing_subsequence(a,n) << endl;
		}
}
