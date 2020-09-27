/*
 * =====================================================================================
 *
 *       Filename:  day85_Count_subarraySumZero.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2020 01:31:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int countSubarray(int a[],int n)
{
    int res  = 0;
    unordered_map<int, int> m;
    int sum = 0;
    int ct=0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if(sum == 0){
            res = i+1;
            ct++;
        }
        
        if(m.find(sum) != m.end())
        {
            // res = max(i-m[sum], res);
            ct+=m[sum];
        }
        m[sum]++;
        // m.insert(make_pair(sum,i));
        
        // m[sum]=i;
    }
    return ct;
}
int main() {
	//code
	int t;
	cin >>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin >> a[i];
	    int k=countSubarray(a,n);
	   cout <<k<< endl;
	}
	return 0;
}
