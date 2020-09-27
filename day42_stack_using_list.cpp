/*
 * =====================================================================================
 *
 *       Filename:  day42_stack_using_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 03:01:49 AM
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
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};
/*78 -1 -1 93 -1 60 68 24 31 12 70 23 30 12 73 25 57 82 71 30 6 65 4 69 95 27 68 35 87 2 53 30 20 18 61 100 89 77 88 */
/* And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

/* The method push to push element
   into the stack */
void MyStack ::push(int x) {
    // Your Code
    StackNode *temp=new StackNode(x);
    if(top==NULL)
    {
        top=temp;
        return;
    }
    //next two line was my mistake at first since i was not keeping account of how to get top next so in my case top next is null and top prev is ryt ans 
    temp->next=top;
    top=temp;
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    // Your Code
    if(top==NULL)
        return -1;
    int x=top->data;
    top=top->next;
    return x;
}

