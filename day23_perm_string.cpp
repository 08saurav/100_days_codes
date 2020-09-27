/*
 * =====================================================================================
 *
 *       Filename:  day23_perm_string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 02:32:05 AM
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
void permut(string s,int l,int r,vector<string>&v)
{
		if(l==r)
				v.push_back(s);
		else{
				for(int i=l;i<=r;i++)
				{
						swap(s[l],s[i]);
						permut(s,l+1,r,v);
						swap(s[l],s[i]);
				}
		}

}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		string s;
		vector<string>v;
		cin>> s;
		permut(s,0,s.length()-1,v);
		sort(v.begin(),v.end());
		for(auto& i:v)
				cout << i <<" ";
		cout << "\n";
	}
}
