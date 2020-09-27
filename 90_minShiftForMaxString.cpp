/*
 * =====================================================================================
 *
 *       Filename:  90_minShiftForMaxString.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2020 09:48:22 PM
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
  
int  KMP(int m, int n, string str2, string str1) 
{ 
    int pos = 0, len = 0; 
  
    int p[m + 1]; 
    int k = 0; 
    p[1] = 0; 
  
    for (int i = 2; i <= n; i++) { 
        while (k > 0 && str1[k] != str1[i - 1]) 
            k = p[k]; 
        if (str1[k] == str1[i - 1]) 
            ++k; 
        p[i] = k; 
    } 
  
    for (int j = 0, i = 0; i < m; i++) { 
        while (j > 0 && str1[j] != str2[i]) 
            j = p[j]; 
        if (str1[j] == str2[i]) 
            j++; 
  
        if (j > len) { 
            len = j; 
            pos = i - j + 1; 
        } 
    } 
   return len;
} 
  
int main() 
{ 
	int t;
	cin >> t;
	while(t--)
	{
    	string str1 = ""; 
    	string str2 = "";
	    cin >> str1 >> str2;	
    	int n = str1.size();
	   	int m=str2.size();	
		string str3=str2,str4=str2;
		reverse(str3.begin(),str3.end());
    	str2 = str2 + str2; 
    	int l1=KMP(2 *m , n, str2, str1); 
		str3=str3+str4;
		int l2=KMP(2*m,n,str3,str1);
		l1=max(l1,l2);
		cout << str1.substr(0,l1) << endl;

	}
    return 0; 
} 
