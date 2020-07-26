#include<iostream>
using namespace std;

class circularQueue{
    private:
        int front;
        int rear;
        int arr[5];
        int itemCount;

    public:
        circularQueue()
        {
            front=-1;
            rear=-1;
            itemCount=0;
            for(int i=0;i<5;i++)
                arr[i]=0;
        }
        bool isEmpty()
        {
            if(front==-1 && rear==-1)
                return true;
            else
                return false;    
        }
        bool isFull()
        {
            if((rear+1)%5==front)
                return true;
            else
                return false;   
        }

        void enqueue(int val)
        {
            if(isFull())
                return;
            else if(isEmpty())
            {
                rear=0;
                front=0;
                arr[rear]=val;
            }
            else
            {
                rear=(rear+1)%5;
                arr[rear]=val;
            }
            itemCount++;    
        }

        int dequeue()
        {
            int x=0;
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return x;
            }
            else if(front == rear)
            {
                x=arr[front];
                front=-1;
                rear=-1;
                itemCount--;
                return x;
            }
            else
            {
              x=arr[front];
              arr[front]=0;
              front=(front+1)%5;
              itemCount--;
              return x;  
            }  
        }
        
        
        int count()
        {
            return (itemCount);
        }

        void display()
        {
            cout<<"Elements in the Circular-Queue are -\n";
            for(int i=0;i<5;i++)
                cout<<arr[i]<<" ";
        } 


};

int main()
{
    circularQueue q1;
    int option,value;
    do
    {
        /* code */
        cout<<"\n\nwhat operation do you want to perform ? Select Option number. Enter 0 to exit.\n";
        cout<<"1.EnQueue()\n";
        cout<<"2.DeQueue()\n";
        cout<<"3.isEmpty()\n";
        cout<<"4.isFull()\n";
        cout<<"5.count()\n";
        cout<<"6.display()\n";
        cout<<"7.clear Screen\n\n";

        cin>>option;

        switch (option)
        {
        case 0:
            break;
        
        case 1:
            cout<<"EnQueue Operation \n Enter an item to EnQueue in the Queue\n";
            cin>>value;
            q1.enqueue(value);
            break;
        
        case 2:
            cout<<"DeQueue Operation \nDequeued Value : "<<q1.dequeue()<<endl;
            break;
        
        case 3:
            if(q1.isEmpty())
                cout<<"Circular-Queue Is Empty\n";
            else
            {
                cout<<"Circular-Queue is not empty\n";
            }   
            break;
        
        case 4:
            if(q1.isFull())
                cout<<"Circular-Queue Is Full\n";
            else
            {
                cout<<"Circular-Queue is not Full\n";
            }   
        
            break;
        
        case 5:
            cout<<"Count operation \nCount of items in Circular-Queue : "<<q1.count()<<endl;
            break;
        
        case 6:
            cout<<"Display function Callled - "<<endl;
            q1.display();
            break;
        
        case 7:
            system("cls");
            break;
    
        default:
            cout<<"Enter proper option number\n";
            break;
        }
    } while (option!=0);
    
    return 0;
}