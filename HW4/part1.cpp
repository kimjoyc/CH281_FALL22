/*
Problem 1:
In a particular game, n participants decide to arrange themselves in a circle
in positions numbered from 0 to n-1.

The game goes as follows: Start-ing from a given participant, a judge starts counting participants and re-
moves the m-th person from the cirle. Then, the judge starts counting
again going around the circle until only one participant, the winner, is
left. 

Write a C++ program that takes n and m as integers and determines which position corresponds to the only player remaining in the game.


HINT: Use a circular queue where after all the participants are added, the head is connected to the tail.

*/

#include<iostream>
#include <climits>
using namespace std;
  
class Queue
{
    int tail, head;
    int size;
    int *arr;


public:
    Queue(int size_)
    {
       head = tail = -1;
       size = size_;
       arr = new int[size_];
    }


    void intake_queue(int value);
    int delete_queue();
    void show_queue();
};
  
  
void Queue::intake_queue(int value)
{
    if ((head == 0 && tail == size-1)||(tail == (head-1)%(size-1)))
    {
        printf("\n queue full");
        return;
    }
  
    else if (head == -1) 
    {
        head = tail = 0;
        arr[tail] = value;
    }
  
    else if ((tail == size-1) && (head != 0))
    {
        tail = 0;
        arr[tail] = value;
    }
  
    else
    {
        tail++;
        arr[tail] = value;
    }
}
  
int Queue::delete_queue()
{
    if (head == -1)
    {
        printf("\n queue empty");
        return INT_MIN;
    }
  
    int data = arr[head];
    arr[head] = -1;
    if (head == tail)
    {
        head = -1;
        tail = -1;
    }
    else if (head == size-1)
        head=0;
    else
        head++;
  
    return data;
}

void Queue::show_queue()
{
    if (head == -1)
    {
        printf("\nempty queue");
        return;
    }
    printf("\ncircular queue elems are ");
    if (tail >= head)
    {
        for (int i = head; i <= tail; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = head; i < size; i++)
            printf("%d ", arr[i]);
  
        for (int i = 0; i <= tail; i++)
            printf("%d ", arr[i]);
    }
}
  
int main()
{
    Queue qwee(5);
    int arr[5]={1,2,3,4,5};
    for(int i=0;i<5;i++)
        {
            qwee.intake_queue(arr[i]);
            qwee.show_queue();
        }
    qwee.delete_queue();



    return 0;
}