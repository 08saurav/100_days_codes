/*
 * =====================================================================================
 *
 *       Filename:  day50_circular_tour.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2020 02:49:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
//   int prefix[n];
//   for(int i=0;i<n;i++)
//         prefix[i]=0;
    long long sum1=p[0].petrol-p[0].distance;
    long long sum=sum1;
    int idx=-1;
    bool flag=true;
    if(sum>0){
        idx=0;
        flag=false;
    }
    if(sum<0)
    {
        sum=0;
        sum1=0;
        // flag=true;
    }
    
   for(int i=1;i<n;i++)
   {
    //   cout << p[i].petrol << " " << p[i].distance << " " << sum1<< idx<<endl;
        if(sum1<0)
            sum1=0;
        sum+=p[i].petrol-p[i].distance;
        sum1=p[i].petrol-p[i].distance+sum1;
        if(sum1>0 && flag){
            idx=i;
            flag=false;
        }
        else if(sum1<0){
            idx=-1;
            flag=true;
        }
        
        // cout << flag << " ";
   }
   if(sum>0)
        return idx;
    else
        return -1;
}
/*--------------smart Solution ------------------------*/
// int tour(petrolPump p[],int n)
// {
//   //Your code here
//   int start=0,deficit=0;
//   int capacity=0;
   
//   for(int i=0;i<n;i++)
//   {
//       capacity+=p[i].petrol-p[i].distance;
//       if(capacity<0){
//           start=i+1;
//           deficit+=capacity;
//           capacity=0;
//       }
//   }
//   return(capacity+deficit>0)?start:-1;
// }

