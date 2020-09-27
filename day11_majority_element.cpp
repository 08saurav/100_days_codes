/*
 * =====================================================================================
 *
 *       Filename:  day11_majority_element.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/2020 01:04:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<math.h>
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

bool cmp(pair<int,int>&a,pair<int,int>&b)
{
				return a.second < b.second;
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		unordered_map<int,int>m;
		int n,temp;
		cin >> n;
		int maxi=-99999999,num=0;
		//cout << maxi << endl;
		for(int i=0;i<n;i++)
		{
						cin >> temp;
						m[temp]++;
						if(m[temp]>maxi)
						{
										maxi=m[temp];
										num=temp;
						}
		}
		//sort(m.begin(),m.end(),cmp);
		//cout << num << " " << maxi << endl;
		if(maxi>n/2)
						cout << num << endl;
		else
						cout << -1 << endl;
	}
}
