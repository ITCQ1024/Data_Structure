//假设利用两个线性表 LA 和 LB 分别表示两个集合 A 和 B(即线性表中的数据元素即为集合中的成员），
//现要求一个新的集合 A = A U B 。这就要求对线性表作如下
//操作：扩大线性表 LA, 将存在线性表 LB 中而不存在于线性表 LA 中的数据元素插入到线性表 LA 中去。
//只要从线性表 LB 中依次取得每个数据元素，并依值在线性表 LA 中进行查访，若不存在，则插入之。
//上述操作过程可用下列算法描述之。
#include "c2-1.h"

// 函数声明
void Union(SqList& La, SqList Lb);

int main(int argc, char* argv[]) {
    SqList La, Lb;

    // 初始化线性表 La 和 Lb
    InitList(La);
    InitList(Lb);

    // 向线性表 La 和 Lb 中插入数据
    for (int i = 1; i <= 5; i++) {
        ListInsert(La, i, i);        // 向 La 中插入 1, 2, 3, 4, 5
        ListInsert(Lb, i, i * 2);    // 向 Lb 中插入 2, 4, 6, 8, 10
    }

    // 输出线性表 La 和 Lb 的内容
    cout << "La = ";
    ListTraverse(La, print1);

    cout << endl;
    cout << "Lb = ";
    ListTraverse(Lb, print1);
    cout << endl;

    // 调用 Union 函数，将 Lb 中的元素合并到 La 中
    Union(La, Lb);

    // 输出合并后的线性表 La 的内容
    cout << "new La = ";
    ListTraverse(La, print1);
    cout << endl;
    return 0;
}

// 合并函数，将线性表 Lb 中的元素合并到线性表 La 中
void Union(SqList& La, SqList Lb) {
    ElemType e;  // 用于存储从 Lb 中获取的元素

    // 获取线性表 La 和 Lb 的长度
    int len_A = ListLength(La);
    int len_B = ListLength(Lb);

    // 遍历线性表 Lb 中的每个元素
    for (int i = 1; i <= len_B; i++) {
        // 获取 Lb 中的第 i 个元素
        GetElem(Lb, i, e);

        // 检查 Lb 中的元素 e 是否存在于 La 中
        // 如果不存在，则将 e 插入到 La 中
        if (!LocateElem(La, e, equal))
            ListInsert(La, ++len_A, e);
    }
}