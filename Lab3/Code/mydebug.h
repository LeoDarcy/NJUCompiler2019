#ifndef DEBUG
#define DEBUG
#include <stdio.h>
#include <assert.h>
void DebugOutPut(char* msg)
{
    printf("DEBUG Message:     %s\n", msg);
}

void DebugAssert(char* msg)
{
    DebugOutPut(msg);
    assert(1 == 2);
}

#endif