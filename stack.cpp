#include<iostream>
using namespace std;
class Stack
{
	private:
		int arr[100],n,top;
	public:
		Stack(int x){
			n=x;
			top=-1;
		}
		void push(int x){
			if(top==n-1){
				cout<<"Stack Overflow";		
			}else{
				top++;
				arr[top]=x;
			}

		}
		int pop(){
			int dataout;
			if(top==-1)
			{
				cout<<"Stack Underflow";
			}else{
				dataout=arr[top];
				top--;
			}
			return dataout;
		}
		int stacktop()
		{
			int dataout;
			if(top==-1)
			{
				cout<<"Underflow";
			}
			else{
				dataout=arr[top];
			}
			return dataout;

		}
		bool isempty()
		{
				if(top==-1)
				{
					return true;
				}
				else
					return false;
		}
		bool isfull()
		{
			if(top==n-1)
				return true;
			else
				return false;

		}
		void display()
		{	
			if(isempty())
			{
				cout<<"Stack is Empty"<<endl;
			}
			else{
				for(int i=top;i>=0;i--)
				{
					cout<<arr[i]<<endl;
				}
			}
				
		}

};
int main()
{
		int n,data,choice;
		cout<<"Enter the Stack Size:"<<endl;
		cin>>n;
		Stack s1(n);
		do{
			cout<<"1.push \n 2.pop \n 3.stacktop \n 4.isempty \n 5.isfull \n 6.Display \n 7.exit "<<endl;
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
					data=s1.pop();
					cout<<data<<endl;
					break;
				case 3:
					data=s1.stacktop();
					cout<<data<<endl;
					break;
					`
				case 4:
					if(s1.isempty())
						cout<<"Stack is empty"<<endl;
					else 
						cout<<"Stack is not empty"<<endl;
					break;
				case 5:
					if(s1.isfull())
						cout<<"Stack is full"<<endl;
					else
						cout<<"Stack is not full"<<endl;
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
