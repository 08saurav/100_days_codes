/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

using namespace std;
void bfs(int s,int x,int level[],int Nodes[],int n,vector<vector<int>>v,bool vis[])
{
	queue<int>q;
	q.push(s);
	level[s]=0;
	Nodes[level[s]]++;
	vis[s]=true;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(vis[v[p][i]]==false && v[p][i]==i)
			{
				level[v[p][i]]=level[p]+1;
				Nodes[level[v[p][i]]]++;
				// cout << p<<" "<<v[p][i] <<" "<<level[v[p][i]] <<" " << Nodes[level[v[p][i]]] << endl;
				vis[v[p][i]]=true;
				q.push(v[p][i]);
			}	
		}
	}
	cout << Nodes[x-1] << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>>v(n+1);
	for (int i = 0; i <=n; i++) {  
    	v[i].resize(n+1);
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		// cout << a  << " is connected to " << b << endl;
		v[a][b]=b;
		v[b][a]=a;
	}
	int x;
	cin >> x;
	int level[n+1],Nodes[n+1];
	bool vis[n+1];
	for(int i=0;i<=n;i++){
		vis[i]=false;
		level[i]=0;
		Nodes[i]=0;
	}
	bfs(1,x,level,Nodes,n,v,vis);
}
