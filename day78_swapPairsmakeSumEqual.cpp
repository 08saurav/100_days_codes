/*
 * =====================================================================================
 *
 *       Filename:  day78_swapPairsmakeSumEqual.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 06:19:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
/*sum1 - x + y = sum2 - y + x
2(y - x) = sum2 - sum1
2(y - x) = diff
y = x + diff/2 
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
				int m,n;
				cin >> m >> n;
				int a[m],b[n];
				int sum=0;
				int sum1=0;
				for(int i=0;i<m;i++){
						cin>> a[i];
						sum+=a[i];
				}
				for(int i=0;i<n;i++){
						cin >> b[i];
						sum1+=b[i];
				}
				int flag=-1;
				int diff=abs(sum1-sum);
				if(diff%2==0)
				{
						diff=diff/2;
						if(sum>=sum1)
						{
							unordered_map<int,int>mp;
							for(int i=0;i<m;i++)
								mp[a[i]]=0;
							for(int i=0;i<n;i++){
									if(mp.find(b[i]+diff)!=mp.end())
									{
										flag=1;
										break;	
									}
							}
						}
						
						if(sum<sum1)
						{
							unordered_map<int,int>mp;
							for(int i=0;i<n;i++)
								mp[b[i]]=0;
							for(int i=0;i<m;i++){
									if(mp.find(a[i]+diff)!=mp.end())
									{
										flag=1;
										break;	
									}
							}
						}
				}
				cout << flag << endl;
		}
}
