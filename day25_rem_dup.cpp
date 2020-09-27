/*
 * =====================================================================================
 *
 *       Filename:  day25_rem_dup.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 05:53:09 PM
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

string remove_str(string s)
{
		bool flag=false,flag1=false;
		int n=s.length(),idx=-1,i=0;
		while(i<s.length())
		{
				if(s[i]==s[i+1] && !flag1)
				{
					idx=i;
					flag=true;
					flag1=true;
				}
				if(s[i]!=s[i+1] && flag1)
				{
					 s.erase(idx,i-idx+1);
					 i=idx;
					 idx=-1;
					 flag1=false;
				}
				else
						i++;
			//	cout << s << endl;
		}
		//cout << s << " "<< flag <<endl;
		if(flag)
		{
				if(idx!=-1)
						s.erase(idx);
				return remove_str(s);
		}
		return s;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		string s;
		cin >> s;
		cout << remove_str(s) << endl;
	}
}
