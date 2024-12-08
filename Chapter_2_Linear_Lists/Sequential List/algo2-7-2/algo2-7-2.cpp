//假设利用两个线性表 LA 和 LB 分别表示两个集合 A 和 B(即线性表中的数据元素即为集合中的成员），
//现要求一个新的集合 A = A U B 。这就要求对线性表作如下
//操作：扩大线性表 LA, 将存在线性表 LB 中而不存在于线性表 LA 中的数据元素插入到线性表 LA 中去。
//只要从线性表 LB 中依次取得每个数据元素，并依值在线性表 LA 中进行查访，若不存在，则插入之。
//上述操作过程可用下列算法描述之。
#include "c2-1.h"

// 函数声明
void MergeList(SqList La, SqList Lb, SqList& Lc);

int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    
    // 初始化线性表 La 和 Lb
    InitList(La);
    InitList(Lb);

    // 向线性表 La 和 Lb 中插入数据
    for (int i = 1; i <= 5; i++) {
        ListInsert(La, i, i);  // 向 La 中插入 1, 2, 3, 4, 5
        ListInsert(Lb, i, i * 2);  // 向 Lb 中插入 2, 4, 6, 8, 10
    }

    // 输出线性表 La 的内容
    cout << "La = ";
    ListTraverse(La, print1);
    cout << endl;

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
    Lc.listsize = La.length + Lb.length;  // 设置线性表 Lc 的存储容量
    ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));  // 为线性表 Lc 分配存储空间
    if (!Lc.elem)
        exit(OVERFLOW);  // 如果分配失败，退出程序
    ElemType* pa_last = La.elem + La.length - 1;  // 初始化指针 pa_last 指向线性表 La 的最后一个元素
    ElemType* pb_last = Lb.elem + Lb.length - 1;  // 初始化指针 pb_last 指向线性表 Lb 的最后一个元素

    // 合并 La 和 Lb 中的元素到 Lc 中
    while (pa <= pa_last && pb <= pb_last) {
        switch (comp(*pa, *pb)) {
            case 0:  // 如果 La 和 Lb 中的元素相等，跳过 Lb 中的元素
                pb++;
                break;
            case -1:  // 如果 La 中的元素小于 Lb 中的元素，将 La 中的元素插入到 Lc 中
                *pc = *pa;
                ++pc;
                ++pa;
                break;
            case 1:  // 如果 La 中的元素大于 Lb 中的元素，将 Lb 中的元素插入到 Lc 中
                *pc = *pb;
                ++pc;
                ++pb;
                break;
        }
    }

    // 如果 La 中还有剩余元素，将其插入到 Lc 中
    while (pa <= pa_last)
        *pc++ = *pa++;

    // 如果 Lb 中还有剩余元素，将其插入到 Lc 中
    while (pb <= pb_last)
        *pc++ = *pb++;

    Lc.length = pc - Lc.elem;  // 设置线性表 Lc 的长度
}