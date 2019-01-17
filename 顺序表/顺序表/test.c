#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

int main()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);
	
	SeqListPopBack(&s);
	PrintSeqList(&s);

	SeqListPushFront(&s, 0);
	PrintSeqList(&s);

	SeqListPopFront(&s);
	PrintSeqList(&s);

	SeqListInsert(&s, 2, 5);
	PrintSeqList(&s);

	SeqListErase(&s, 2);
	PrintSeqList(&s);

	SeqListFind(&s, 3);
	SeqListRemove(&s, 2);
	PrintSeqList(&s);

	SeqListRemoveAll(&s, 2);
	PrintSeqList(&s);

	printf("顺序表有效元素个数: %d \n", SeqListSize(&s));
	printf("顺序表容量: %d \n", SeqListCapacity(&s));
	printf("%d\n", SeqListEmpty(&s));
	printf("顺序表第一个元素: %d \n", SeqListFront(&s));
	printf("顺序表最后一个元素: %d \n", SeqListBack(&s));
	SeqListDestroy(&s);
	return 0;
}

