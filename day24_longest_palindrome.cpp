/*
 * =====================================================================================
 *
 *       Filename:  day24_longest_palindrome.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 03:21:09 PM
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

string find_long_palin(string s)
{
		int maxlen=1,n=s.size(),l=0;
		for(int i=1;i<n;i++)
		{
				int low=i-1;
				int high=i;
				while(s[low]==s[high] && low>=0 && high<n)
				{
						if(maxlen<high-low+1){
								maxlen=high-low+1;
								l=low;
						}
						low--;
						high++;
				}
				low=i-1;
				high=i+1;
				while(s[low]==s[high] && low>=0 && high<n)
				{
						if(maxlen<high-low+1){
								maxlen=high-low+1;
								l=low;
						}
						low--;
						high++;
				}
		}
		return s.substr(l,maxlen);
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		string s;
		cin >> s;
		cout << find_long_palin(s) << endl;
	}
}
