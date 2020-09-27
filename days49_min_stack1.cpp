/*
 * =====================================================================================
 *
 *       Filename:  days49_min_stack1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 10:09:40 PM
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
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty())
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
    if(s.empty())
        return -1;
    // s.pop();
    // int x=s.top();
    // s.pop();
    // if(!s.empty())
    //     minEle=s.top();
    // return x;
    int t=s.top();
    s.pop();
    if(t<minEle){
        int prev=minEle;
        minEle=2*minEle-t;
        return prev;
    }
    return t;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty()){
        minEle=x;
        s.push(x);
    }
    else if(minEle>x){
        s.push(2*x-minEle);
        minEle=x;
    }
    else 
        s.push(x);
    // s.push(minEle);
   //Your code here
}

