/*
 * =====================================================================================
 *
 *       Filename:  day44_paranthesis_checker.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 03:58:10 AM
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

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				string s;
				cin >> s;
				stack<char>st;
				int n=s.length();
				for(int i=0;i<n;i++)
				{
						if(st.size()==0)
								st.push(s[i]);
						else if((st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']') || (st.top()=='(' && s[i]==')') ){
							//	cout << st.top() << endl;  
								st.pop();
						}
						else if(!st.empty())
								st.push(s[i]);
				}
				if(st.size()==0)
						cout << "balanced" << endl;
				else{
						//cout<<st.top() << endl;
						cout << "not balanced" << endl;
				}
		}
		return 0;
}
