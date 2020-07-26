#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;
        
     public:
        Node()
        {
            key=0;
            data=0;
            next=NULL;
        }
        Node(int k,int d)
        {
            key= k;
            data =d;
        }   
};

class SinglyLinkedList{
    public:
        Node* head;

        SinglyLinkedList()
        {
            head=NULL;
        }

        SinglyLinkedList(Node* n)
        {
            head=n;
        }

        // 1. Check if node exists using key value 

        Node* nodeExists(int k)
        {
            Node* temp = NULL;
            
            Node* ptr = head;
            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr = ptr->next;
            }
            return temp;

            // So this function returns NULL if key is absent 
            // otherwise it will return the address of Node which has same key 
        }

        // 2. Append a node to the list 

        void appendNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node already exists with key value : "<<n->key<<". Append another node with different key value"<<endl;
            }
            else 
            {
                if(head==NULL)
                {
                    head = n;
                    cout<<"Node appended and this is first node in the list\n";
                }
                else 
                {
                    Node* ptr = head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next=n;
                    cout<<"Node Appended"<<endl;
                }
            }
        }

        // 3. Prepend Node -> Attach a node at the start 

        void prependNode(Node* n)
        {
             if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node already exists with key value : "<<n->key<<". Append another node with different key value"<<endl;
            }
            else 
            {
                n->next=head;
                head = n;
            }
        }

        // 4. Insert a Node after a particular node in the list 
        // argument of this function will take key value of the node after which we have to insert the node 
        // and 2nd argument will be address of NODE which is to be inserted 
        
        void insertNodeAfter( int k,Node *n)
        { 
            Node* ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout<<"no node exists with key value\n";
            }
            else
            {
                if(nodeExists(n->key)!=NULL)
                {
                    cout<<"Node already exists with key value : "<<n->key<<". Append another node with different key value"<<endl;
                }
                else 
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout<<"Node inserted\n";
                }
            }   
        }

        // 5. delete node by unique key 

        void deleteNodeByKey(int k)
        {
            if(head==NULL)
            {
                cout<<"Singly Linked is already empty. can't delete\n";
            }
            else if(head!=NULL)
            {
                if(head->key==k)
                {
                    head=head->next;
                    cout<<"Node Unlinked with key value :- "<<k<<endl;
                }
                else 
                {
                    Node *temp=NULL;
                    Node *prevptr=head;
                    Node *currentptr=head->next;
                    while(currentptr!=NULL)
                    {
                        if(currentptr->key==k)
                        {
                            temp=currentptr;
                            currentptr=NULL;
                        }
                        else
                        {
                           prevptr = prevptr->next;
                           currentptr = currentptr->next;
                        }
                    }
                    if(temp!=NULL)
                    {
                        prevptr->next=temp->next;
                        cout<<"Node unlinked with key value :- "<<k<<endl;
                    }
                    else 
                    {
                        cout<<"Node Does'nt exist with key value :- "<<k<<endl;
                    } 
                }   
            }
        }

        // 6. update node by key 
        void updateNodeByKey(int k,int d)
        {
            Node* ptr = nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node data updated successfully\n";
            }
            else 
            {
                cout<<"Node Does'nt exists with key value\n";
            }
        }

        // 7. printing 

        void printList()
        {
            if(head==NULL)
            {
                cout<<"No Nodes in the list\n";
            }
            else
            {
                cout<<endl<<"data in singly linked lists are : ";
                Node* temp = head;
                while (temp!=NULL)
                {
                   cout<<"("<<temp->key<<","<<temp->data<<") -->";

                   temp=temp->next;
                }
                
            }
            
        }
};



  
int main()
{
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do
    {
        /* code */
        cout<<"\n\nwhat operation do you want to perform ? Select Option number. Enter 0 to exit.\n";
        cout<<"1.appendNode()\n";
        cout<<"2.prependNode()\n";
        cout<<"3.insertNodeAfter()\n";
        cout<<"4.deleteNodeByKey()\n";
        cout<<"5.updateNodeByKey()\n";
        cout<<"6.print()\n";
        cout<<"7.clear Screen\n\n";

        cin>>option;
        Node* n1 = new Node();

        switch (option)
        {
        case 0:

            break;
        
        case 1:
            cout<<"Append Node operation \n Enter key & data of the node to be appended\n";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appendNode(n1); 
            break;
        
        case 2:
            cout<<"Prepend Node operation \n Enter key & data of the node to be Prepend\n";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prependNode(n1);
            break;
        
        case 3:
            cout<<"Insert Node After operation\n Enter key of existing Node after which you want to insert this new Node :\n";
            cin>>k1;
            cout<<"Enter Key & data of the node which is to be inserted :\n";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;


            s.insertNodeAfter(k1,n1);
            break;
        
        case 4:
            cout<<"delete node by key operation -\nEnter key of the Node to be deleted\n";
            cin>>k1;

            s.deleteNodeByKey(k1);
            break;
        
        case 5:
            cout<<"Update Node by key operation -\nEnter key & new-data => which is to be updated"<<endl;
            cin>>key1;
            cin>>data1;

            s.updateNodeByKey(key1,data1);
            break;
        
        case 6:
            s.printList();
            break;
        
        case 7:
            system("cls");
            break;
    
        default:
            cout<<"Enter proper option number\n";
        }
    } while (option!=0);
    return 0;
}
