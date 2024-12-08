//Basic Operations 每种存储结构的一组基本操作函数。以 bo(bo 表示基本操作)开头

#include "c2-1.h"

void InitList(SqList& L) {
	//操作结果:构造一个空的顺序线性表L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);//存储空间分配失败
	L.length = 0;//空表长度为0
	L.listsize = LIST_INIT_SIZE;//初始化存储容量
}


//遍历顺序线性表
//参数 visit 是一个函数指针，指向一个接受 ElemType& 类型参数的函数。该函数用于处理线性表中的每个元素。

//ListTraverse() 函数要调用visit() 函数，visit()  是ListTraverse()的形参。因
//为visit() 不是一个特定的函数，它是满足一定条件的一类函数， 所以称其为函数类形参。在
//函数类形参的声明中指定了visit() 的函数类型，也就是函数返回值的类型(void)。在声明中
//还指定了visit()  函数形参的个数(1个)和类型(ElemType的引用类型)。所有满足条件的函数
//(返回值为void 类型，有一一个形参，且类型为ElemType&)，都可以作为ListTraverse() 函
//数的实参。

void ListTraverse(SqList L, void(*visit)(ElemType&)) {
	//初始条件:顺序线性表L已存在 
	//操作结果:依次对L的每个数据元素调用函数visit()
	//	      visit()的形参加上& 引用 表明可以通过调用visit()改变数据元素的值
	ElemType* p = L.elem;//初始化指针 p 指向线性表L中第一个数据元素的存储位置
	for (int i = 0; i < L.length; i++)
		visit(*p++);
	printf("\n");
}