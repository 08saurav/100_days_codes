/*
 * =====================================================================================
 *
 *       Filename:  day19_smallerleft_greaterright.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2020 10:21:54 PM
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

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++)
				cin >> a[i];
		int left[n],right=a[n-1];
		left[0]=a[0];
		for(int i=1;i<n;i++)
				left[i]=max(left[i-1],a[i-1]);
		int temp=0;
		bool flag=false;
		for(int i=n-1;i>=0;i--)
		{
				if(left[i]<a[i] && right> a[i]){
						//cout << a[i] << endl;
						temp=a[i];
						flag=true;
						//break;
				} 
				right=min(right,a[i]);
		}
		if(!flag)
			cout << -1 << endl;
		else
				cout << temp << endl;
	}
	return 0;
}
