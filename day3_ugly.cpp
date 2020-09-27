/*
 * =====================================================================================
 *
 *       Filename:  day3_ugly.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2020 01:56:00 PM
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
lli find_ugly(int n)
{
	int i2=0,i3=0,i5=0;
	lli n2=2,n3=3,n5=5;
	lli next_ugly=0;
	lli ugly[n];
	ugly[0]=1;
	for(int i=1;i<n;i++)
	{
		next_ugly=min(min(n2,n3),n5);
		ugly[i]=next_ugly;
		if(next_ugly==n2)
		{
			i2++;
			n2=ugly[i2]*2;
		}
		if(next_ugly==n3)
		{
			i3++;
			n3=ugly[i2]*3;
		}
		if(next_ugly==n5)
		{
			i5++;
			n5=ugly[i5]*5;
		}
	}
	return next_ugly;
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int n;
		cin >> n;
		lli resi= find_ugly(n);
		cout << resi << endl;
	}
}

