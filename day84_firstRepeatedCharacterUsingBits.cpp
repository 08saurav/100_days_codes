/*
 * =====================================================================================
 *
 *       Filename:  day84_firstRepeatedCharacterUsingBits.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2020 12:56:25 AM
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
using namespace std; 
int FirstRepeated(string str) 
{ 
    int checker = 0; 
  
    for (int i = 0; i < str.length(); ++i) 
    { 
        int val = (str[i]-'a'); 
        if ((checker & (1 << val)) > 0) 
            return i; 
        checker |= (1 << val); 
    } 
  
    return -1; 
} 
  

int main() 
{ 
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int r=FirstRepeated(s);
        if(r==-1)
            cout << -1 << endl;
        else
            cout << s[r] << endl;
    }
} 
