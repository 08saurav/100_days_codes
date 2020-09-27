/*
 * =====================================================================================
 *
 *       Filename:  day20_spirally_traverse.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2020 12:40:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/*
 * =====================================================================================
 *
 *       Filename:  day14_spirally_traverse.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2020 11:51:07 PM
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
  cout.tie(NULL);  
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int m,n;
		cin >> m >> n;
		int a[m][n];
		for(int i=0;i<m;i++)
		{
				for(int j=0;j<n;j++)
						cin >> a[i][j];
		}
		int i=0,j=0;
		while(i<m && j<n)
		{
				for(int p=j;p<n;p++)
						cout << a[i][p] << " ";
				i++;
				for(int p=i;p<m;p++)
						cout << a[p][n-1] << " ";
				n--;
				if(i<m)
				{
						for(int p=n-1;p>=j;p--)
								cout << a[m-1][p] << " ";
						m--;
				}
				if(j<n)
				{
						for(int p=m-1;p>=i;p--)
								cout << a[p][j] << " ";
						j++;
				}
		}
		cout << endl;
	}
}
