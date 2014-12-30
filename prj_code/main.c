#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "oper_list.h"


/*
	verify the double-calc link list
*/
int main()
{
	PDLINK pDLinkHead = NULL;
	int iRet = 0;

	iRet = Init_List(&pDLinkHead);
	if(0 != iRet)
	{
		printf("%s\n", "Init list error");
		return 1;
	}
	
	Print_List(pDLinkHead);
	int *a1 = (int *)malloc(sizeof(int));
	int *a2 = (int *)malloc(sizeof(int));
	int *a3 = (int *)malloc(sizeof(int));
	int *a4 = (int *)malloc(sizeof(int));
	*a1 = 1; *a2 = 2; *a3 = 3; *a4 = 4;
	AddElem_List(pDLinkHead, a1);
	AddElem_List(pDLinkHead, a2);
	AddElem_List(pDLinkHead, a3);
	AddElem_List(pDLinkHead, a4);
	
	Print_List(pDLinkHead);

	printf("the list length=%d\n", GetLength_List(pDLinkHead));
	
	DelNodeByIndex_List(pDLinkHead, 2);
	Print_List(pDLinkHead);
	
//	DelNodeByIndex_List(pDLinkHead, 2);
//	Print_List(pDLinkHead);

	DelNodeByIndex_List(pDLinkHead, 1);
	Print_List(pDLinkHead);

	PDLINK cur_test = GetElem_List(pDLinkHead, 1);
/*
	if(NULL == cur_test)
	{
		printf("the index=1 is NULL\r\n");
	}else{
		printf("the index=1 is %d \r\n", *(int *)(cur_test->element));	
	}
*/	
	cur_test = GetElem_List(pDLinkHead, 0);
	if(NULL == cur_test)
	{
		printf("the index=1 is NULL\r\n");
	}else{
//		printf("the index=1 is %d \r\n", cur_test->element);	
	}

	Clear_List(pDLinkHead);
}
