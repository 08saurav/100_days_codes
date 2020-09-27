/*
 * =====================================================================================
 *
 *       Filename:  day18_buy_stocks.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2020 09:47:43 PM
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
		//unordered_map<int,int>m;
		bool flag=false;
		bool flag1=false;
		int temp=0;
		for(int i=0;i<n;i++)
		{
			if(i+1 <n && a[i]<a[i+1] && !flag){
					cout << "(" << i << " ";
					flag=true;
					flag1=true;
					temp=a[i];
			}
			if( i+1 < n && a[i]>a[i+1] && flag){
					cout << i << ") ";
					flag=false;
			}
		}
		if(flag)
				cout << n-1 << ") ";
		if(!flag1)
				cout << "No Profit";
		cout << endl;
	}
	return 0;
}
