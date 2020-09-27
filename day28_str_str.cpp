/*
 * =====================================================================================
 *
 *       Filename:  day28_str_str.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 09:52:23 PM
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
int kmp(string st,string pattern)
{
		int m=pattern.length();
		int n=st.length();
		int j=0,temp=0;
		int prefix[m];
		prefix[0]=0;
		for(int i=1;i<m;){
			if(pattern[i]==pattern[j]){
				j++;
				prefix[i]=j++;
				i++;
			}
			else{
					if(j!=0)
							j=prefix[j-1];
					else{
							prefix[i]=0;
							i++;
					}
			}
		}
		j=0,temp=-1;
		bool flag=false;
		for(int i=0;i<n;)
		{
			if(pattern[j]==st[i]){
					j++;
					i++;
			}
			if(j==m){
					temp=i-j;
					break;
			}
			else if(i<n && pattern[j]!=st[i])
			{
					if(j !=0)
							j=prefix[j-1];
					else
							i++;
			}
			if(j!=m && i==n-1)
				temp=-1;
		}
		return temp;
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		string st,pattern;
		cin >> st >> pattern;
		cout << kmp(st,pattern) << endl;
	}
}
