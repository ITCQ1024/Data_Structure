#pragma once

//Sequential List

//c2-1.h 线性表的动态分配顺序存储结构

#include "c1.h"

typedef int ElemType; //定义了一个类型别名 ElemType，表示线性表中元素的类型。这里假设元素类型为 int。

#define LIST_INIT_SIZE 10 //线性表存储空间的厨师分配量
#define LIST_INCREMENT 2 //线性表存储空间的分配增量

typedef struct SqList {
	ElemType* elem; //存储空间地址
	int length; //当前长度
	int listsize;//当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

// 函数声明
void InitList(SqList& L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType& e);

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));

Status ListInsert(SqList& L, int i, ElemType e);

void ListTraverse(SqList L, void(*visit)(ElemType&));


//----------------------------------------------------------------
Status equal(ElemType e1, ElemType e2);

void print1(ElemType& e);
