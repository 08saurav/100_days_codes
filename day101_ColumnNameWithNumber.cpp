/*
 * =====================================================================================
 *
 *       Filename:  day101_ColumnNameWithNumber.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2020 11:57:52 PM
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

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    long long n;
	    cin >> n;
	    string s="";
	    int m=1;
	    while(n>0)
	    {
	        if(n%26==0)
	        {
	            s="Z"+s;
	            n=(n/26)-1;
	        }
	        else
	        {
	            s=char(n%26+'A'-1)+s;
	            n=n/26;
	        }
	    }
	    cout << s << endl;
	}
	return 0;
}
