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
    node *top;
};
class StackSll
{
    private:
        header *stack;
        node *pnew,*temp;
    public:
        StackSll()
        {
            stack=new header;
            stack->count=0;
            stack->top=NULL;
        }
        void push(int x)
        {
            pnew=new node;
            if(pnew==NULL)
            {
                cout<<"Memory full";
                return;
            }
            pnew->data=x;
            pnew->next=stack->top;
            stack->top=pnew;
            stack->count++;
        }
        void pop()
        {
            if(isempty())
            {
                cout<<"Stack is Empty"<<endl;
                return;
            }
            cout<<stack->top->data<<"is deleted"<<endl;
            stack->top=stack->top->next;
            stack->count--;
        }
        void display()
        {
             if(isempty())
            {
                cout<<"Stack is Empty"<<endl;
                return;
            }
            temp=stack->top;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
        void stacktop()
        {
              if(isempty())
            {
                cout<<"Stack is Empty"<<endl;
                return;
            }
            cout<<stack->top->data;
        }
        bool isempty()
        {
            if(stack->count==0)
                return true;
            else 
                return false;
        }
        ~StackSll()
        {
            temp=stack->top;
            while(temp!=NULL)
            {
                    stack->top=temp->next;
                    cout<<temp->data<<"is deleted"<<endl;
                    delete temp;
                    temp=stack->top;
            }
            delete temp;
            delete pnew;
            delete stack;
        }

};
int main()
{
    StackSll s1;
    int choice,data;
    do{
			cout<<"1.Push \n 2.pop \n 3.Stacktop \n 4.isempty  \n 5.Display \n 6.exit "<<endl;
			cout<<"Enter choice";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"Enter Data to Enter:";
					cin>>data;
					s1.push(data);
					break;
				case 2:
                    s1.pop();
					break;
				case 3:
					s1.stacktop();
					break;
				case 4:
					if(s1.isempty())
						cout<<"Stack is empty"<<endl;
					else 
						cout<<"Stack is not empty"<<endl;
					break;
				case 5:
					s1.display();
					break;
				case 6:
					break;
				default:
					cout<<"Invalid choice"<<endl;
					break;

			}

		}while(choice!=6);
}
