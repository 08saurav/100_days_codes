/*
 * =====================================================================================
 *
 *       Filename:  day7_subarray_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/2020 11:03:44 AM
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
              lli n,target;
	      cin >> n >>target;
	      int a[n];
	      for(int i=0;i<n;i++)
	      	cin >> a[i];
	      int st=1,end=0,sum=0;
	      for(int i=0;i<n;i++)
	      {
		  sum=sum+a[i];
		  if(sum > target){
			  sum=sum-a[st-1];
			  st=st+1;
		  }
		  if(sum==target){
			  end=i+1;
			  break;
		  }
	      }
	      if(sum==target)
	      	cout << st << " " << end << endl;
	      else
		      cout << -1 << endl;
	}
}
