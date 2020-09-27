/*
 * =====================================================================================
 *
 *       Filename:  day41_queue_using_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2020 02:31:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
//Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode *temp=new QueueNode(x);
        if(front==NULL){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
        // Your Code
     if(front==NULL)
        return -1;
     int x=front->data;
    front=front->next;
    return x;
}

