/*
 * =====================================================================================
 *
 *       Filename:  day90_bfs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2020 06:10:54 PM
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

vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    queue<int>q;
    vector<int>v;
    q.push(0);
    bool vis[N];
    for(int i=0;i<N;i++)
        vis[i]=false;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        // cout << f << " ";
        if(vis[f]==true)
            continue;
        v.push_back(f);
        vis[f]=true;
        for(int i=0;i<g[f].size();i++)
                q.push(g[f][i]);
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
				cin >> n >> e;
				vector<int>adj[n];
				for(int i=0;i<e;i++)
				{
						int u,v;
						cin >> u >> v;
						adj[u].push_back(v);
				}
				vector<int>res=bfs(adj,n);
				for(int i=0;i<res.size();i++)
						cout << res[i] << " ";
				cout << endl;
		}
}
