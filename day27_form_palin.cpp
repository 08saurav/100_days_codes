/*
 * =====================================================================================
 *
 *       Filename:  day27_form_palin.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 07:35:16 PM
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

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		string s,s1;
		cin>> s;
		s1=s;
		reverse(s1.begin(),s1.end());
		int n=s.length();
		int dp[n+1][n+1];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
					dp[i][j]=0;
		for(int i=1;i<=n;i++)
		{
				for(int j=1;j<=n;j++)
				{
						if(s[i-1]==s1[j-1])
								dp[i][j]=1+dp[i-1][j-1];
						else
								dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
		}
		cout <<n-dp[n][n] << endl;	
	}
	return 0;
}
