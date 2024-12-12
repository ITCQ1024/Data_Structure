/*
 * @Date: 2024-12-12 23:20:28
 * @LastEditors: HashMap2020 && xjd_aiit_1960_thj@163.com
 * @LastEditTime: 2024-12-13 01:58:29
 * @FilePath: \LinkList\bo2-2.cpp
 */

#include "c2-2.h"

// 初始化链表
void InitList(LinkList &L)
{
    // 操作结果:构造一个空的线性表L
    L = (LinkList)malloc(sizeof(LNode)); // 产生头结点,并使L指向头结点
    if (!L)                              // 存储空间分配失败
        exit(OVERFLOW);
    L->next = NULL; // 指针域为空
}

// 销毁链表
void DestroyList(LinkList &L)
{
    // 初始条件:线性表L已存在
    // 操作结果:销毁线性表L
    LinkList p;
    while (L)
    {
        p = L->next;
        free(L);
        L = p;
    }
}

// 清空链表
void ClearList(LinkList L)
{                         // 不改变L
    LinkList p = L->next; // p指向第一个结点
    LinkList q;
    while (p)
    { // 没有到表尾
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; // 头指针指针域为空
}

// 判断链表是否为空
Status ListEmpty(LinkList L)
{
    // 初始条件:线性表L已存在
    // 操作结果:若L为空表,则返回TRUE,否则返回FALSE
    if (L->next) // 非空
        return FALSE;
    else
        return TRUE;

    // return L->next == NULL;
}

// 获取链表长度
int ListLength(LinkList L)
{
    // 初始条件:线性表L已存在
    // 操作结果:返回L中数据元素个数
    int i = 0;
    LinkList p = L->next; // p指向第一个结点
    while (p)             // 没有到表尾
    {
        i++;
        p = p->next;
    }
    return i;
}

// 获取链表中第i个元素
Status GetElem(LinkList L, int i, ElemType &e)
{
    // L为带头结点的单链表的头指针,当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR
    int j = 1;            // 初始化,j为计数器
    LinkList p = L->next; // 初始化,p指向第一个结点
    while (p && j < i)
    { // 顺指针向后查找,直到p指向第i个元素或p为空
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR; // 第i个元素不存在
    e = p->data;      // 取第i个元素
    return OK;
}

// 定位元素
int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // 初始条件:线性表L已存在,compare()是数据元素判定函数(满足为1 否则为0)
    // 操作结果:返回线性表L中第1个与e满足关系compare()的数据元素的位置(位序)
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        ++i;
        if (compare(p->data, e)) // 找到这样的数据元素
            return i;
        p = p->next; // p后移
    }
    return 0;
}

// 获取前驱元素
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    // 初始条件:线性表L已存在
    // 操作结果:若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,返回OK
    //          否则操作失败,pre_e无定义,返回INFEASIBLE
    LinkList p = L->next; // p指向第一个结点
    LinkList q;
    while (p->next)
    {                // p所指结点有后继
        q = p->next; // q为p的后继
        if (q->data == cur_e)
        {
            pre_e = p->data;
            return OK;
        }
        p = q; // p依次后移
    }
    return INFEASIBLE;
}

// 获取后继元素
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    // 初始条件:线性表L已存在
    // 操作结果:若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继,返回OK
    //          否则操作失败,next_e无定义,返回INFEASIBLE
    LinkList p = L->next; // p指向第一个结点
    while (p->next)
    { // p所指结点有后继
        if (p->data == cur_e)
        {
            next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE; // 添加默认返回值
}

// 插入元素
Status ListInsert(LinkList L, int i, ElemType e)
{
    // 在带头点的单链线性表L中第i个位置上(之前)插入元素e
    int j = 0;
    LinkList p = L;
    while (p && j < i - 1)
    { // 让 p 移动到第 i-1 个节点（即插入位置的前一个节点）
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        // 如果 p 为 NULL，说明链表的长度小于 i，插入位置 i 超出了链表的范围。
        // 如果 j > i - 1，说明在遍历过程中，j 已经超过了 i - 1，插入位置 i 也是不合法的。
        return ERROR;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 生成新的结点
    if (!s)
    {
        // 内存不足,不足以分配空间给s
        exit(OVERFLOW);
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除元素
Status ListDelete(LinkList L, int i, ElemType &e)
{
    // 在带头点的单链线性表L中,删除第i个元素,并由e返回其值
    int j = 0;
    LinkList p = L;

    while (p->next && j < i - 1)
    { // 寻找第i个结点,并令p指向其前驱
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) // 删除位置不合理
        return ERROR;
    LNode *q = p->next; // 删除并释放结点
    e = q->data;
    free(q);
    p->next = q->next;
    return OK;
}

// 遍历链表
void ListTraverse(LinkList L, void (*visit)(ElemType))
{
    // visit的形参类型为ElemType,与bo2-1.cpp中相应函数的形参类型ElemType&不同
    // 初始条件:线性表L已存在
    // 操作结果:依次对L中的每个数据元素调用函数visit()
    LinkList p = L->next;

    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    cout << endl;
}