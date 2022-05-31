#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "Heap.h"

/**
 * 申请新的堆
 */
Heap* newHeap(HeapNodeCompare compare) {
	Heap* heap = (Heap*) malloc(1 * sizeof(Heap));
	heap->compare = compare;
	heap->capacity = HEAP_DEFAULT_CAPACITY;
	heap->data = (void**) malloc((heap->capacity) * sizeof(void*));
	heap->size = 0;
	return heap;
}


/**
 * 向堆中插入新的数据
 */
void* heapPush(Heap* heap, void* element) {
	if (heap->size == heap->capacity) {
		heap->capacity = (int)(1.5 * heap->capacity);
		heap->data = (void**) realloc(heap->data, heap->capacity * sizeof(void*));
	}

	int32_t index = heap->size;
	heap->data[index] = element;
	heap->size ++;
	HeapNodeCompare compare = heap->compare;
	while (index > 0) {
		// 如果父结点的值 > 子结点的值, 则交换
		if ((*compare)(heap->data[index/2], heap->data[index]) > 0) {
			void* tmp = heap->data[index/2];
			heap->data[index/2] = heap->data[index];
			heap->data[index] = tmp;
		} else {
			break;
		}
		index = index / 2;
	}
	return heap->data[index];
}

/**
 * 获取堆顶
 */
void* heapTop(Heap* heap) {
	if (heap->size == 0) {
		// 堆空, 返回 NULL
		return NULL;
	}
	return heap->data[0];
}

void shiftDown(Heap* heap, int32_t index) {
	int32_t lc = index * 2 + 1, rc = index * 2 + 2;
	if (lc >= heap->size) {
		return;
	}
	int32_t d = rc;
	if (rc >= heap->size || (*heap->compare)(heap->data[lc], heap->data[rc]) < 0) {
		d = lc;
	}

	if ((*heap->compare)(heap->data[index], heap->data[d]) > 0) {
		void* tmp = heap->data[index];
		heap->data[index] = heap->data[d];
		heap->data[d] = tmp;

		shiftDown(heap, d);
	}
}

/**
 * 弹出堆顶
 */
void heapPop(Heap* heap) {
	if (heapEmpty(heap)) { return; }
	heap->data[0] = heap->data[heap->size-1];
	heap->size --;
	shiftDown(heap, 0);
}


/**
 * 检查堆是否空
 */
int heapEmpty(Heap* heap) {
	return heap->size == 0 ? 1 : 0;
}

/**
 * 检查堆是否满
 */
int heapFull(Heap* heap) {
	return heap->size == heap->capacity ? 1 : 0;
}

void* heapSearchElement(Heap* heap, int32_t index, void* element) {
	HeapNodeCompare compare = heap->compare;
	while (index < heap->size) {
		if ((*compare)(element, heap->data[index]) < 0) {
			return NULL;
		} else if ((*compare)(element, heap->data[index]) == 0) {
			return heap->data[index];
		} else {
			void* lr = heapSearchElement(heap, index * 2 + 1, element);
			if (lr != NULL) {
				return lr;
			} else {
				return heapSearchElement(heap, index * 2 + 2, element);
			}
		}
	}
	return NULL;
}

/**
 * 查询数据
 */
void* heapSearch(Heap* heap, void* element) {
	return heapSearchElement(heap, 0, element);
}

/**
 * 清空栈
 */
void heapClear(Heap* heap) {
	heap->size = 0;
	for (int i = 0; i < heap->capacity; i++) {
		heap->data[i] = NULL;
	}
}

/**
 * 释放一个堆及相应的空间
 */
void heapFree(Heap* heap) {
	free(heap->data);
	free(heap);
}
