#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

    Node()
    {
        key=0;
        data=0;
        next=NULL;
        previous=NULL;

    }
    Node(int k,int d)
    {
        key=k;
        data=d;
    }    
};

class DoublyLinkedList{
    public:
        Node* head;
    
    DoublyLinkedList()
    {
        head=NULL;
    }
    DoublyLinkedList(Node* n)
    {
        head=n;
    }

    // 1. check if node exist using its key value 

    Node* nodeExists(int k)
    {
        Node* temp=NULL;
        Node* ptr=head;

        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
        // so this function will return 
        //adress of element if exists otherwise it will return null
    }  

    // 2. appending a node  
    void appendNode(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"node already exists with this key value"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node appended as head node as this node is first node in the list\n";
            }
            else
            {
                Node* ptr=head;
                while (ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next=n;
                n->previous=ptr;
                cout<<"Node appended\n";
            }
            
        }
        
    }


    // 3. prepend Node -attach a node at the start 
    void prependNode(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"node already exists with this key value please use another node\n";
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"node prepended as head node"<<endl;
            }
            else
            {
                head->previous=n;
                n->next=head;
                head=n;
                cout<<"Node prepended\n";
            }
            
        }
        
    }

    //    4. inserting a node after a particular node 
        // 1st agrument => key of element after which we have to insert
        //2nd argument => Node which is to be inserted 
        
    void insertNodeAfter(int k,Node *n)
    {
        Node* ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"no node exists with key value : "<<k<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"node already exists with key value : "<<n->key<<". append another node with different key value\n";
            }
            else
            {
                cout<<"inserting\n";
                Node* nextNode = ptr->next;
                 
                // nextNode will be equal to NULL if ptr is pointing on last Node 
                // appending at last 

                if(nextNode==NULL)
                {
                    ptr->next = n;
                    n->previous = ptr;
                    cout<<"Node inserted at the end"<<endl;
                }
                else
                {
                    //inserting in between
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;

                    cout<<"Node inserted successfully\n";
                }
                

            }
            
        }
        
    }

    //5. deleting  node by key [ basically d-linking not delete]
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"no node exists with key value: "<<k<<endl;
        }
        else
        {
            if(head->key==k)
            {
                head = head->next;
                cout<<"Node unlinked with key value: "<<k<<endl;
            }
            else
            {
                Node* nextNode = ptr->next;
                Node* prevNode = ptr->previous;
                //deleting at the end
                if(nextNode==NULL)
                {
                    prevNode->next = NULL;
                    cout<<"Node deleted at the end\n"; 
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    
                    cout<<"Node deleted in between"<<endl;
                }
                
            }
        }
    }

    // 6.Update Node by key

    void uopdateNodeByKey(int k,int d)
    {
        Node* ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"Node doesn't exists with key value: "<<k<<endl;
        }
        else
        {
            ptr->data = d;
            cout<<"Node data updated successfully\n";
        }
    }

    // 7. printing 
     
     void printList()
     {
         if(head==NULL)
         {
            cout<<"No node exists in doubly linked list";
         }
         else
         {
            cout<<"]\nDoubly linked list values: ";
            Node* temp = head;
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<") <--> ";
                temp = temp->next;
            }
         }
         
     }

};





int main()
{
    DoublyLinkedList obj;
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
        cout<<"6.printDoublyLinkedLIst()\n";
        cout<<"7.clear Screen\n\n";

        cin>>option;
        Node* n1 = new Node();
        //Node n1
        switch (option)
        {
        case 0:
            break;
        
        case 1:
            cout<<"append Node Operation \nEnter kay and data of the Node to be appended";
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendNode(n1);
            break;
        
        case 2:
            cout<<"prepend node operation \nEnter key & data of the node to be prepended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependNode(n1);
            break;
        
        case 3:
            cout<<"insert node after operation \nEnter key of existing node after which you want to insert this new node: "<<endl;
            cin>>k1;
            cout<<"now enter key and data of the new node which is to be inserted: "<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAfter(k1,n1);
            break;
        
        case 4:
            cout<<"delete node by key operation- \nEnter key of the node to be deleted: "<<endl;
            cin>>k1;
            obj.deleteNodeByKey(k1);
            break;
        
        case 5:
            cout<<"Update Node by key Operation- \nEnter key & NEW data to be updated\n";
            cin>>key1;
            cin>>data1;
            obj.uopdateNodeByKey(key1,data1);
            break;
        
        case 6:
            obj.printList();
            break;
        
        case 7:
            system("cls");
            break;
    
        default:
            cout<<"enter proper option number "<<endl;
            
        }
    } while (option!=0);
    
    return 0;
}
