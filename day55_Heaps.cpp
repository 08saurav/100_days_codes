/*
 * =====================================================================================
 *
 *       Filename:  day55_Heaps.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/06/2020 08:23:50 PM
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
inline int getLeftChildIndex(int parentIndex){ return 2*parentIndex+1;}
inline int getRightChildIndex(int parentIndex){return 2*parentIndex+2;}
inline int getParentIndex(int childIndex){return (childIndex-1)/2;}

inline bool hasLeftChild(int index,int size){return getLeftChildIndex(index)<size;}
inline bool hasRighttChild(int index,int size){return getRightChildIndex(index)<size;}
inline bool hasParent(int index){return getParentIndex(index)>=0;}

inline int leftChild(int index,vector<int>a){ return a[getLeftChildIndex(index)];}
inline int rightChild(int index,vector<int>a){ return a[getRightChildIndex(index)];}
inline int parent(int index,vector<int>a){ return a[getParentIndex(index)];}


void heapyUp(int size,vector<int>&a)
{
		int index=size-1;
		while(hasParent(index)&& parent(index,a)>a[index])
		{
				swap(a[getParentIndex(index)],a[index]);
				index=getParentIndex(index);
		}
}
void heapyDown(vector<int>&a,int size)
{
		int index=0;
		while(hasLeftChild(index,size))
		{
				int smallerChildIndex=getLeftChildIndex(index);
				if(hasRighttChild(index,size) && rightChild(index,a)<leftChild(index,a))
						smallerChildIndex=getRightChildIndex(index);
				if(a[index]<a[smallerChildIndex]){
						break;
				}
				else{
						swap(a[index],a[smallerChildIndex]);
				}
				index=smallerChildIndex;
		}
}
void swap(int *a,int *b)
{
		int temp=*a;
		*a=*b;
		*b=temp;
}
int peek(int size,vector<int>a)
{
		if(size==0)
				return -1;
		return a[0];
}
int poll(int *size,vector<int>&a)
{
	if(size==0)
			return -1;
	int k=a[0];
	a[0]=a[*size-1];
	*size=*size-1;
	a.pop_back();
	heapyDown(a,*size);
	return k;
}
void add(int item,vector<int>&a,int *size)
{
	a.push_back(item);
	*size=*size+1;
	heapyUp(*size,a);
}

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
				int n;
				cin >> n;
				int temp,size=0;
				vector<int>a;
				for(int i=0;i<n;i++){
						cin >> temp;
						int temp1;
						if(temp==0){
							cin >> temp1;
							add(temp1,a,&size);
						}
						else if(temp==1)
								cout << peek(size,a) << " ";
						else if(temp==2)
								cout << poll(&size,a) << " ";
				}
				
		}
}
