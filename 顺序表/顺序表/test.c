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

	printf("˳�����ЧԪ�ظ���: %d \n", SeqListSize(&s));
	printf("˳�������: %d \n", SeqListCapacity(&s));
	printf("%d\n", SeqListEmpty(&s));
	printf("˳����һ��Ԫ��: %d \n", SeqListFront(&s));
	printf("˳������һ��Ԫ��: %d \n", SeqListBack(&s));
	SeqListDestroy(&s);
	return 0;
}

