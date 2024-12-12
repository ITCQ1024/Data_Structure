/*
 * @Date: 2024-12-12 23:15:30
 * @LastEditors: HashMap2020 && xjd_aiit_1960_thj@163.com
 * @LastEditTime: 2024-12-13 01:58:10
 * @FilePath: \LinkList\c2-2.h
 */
// c2-2.h 线性表的单链表存储结构

#pragma once

#include "c1.h"

typedef int ElemType;

typedef struct LNode
{
    ElemType data; // 数据域
    LNode *next;   // 指针域
} LNode, *LinkList;

// 初始化链表
void InitList(LinkList &L);

// 销毁链表
void DestroyList(LinkList &L);

// 清空链表
void ClearList(LinkList L);

// 判断链表是否为空
Status ListEmpty(LinkList L);

// 获取链表长度
int ListLength(LinkList L);

// 获取链表中第i个元素
Status GetElem(LinkList L, int i, ElemType &e);

// 定位元素
int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));

// 获取前驱元素
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);

// 获取后继元素
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);

// 插入元素
Status ListInsert(LinkList L, int i, ElemType e);

// 删除元素
Status ListDelete(LinkList L, int i, ElemType &e);

// 遍历链表
void ListTraverse(LinkList L, void (*visit)(ElemType));

// 比较函数
Status equal(ElemType e1, ElemType e2);

// 比较函数
int comp(ElemType e1, ElemType e2);

// 打印函数
void print(ElemType e);

// 打印函数
void print1(ElemType &e);

// 打印函数
void print2(ElemType e);

// 平方关系判定函数
Status square(ElemType e1, ElemType e2);

// 元素加倍函数
void doubleValue(ElemType &e);