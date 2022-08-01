#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;
	struct node * prev;
}NODE, * PNODE;

class DoublyLinkList
{
	private:
		PNODE first;
		int size;
	public:
		DoublyLinkList()
		{
			first = NULL;
			size = 0;
		}
		
		void InsertFirst(int no)
		{
			PNODE newn = new NODE;
			
			newn->data = no;
			newn->next = NULL;
			newn->prev = NULL;
			
			if(size == 0)
			{
				first = newn;
			}
			else
			{
				newn->next = first;
				first->prev = newn;
				first = newn;
			}
			size++;
		}
		
		void InsertLast(int no)
		{
			PNODE temp = first;
			PNODE newn = new NODE;
			
			newn->data = no;
			newn->next = NULL;
			newn->prev = NULL;
			
			if(size == 0)
			{
				first = newn;
			}
			else if(first->next == NULL)
			{
				first->next = newn;
				newn->prev = first;
			}
			else
			{
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newn;
				newn->prev = temp;
			}
			size++;
		}
		
		void InsertAtPos(int no , int iPos)
		{
			if((iPos < 1) || (iPos > size+1))
			{
				cout<<"Invalid position\n";
				return;
			}
			
			if(iPos == 1)
			{
				InsertFirst(no);
			}
			else if(iPos == size+1)
			{
				InsertLast(no);
			}
			else
			{
				PNODE newn = new NODE;
				PNODE temp = first;
				int i=0;
				
				newn->data = no;
				newn->next = NULL;
				newn->prev = NULL;
				
				for(i=1 ; i<iPos-1 ; i++)
				{
					temp = temp->next;
				}
				newn->next = temp->next;
				newn->next->prev = newn;
				temp->next = newn;
				newn->prev = temp;
				
				size++;
			}
		}
	
		void DeleteFirst()
		{
			PNODE temp = first;
			
			if(first == NULL)
			{
				return;
			}
			else
			{
				first = first->next;
				first->prev = NULL;
				delete temp;
			}
			size--;
		}
		
		void DeleteLast()
		{
			if(size == 0)
			{
				return;
			}
			else if(first->next == NULL)
			{
				delete first;
				first = NULL;
			}
			else
			{
				PNODE temp = first;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp = temp->prev;
				
				delete temp->next;
				temp->next = NULL;
			}
			size--;
		}
		
		void DeleteAtPos(int iPos)
		{
			if((iPos < 1) || (iPos > size))
			{
				cout<<"Invalid position\n";
				return;
			}
			
			if(iPos == 1)
			{
				DeleteFirst();
			}
			else if(iPos == size)
			{
				DeleteLast();
			}
			else
			{
				PNODE temp = first,temp1=NULL;
				int i=0;
				
				for(i=1 ; i < iPos-1 ; i++)
				{
					temp = temp->next;
				}
				temp1 = temp->next;
				temp1->next->prev = temp;
				temp->next = temp1->next;
				
				size--;
			}
		}
		
		void Display()
		{
			PNODE temp = first;
			int i = 0;
			for(i=1 ; i <= size ; i++)
			{
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"\n";
		}
		
		int Count()
		{
			return size;
		}
};

int main()
{
	DoublyLinkList obj;
	int iRet = 0;
	
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	
	obj.InsertAtPos(31,3);
	obj.InsertAtPos(61,5);
	obj.Display();
	
	//obj.DeleteFirst();
	//obj.DeleteLast();
	obj.DeleteAtPos(6);
	obj.Display();
	iRet = obj.Count();
	cout<<"Number of elements in linked list are "<<iRet<<"\n";
	return 0;
}