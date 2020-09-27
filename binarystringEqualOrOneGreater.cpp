/*
 * =====================================================================================
 *
 *       Filename:  binarystringEqualOrOneGreater.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2020 05:26:07 PM
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
#define ll long long
#define mod 1000000007
#define dbg(var) cout<<#var<<"= "<<var<<" \n"
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, n, t;
	string s;
	cin >> s;
	unordered_map<ll, ll>m;
	m[0] = -1;
	ll res = 0, cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1')
			cnt++;
		else
			cnt--;
		if (m.count(cnt) == 0)
			m[cnt] = i;
		if (m.count(cnt + 1) != 0 && i!=s.length()-1) {
			res = max(res, i - m[cnt + 1]+1);
			flag=false;
		}
		if(m.count(cnt)!=0)
				res=max(res,i-m[cnt]);
	}
	cout << res << endl;


	return 0;
}
