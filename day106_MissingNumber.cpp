/*
 * =====================================================================================
 *
 *       Filename:  day106_MissingNumber.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 12:04:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int *findTwoElement(int *a, int n) {
        // code here
        int *b=new int[2];
        int p=0;
        for(int i=0;i<n;i++)
        {
            while(a[i]!=i+1 && a[i]!=a[a[i]-1])
            {
                p=a[a[i]-1];
                a[a[i]-1]=a[i];
                a[i]=p;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]!=i+1){
                b[0]=a[i];
                b[1]=i+1;
                return b;
            }
        }
        return b;
    }
