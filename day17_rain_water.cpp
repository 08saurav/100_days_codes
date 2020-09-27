/*
 * =====================================================================================
 *
 *       Filename:  day17_rain_water.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2020 12:46:36 PM
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
		vector<int>arr;
		lli n;
		cin >> n;
		input(arr,n);
		int left[n],right[n],maxi=-1;
		for(int i=0;i<n;i++)
		{
				if(maxi<arr[i])
				{
						maxi=arr[i];
						left[i]=i;
				}
				else
						left[i]=left[i-1];
		}
		maxi=-1;
		for(int i=n-1;i>0;i--)
		{
				if(maxi<arr[i])
				{
						maxi=arr[i];
						right[i]=i;
				}
				else
						right[i]=right[i+1];
		}
		int sum=0;
		for(int i=0;i<n;i++)
				if(min(arr[left[i]],arr[right[i]])-arr[i]>0)
				sum+=min(arr[left[i]],arr[right[i]])-arr[i];
		cout << sum << endl;
	}
	return 0;
}
