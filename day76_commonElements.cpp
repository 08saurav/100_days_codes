/*
 * =====================================================================================
 *
 *       Filename:  day76_commonElements.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 04:02:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n1,n2,n3;
	    cin >> n1>>n2>>n3;
	    map<int,int>m;
	    int temp;
	    for(int i=0;i<n1;i++)
	    {
	        cin >> temp;
	        m[temp]=1;
	    }
	    for(int i=0;i<n2;i++)
	    {
	        cin >> temp;
	        if(m.find(temp)!=m.end())
	           m[temp]=2;
	    }
	    for(int i=0;i<n3;i++)
	    {
	        cin >> temp;
	        if(m.find(temp)!=m.end())
	        {
	            if(m[temp]==2)
	                m[temp]=3;
	        }
	    }
	    int flag=0;
	    for(auto& i:m)
	    {
	        if(i.second==3){
	            cout << i.first << " ";
	            flag=1;
	        }
	    }
	    if(!flag)
	        cout << -1;
	    cout << endl;
	}
	return 0;
}
