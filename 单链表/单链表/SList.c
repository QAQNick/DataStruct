#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// ���������
Node* SListCreatNode(SDataType data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->pNext = 0;

	return temp;
}

// ����ĳ�ʼ�� 
void SListInit(SList* pl)
{
	assert(pl);
	pl->pHead = NULL;
}

// ���������
void SListDestroy(SList* pl)
{
	Node *begin = pl->pHead;
	assert(pl);
	while (begin)
	{
		Node *temp = begin;
		begin = begin->pNext;
		free(temp);
	}
	pl->pHead = 0;
}

// β��
void SListPushBack(SList* pl, SDataType data)
{
	Node* NewNode = 0;
	assert(pl);

	NewNode = SListCreatNode(data);

	// û�нڵ�/һ������
	if (pl->pHead == NULL)
	{
		pl->pHead = NewNode;
	}
	else
	{
		Node* begin = pl->pHead;
		while (begin->pNext)
		{
			begin = begin->pNext;
		}

		begin->pNext = NewNode;
	}
}

// βɾ
void SListPopBack(SList* pl)
{
	Node *begin = 0;
	assert(pl);
	//û�нڵ�
	if (NULL == pl)
		return;
	//��һ���ڵ�
	if (NULL == pl->pHead)
	{
		free(pl);
		pl->pHead = 0;
		return;
	}
	//����ڵ�
	begin = pl->pHead;
	while (begin->pNext->pNext != NULL)
	{
		begin = begin->pNext;
	}

	free(begin->pNext);
	begin->pNext = 0;

}

// ͷ��
void SListPushFront(SList* pl, SDataType data)
{
	Node *NewNode = 0;
	assert(pl);
	NewNode = SListCreatNode(data);

	//û�нڵ�
	if (NULL == pl->pHead)
	{
		pl->pHead = NewNode;
	}
	//�нڵ�
	else
	{
		NewNode->pNext = pl->pHead;
		pl->pHead = NewNode;
	}

}

// ͷɾ
void SListPopFront(SList* pl)
{
	Node *begin = 0;
	assert(pl);
	//û�нڵ�
	if (NULL == pl)
		return;
	//һ���ڵ�
	if (NULL == pl->pHead)
	{
		free(pl);
		pl->pHead = 0;
		return;
	}
	//����ڵ�
	begin = pl->pHead;
	pl->pHead = begin->pNext;
	free(begin);

}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ�
Node* SListFind(SList* pl, SDataType data)
{
	Node* begin = 0;
	assert(pl);

	begin = pl->pHead;
	while (begin)
	{
		if (data == begin->data)
		{
			return begin;
		}
		begin = begin->pNext;
	}
	return 0;
}

// ������posλ�ú����ֵΪdata�Ľڵ�
void SListInsertAfter(Node* pos, SDataType data)
{
	if (pos)
	{
		Node *NewNode = SListCreatNode(data);
		if (NewNode)
		{
			NewNode->pNext = pos->pNext;
			pos->pNext = NewNode;
		}
	}
}

// ɾ��������ֵΪdata�Ľڵ�
void SListErase(SList* pl, Node* pos)
{
	Node *DelNode = 0;
	assert(pl);
	assert(pos);

	if (pos->pNext == NULL)
	{
		SListPopBack(pl);
		return;
	}

	pos->data = pos->pNext->data;	
	DelNode = pos->pNext;
	pos->pNext = pos->pNext->pNext;
	free(DelNode);

}

// ��ȡ��������Ч�ڵ�ĸ���
int SListSize(SList* pl)
{

	assert(pl);
	if (NULL == pl)
	{
		return 0;
	}
	int count = 0;
	Node *temp = pl->pHead;
	while (temp != NULL)
	{
		temp = temp->pNext;
		count++;
	}
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	assert(pl);
	if (NULL == pl)
	{
		return -1;
	}
	else
		return 1;
}

// ��ȡ����ĵ�һ���ڵ�
Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->pHead;
}

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl)
{
	assert(pl);
	if (NULL == pl)
	{
		printf("�������\n");
		return 0;
	}
	Node* EndNode = pl->pHead;
	while (EndNode->pNext != NULL)
	{
		EndNode = EndNode->pNext;
	}
	return EndNode;
}

void SListRemove(SList* pl, SDataType data)
{
	assert(pl);
	SListErase(pl, SListFind(pl, data));
}

void SListRemoveAll(SList* pl, SDataType data)
{
	assert(pl);
	if (NULL == pl->pHead)
	{
		return;
	}

	Node* DeleNode = pl->pHead;
	if (data == DeleNode->data)
	{
		pl->pHead = DeleNode->pNext;
		free(DeleNode);
	}

	Node* PCur = pl->pHead;
	Node* Prev = PCur;

	while (PCur)
	{
		if (data == PCur->data)
		{
			Prev->pNext = PCur->pNext;
			free(PCur);
			PCur = Prev->pNext;
		}
		else
		{
			Prev = PCur;
			PCur = PCur->pNext;
		}
	}

}






////////////////////////////////////////////////////////////////

void PrintSList(SList *pl)
{
	assert(pl);
	Node* begin = pl->pHead;

	while (begin)
	{
		printf("%d--->", begin->data);
		begin = begin->pNext;
	}
	printf("NULL\n");
}


void Test1()
{
	SList s;

	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	PrintSList(&s);

	SListPopBack(&s);
	PrintSList(&s);

	SListPushFront(&s, 0);
	PrintSList(&s);

	SListPopFront(&s);
	PrintSList(&s);


	SListDestroy(&s);
}

void Test2()
{
	SList s;
	
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	PrintSList(&s);

	SListInsertAfter(SListFind(&s, 2), 5);
	SListInsertAfter(SListFind(&s, 2), 6);
	PrintSList(&s);

	SListErase(&s, SListFind(&s, 2));
	PrintSList(&s);

	printf("��Ч�ڵ����: %d \n", SListSize(&s));


	SListDestroy(&s);

}

void Test3()
{
	SList s;

	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 3);
	SListPushBack(&s, 3);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	PrintSList(&s);

	SListRemove(&s, 3);
	PrintSList(&s);
	SListRemoveAll(&s, 3);
	PrintSList(&s);

	printf("%p\n", SListFind(&s, 4));
	printf("��һ���ڵ��ַ: %p \n", SListFront(&s));
	printf("�ڶ����ڵ��ַ: %p \n", SListFront(&s));
	SListDestroy(&s);
}
void Test()
{
	//Test1();
	//Test2();
	Test3();
}