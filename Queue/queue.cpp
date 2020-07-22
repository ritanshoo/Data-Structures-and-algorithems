#include<iostream>
using namespace std;

class queue{
    private:
        int front;
        int rear;
        int arr[5];

    public:
        queue()
        {
            front=-1;
            rear=-1;
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
            if(rear==4)
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
                rear++;
                arr[rear]=val;
            }    
        }

        int dequeue()
        {
            int x;
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return 0;
            }
            else if(front == rear)
            {
                x=arr[front];
                front=-1;
                rear=-1;
                return x;
            }
            else
            {
              x=arr[front];
              arr[front]=0;
              front++;
              return x;  
            }  
        }
        
        
        int count()
        {
            return (rear - front + 1);
        }

        void display()
        {
            cout<<"Elements in the Queue are -\n";
            for(int i=0;i<5;i++)
                cout<<arr[i]<<" ";
        } 


};

int main()
{
    queue q1;
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
                cout<<"Queue Is Empty\n";
            else
            {
                cout<<"Queue is not empty\n";
            }   
            break;
        
        case 4:
            if(q1.isFull())
                cout<<"Queue Is Full\n";
            else
            {
                cout<<"Queue is not Full\n";
            }   
        
            break;
        
        case 5:
            cout<<"Count operation \nCount of items in Queuee : "<<q1.count()<<endl;
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