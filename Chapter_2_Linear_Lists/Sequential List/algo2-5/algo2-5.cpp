#include "c2-1.h"

// 函数声明
Status ListDelete(SqList& L, int i, ElemType& e);

int main(int argc, char* argv[]) {
    SqList L;
    ElemType e;
    Status i;

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

    printf("在L的表尾依次插入1~10后:L.elem = %p L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);

    cout << endl;
	
	int len=ListLength(L);

    // 删除第 8 到第 12 个元素
    for (int j = len+2; j >= len-4; j--) {
        i = ListDelete(L, j, e);
        if (i == ERROR)
            printf("删除第%d个元素失败\n\n", j);
        else
            printf("删除第%d个元素成功,其值为%d\n\n", j, e);
    }

    printf("经删除操作后,*L.elem = ");

    ListTraverse(L, print1);

    return 0;
}

// 删除函数，删除顺序线性表 L 中第 i 个元素
Status ListDelete(SqList& L, int i, ElemType& e) {
    if (i < 1 || i > L.length)  // 检查删除位置 i 是否在有效范围内
        return ERROR;

    ElemType* p = L.elem + i - 1;  // 初始化指针 p 指向要删除的元素的存储位置
    ElemType* q = L.elem + L.length - 1;  // 初始化指针 q 指向线性表的最后一个元素的存储位置

    e = *p;  // 将要删除的元素赋值给 e

    // 将删除位置后面的元素向前移动一位
    for (p; p < q; p++)
        *p = *(p + 1);

    --L.length;  // 减少线性表的长度
    return OK;
}