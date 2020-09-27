/*
 * =====================================================================================
 *
 *       Filename:  day16_k_small.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2020 12:05:38 AM
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
void swap(int *a,int *b)
{
		int temp=*a;
		*a=*b;
		*b=temp;
}
int part(int arr[],int l,int r)
{
		int x=arr[r],i=l;
		for(int j=l;j<=r-1;j++)
		{
				if(arr[j]<=x){
						swap(&arr[i],&arr[j]);
						i++;
				}
		}
		swap(&arr[i],&arr[r]);
		return i;
}
int findk(int arr[],int l,int r,int k)
{
		if(k>0 && k<=r-l+1)
		{
			int idx=part(arr,l,r);
			//output(arr);
			//cout << arr[idx]<<"  "<<idx <<endl;
			if(idx-l==k-1)
					return arr[idx];
			else if(idx-l>k-1)
					return findk(arr,l,idx-1,k);
			return findk(arr,idx+1,r,k-idx+l-1);
		}
		return -1;
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		lli n,k;
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++)
				cin >> arr[i];
		cin >> k;
		cout << findk(arr,0,n-1,k) << endl;
		//output(arr);
	}
}
