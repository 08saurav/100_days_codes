/*
 * =====================================================================================
 *
 *       Filename:  day102_OverlappingRecangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2020 11:59:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
using namespace std;

bool checkOverlap(int r1[],int r2[])
{
    if(r2[0]>r1[2]||r2[2]<r1[0])
        return false;
    if(r2[3]>r1[1] || r2[1]<r1[3])
        return false;
    return true;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int r1[4],r2[4];
	    cin >> r1[0] >> r1[1] >> r1[2] >> r1[3];
	    cin >> r2[0] >> r2[1] >> r2[2] >> r2[3];
	    cout << checkOverlap(r1,r2) << endl;
	}
	return 0;
}
