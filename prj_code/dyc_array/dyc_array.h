#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _cplusplus
extern "C"{
#endif

#define Ret int
typedef struct _DArray;
typedef struct _DArray DArray;

DArray * darray_create(DataDestroyFunc data_destory, void *ctx);
Ret darray_insert(DArray *thiz. size_t index, void *data);
Ret darray_preappend(DArray *thiz, void *data);
Ret darray_append(DArray *thiz, void *data);
Ret darray_delete(DArray *thiz, size_t index);
Ret darray_get_by_index(DArray *thiz, size_t index, void *data);
Ret darray_set_by_index(DArray *thiz, size_t index, void *data);
size_t darray_length(DArray *thiz);
int darray_find(DArray *thiz, DataCompareFunc cmp, void *ctx);
Ret darray_foreach(DArray *thiz, DataVisitFunc visit, void *ctx);
void darray_destory(DArray *thiz);

#ifdef _cplusplus
}
#endif

