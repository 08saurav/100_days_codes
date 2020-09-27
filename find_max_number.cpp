/*
 * =====================================================================================
 *
 *       Filename:  find_max_number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/07/2020 02:40:50 PM
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

int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    //freopen("input.txt", "r", stdin);   
    //freopen("output.txt", "w", stdout);
    #endif   
    int t;
    cin>>t;
    while (t--) {   
        int n;
        cin>>n;
        int cost[10];
        for(int i=1;i<10;i++) {
            cin>>cost[i];
        }
        string dp[n+1];
        dp[0]="";
        for(int i=1;i<=n;i++) {
            std::vector<string> v;
            for(int j=1;j<=9;j++) {
                if(cost[j]<=i) {
                    v.push_back(dp[i-cost[j]]+char(j+'0'));
                }
            }
            v.push_back(dp[i-1]);
            int mx=0;
            for(auto i:v) {
                if(i.length()>mx) {
                    mx=i.length();
                }
            }
            std::vector<string> pos;
            for(auto i:v) {
                if(i.length()==mx) {
                    pos.push_back(i);
                }
            }
            sort(pos.begin(), pos.end());
            if(pos.size()==0) {
                dp[i]="";
            }
            else
            	dp[i]=pos[pos.size()-1];
        }
        cout<<dp[n]<<endl;
    }   
    return 0;  
}
