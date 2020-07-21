#include<iostream>
#include<string>
using namespace std;

class stack{
    private:
        int top;
        int arr[5];

    public:
    stack()
    {
        top=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }

    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
        {
            return false;
        }    
    }

      bool isFull()
    {
        if(top==4)
            return true;
        else
        {
            return false;
        }  
    }

    // push method
    void push (int val)
    {
        if(isFull())
            cout<<"stack overflow"<<endl;
        else
        {
            top++;
            arr[top]=val;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow "<<endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count()
    {
        return(top+1);
    }

    int peek(int position)
    {
          if(isEmpty())
        {
            cout<<"stack underflow "<<endl;
            return 0;
        }
        else
        {
            return arr[position];
        }
        
    }

    void change(int position,int value)
    {
        arr[position]=value;
    }

    void display()
    {
        cout<<"elements of stack are "<<endl;

        for(int i=4;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }    
};

int main()
{
    stack s1;
    int option ,positi,value;
    
    do
    {
        cout<<"what option do you want to perform ? Select Option number . Enter 0 to exit"<<endl;
        cout<<"1.Push \n";
        cout<<"2.Pop \n";
        cout<<"3.isEmpty()\n";
        cout<<"4.isFull()\n";
        cout<<"5.peek() \n";
        cout<<"6.count()\n";
        cout<<"7.change()\n";
        cout<<"8.display\n";
        cout<<"9.clear Screen\n\n";

        cin>>option;
        switch (option)
        {
        case 0:
            break;    
        case 1: 
            /* code */
            cout<<"Enter an item to push in the stack"<<endl;
            cin>>value;
            s1.push(value);
            break;
        case 2:
            cout<<"pop function called --- Poped-value : "<<s1.pop()<<endl;
            break;
        case 3:
            if(s1.isEmpty())
                cout<<"Stack is Empty \n";
            else
            {
                cout<<"stack is not empty\n";
            } 
            break;   
        case 4:
             if(s1.isFull())
                cout<<"Stack is Full \n";
            else
            {
                cout<<"stack is not full\n";
            }
            break;  
        case 5:
            cout<<"Enter position of item that you want to peek : "<<endl;
            cin>>positi;
            cout<<"Peek function called - value at position "<<positi<<" is "<<s1.peek(positi)<<endl; 
            break;  
        case 6:
            cout<<"count function called -Number of items in the stack are : "<<s1.count()<<endl;
            break; 
        case 7:
            cout<<"Change function called -\n";
            cout<<"Enter position of item you want to change : ";
            cin>>positi;
            cout<<endl;
            cout<<"Enter value of item that you want to change : ";
            cin>>value;
            s1.change(positi,value);
            break; 
        case 8:
            cout<<"Display function called "<<endl;
            s1.display();
            break; 
        case 9:
            system("cls");
            break;

        default:
            cout<<"Enter proper option number\n";
            break;
        }
    } while (option!=0);

    return 0;
}