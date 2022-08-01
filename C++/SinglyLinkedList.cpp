#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;
}NODE, * PNODE;

class SinglyLL
{
private:
	PNODE first;
	int size;
		
public:
	SinglyLL()
	{
		first = NULL;
		size = 0;
	}
	
	void InsertFirst(int no)
	{
		PNODE newn = new NODE;
		
		newn->data = no;
		newn->next = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn->next = first;
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
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
		}
		size++;
	}
	
	void InsertAtPos(int no, int iPos)
	{	
		if((iPos < 1) || (iPos > size+1))
		{
			cout<<"Invalid position";
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
			PNODE temp = first;
			PNODE newn = new NODE;
			int i=0;
			
			newn->data = no;
			newn->next = NULL;
			
			for(i=1 ; i < iPos-1 ; i++)
			{
				temp = temp->next;
			}
			newn->next = temp->next;
			temp->next = newn;
			
			size++;
		}
	}
	
	void DeleteFirst()
	{
		PNODE temp = first;
		
		if(first != NULL)
		{
			first = first->next;
			delete temp;
		}
		size--;
	}
	
	void DeleteLast()
	{
		PNODE temp = first;
		
		if(first == NULL)
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
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			
			delete temp->next;
			temp->next = NULL;
		}
		size--;
	}
	
	void DeleteAtPos(int iPos)
	{
		if((iPos < 1) || (iPos > size))
		{
			cout<<"Invalid position";
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
			PNODE temp = first, temp1=NULL;
			int i=0;
			for(i=0 ; i<iPos-1 ; i++)
			{
				temp = temp->next;
			}
			temp1 = temp->next;
			temp->next = temp1->next;
			delete temp1;
			
			size--;
		}
	}
	
	void Display()
	{
		PNODE temp = first;
		int i=0;
		for(i=1 ; i<=size; i++)
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
	SinglyLL obj;
	int iRet = 0;
	
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.InsertLast(101);
	obj.InsertAtPos(61,4);
	obj.Display();
	
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.DeleteAtPos(2);
	obj.Display();
	iRet = obj.Count();
	cout<<"Number of elements in linkedlist are "<<iRet;
	
	return 0;
}
