/*
 * =====================================================================================
 *
 *       Filename:  day94_findMedian.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2020 03:50:07 PM
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

priority_queue<int,vector<int>,greater<int>>minHeap;
priority_queue<int>maxHeap;
void add_num(int n)
{
    maxHeap.push(n);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    if(minHeap.size()>maxHeap.size())
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}
int findMedian()
{
    if(maxHeap.size()>minHeap.size())
        return maxHeap.top();
    return (maxHeap.top()+minHeap.top())/2;
}
int main() {
	//code
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
	    int temp;
	    cin >> temp;
	    add_num(temp);
	    cout <<findMedian() << endl;
	}

	return 0;
}
