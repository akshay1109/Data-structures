#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head , int no)
{
	PNODE newn = NULL;
	
	// 1. Allocate the memory
	newn = (PNODE)malloc(sizeof(NODE));
	
	// 2. Initialize the memory
	newn->data = no;
	newn->next = NULL;
	
	//3. Insert the node
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head, int no)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	// 1. Allocate the memory
	newn = (PNODE)malloc(sizeof(NODE));
	
	//2. Initialize the memory
	newn->data = no;
	newn->next = NULL;
	
	//3. Insert the node
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head != NULL)
	{
		*Head = (*Head)->next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	
	if((*Head) == NULL) // LL is empty
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		*Head = NULL;
		free(temp);
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d->",Head->data);
		Head = Head->next;
	}
}

int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}

void InsertAtPos(PPNODE Head, int no, int iPos)
{
	PNODE temp=*Head,newn;
	int size=0,i=0;
	
	size = Count(*Head);
	
	if((iPos < 1) || (iPos > size+1))
	{
		printf("\nInvalid Position.");
		return;
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn->data=no;
		newn->next = NULL;
		
		for(i=1; i < iPos-1 ; i++)
		{
			temp = temp->next;
		}
		newn->next=temp->next;
		temp->next = newn;
	}
}

void DeleteAtPos(PPNODE Head, int iPos)
{
	PNODE temp = *Head,temp1;
	int size = 0,i=0;
	
	size = Count(*Head);
	if((iPos < 1) || (iPos > size+1))
	{
		printf("\nInvalid Position.\n");
		return;
	}
	else
	{
		if(iPos == 1)
		{
			*Head = (*Head)->next;
			free(temp);
		}
		else if(iPos == size)
		{
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
		}
		else
		{
			for(i=1 ; i < iPos-1 ; i++)
			{
				temp = temp->next;
			}
			temp1 = temp->next;
			temp->next = temp1->next;
			free(temp1);
		}
	}
}

int main()
{
	PNODE first = NULL;
	int count = 0;
	
	InsertFirst(&first , 51);
	InsertFirst(&first , 21);
	InsertFirst(&first , 11);
	
	InsertLast(&first , 61);
	InsertAtPos(&first, 55, 4);
	
	Display(first);
	printf("\n");
	DeleteAtPos(&first , 2);
	//DeleteFirst(&first);
	//DeleteLast(&first);
	
	Display(first);
	count = Count(first);
	printf("\nNumber of nodes present in LinkList are %d",count);
	
	return 0;
}

/*
void InsertFirst(PPNODE Head, int no);
void InsertLast(PPNODE Head, int no);
void InsertAtPos(PPNODE Head, int no, int iPos);

void DeleteFirst(PPNODE Head);
void DeleteLast(PPNODE Head);
void DeleteAtPos(PPNODE Head , int iPos);

void Display(PPNODE Head);
int Count(PPNODE Head);
*/
