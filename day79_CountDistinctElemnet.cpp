/*
 * =====================================================================================
 *
 *       Filename:  day79_CountDistinctElemnet.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2020 06:48:55 PM
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

vector <int> countDistinct (int a[], int n, int k)
{
    //code here.
    vector<int>res;
    unordered_map<int,int>m;
    int i,ct=0;
    for(i=0;i<k;i++){
        if(m.find(a[i])==m.end())
            ct++;
        m[a[i]]=i;
    }
    res.push_back(ct);
    int j=0;
    for(;i<n;i++)
    {
        if(m[a[j]]==j){
            m.erase(a[j]);
            ct--;
        }
        if(m.find(a[i])==m.end())
            ct++;
        j++;
        m[a[i]]=i;
        res.push_back(ct);
    }
    return res;
}
