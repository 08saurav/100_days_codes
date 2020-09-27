/*
 * =====================================================================================
 *
 *       Filename:  day59_longestIncreasingSubsequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2020 10:48:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/*
 * =====================================================================================
 *
 *       Filename:  day59_longestCommonSubsequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2020 10:38:17 PM
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
			int n;
			cin >> n;
			if(n==0)
					cout << 0 << endl;
			else
			{
					int a[n];
					for(int i=0;i<n;i++)
							cin >> a[i];
					int dp[n];
					for(int i=0;i<n;i++)
							dp[i]=1;
					int maxi=1;
					for(int i=0;i<n;i++)
					{
							for(int j=0;j<i;j++)
							{
									if(a[i]>a[j])
									{
											dp[i]=max(dp[i],dp[j]+1);
											maxi=max(maxi,dp[i]);
									}
							}
					}
					cout << maxi << endl;
			}
		}
		return 0;
}
