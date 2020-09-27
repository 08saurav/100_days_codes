/*
 * =====================================================================================
 *
 *       Filename:  day52_max_subaarray_k.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2020 03:54:11 AM
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
void sliding_window(vector<int>arr,int n,int k,vector<int>&ans)
{
		deque<int>dq;
		int i=0;
		for(i=0;i<k;i++)
		{
				while(!dq.empty() && arr[i]>=arr[dq.back()])
						dq.pop_back();
				dq.push_back(i);
		}
		for(;i<n;i++)
		{
				ans.push_back(arr[dq.front()]);
				while(!dq.empty()  && dq.front()<=i-k)
						dq.pop_front();
				while(!dq.empty() && arr[i]>=arr[dq.back()])
						dq.pop_back();
				dq.push_back(i);

		}
		ans.push_back(arr[dq.front()]);

}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int n,k;
		cin >> n>> k;
		vector<int>arr,ans;
		input(arr,n);
		sliding_window(arr,n,k,ans);
		output(ans);
	}
}
