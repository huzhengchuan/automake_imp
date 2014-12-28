#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef  int NodeElem;

typedef struct _DLINK{
	NodeElem element;
	struct _DLINK *pre;
	struct _DLINK *next;
}DLINK, *PDLINK;

int Init_List(PDLINK *pDLinkHead); 
int Clear_List(PDLINK pDLinkHead);
int GetLength_List(PDLINK pDLinkHead);
PDLINK GetElem_List(PDLINK pDLinkHead, int index);
int AddElem_List(PDLINK pDLinkHead, NodeElem elem);
int DelNodeByIndex_List(PDLINK pDLinkHead, int index);
int DelNodeByElem_List(PDLINK pDLinkHead, PDLINK pDLinkNode);
int Print_List(PDLINK pDLinkHead);

#ifdef __cplusplus
}
#endif
