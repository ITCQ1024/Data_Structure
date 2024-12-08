#pragma once

// Sequential List

// c2-1.h 线性表的动态分配顺序存储结构

#include "c1.h"  // 包含基础头文件 c1.h

typedef int ElemType;  // 定义了一个类型别名 ElemType，表示线性表中元素的类型。这里假设元素类型为 int。

#define LIST_INIT_SIZE 10  // 线性表存储空间的初始分配量
#define LIST_INCREMENT 2  // 线性表存储空间的分配增量

// 定义线性表结构体 SqList
typedef struct SqList {
    ElemType* elem;  // 存储空间地址
    int length;  // 当前长度
    int listsize;  // 当前分配的存储容量（以 sizeof(ElemType) 为单位）
} SqList;

// 函数声明
void InitList(SqList& L);  // 初始化线性表 L

Status ListInsert(SqList& L, int i, ElemType e);  // 在线性表 L 的第 i 个位置插入元素 e

void ListTraverse(SqList L, void(*visit)(ElemType&));  // 遍历线性表 L，对每个元素调用 visit 函数

void print1(ElemType& e);  // 打印元素 e（引用版本）
