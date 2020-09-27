/*
 * =====================================================================================
 *
 *       Filename:  salesman_problem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2020 08:20:44 PM
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
using ll =long long;
#define F first
#define S second
#define pb push_back
long double euc(pair<int,int>a,pair<int,int>b) {
    long double val=(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    return sqrt(val);
}
long double min1(long double a,long double b) {
    if(a>b)
        a=b;
    return a;
}
vector<int>adj[1002];
vector<pair<int,int>> v;
long double dfs(long double ww,set<int>s,int i,int n) {
    if(s.size()==n) {  
        return ww;
    }
    long double ans=INT_MAX;
    for(auto j:adj[i]) {
        if(s.find(j)==s.end()) {
            long double we=euc(v[i],v[j]);
            set<int>s1;
            s1=s;
            s1.insert(j);
            ans=min1(ans,dfs(ww+we,s1,j,n));
        }
    }
    return ans;
}
int main() {  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
    cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
    v.clear();  
        int n,k;
        cin>>n>>k;
        int min=0,x,y;
        for(int i=0;i<n;i++) {
            int val;
            cin>>val;
            v.push_back({val,0});
        }
        min=v[k-1].first;
        cin>>x>>y;
        sort(v.begin(),v.end());
        v.push_back({x,y});
        for(int i=0;i<n;i++) {
            if(i!=0)
            adj[i].push_back(i-1);
            if(i!=n-1)
            adj[i].push_back(i+1);
            adj[i].push_back(n);
            adj[n].push_back(i);
        }
        std::vector<bool> visited(n+1);
        visited.assign(false,n+1);
        long double ans=INT_MAX;
        for(int i=0;i<=n;i++) {
            visited[i]=true;
            set<int>s;
            s.insert(i);
            long double ww=euc(v[i],{min,0});
            ans=min1(ans,dfs(ww,s,i,n+1));
            visited[i]=false;
        }
        printf("%0.6Lf\n",ans);

    }  
    return 0;  
}   


