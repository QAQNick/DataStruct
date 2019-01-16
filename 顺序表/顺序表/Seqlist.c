#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SeqListInit(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
		return;
	ps->array = (DataType *)malloc(sizeof(DataType) * 5);
	if (NULL == ps->array)
	{
		assert(0);
		return ;
	}
	ps->capacity = 5;
	ps->size = 0;	
}

void SeqListDestroy(PSeqList ps)
{
	assert(ps);
	ps->size = 0;
	ps->capacity = 0;
	free(ps->array);
	ps->array = NULL;
}

//检查空间
void CheckSeqList(PSeqList ps)
{
	assert(ps);

	if (NULL == ps)
		return ;
	if (ps->capacity == ps->size)
	{
		ps->array = (DataType *)realloc(ps->array, sizeof(DataType)*(ps->capacity * 2));
		ps->capacity *= 2;
	}
}

void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	if (NULL == ps)
		return;
	
	CheckSeqList(ps);

	ps->array[ps->size] = data;
	ps->size++;
}

void SeqListPopBack(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
		return;
	ps->size--;
}

void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	if (NULL == ps)
		return;
	CheckSeqList(ps);

	for (int i = ps->size; i >= 0; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = data;
	ps->size++;
}

void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
		return;

	for (int i = 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;

}

void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	assert(ps);
	if (NULL == ps)
		return;
	CheckSeqList(ps);

	if (pos < 0 || pos > ps->size)
	{
		printf("插入位置不合法!\n");
		return;
	}
	else
	{
		for (int i = ps->size; i > pos; i--)
		{
			ps->array[i] = ps->array[i - 1];
		}
		ps->array[pos] = data;
		ps->size++;
	}

}

void SeqListErase(PSeqList ps, int pos)
{
	assert(ps);
	if (NULL == ps)
		return;
	if (pos < 0 || pos > ps->size)
	{
		printf("删除位置不合法!\n");
		return;
	}

	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	if (NULL == ps)
	{
		printf("NULL");
		return -1;
	}
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == data)
		{
			printf("找到了!\n");
			return 1;
		}
	}
	printf("找不到!\n");
	return -1;
}

void SeqListRemove(PSeqList ps, DataType data)
{
	assert(ps);
	if (NULL == ps)
		return;
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == data)
		{
			for (int j = i + 1; j < ps->size; j++)
			{
				ps->array[j - 1] = ps->array[j];
			}
			ps->size--;
			break;
		}
	}
}

void SeqListRemoveAll(PSeqList ps, DataType data)
{
	assert(ps);
	if (NULL == ps)
		return;
	int i = 0;
	int j = 0;
	while (i < ps->size && ps->array[i] != data)
		i++;
	for (j = i + 1; j < ps->size; j++)
	{
		if (ps->array[j] != data)
		{
			ps->array[i++] = ps->array[j];
		}
	}
	ps->size = i;
}

int SeqListSize(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
	{
		printf("NULL\n");
		return 0;
	}
	printf("顺序表中有 %d 个有效元素\n", ps->size);
	return 0;

}

int SeqListCapacity(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
	{
		printf("NULL\n");
		return 0;
	}
	printf("顺序表容量为: %d \n", ps->capacity);
	return 0;
}

int SeqListEmpty(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
	{
		printf("NULL\n");
		return 0;
	}
	else
	{
		printf("顺序表不为空!\n");
		return 0;
	}
}

DataType SeqListFront(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
		return 0;
	printf("顺序表第一个元素是 %d\n", ps->array[0]);
	return 0;
}


DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
		return 0;
	printf("顺序表最后一个元素是 %d\n", ps->array[ps->size - 1]);
	return 0;
}



//////////////////////////////////////////////////////////////////////////
void PrintSeqList(PSeqList ps)
{
	assert(ps);
	if (NULL == ps)
		return;
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}