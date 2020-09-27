/*
 * =====================================================================================
 *
 *       Filename:  day104_UglyNumbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 12:01:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
ull getNthUglyNo(int n) {
	   priority_queue<long long int,vector<long long int>,greater<long long int>>q;

        if(n==1)
            return 1;
        long long int ct=1;
        q.push(2);
        q.push(3);
        q.push(5);
        while(ct<n)
        {
            long long int minEle=q.top();
            q.pop();
            ct++;
            if(ct==n)
                return minEle;
            if(minEle%5==0)
                q.push(minEle*5);
            else if(minEle%3==0)
            {
                q.push(minEle*3);
                q.push(minEle*5);
            }
            else if(minEle%2==0)
            {
                q.push(minEle*2);
                q.push(minEle*5);
                q.push(minEle*3);
            }
        }
        return -1;
	}
