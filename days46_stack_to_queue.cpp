/*
 * =====================================================================================
 *
 *       Filename:  days46_stack_to_queue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 05:16:06 PM
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
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        // Your Code
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code    
        if(s2.empty())
        {
            if(s1.empty())
                return -1;
            else
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                int m=s2.top();
                s2.pop();
                return m;
            }
        }
        else{
            int m=s2.top();
                s2.pop();
                return m;
        }
        
}

