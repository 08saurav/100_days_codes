/*
 * =====================================================================================
 *
 *       Filename:  day100_DetectCycle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2020 09:26:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool dfs(vector<int>adj[],int s,bool visited[])
{
    visited[s]=true;
//    helper[s]=true;
    // cout << s << " "<<adj[s].size() <<  endl;
    vector<int>v(adj[s].begin(),adj[s].end());
    for(int i=0;i<v.size();i++)
    {
        int curr=v[i];
        // cout << curr << " ";
  //      if(helper[curr]==true) return true;
        if(visited[curr]==false)
        {
            bool ans=dfs(adj,curr,visited);
            if(ans) return true;
        }
        
    }
//    helper[s]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    //    helper[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            bool ans=dfs(adj,i,visited);
            if(ans) return true;
        }
    }
    return false;
}
