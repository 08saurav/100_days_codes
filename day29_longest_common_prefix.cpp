/*
 * =====================================================================================
 *
 *       Filename:  day29_longest_common_prefix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2020 12:28:39 AM
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
string FindLongestPrefix(string s1,string s2)
{
		int n=s1.length();
		int m=s2.length();
		string result="";
		for(int i=0,j=0;i<=n-1 && j<=m-1;i++,j++)
		{
				if(s1[i]!=s2[j])
						break;
				result.push_back(s1[i]);
		}
		return result;
}
string LongPrefDivide(string s[],int l,int r)
{
		if(l==r)
				return s[l];
		else
		{
				int mid=(l+r)/2;
				string s1=LongPrefDivide(s,0,mid);
				string s2=LongPrefDivide(s,mid+1,r);
				return FindLongestPrefix(s1,s2);
		}
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int n,len=0,k=0;
		cin >> n;
		string s[n];
		for(int i=0;i<n;i++)
				cin >> s[i];
		cout <<LongPrefDivide(s,0,n-1) << endl;
	}
}
