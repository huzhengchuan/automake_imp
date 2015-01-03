#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "oper_list.h"


typedef struct _DLINK{
	void * element;
	struct _DLINK *pre;
	struct _DLINK *next;
}DLINK, *PDLINK;

typedef struct _OperDLink{
	const char *oper_name;
	int  (*oper_action)(PDLINK pDLinkHead, void *context);
}OperDLink;


static int oper_sum(PDLINK pDLinkHead, void *context);
static int oper_max(PDLINK pDLinkHead, void *context);
static int oper_print(PDLINK pDLinkHead, void *context);


OperDLink mOper[] = {
	{"sum", oper_sum},
	{"max", oper_max},
	{"print", oper_print},
};


/*
	print the double-calc link list
	return: 0 -> ok
			other -> failed
*/
static int oper_print(PDLINK pDLinkHead, void *context)
{
	if(NULL == pDLinkHead)
	{
		return 1;
	}

	printf("oper print begin\r\n");
	PDLINK cur = pDLinkHead->next;

	printf("The link list is\r\n");
	while(cur != pDLinkHead)
	{
		(((OperContext *)context)->oper)(cur->element, ((OperContext *)context)->result);
		cur = cur->next;
	}
	printf("\r\n");
	printf("oper print end\r\n");
	return 0;
}
static int oper_sum(PDLINK pDLinkHead, void *context)
{
	if(NULL == pDLinkHead)
	{
		return 1;
	}

	printf("oper sum begin\r\n");
	PDLINK cur = pDLinkHead->next;

	while(cur != pDLinkHead)
	{
		(((OperContext *)context)->oper)(cur->element, ((OperContext *)context)->result);
		cur = cur->next;
	}
	printf("oper sum end\r\n");
	return 0;
}

static int oper_max(PDLINK pDLinkHead, void *context)
{
	if(NULL == pDLinkHead)
	{
		return 1;
	}

	printf("oper max begin\r\n");
	PDLINK cur = pDLinkHead->next;

	while(cur != pDLinkHead)
	{
		(((OperContext *)context)->oper)(cur->element, ((OperContext *)context)->result);
		cur = cur->next;
	}
	printf("oper max end\r\n");
	return 0;
}

/*
	init double-calc link list
	return: int 0 ->ok
			int other ->error
*/
int Init_List(PDLINK *pDLinkHead)
{
	*pDLinkHead = (PDLINK)malloc(sizeof(DLINK));
	if(NULL != *pDLinkHead)
	{
		(*pDLinkHead)->pre = (*pDLinkHead)->next = *pDLinkHead;
		return 0;
	}else{
		return 1;
	}
}

/*
	clearall double-calc link list
	return: int 0 -> ok
			int other -> error
*/
int Clear_List(PDLINK pDLinkHead)
{
	PDLINK pCur = pDLinkHead;
	PDLINK pNext = pDLinkHead->pre;

	while(pCur != NULL)
	{
		pNext = pCur->next;
		pCur->pre->next = NULL;
		free(pCur->element);
		pCur->element = NULL;
		free(pCur);
		pCur = NULL;
		pCur = pNext;
	}
	return 0;
}

/*
	cal the length of  double-calc link list
	return: int len -> the length of double-calc link list
*/
int GetLength_List(PDLINK pDLinkHead)
{
	PDLINK pCur = pDLinkHead;
	int  length = 0;
	
	if(NULL == pDLinkHead)
	{
		return 0;
	}
	while(pCur->next != pDLinkHead)
	{
		length ++;
		pCur = pCur->next; 
	}
	return length;
}

/*
	get the index element in double-calc link list
	return: PDLINK is not null -> ok
			PDLINK is null -> error
*/
PDLINK GetElem_List(PDLINK pDLinkHead, int index)
{
	if(NULL == pDLinkHead || (GetLength_List(pDLinkHead) <= index))
	{
		return NULL;
	}
	int curIndex = 0;
	PDLINK pCur = pDLinkHead->next;

	while(curIndex != index)
	{
		pCur = pCur->next;
		curIndex ++;
	}
	return pCur;

}

/*
	add the element to the tail of double-calc link list
	return: 0 -> ok
			other -> failed
*/
int AddElem_List(PDLINK pDLinkHead, void * elem)
{
	int iRet = 0;
	if(NULL == pDLinkHead)
	{
		iRet = Init_List(&pDLinkHead);
		if((0 != iRet) || (NULL == pDLinkHead))
		{
			return 1;
		}
	}
	
	PDLINK pre = pDLinkHead->pre;
    PDLINK cur = (PDLINK)malloc(sizeof(DLINK));
	if(NULL == cur)
	{
		return 1;	
	}
	cur->element = elem;
	pre->next = cur;
	cur->pre = pre;
	pDLinkHead->pre = cur;
	cur->next = pDLinkHead;
	
	return 0;
}

/*
	delete the element by index in the double-calc link list
	return: 0 -> ok
			other -> failed
*/
int DelNodeByIndex_List(PDLINK pDLinkHead, int index)
{
	if((NULL == pDLinkHead) || (GetLength_List(pDLinkHead) <= index) )
	{
		return 1;
	}
	PDLINK cur = pDLinkHead->next;
	PDLINK pre = pDLinkHead;
	int cur_index = 0;
	
	while(cur_index != index)
	{
		cur = cur->next;
		cur_index++;
	}
	
	pre = cur->pre;
	pre->next = cur->next;
	cur->next->pre = pre;
	free(cur);
	cur = NULL;
	return 0;

}

/*
	delete the element by element in the double-calc link list
	return: 0 -> ok
			other -> failed
*/
int DelNodeByElem_List(PDLINK pDLinkHead, PDLINK pDLinkNode)
{
	
	if(NULL == pDLinkHead)
	{
		return 1;
	}
	PDLINK cur = pDLinkHead->next;
	PDLINK pre = pDLinkHead;
	int cur_index = 0;
	
	while(cur != pDLinkHead)
	{
		cur = cur->next;
		cur_index++;
	}
	
	if( cur == pDLinkHead)
	{
		return 1;
	}
	pre = cur->pre;
	pre->next = cur->next;
	cur->next->pre = pre;
	free(cur);
	cur = NULL;
	return 0;
}


int Oper_List(PDLINK pDLinkHead, char * operName, void *context)
{
	int iLoop = 0;
	int operLen = sizeof(mOper)/sizeof(OperDLink);
	for(iLoop = 0; iLoop < operLen; iLoop++)
	{
		if( 0 == strcmp(mOper[iLoop].oper_name, operName))
		{
				mOper[iLoop].oper_action(pDLinkHead, (void *)context);
		}
	}
}

