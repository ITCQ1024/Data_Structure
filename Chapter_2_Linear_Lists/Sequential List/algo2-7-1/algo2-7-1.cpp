#include "c2-1.h"
//已知线性表 LA 和 LB 中的数据元素按值非递减有序排列，现要求将 LA 和LB 归并为一个新的线性表 LC, LC 中的数据元素仍按值非递减有序排列。
//例如，设LA = (3, 5, 8, 11)LB = (2, 6, 8, 9, ll, 15, 20)
//则LC = (2, 3, 5, 6, 8, 8, 9, ll, ll, 15, 20)
// 函数声明
void MergeList(SqList La, SqList Lb, SqList& Lc);

int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int a[4] = { 3, 5, 8, 11 };  // 定义数组 a，包含元素 3, 5, 8, 11
    int b[7] = { 2, 6, 8, 9, 11, 15, 20 };  // 定义数组 b，包含元素 2, 6, 8, 9, 11, 15, 20
    int len_a_arry = sizeof(a) / sizeof(a[0]);  // 计算数组 a 的长度
    int len_b_array = sizeof(b) / sizeof(b[0]);  // 计算数组 b 的长度

    // 初始化线性表 La 和 Lb
    InitList(La);
    InitList(Lb);

    cout << endl;

    // 将数组 a 中的元素插入到线性表 La 中
    for (int i = 0; i < len_a_arry; i++)
        ListInsert(La, i + 1, a[i]);

    // 输出线性表 La 的内容
    cout << "La = ";
    ListTraverse(La, print1);
    cout << endl;

    // 将数组 b 中的元素插入到线性表 Lb 中
    for (int i = 0; i < len_b_array; i++)
        ListInsert(Lb, i + 1, b[i]);

    // 输出线性表 Lb 的内容
    cout << "Lb = ";
    ListTraverse(Lb, print1);
    cout << endl;

    // 调用 MergeList 函数，将 La 和 Lb 合并到 Lc 中
    MergeList(La, Lb, Lc);

    // 输出合并后的线性表 Lc 的内容
    cout << "Lc = ";
    ListTraverse(Lc, print1);

    return 0;
}

// 合并函数，将线性表 La 和 Lb 合并到线性表 Lc 中
void MergeList(SqList La, SqList Lb, SqList& Lc) {
    ElemType* pa = La.elem;  // 初始化指针 pa 指向线性表 La 的第一个元素
    ElemType* pb = Lb.elem;  // 初始化指针 pb 指向线性表 Lb 的第一个元素
    Lc.listsize = Lc.length = La.length + Lb.length;  // 设置线性表 Lc 的存储容量和长度
    ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));  // 为线性表 Lc 分配存储空间
    if (!Lc.elem)
        exit(OVERFLOW);  // 如果分配失败，退出程序
    ElemType* pa_last = La.elem + La.length - 1;  // 初始化指针 pa_last 指向线性表 La 的最后一个元素
    ElemType* pb_last = Lb.elem + Lb.length - 1;  // 初始化指针 pb_last 指向线性表 Lb 的最后一个元素

    // 合并 La 和 Lb 中的元素到 Lc 中
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb)
            *pc++ = *pa++;  // 如果 La 中的元素小于等于 Lb 中的元素，将 La 中的元素插入到 Lc 中
        else
            *pc++ = *pb++;  // 否则，将 Lb 中的元素插入到 Lc 中
    }

    // 如果 La 中还有剩余元素，将其插入到 Lc 中
    while (pa <= pa_last)
        *pc++ = *pa++;

    // 如果 Lb 中还有剩余元素，将其插入到 Lc 中
    while (pb <= pb_last)
        *pc++ = *pb++;
}