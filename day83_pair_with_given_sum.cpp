/*
 * =====================================================================================
 *
 *       Filename:  day83_pair_with_given_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2020 12:14:23 AM
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
				int n,m,sum;
				cin >> n>>m>>sum;
				int a[n],b[m];
				unordered_map<int,int>m1,m2;
				for(int i=0;i<n;i++){
						cin >> a[i];
						m1[a[i]]++;
				}
				for(int i=0;i<m;i++)
				{
						cin >> b[i];
						m2[b[i]]++;
				}
				int flag=0;
				sort(a,a+n);
				sort(b,b+m);
				for(int i=0;i<n;i++)
				{
						if(m2.find(sum-a[i])!=m2.end()&&m2[sum-a[i]]>0)
						{
								m1[a[i]]--;
								if(!flag){
									cout << a[i] << " " << sum-a[i];
									flag=1;
								}
								else
										cout << ", " << a[i]<< " "<<sum-a[i];
						}
				}
				for(int i=0;i<m;i++)
				{
						if(m1.find(sum-b[i])!=m1.end()&&m1[sum-b[i]]>0)
						{
								m2[b[i]]--;
								if(!flag){
									cout << sum-b[i] << " " << b[i];
									flag=1;
								}
								else
										cout << ", " << sum-b[i]<< " "<<b[i];
						}
				}
				if(!flag)
				    cout << -1;
				
				cout << endl;
		}
		return 0;
}
