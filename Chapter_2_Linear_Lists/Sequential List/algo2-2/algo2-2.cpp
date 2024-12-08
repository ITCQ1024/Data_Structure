//已知线性表 LA 和 LB 中的数据元素按值非递减有序排列，现要求将 LA 和LB 归并为一个新的线性表 LC, LC 中的数据元素仍按值非递减有序排列。
//例如，设LA = (3, 5, 8, 11)LB = (2, 6, 8, 9, ll, 15, 20)
//则LC = (2, 3, 5, 6, 8, 8, 9, ll, ll, 15, 20)
#include "c2-1.h"

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
    int i = 0, j = 0, k = 0;  // 初始化索引变量 i, j, k
    int La_len = ListLength(La);  // 获取线性表 La 的长度
    int Lb_len = ListLength(Lb);  // 获取线性表 Lb 的长度
    ElemType ai, bj;  // 用于存储从 La 和 Lb 中获取的元素

    // 初始化线性表 Lc
    InitList(Lc);

    // 合并 La 和 Lb 中的元素到 Lc 中
    while (i < La_len && j < Lb_len) {
        // 获取 La 中的第 i+1 个元素
        GetElem(La, i + 1, ai);
        // 获取 Lb 中的第 j+1 个元素
        GetElem(Lb, j + 1, bj);

        // 比较 ai 和 bj，将较小的元素插入到 Lc 中
        if (ai <= bj) {
            ListInsert(Lc, ++k, ai);  // 将 ai 插入到 Lc 中
            ++i;  // 移动 La 的索引
        }
        else {
            ListInsert(Lc, ++k, bj);  // 将 bj 插入到 Lc 中
            ++j;  // 移动 Lb 的索引
        }
    }

    // 如果 La 中还有剩余元素，将其插入到 Lc 中
    while (i < La_len) {
        GetElem(La, ++i, ai);  // 获取 La 中的下一个元素
        ListInsert(Lc, ++k, ai);  // 将 ai 插入到 Lc 中
    }

    // 如果 Lb 中还有剩余元素，将其插入到 Lc 中
    while (j < Lb_len) {
        GetElem(Lb, ++j, bj);  // 获取 Lb 中的下一个元素
        ListInsert(Lc, ++k, bj);  // 将 bj 插入到 Lc 中
    }
}