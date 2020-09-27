/*
 * =====================================================================================
 *
 *       Filename:  day6_egg_dropping_dyanmicsol.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/21/2020 12:21:48 AM
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

int egg_dropping(int n,int k)
{
	int egg[n+1][k+1],res=0;
	for(int i=1;i<=n;i++){
		egg[i][1]=1;
		egg[i][0]=0;
	}
	for(int i=1;i<=k;i++)
		egg[1][i]=i;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			egg[i][j]=2147483647;
			for(int x=1;x<=j;x++){
				res=1+max(egg[i-1][x-1],egg[i][j-x]);
				egg[i][j]=min(res,egg[i][j]);
			}
		}
	}
	return egg[n][k];
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int n,k;
		cin >> n >> k;
		int res=egg_dropping(n,k);
		cout << res << endl;
	}
	return 0;
}
