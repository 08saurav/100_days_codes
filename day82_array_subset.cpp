/*
 * =====================================================================================
 *
 *       Filename:  day82_array_subset.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2020 12:06:24 AM
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
				int m,n;
				cin >> m >> n;
				unordered_map<int,int>mp;
				for(int i=0;i<m;i++){
						int temp;
						cin>> temp;
						mp[temp]=1;
				}
				int flag=0;
				for(int i=0;i<n;i++)
				{
					int temp=0;
					cin >> temp;
					if(mp.find(temp)==mp.end())
							flag=1;
				}
				if(flag)
						cout << "No" << endl;
				else
					cout << "Yes" << endl;	
		}
		return 0;
}
