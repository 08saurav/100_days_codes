/*
 * =====================================================================================
 *
 *       Filename:  day87_smallestWindowString.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2020 06:32:14 PM
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
			string s,t;
			cin >> s >> t;
			int a[26]={0},b[26]={0};
			int flag1=0;
			for(int i=0;i<t.length();i++){
					a[t[i]-97]++;
			}
			int l=0,r=0;
			int mini=INT_MAX,l1=0,r1=0;
			for(r=0;r<s.length();r++)
			{
				b[s[r]-97]++;
				int flag=1;
				for(int i=0;i<26;i++)
						if(a[i]>b[i])
								flag=0;
				if(flag)
				{
				        flag1=1;
					//	cout << l << " " <<r << endl;
						if(mini>r-l)
						{
								mini=r-l;
								l1=l;
								r1=r;
						}
						while(l<r && flag)
						{
								
							b[s[l]-97]--;
						//	cout << s[l] << " " << s[r] << endl;
						///	cout << b[s[l]-97] << a[s[l]-97] << endl;
							l++;
							for(int i=0;i<26;i++){
								if(a[i]>b[i]){
								//	cout << a[i] << " " << b[i] << endl;
									flag=0;
									break;
								}
							}
							if(!flag)
									break;
							if(mini>r-l)
							{
									mini=r-l;
									l1=l;
									r1=r;
								//	cout << l << " " << r << endl;
									//cout << l << endl;
							}
						}
				}
			}
			if(flag1){
			    for(int i=l1;i<=r1;i++)
				    cout << s[i];
			}
			else
			    cout << -1;
			cout << endl;
		}
		return 0;
}
