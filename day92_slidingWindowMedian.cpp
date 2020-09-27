/*
 * =====================================================================================
 *
 *       Filename:  day92_slidingWindowMedian.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2020 11:53:23 AM
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

 vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>v;
        multiset<int>wind(nums.begin(),nums.begin()+k);
        auto mid=next(wind.begin(),k/2);
        for(int i=k;;i++)
        {
            double a=double(double(*mid)+double(*prev(mid,1-k%2)))/2.0;
            v.push_back(a);
            if(i==nums.size())
                return v;
            wind.insert(nums[i]);
            if(nums[i]<*mid)
                mid--;
            if(nums[i-k]<=*mid)
                mid++;
             wind.erase(wind.lower_bound(nums[i-k]));
        }
    }
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
			int n,k;
			cin >> n >> k;
			vector<int>nums;
			for(int i=0;i<n;i++)
			{
					int temp;
					cin >> temp;
					nums.push_back(temp);
			}
			vector<double>res=medianSlidingWindow(nums,k);
			for(int i=0;i<res.size();i++)
					cout << res[i] << " ";
			cout << endl;
	}
}
