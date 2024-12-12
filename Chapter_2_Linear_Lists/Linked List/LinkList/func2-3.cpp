/*
 * @Date: 2024-12-13 00:21:10
 * @LastEditors: HashMap2020 && xjd_aiit_1960_thj@163.com
 * @LastEditTime: 2024-12-13 01:58:04
 * @FilePath: \LinkList\fun2-3.cpp
 */
#include "c2-2.h"

// 判断两个元素是否相等
Status equal(ElemType e1, ElemType e2)
{
    // 判断是否相等的函数
    if (e1 == e2)
        return TRUE;
    else
        return FALSE;
}

// 比较两个元素的大小
int comp(ElemType e1, ElemType e2)
{
    // 根据e1<.=.>e2 分别返回 -1 0 1
    if (e1 == e2)
        return 0;
    else
        return (e1 - e2) / abs(e1 - e2);
}

// 打印元素
void print(ElemType e)
{
    printf("%d ", e);
}

// 打印元素（引用版本）
void print1(ElemType &e)
{
    printf("%d ", e);
}

// 打印元素（字符版本）
void print2(ElemType e)
{
    printf("%c", e);
}

// 判断两个元素是否满足平方关系
Status square(ElemType e1, ElemType e2)
{
    // 数据元素判定函数(平方关系) LocateElem()调用的函数
    if (e1 == e2 * e2)
        return TRUE;
    else
        return FALSE;
}

// 将元素的值加倍
void doubleValue(ElemType &e)
{
    // ListTraverse()调用的另一函数(元素加倍)
    e *= 2;
}