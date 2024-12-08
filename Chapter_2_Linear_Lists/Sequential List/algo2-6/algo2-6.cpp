#include "c2-1.h"

// 函数声明
int LocateElem(SqList L, ElemType e, Status(*comp)(ElemType, ElemType));

int main(int argc, char* argv[]) {
    SqList L;
    int k;
    ElemType e;

    // 初始化线性表 L
    InitList(L);

    cout << endl;

    printf("初始化后:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);

    // 在 L 的表尾依次插入 1~10
    for (int j = 1; j <= 10; j++)
        ListInsert(L, j, j);

    cout << endl;

    printf("在L的表尾依次插入1~10后:*L.elem = ");

    ListTraverse(L, print1);

    cout << endl;

    // 查找值为 10 和 11 的元素
    for (int j = 10; j <= 11; j++) {
        k = LocateElem(L, j, equal);
        if (k)
            printf("第%d个元素的值为%d\n\n", k, j);
        else
            printf("没有值为%d的元素\n\n", j);
    }

    return 0;
}

// 查找函数，查找线性表 L 中第一个与 e 满足 comp 关系的元素的位置
int LocateElem(SqList L, ElemType e, Status(*comp)(ElemType, ElemType)) {
    int i = 1;  // 初始化索引变量 i
    ElemType* p = L.elem + i - 1;  // 初始化指针 p 指向线性表 L 的第一个元素

    // 遍历线性表 L 中的元素，查找满足 comp 关系的元素
    while (i <= L.length && !comp(*p++, e))
        ++i;

    // 如果遍历完所有元素仍未找到满足条件的元素，返回 0
    if (i > L.length)
        return 0;
    else
        return i;  // 返回找到的元素的位置
}