/*
 * =====================================================================================
 *
 *       Filename:  str_sort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 12:50:10 AM
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
				//int n;
				//cin >> n;
				//string s[n];
				//for(int i=0;i<n;i++)
				//		cin >> s[i];
				//sort(s,s+n);
				/*for(int i=0;i<n;i++)
						cout << s[i] << " ";
				cout << endl;*/
				string s1[4];
				s1[0]="12345",s1[1]="13245",s1[2]="14532",s1[3]="54321";
				sort(s1,s1+4);
				for(int i=0;i<4;i++)
						cout << s1[i] << " ";
				cout << endl;
		}
		return 0;
}
