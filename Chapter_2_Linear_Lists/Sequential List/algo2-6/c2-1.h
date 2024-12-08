#pragma once

// Sequential List

// c2-1.h ���Ա�Ķ�̬����˳��洢�ṹ

#include "c1.h"  // ��������ͷ�ļ� c1.h

typedef int ElemType;  // ������һ�����ͱ��� ElemType����ʾ���Ա���Ԫ�ص����͡��������Ԫ������Ϊ int��

#define LIST_INIT_SIZE 10  // ���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT 2  // ���Ա�洢�ռ�ķ�������

// �������Ա�ṹ�� SqList
typedef struct SqList {
    ElemType* elem;  // �洢�ռ��ַ
    int length;  // ��ǰ����
    int listsize;  // ��ǰ����Ĵ洢�������� sizeof(ElemType) Ϊ��λ��
} SqList;

// ��������
void InitList(SqList& L);  // ��ʼ�����Ա� L

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));  // �������Ա� L �е�һ���� e ���� compare ��ϵ��Ԫ�ص�λ��

Status ListInsert(SqList& L, int i, ElemType e);  // �����Ա� L �ĵ� i ��λ�ò���Ԫ�� e

void ListTraverse(SqList L, void(*visit)(ElemType&));  // �������Ա� L����ÿ��Ԫ�ص��� visit ����

// �ȽϺ���
Status equal(ElemType e1, ElemType e2);  // �ж�����Ԫ���Ƿ����

void print1(ElemType& e);  // ��ӡԪ�� e�����ð汾��
