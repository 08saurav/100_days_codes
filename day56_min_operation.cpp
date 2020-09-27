/*
 * =====================================================================================
 *
 *       Filename:  day56_min_operation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/07/2020 02:16:21 PM
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
int find_min(int n,int* dp)
{
	
		if(n==1)
				return 1;
		if(dp[n/2]==0)
				dp[n/2]=find_min(n/2,dp);
		if(dp[n-1]==0)
				dp[n-1]=find_min(n-1,dp);
		//cout <<n/2 <<" "<<dp[n/2] << " " << n-1 << " " << dp[n-1] << endl;
		/*for(int i=1;i<=n;i++)
				cout << dp[i] << " ";
		cout << endl;*/
		dp[n]=min(1+dp[n-1],1+dp[n/2]+n%2);
	/*	for(int i=1;i<=n;i++)
				cout << dp[i] << " ";
		cout << endl;
		cout << "n = " << n << endl;*/
		return dp[n];
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int n;
		cin >> n;
		int dp[10001]={0};
		cout << find_min(n,dp) << endl;
	}
}
