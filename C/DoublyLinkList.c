#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d->",Head->data);
		Head = Head->next;
	}
	printf("\n");
}

int Count(PNODE Head)
{
	int iCnt=0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn=NULL;
	
	//1. Allocate the memory
	newn = (PNODE)malloc(sizeof(NODE));
	
	//2. Initialize the memory
	newn->data = no;
	newn->next=NULL;
	newn->prev=NULL;
	
	//3.Insert node
	if((*Head) == NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->next=*Head;
		(*Head)->prev=newn;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head,int no)
{
	PNODE temp = *Head;
	PNODE newn=NULL;
	
	//1.Allocate memory
	newn = (PNODE)malloc(sizeof(NODE));
	
	//2.Initialize memory
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	//3. Insert node
	if((*Head) == NULL)
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
		newn->prev = temp;
	}
	
}

void InsertAtPos(PPNODE Head, int No, int iPos)
{
	int iSize = 0,i=0;
	PNODE temp=*Head,newn;
	
	iSize = Count(temp);
	if((iPos < 1) || (iPos > iSize+1)) //filter
	{
		printf("Invalid position!!\n");
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(Head,No);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(Head,No);
	}
	else
	{
		//1. allocate memory
		newn = (PNODE)malloc(sizeof(NODE));
	
		//2. Initialize the memory
		newn->data=No;
		newn->next = NULL;
		newn->prev = NULL;
	
		// 3. Insert node
		for(i=1 ; i < iPos-1 ; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->prev = temp;
		temp->next = newn;
		newn->next->prev = newn;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head == NULL)
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
		*Head = (*Head)->next;
		(*Head)->prev = NULL;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	
	if(*Head == NULL)
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
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp = temp->prev;
		free(temp->next);
		temp->next = NULL;
	}
}

void DeleteAtPos(PPNODE Head , int iPos)
{
	int size=0,i=0;
	PNODE temp=*Head , temp1;
	
	size = Count(*Head);
	
	if((iPos < 1) || (iPos > size+1))
	{
		printf("Invalid position!!\n");
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if(iPos == size)
	{
		DeleteLast(Head);
	}
	else
	{
		for(i=1 ; i<(iPos-1) ; i++)
		{
			temp = temp->next;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		temp1->next->prev = temp;
		free(temp1);
	}
}

int main()
{
	PNODE first=NULL;
	int iRet = 0;
	
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	InsertLast(&first, 51);
	
	InsertAtPos(&first, 55 , 3);
	Display(first);
	//iRet = Count(first);
	//printf("Number of nodes present in linkedlist are %d\n",iRet);
	DeleteAtPos(&first , 4);
	//DeleteFirst(&first);
	//DeleteLast(&first);
	Display(first);
	
	return 0;
}

