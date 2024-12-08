#include "c2-1.h"

// 函数声明
Status ListInsert(SqList& L, int i, ElemType e);

int main(int argc, char* argv[]) {
    SqList L;  // 定义一个线性表 L

    InitList(L);  // 初始化线性表 L

    cout << endl;

    printf("L初始化后, L.elem = %p, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);  // 输出线性表 L 的初始化信息

    cout << endl;

    // 在 L 的表尾依次插入 1~10
    for (int i = 1; i <= 10; i++)
        ListInsert(L, i, i);

    printf("在L的表尾依次插入1~10后:");

    ListTraverse(L, print1);  // 遍历并输出线性表 L 的内容

    cout << endl;

    return 0;
}

// 插入函数，在顺序线性表 L 的第 i 个位置插入元素 e
Status ListInsert(SqList& L, int i, ElemType e) {//算法2.4
    // 初始条件:顺序线性表L已存在 1<=i<=ListLength(L)+1
    // 操作结果:在顺序线性表L中的第 i 个 位置上插入新的数据元素e, L的长度+1

    if (i < 1 || i > L.length + 1)  // 插入位置 i 不合法
        return ERROR;

    if (L.length >= L.listsize) {  // 如果线性表的长度已经达到或超过当前的存储容量
        ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));  // 重新分配内存，增加存储容量
        if (!newbase)
            exit(OVERFLOW);  // 如果分配失败，退出程序
        L.elem = newbase;  // 更新基址
        L.listsize += LIST_INCREMENT;  // 增加存储容量
    }

    ElemType* p = L.elem + L.length - 1;  // 初始化指针 p 指向线性表的最后一个元素的存储位置
    ElemType* q = L.elem + i - 1;  // 初始化指针 q 指向插入位置的存储位置

    for (p; p >= q; --p)  // 用于将插入位置及其后面的元素向后移动一位
        *(p + 1) = *p;  // 将当前元素 *p 移动到下一个位置 *(p + 1)

    *q = e;  // 插入元素 e
    ++L.length;  // 表长+1
    return OK;
}