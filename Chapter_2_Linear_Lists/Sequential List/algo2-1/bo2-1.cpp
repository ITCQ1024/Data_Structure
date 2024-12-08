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

Status GetElem(SqList L, int i, ElemType& e) {
	//初始条件:顺序线性表L已存在 1<=i<=ListLength(L) 操作结果:用e返回L中第i个元素的值
	//检查位置 i 是否在有效范围内（即 1 到 L.length 之间）。如果不在有效范围内，返回 ERROR，表示操作失败。
	if (i<1 || i>L.length)
		return ERROR;
	else
		e = *(L.elem + i - 1);// e = L.elem[i - 1] 和 e = *(L.elem + i - 1) 在功能上是完全等价的
		//数组下标访问: e = L.elem[i - 1] 更直观，易于理解。
		//指针运算 : e = *(L.elem + i - 1) 更接近底层实现，可能在一些情况下更高效。
	return OK;
}


//函数指针 compare

//在C语言中，函数指针是一种特殊的指针类型，它指向一个函数的入口地址。函数指针可以作为参数传递给其他函数，从而实现回调机制。
//Status(*compare)(ElemType, ElemType) 是一个函数指针类型，它被用作 LocateElem 函数的参数。


//LocateElem()函数也要调用一类函数compare()。 由LocateElem() 函数的声明可以看出 : 
//要求这类函数具有2个形参，其类型均为ElemType; 函数的返回值为Status类型。
//不仅如此，根据LocateElem() 函数的说明(初始条件)，当compare()函数的2个形参满足给
//定条件时，返回值为1; 否则为0。只有满足这种条件的函数才能作为替代compare()函数的实参函数。

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	//初始条件:顺序线性表L已存在 compare()是数据元素判定函数(满足为1 否则为0)
	//操作结果:返回L中第一个与e满足关系compare()的数据元素的位序
	//		  若这样的元素不存在 则返回值为0 算法2.6

	int i = 1;//i的初值为第一个元素的位序
	ElemType* p = L.elem;//p的初值为第1个元素的存储位置
	while (i <= L.length && !compare(*p++, e)) //*p++ ++ 的优先级高于 * *p++ 等价于 *p p++
		++i;

	if (i <= L.length)
		return i;
	else
		return 0;
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