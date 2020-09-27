/*
 * =====================================================================================
 *
 *       Filename:  day13_rearrange_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2020 06:15:31 PM
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
/*int f(){
		return printf("\n");
}*/
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				ll n;
				cin >> n;
				ll a[n];
				for(int i=0;i<n;i++)
						cin >> a[i];
				ll mx=a[n-1]+1,mx_idx=n-1,mn_idx=0;
				for(int i=0;i<n;i++)
				{
					if(i%2==0){
							a[i]+=(a[mx_idx]%mx)*mx;
							mx_idx--;
					}
					if(i%2!=0){
							a[i]+=(a[mn_idx]%mx)*mx;
							mn_idx++;
					}
				}
				for(int i=0;i<n;i++)
						a[i]=a[i]/mx;
				for(int i=0;i<n;i++)
						cout << a[i] << " ";
				cout << endl;
		}
		return 0;
}
