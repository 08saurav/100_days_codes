/*
 * =====================================================================================
 *
 *       Filename:  days48_stack_using_queue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 05:32:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code
        if(q1.empty()) return -1;
        int ct=0;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
            ct++;
        }
        int n=0;
        while(n<ct)
        {
            if(n==ct-1){
                int m=q2.front();
                q2.pop();
                return m;
            }
            q1.push(q2.front());
            q2.pop();
            n++;
        }
}
