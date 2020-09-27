/*
 * =====================================================================================
 *
 *       Filename:  day51_non_repeating.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2020 02:53:14 AM
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
				char c[n];
				for(int i=0;i<n;i++)
						cin >> c[i];
				int a[26]={0};
				queue<char>q;
				for(int i=0;i<n;i++)
				{
						a[c[i]-'a']++;
						q.push(c[i]);
						while(!q.empty())
						{
								if(a[q.front()-'a']>1)
										q.pop();
								else{
										cout << q.front() << " ";
									   break;	
								}
						}
						if(q.empty())
								cout << -1 << endl;

				}
				cout<< endl;
		}
}
