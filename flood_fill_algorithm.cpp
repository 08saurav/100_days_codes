/*
 * =====================================================================================
 *
 *       Filename:  flood_fill_algorithm.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2020 05:47:27 PM
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

void flood_fill(int m,int n,int x,int y,int k,int p,int **a)
{
		if(x<0 || y<0||x>=m || y>=n)
				return;
		if(a[x][y]!=p)
				return;
		if(a[x][y]==p)
		{
				a[x][y]=k;
				//cout << x << " " << y << endl;
				if(x>0 && a[x-1][y]==p)
					flood_fill(m,n,x-1,y,k,p,a);
				if(x<m-1 && a[x+1][y]==p)
					flood_fill(m,n,x+1,y,k,p,a);
				if(y>0 && a[x][y-1]==p)
					flood_fill(m,n,x,y-1,k,p,a);
				if(y<n-1 && a[x][y+1]==p)
					flood_fill(m,n,x,y+1,k,p,a);
		}
/*		for(int i=0;i<m;i++)
		{
				for(int j=0;j<n;j++)
						cout << a[i][j] << " ";
			//	cout << endl;
		}
		cout << endl;*/
}
int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int m,n;
				cin >> m >> n;
				int **a=new int *[m];
				for(int i=0;i<m;i++)
				{
						a[i]=new int[n];
				}
				for(int i=0;i<m;i++)
				{
						for(int j=0;j<n;j++)
						{
							cin >>a[i][j];
						}
				}
				int x,y,k;
				cin >> x >> y >> k;
				flood_fill(m,n,x,y,k,a[x][y],a);
				for(int i=0;i<m;i++)
						for(int j=0;j<n;j++)
								cout << a[i][j] << " ";
				cout << endl;
		}
}
