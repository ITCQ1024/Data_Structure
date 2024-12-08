#include "c2-1.h"

// 初始化线性表 L
void InitList(SqList& L);

int main(int argc, char* argv[]) {
    SqList L;  // 定义一个线性表 L
    InitList(L);  // 初始化线性表 L
	cout<<endl;
    printf("L初始化后, L.elem = %p, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);  // 输出线性表 L 的初始化信息
    return 0;
}

// 初始化线性表 L
void InitList(SqList& L) {
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));  // 为线性表 L 分配初始存储空间
    if (!L.elem)
        exit(OVERFLOW);  // 如果分配失败，退出程序
    L.length = 0;  // 初始化线性表 L 的长度为 0
    L.listsize = LIST_INIT_SIZE;  // 初始化线性表 L 的存储容量为 LIST_INIT_SIZE
}