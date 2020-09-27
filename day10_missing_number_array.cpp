/*
 * =====================================================================================
 *
 *       Filename:  day10_missing_number_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/2020 12:51:51 PM
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
		while(t--){
				int n,temp;
				cin >> n;
				int a[n+1];
				memset(a,0,sizeof(a));
				for(int i=0;i<n-1;i++){
						cin >> temp;
						a[temp]=1;
				}
				for(int i=1;i<=n;i++){
								if(!a[i])
												cout << i << endl;
				}
		}
		return 0;
}
