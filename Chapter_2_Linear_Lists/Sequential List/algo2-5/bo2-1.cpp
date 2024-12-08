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


int ListLength(SqList L) {
	//初始条件:顺序线性表L已经存在.操作结果 : 返回L中数据元素的个数
	return L.length;
}

//检查插入位置 i 是否在有效范围内，如果不在有效范围内，返回 ERROR。
//如果线性表的长度已经达到或超过当前的存储容量，重新分配内存，增加存储容量。
//将插入位置及其后面的元素向后移动一位，为新元素腾出空间。
//将新元素 e 插入到指定位置。
//增加线性表的长度。
//返回 OK，表示插入操作成功。

Status ListInsert(SqList& L, int i, ElemType e) {//算法2.4
	//初始条件:顺序线性表L已存在 1<=i<=ListLength(L)+1
	//操作结果:在顺序线性表L中的第 i 个 位置上插入新的数据元素e, L的长度+1

	if (i<1 || i>L.length + 1)//插入位置i不合法
		return ERROR;
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);//存储空间分配失败
		L.elem = newbase;//新基址
		L.listsize += LIST_INCREMENT;//增加存储容量
	}

	ElemType* p = L.elem + L.length - 1;//初始化指针 p 指向线性表的最后一个元素的存储位置。
	ElemType* q = L.elem + i - 1;//初始化指针 q 指向插入位置的存储位置。

	for (p; p >= q; --p) //用于将插入位置及其后面的元素向后移动一位
		*(p + 1) = *p;//将当前元素 *p 移动到下一个位置 *(p + 1)。

	*q = e;//插入e
	++L.length;//表长+1
	return OK;
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