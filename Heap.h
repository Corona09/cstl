#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef HEAP_H_ZUMVV5UX
#define HEAP_H_ZUMVV5UX

static const int32_t HEAP_DEFAULT_SIZE = 5;


typedef int (*HeapNodeCompare)(void*, void*);

typedef struct Heap {
	int32_t size;
	int32_t capacity;
	void** data;
	HeapNodeCompare compare;
} Heap;

/**
 * 申请新的堆
 */
Heap* newHeap(HeapNodeCompare compare);

/**
 * 向堆中插入新的数据
 * 并返回其指针
 */
void* heapPush(Heap* heap, void* element);

/**
 * 删除数据
 */
void heapPop(Heap* heap);

/**
 * 查询数据
 */
void* heapSearch(Heap* heap, void* element);

/**
 * 获取堆顶
 */
void* heapTop(Heap* heap);

/**
 * 检查堆是否空
 */
int heapEmpty(Heap* heap);

/**
 * 检查堆是否满
 */
int heapFull(Heap* heap);

/**
 * 清空栈
 */
void heapClear(Heap* heap);

/**
 * 释放一个堆及相应的空间
 */
void heapFree(Heap* heap);

#endif /* end of include guard: HEAP_H_ZUMVV5UX */
