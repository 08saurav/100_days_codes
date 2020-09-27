/*
 * =====================================================================================
 *
 *       Filename:  day88_MovingStonesUntilConsecutiveII.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2020 05:46:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h> 
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n=stones.size();
        sort(stones.begin(),stones.end());
        int max_moves=max(stones[n-1]-stones[1]-n+1,stones[n-2]-stones[0]-n+1)+1;
        int start=0,end=0;
        int low=n;
        while(end<n)
        {
            int range=stones[end]-stones[start]+1;
            int stone_count=end-start+1;
            if(range>n)
            {
                start++;
                continue;
            }
            if(stone_count==n-1 && range==n-1)
            {
                low=min(low,2);
            }
            else
                low=min(low,n-stone_count);
            end++;
        }
        return{low,max_moves};
    }
};
