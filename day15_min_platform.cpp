/*
 * =====================================================================================
 *
 *       Filename:  day15_number_of_pairs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2020 11:33:11 PM
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
		int n;
		cin >> n;
		pair<int,char>p[2*n];
		for(int i=0;i<n;i++){
			cin >> p[i].first;
			p[i].second='a';
		}
		for(int i=0;i<n;i++){
			cin >> p[n+i].first;
			p[n+i].second='d';
		}
		int m=n+n;
		sort(p,p+m);
		int tem=0,maxi=1;
		for(int i=0;i<m;i++)
		{
			if(p[i].second=='d')
					tem--;
			else if(p[i].second=='a')
					tem++;
			if(tem>maxi)
					maxi=tem;
		}
		cout << maxi << endl;
	}
	return 0;
}
