#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dyc_array.h"

#define MAX_SIZE_LEN 100

typedef struct _DArray{
	int  length;
	int  capacity;
	void *data[MAX_SIZE_LEN];
}DArray;



DArray * darray_create(DataDestroyFunc data_destory, void *ctx)
{
	if(NULL != ctx)
	{
		if((DArray *)ctx->length > 0)
		{
		
		}
	}
	DArray *thiz = (DArray *)malloc(sizeof(DArray));
	memset(thiz, 0x00, sizeof(DArray));
	thiz->length = 0;
	thiz->capacity = MAX_SIZE_LEN;
}

Ret darray_insert(DArray *thiz. size_t index, void *data)
{
	if(NULL == thiz || data == thiz)
	{
		return 1;
	}

	int insert_index = index < thiz->capacity?index:thiz->capacity;
	if(insert_index < thiz->length)
	{
		realloc(thiz->data, thiz->capacity + MAX_SIZE_LEN + MAX_SIZE_LEN>>2);
		thiz->capacity = thiz->capacity + MAX_SIZE_LEN + MAX_SIZE_LEN>>2;
	}
	int pos = 0;
	for(pos = thiz->length; pos > insert_index; pos--)
	{
		thiz->data[pos] = thiz->data[pos-1];
	}
	thiz->data[insert_index] = data;

}

Ret darray_preappend(DArray *thiz, void *data)
{
	return darray_insert(thiz, 0, data);
}

Ret darray_append(DArray *thiz, void *data)
{
	return darray_insert(thiz, thiz->length, data);
}

Ret darray_delete(DArray *thiz, size_t index)
{
	if(NULL == thiz || index >= thiz->length)
	{
		return 1;
	}
	int pos = 0;
	for(pos = index; pos < length; pos++)
	{
		thiz->data[index] = thiz->data[index+1];
	}
	thiz->length--;

}

Ret darray_get_by_index(DArray *thiz, size_t index, void *data)
{
	if(NULL == thiz || NULL == data || index >= thiz->length)
	{
		return 1;
	}
	
	*data = thiz->data[index];
	return 0;
}
Ret darray_set_by_index(DArray *thiz, size_t index, void *data)
{

	if(NULL == thiz || NULL == datai || index < thiz->length)
	{
		return 1;
	}
	thiz->data[index] = data;
	return 0;
}
size_t darray_length(DArray *thiz)
{
	return thiz->length;
}
int darray_find(DArray *thiz, DataCompareFunc cmp, void *ctx)
{
	int pos = 0;
	for(pos = 0; pos < thiz->length; pos++)
	{
		if(0 == cmp(thiz->data[pos], ctx))
		{
			return pos;
		}
	}
}
Ret darray_foreach(DArray *thiz, DataVisitFunc visit, void *ctx)
{
	
	int pos = 0;
	for(pos = 0; pos < thiz->length; pos++)
	{
		visit(thiz->data[pos]);
	}
	return 0;
}
void darray_destory(DArray *thiz)
{

	int pos = 0;
	for(pos = 0; pos < thiz->length; pos++)
	{
		free(thiz->data[pos]);
		thiz->data[pos] = NULL;
	}
	free(thiz->data);
	thiz->length=0;
	thiz->capacity = 0;
	free(thiz);
	thiz = NULL;
	return ;
}


