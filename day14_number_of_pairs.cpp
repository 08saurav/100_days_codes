/*
 * =====================================================================================
 *
 *       Filename:  day14_number_of_pairs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2020 07:24:20 PM
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

int b_search(int key,int y[],int l,int r)
{
		while(l<r)
		{
				int m = l+(r-l)/2;
				if(key<y[m] && ((m-1)>=l && key>=y[m-1])){
					//cout << key   << endl;
						return m;
				}
				else if(key<y[m] && (m-1)>=l && key<y[m-1]){
						r=m;
				}
				else if(key<y[m] && m-1<l){
						//cout << key << endl;
						return m;
				}
				else if(key>=y[m])
						l=m+1;
		}
		return -1;
        
}
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);
  lli testcases;
	cin>>testcases;
	while(testcases--) {
		int m,n;
		cin >> m >> n;
		int x[m],y[n],y1=0,y2=0,x1=0,x3=0,y3=0,y4=0;
		for(int i=0;i<m;i++){
				cin >> x[i];
				if(x[i]==1)
						x1++;
				if(x[i]==3)
				    x3++;
		}
		for(int i=0;i<n;i++){
				cin >> y[i];
				if(y[i]==1)
						y1++;
				if(y[i]==2)
				    y2++;
				if(y[i]==3)
				    y3++;
				if(y[i]==4)
				    y4++;
		}
		sort(y,y+n);
		sort(x,x+m);
		int ct=y1*(m-x1)+x3*y2,p=1;
		for(int i=0;i<m;i++)
		{
		        if(i+1 <m && x[i]==x[i+1])
		        {
		            p++;
		            continue;
		        }
				int yy=b_search(x[i],y,0,n);
				if(yy==-1){
				        p=1;
						continue;
				}
				else if(x[i]==1){
			            p=1;
			            continue;
				}
				else if(x[i]==2)
				{
				    ct+=p*(n-yy-y4-y3);
				}
				else{
					ct+=p*(n-yy);
					p=1;
				}
				
		}
		cout << ct << endl;
	}
	return 0;
}
