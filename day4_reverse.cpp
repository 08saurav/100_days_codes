/*
 * =====================================================================================
 *
 *       Filename:  day4_reverse.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2020 02:36:45 PM
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
void reverse_string(string& s)
{
	int start=0;
	for(int end=0;end<s.length();end++){
		if(s[end]==' '){
			reverse(s.begin()+start,s.begin()+end);
			start=end+1;
			//cout << s << endl;
		}
		//cout << s << endl;
			
	}
	reverse(s.begin()+start,s.end());
	//cout << s << endl;
	reverse(s.begin(),s.end());
	//cout << s << endl;
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {

		string s,s1;
		cin >> s1;
		getline(cin,s);
		//cout << s << endl;
		reverse_string(s);
		cout << s << endl;
	}
}
