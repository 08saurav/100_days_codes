/*
 * =====================================================================================
 *
 *       Filename:  day91_dfs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2020 07:47:24 PM
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


vector <int> dfs(vector<int> g[], int N)
{

    // Your code here
    stack<int>s;
    s.push(0);
    bool vis[N];
    vector<int>v;
    for(int i=0;i<N;i++)
        vis[i]=false;
    while(!s.empty())
    {
        int p=s.top();
        s.pop();
        if(vis[p])
            continue;
        v.push_back(p);
        vis[p]=true;
        for(int i=g[p].size()-1;i>=0;i--)
            s.push(g[p][i]);

    }
    return v;
}

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n,e;
				cin >> n>> e;
				vector<int>g[n];
				for(int i=0;i<e;i++)
				{
						int u,v;
						cin >> u>> v;
						g[u].push_back(v);
						g[v].push_back(u);
				}
				vector<int>res = dfs(g,n);
				for(int i=0;i<res.size();i++)
						cout << res[i] << " ";
				cout << endl;
		}
}
