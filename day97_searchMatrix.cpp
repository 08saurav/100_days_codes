/*
 * =====================================================================================
 *
 *       Filename:  day97_searchMatrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2020 11:33:00 PM
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
	    int n,m;
	    cin >> n >> m;
	    vector<vector<int>>a(n,vector<int>(m,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	            cin >> a[i][j];
	    }
	    int x;
	    cin >> x;
	    bool flag=0;
	    for(int i=0;i<n;i++)
	    {
	        flag=binary_search(a[i].begin(),a[i].end(),x);
	        if(flag)
	            break;
	    }
	    cout << flag << endl;
	}
	return 0;
}
