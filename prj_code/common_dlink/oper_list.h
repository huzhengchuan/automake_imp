#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SIZE 128

typedef struct _DLINK DLINK;
typedef struct _DLINK *PDLINK;

typedef struct _OperDLink OperDLink;


typedef void (*PrintElemFun)(void *data);  /* 解耦合，使得链表成为一个通用的双向链表 */

typedef struct _OperContext{
	int (*oper)(void *elem, void *result);
	void *result;
}OperContext;

int Init_List(PDLINK *pDLinkHead); 
int Clear_List(PDLINK pDLinkHead);
int GetLength_List(PDLINK pDLinkHead);
PDLINK GetElem_List(PDLINK pDLinkHead, int index);
int AddElem_List(PDLINK pDLinkHead, void *elem);
int DelNodeByIndex_List(PDLINK pDLinkHead, int index);
int DelNodeByElem_List(PDLINK pDLinkHead, PDLINK pDLinkNode);
int Oper_List(PDLINK pDLinkHead, char *operName, void *context);
#ifdef __cplusplus
}
#endif
