/*
 * =====================================================================================
 *
 *       Filename:  day54_RottenOranges.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/06/2020 12:18:08 PM
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
				int m,n;
				cin >> m >> n;
				int a[m][n];
				int ct1=0;
				queue<pair<int,int>>q;
				for(int i=0;i<m;i++){
					for(int j=0;j<n;j++){
							cin >> a[i][j];
							if(a[i][j]==2){
									q.push({i,j});
							}
							else if(a[i][j]==1){
									ct1++;
								//	cout << i << " " << j << endl;
							}
					}
				}
				int ct=0,ct2=0;	
				q.push({-1,-1});
				while(!q.empty())
				{
						pair<int,int> p=q.front();
						q.pop();
						//cout << "q.pop(): " << p.first << " " << p.second << endl;
						if(q.size()>0 && p.first==-1 && p.second==-1){
								ct++;
								q.push({-1,-1});
						}
						else if(a[p.first][p.second]==2)
						{
								if((p.first-1>=0) && a[p.first-1][p.second]==1)
								{
									a[p.first-1][p.second]=2;
									q.push({p.first-1,p.second});
									//cout << p.first-1 <<" " << p.second << endl; 
									ct2++;
								}
								if(p.first+1<m && a[p.first+1][p.second]==1)
								{
										a[p.first+1][p.second]=2;
										q.push({p.first+1,p.second});
								//		cout << p.first+1 <<" " << p.second << endl;
										ct2++;
								}
								if((p.second-1>=0) && a[p.first][p.second-1]==1)
								{
										a[p.first][p.second-1]=2;
										q.push({p.first,p.second-1});
								//	    cout << p.first <<" " << p.second-1 << endl;
										ct2++;
								}
								
								if((p.second+1<n) && a[p.first][p.second+1]==1)
								{
										a[p.first][p.second+1]=2;
										q.push({p.first,p.second+1});
								//		cout << p.first <<" " << p.second+1 << endl;
										ct2++;
								}
								//cout << ct2 << endl;
								/*for(int i=0;i<m;i++){
									for(int j=0;j<n;j++)
											cout << a[i][j] << " ";
									cout << endl;
								}*/

						}

				}
			//	cout << ct1 <<" " <<ct2 << endl; 
				if(ct2==ct1)
					cout << ct << endl;
				else 
						cout << -1 << endl;
		}
		return 0;
}
