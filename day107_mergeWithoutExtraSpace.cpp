/*
 * =====================================================================================
 *
 *       Filename:  day107_mergeWithoutExtraSpace.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 12:05:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
oid merge(int a[], int b[], int n, int m) {
	    // code here
	    int k=n-1;
	    for(int i=0,j=0;i<n&&j<m&&k>=0;)
	    {
	        if(a[i]>b[j])
	        {
	            int temp=a[k];
	            a[k--]=b[j];
	            b[j++]=temp;
	        }
	        else if(a[i]<=b[j])
	            i++;
	    }
	    sort(a,a+n);
	    sort(b,b+m);
	}
