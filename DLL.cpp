#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
} ;
struct header
{
    int count;
    node *front;
    node *rear;
};
class DLL
{
        private:
            node *pnew,*pred,*succ,*temp;
            header *list;
        public:
            DLL()
            {
                list = new header;
                list->count=0;
                list->front=NULL;
                list->rear=NULL;
            }
            void insertnode(int x)
            {
                pnew=new node;
                if(pnew==NULL)
                {
                    cout<<"Memory Full";
                    return;
                }
                bool found=search(x);
                if(found)
                {
                    cout<<"Duplicate Can't Insert";
                    return;
                }
                pnew->data=x;
                if(pred==NULL)
                {
                    pnew->prev=NULL;
                    pnew->next=list->front;
                    list->front=pnew;

                }
                else
                {
                    pnew->next=succ;
                    pnew->prev=pred;
                    pred->next=pnew;
                   
                }
                 if(succ==NULL)
                    {
                        list->rear=pnew;
                    }
                    else
                    {
                        succ->prev=pnew;
                    }
                list->count++;
            }
            void deletenode(int x)
            {
                if(isempty())
                {
                    cout<<"List is Empty"<<endl;
                    return;
                }
                bool found=search(x);
                if(!found)
                {
                    cout<<"Data Not found in the List"<<endl;
                    return;
                }
                temp=succ;
                if(pred==NULL)
                {
                    list->front=succ->next;
                }
                else
                {
                    pred->next=succ->next;
                    if(succ->next==NULL)
                    {
                        list->rear=pred;
                    }
                    else
                    {
                        succ->next->prev=pred;
                    }

                }
                delete temp;
                list->count--;
            }
        bool search(int target)
        {
            pred=NULL;
            succ=list->front;
            while(succ!=NULL && succ->data <target)
            {
                pred=succ;
                succ=succ->next;
            }
            if(succ==NULL)
            {
                return false;
            }
            else
            {
                if(succ->data==target)
                    return true;
                else 
                    return false;
            }
        }
       bool isempty()
        {
            if(list->count==0)
                return true;
            else
                return false;
        }
        void displayFromFront()
        {
            if(isempty())
            {
                cout<<"List is empty";
                return;
            }
            temp=list->front;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
        void displayFromRear()
        {
            if(isempty())
            {
                cout<<"List is empty";
                return;
            }
            temp=list->rear;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->prev;
            }
        }
        ~DLL()
        {
             temp=list->front;
             while(temp!=NULL)
             {
                list->front=temp->next;
                cout<<temp->data<<"is deleted"<<endl;
                delete temp;
                list->count--;
                temp=list->front;
             }
            delete list;
        }

};
int main()
{
    DLL s1;
    int choice,data;
    do{
			cout<<"1.Insertion \n 2.Deletion \n 3.Search \n 4.isempty \n 5.Display from front \n 6.Display from rear \n 7.exit "<<endl;
			cout<<"Enter choice";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"Enter Data to Enter:";
					cin>>data;
					s1.insertnode(data);
					break;
				case 2:
					cout<<"Enter Data to Delete:";
                    cin>>data;
                    s1.deletenode(data);
					break;
				case 3:
					cout<<"Enter Data to search:";
                    cin>>data;
                    if(s1.search(data))
                        cout<<"Data Present in the List"<<endl;
                    else
                        cout<<"Data not Found in the List"<<endl;
					break;
				case 4:
					if(s1.isempty())
						cout<<"Sll is empty"<<endl;
					else 
						cout<<"SLL is not empty"<<endl;
					break;
				case 5:
					s1.displayFromFront();
                    break;
				case 6:
					s1.displayFromRear();
					break;
				case 7:
					break;
				default:
					cout<<"Invalid choice"<<endl;
					break;

			}

		}while(choice!=7);
}
