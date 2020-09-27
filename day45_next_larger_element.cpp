/*
 * =====================================================================================
 *
 *       Filename:  day45_next_larger_element.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 04:20:51 AM
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
#define ll long long

using namespace std;

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n;
				cin >> n;
				stack<ll>s;
				ll a[n];
				unordered_map<ll,ll>m;
				// queue<ll>q;
				ll temp,k=0;
				for(int i=0;i<n;i++)
				{
						cin >> a[i];
						m[a[i]]=-1;
						while(!s.empty() &&s.top()<a[i]){ 
								m[s.top()]=a[i];
								s.pop();
						}
						s.push(a[i]);
				}
				for(int i=0;i<n;i++)
				    cout << m[a[i]] << " ";
				cout << endl;
		}
		return 0;
}
