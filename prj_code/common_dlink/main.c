#include <stdlib.h>

#include "oper_list.h"


/*
	verify the double-calc link list
	解开耦合，使得函数独立通用行
*/

int fun_print(void *element, void *result)
{
	if(NULL == element)
	{
		printf("error\t");
		return 1;
	}
	printf("%d\t", *(int *)element);
	return 0;
}

int fun_max(void *element, void *result)
{
	if(NULL == element |  NULL == result)
	{
		printf("error\t");
		return 1;
	}
	if(*(int *)element  > *(int *)result)
	{
		*(int *)result = *(int *)element;
	}
	return 0;
}

int fun_sum(void *element, void *result)
{
	if(NULL == element |  NULL == result)
	{
		printf("error\t");
		return 1;
	}
	*(long *)result += *(int *)element;
	return 0;
}
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
	
	OperContext  contxt;
	contxt.oper = fun_print;
	contxt.result = NULL;
	Oper_List(pDLinkHead, &contxt);
	int *a1 = (int *)malloc(sizeof(int));
	int *a2 = (int *)malloc(sizeof(int));
	int *a3 = (int *)malloc(sizeof(int));
	int *a4 = (int *)malloc(sizeof(int));
	*a1 = 1; *a2 = 2; *a3 = 3; *a4 = 4;
	AddElem_List(pDLinkHead, a1);
	AddElem_List(pDLinkHead, a2);
	AddElem_List(pDLinkHead, a3);
	AddElem_List(pDLinkHead, a4);
	
	Oper_List(pDLinkHead, &contxt);

	printf("the list length=%d\n", GetLength_List(pDLinkHead));
	

	contxt.oper = fun_max;
	contxt.result =(void *)malloc(sizeof(int));
	memset(contxt.result, 0x00, sizeof(int));
	Oper_List(pDLinkHead, &contxt);
	printf("the max num=%d\r\n", *(int *)(contxt.result));
	free(contxt.result);

	contxt.oper = fun_sum;
	contxt.result =(void *)malloc(sizeof(long));
	memset(contxt.result, 0x00, sizeof(long));
	Oper_List(pDLinkHead, &contxt);
	printf("the sum num=%ld\r\n", *(long *)(contxt.result));
	free(contxt.result);

	DelNodeByIndex_List(pDLinkHead, 2);
	Oper_List(pDLinkHead, &contxt);
	

	DelNodeByIndex_List(pDLinkHead, 1);
	Oper_List(pDLinkHead, &contxt);

	PDLINK cur_test = GetElem_List(pDLinkHead, 1);
	
	cur_test = GetElem_List(pDLinkHead, 0);
	if(NULL == cur_test)
	{
		printf("the index=1 is NULL\r\n");
	}else{
//		printf("the index=1 is %d \r\n", cur_test->element);	
	}

	Clear_List(pDLinkHead);
}
