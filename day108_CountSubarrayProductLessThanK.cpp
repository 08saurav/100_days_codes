/*
 * =====================================================================================
 *
 *       Filename:  day108_CountSubarrayProductLessThanK.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 12:06:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    long long k;
	    cin >> n >> k;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>> a[i];
	   __int128 prod=1;
	   int s=0;
	   long long ct=0;
	   for(int i=0;i<n;i++)
	   {
	       prod*=a[i];
	       while(s<i && prod>=k)
	           prod/=a[s++];
	       if(prod<k)
	           ct=ct+1+(i-s);
	   }
	   cout << ct << endl;
	   
	}
	return 0;
}
