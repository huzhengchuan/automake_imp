#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _DLINK DLINK;
typedef struct _DLINK *PDLINK;


typedef void (*PrintElemFun)(void *data);  /* 解耦合，使得链表成为一个通用的双向链表 */

int Init_List(PDLINK *pDLinkHead); 
int Clear_List(PDLINK pDLinkHead);
int GetLength_List(PDLINK pDLinkHead);
PDLINK GetElem_List(PDLINK pDLinkHead, int index);
int AddElem_List(PDLINK pDLinkHead, void *elem);
int DelNodeByIndex_List(PDLINK pDLinkHead, int index);
int DelNodeByElem_List(PDLINK pDLinkHead, PDLINK pDLinkNode);
int Print_List(PDLINK pDLinkHead, PrintElemFun print);  /* 解耦合，使得链表成为一个通用的双向链表 */

#ifdef __cplusplus
}
#endif
