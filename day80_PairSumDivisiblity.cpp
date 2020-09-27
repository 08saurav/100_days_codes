/*
 * =====================================================================================
 *
 *       Filename:  day80_PairSumDivisiblity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 08:31:00 PM
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
				int n,k;
				cin >> n;
				int a[n];
				map<int,int>m;
				for(int i=0;i<n;i++){
						cin >> a[i];
				}
				cin >> k;
				for(int i=0;i<n;i++){
						m[a[i]%(k)]++;
				// 		cout <<m[a[i]%(k)]<<" ";
				// 		cout << a[i]%(k) <<endl;
				}

				int ct=0;
				for(int i=0;i<n;i++)
				{
				    if(a[i]%(k)==0 && m[a[i]%(k)]>=2)
				    {
				        m[a[i]%(k)]=m[a[i]%(k)]-2;
				        ct++;
				    }
					else if(m.find(k-(a[i]%(k)))!=m.end() && m[k-(a[i]%(k))]>0){
							m[k-(a[i]%(k))]--;
							m[a[i]%(k)]--;
							if(m[k-(a[i]%(k))]>=0)
							    ct++;
					}
					else
							break;
				}
				// cout << ct << endl;
				if(ct==(n/2) && n%2==0)
						cout << "True" << endl;
				else
						cout <<"False" << endl; 
		}
		return 0;
}
