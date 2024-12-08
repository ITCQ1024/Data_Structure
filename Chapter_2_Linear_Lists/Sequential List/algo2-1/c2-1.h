#pragma once

//Sequential List

//c2-1.h ���Ա�Ķ�̬����˳��洢�ṹ

#include "c1.h"

typedef int ElemType; //������һ�����ͱ��� ElemType����ʾ���Ա���Ԫ�ص����͡��������Ԫ������Ϊ int��

#define LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʦ������
#define LIST_INCREMENT 2 //���Ա�洢�ռ�ķ�������

typedef struct SqList {
	ElemType* elem; //�洢�ռ��ַ
	int length; //��ǰ����
	int listsize;//��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;

// ��������
void InitList(SqList& L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType& e);

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));

Status ListInsert(SqList& L, int i, ElemType e);

void ListTraverse(SqList L, void(*visit)(ElemType&));


//----------------------------------------------------------------
Status equal(ElemType e1, ElemType e2);

void print1(ElemType& e);
