/*
 * =====================================================================================
 *
 *       Filename:  day26_rem_dup.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 06:56:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<string.h>
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
void rem_duplicates(char *s,char c)
{
	unordered_map<char,int>m;
	int n=strlen(s);
	cout << c;
	m[c]++;
	for(int i=0;i<n;i++)
	{
			if(m[s[i]]==0)
			{
					cout << s[i];
					m[s[i]]++;
			}
	}
	cout << "\n";
}
int main() {
  
  //ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	//char c;
	//cin >> c;
	while(testcases--) {
		char s[1001];
		char c;
	    cin >> c;
		//cout << c;
		scanf("%[^\n]s",s);
		rem_duplicates(s,c);
	}
}
