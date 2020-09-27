/*
 * =====================================================================================
 *
 *       Filename:  day27_form_palin2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 08:58:17 PM
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
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  T temp;
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}


lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}
int dp[100][100];
int MinInsert(string s,int l,int r)
{
		if(l>=r)
				return 0;
		if(dp[l][r]!=-1)
				return dp[l][r];
		if(s[l]==s[r]){
				dp[l][r]=MinInsert(s,l+1,r-1);
				return dp[l][r];
		}
		else
		{
				int m1=1+MinInsert(s,l+1,r);
				int m2=1+MinInsert(s,l,r-1);
				dp[l][r]=min(m1,m2);
				return dp[l][r];
		}
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		string s;
		cin >> s;
		int n=s.length();
		for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
						dp[i][j]=-1;
		cout << MinInsert(s,0,n-1) << endl;
	}
	return 0;
}
