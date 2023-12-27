#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct header
{
    int count;
    node *head;
    node *pos;
};
class SLL
{
    private:
        node *pnew,*pred,*ploc,*temp;
        header *plist;
    public:
        SLL()
        {
            plist=new header;
            plist->count=0;
            plist->head=NULL;
            plist->pos=NULL;
        }
        void insertnode(int x)
        {
            bool found=search(x);
            if(found)
            {
                cout<<"Duplicate Can't Insert"<<endl;
                return;
            }
            pnew=new node;
            if(pnew==NULL)
            {
                cout<<"Memory FUll";
                return;
            }
            pnew->data=x;
            if(pred==NULL)
            {
                pnew->next=plist->head;
                plist->head=pnew;
            }
            else
            {
                pnew->next=pred->next;
                pred->next=pnew;
            }
            plist->count++;

        }
        void deletenode(int x)
        {
            if(plist->count==0)
            {
                cout<<"SLL is empty";
                return;
            }
            bool found=search(x);
            if(!found)
            {
                    cout<<"Data Not found on the list";
                    return;
            }
            if(pred==NULL)
            {
                plist->head=ploc->next;
            }
            else
            {
                pred->next=ploc->next;
            }
            plist->count--;

        }
        bool search(int target)
        {
            pred=NULL;
            ploc=plist->head;
            while(ploc!=NULL && ploc->data <target)
            {
                pred=ploc;
                ploc=ploc->next;
            }
            if(ploc==NULL)
            {
                return false;
            }
            else
            {
                if(ploc->data==target)
                    return true;
                else 
                    return false;
            }
        }
        void traverse(){
            if(isempty())
            {
                cout<<"Empty List"<<endl;
                return;
            }
            if(plist->pos==NULL)
            {
                plist->pos=plist->head;
            }
            cout<<"Traversed element:"<<plist->pos->data<<endl;
            plist->pos=plist->pos->next;
            if(plist->pos==NULL)
            {
                cout<<"End of list"<<endl;
                return;
            }
        }
        bool isempty()
        {
            if(plist->count==0)
                return true;
            else
                return false;
        }
        void display()
        {
            temp=plist->head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
        ~SLL()
        {
             temp=plist->head;
             while(temp!=NULL)
             {
                plist->head=temp->next;
                cout<<temp->data<<"is deleted"<<endl;
                delete temp;
                plist->count--;
                temp=plist->head;
             }
            delete plist;
        }
};
int main()
{
    SLL s1;
    int choice,data;
    do{
			cout<<"1.Insertion \n 2.Deletion \n 3.Search \n 4.isempty \n 5.traverse \n 6.Display \n 7.exit "<<endl;
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
					s1.traverse();
                    break;
				case 6:
					s1.display();
					break;
				case 7:
					break;
				default:
					cout<<"Invalid choice"<<endl;
					break;

			}

		}while(choice!=7);
}
