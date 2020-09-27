/*
 * =====================================================================================
 *
 *       Filename:  day105_TotalDecodingMessages.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 12:02:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
using namespace std;

int decode(string s,int n,int dp[])
{
    dp[0]=1;
    dp[1]=1;
    if(s[0]=='0')
        return 0;
    for(int i=2;i<=n;i++)
    {
        if(s[i-1]!='0')
            dp[i]+=dp[i-1];
        if(s[i-2]=='1' ||(s[i-2]=='2'&&s[i-1]<'7'))
            dp[i]+=dp[i-2];
    }
    return dp[n];
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    int dp[n+1];
	    for(int i=0;i<=n;i++) dp[i]=0;
	    cout << decode(s,n,dp) << endl;
	}
	return 0;
}
