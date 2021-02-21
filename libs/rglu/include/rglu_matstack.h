#ifndef __RGLU_MATSTACK_H__
#define __RGLU_MATSTACK_H__

#include "./rglu_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct MatStack
{
    Stack stack;
} MatStack;

void matstack_init(MatStack* s);
void matstack_free(MatStack* s);
void matstack_push(MatStack* s, mat4 m);
void matstack_pushTop(MatStack* s);
bool matstack_pop(MatStack* s, /* out */ mat4 ret);
bool matstack_top(MatStack* s, /* out */ mat4 ret);
void matstack_mul(MatStack* s, /* out */ mat4 m);

#ifdef __cplusplus
}
#endif

#endif // __RGLU_MATSTACK_H__
