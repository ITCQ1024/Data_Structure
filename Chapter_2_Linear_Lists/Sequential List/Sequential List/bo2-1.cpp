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

void DestroyList(SqList& L) {
	//初始条件:顺序线性表L已经存在. 操作结果:销毁顺序线性表L
	free(L.elem); //使用 free 函数释放之前通过 malloc 分配的内存。这会释放 L.elem 指向的内存空间，防止内存泄漏。
	L.elem = NULL;//将 L.elem 指针设置为 NULL，以避免悬空指针问题。悬空指针是指向已释放内存的指针，可能会导致未定义行为
	L.length = 0;
	L.listsize = 0;
}

//仅重置长度
//只是将 L.length 设置为 0，没有释放或重新初始化存储空间，那么线性表的存储空间仍然存在，只是长度被重置为 0。
//这意味着虽然线性表在逻辑上被清空了，但实际的存储空间并没有被释放，后续添加元素时会覆盖原有的数据

void ClearList(SqList& L) {
	//初始条件:顺序线性表L已经存在. 操作结果:将L重置为空表
	L.length = 0;
}

//void ClearList(SqList& L) {
//	 初始条件:顺序线性表L已经存在. 操作结果:将L重置为空表
//	free(L.elem);  // 释放原有的存储空间
//	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));  // 重新分配初始大小的存储空间
//	if (!L.elem)
//		exit(OVERFLOW);  // 存储空间分配失败
//	L.length = 0;  // 重置长度
//	L.listsize = LIST_INIT_SIZE;  // 重置存储容量
//}
//
//void ClearList(SqList& L) {
//	 初始条件:顺序线性表L已经存在. 操作结果:将L重置为空表
//	memset(L.elem, 0, L.listsize * sizeof(ElemType));  // 将存储空间中的数据全部设置为 0
//	L.length = 0;  // 重置长度
//}
//
//void ClearList(SqList& L) {
//	 初始条件:顺序线性表L已经存在. 操作结果:将L重置为空表
//	L.length = 0;
//}


//检查一个已经存在的顺序线性表 L 是否为空
Status ListEmpty(SqList L) {
	//初始条件:顺序线性表L已经存在.操作结果 : 若L为空表 则返回TRUE 否则 返回 FALSE
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
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


//cur_e 要查找前驱的元素。  pre_e是cur_e 的前驱元素

//初始化位置 i 为 2，指针 p 指向线性表的第二个元素。
//遍历线性表中的元素，查找目标元素 cur_e。
//如果找到目标元素 cur_e，则将其前驱元素的值赋给 pre_e，并返回 OK。
//如果遍历完所有元素仍未找到目标元素 cur_e，则返回 INFEASIBLE，表示操作失败。
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e) {
	//初始条件:顺序线性表L已存在
	//操作结果:若cur_e是L的数据元素 且不是第一个 则用pre_e返回它的前驱
	//		  否则操作失败 pre_e无定义
	int i = 2; //i的初值为顺序线性表L中第2个元素的位序
	ElemType* p = L.elem + 1;//p的初值为顺序线性表L中第2个元素的存储位置

	/*i <= L.length: 检查当前位置 i 是否在有效范围内（即 2 到 L.length 之间）。
	* p != cur_e : 检查当前元素 * p 是否等于目标元素 cur_e。
	++i; : 如果当前元素不等于目标元素，则将位置 i 加 1，继续查找下一个元素。
	++p; : 如果当前元素不等于目标元素，则将指针 p 移动到下一个元素的位置*/
	while (i <= L.length && *p != cur_e) {
		++i;//位序后移
		++p;//存储位置后移
	}

	if (i > L.length) {//遍历完整个顺序线性表L 走到头了 跳出循环后 发现 i >L.length 说明没找到cur_e 也就没有相应的前驱
		return INFEASIBLE;//如果 i 超出了有效范围，表示未找到目标元素 cur_e，返回 INFEASIBLE，表示操作失败。
	}
	else {
		//位序合法 p指向的是cur_e的存储位置 要它的前驱 理应--p
		pre_e = *--p;//将指针 p 回退一个位置，即指向 cur_e 的前驱元素，并将该元素的值赋给 pre_e
		return OK;
	}
}

//初始化位置 i 为 1，指针 p 指向线性表的第一个元素。
//遍历线性表中的元素，查找目标元素 cur_e。
//如果找到目标元素 cur_e，则将其后继元素的值赋给 next_e，并返回 OK。
//如果遍历完所有元素仍未找到目标元素 cur_e，则返回 INFEASIBLE，表示操作失败。
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e) {
	//初始条件:顺序线性表L已存在
	//操作结果:若cur_e是L的数据元素 且不是最后一个 则用next_e返回它的后继
	//		  否则操作失败 next_e无定义
	int i = 1;					//i的初值为顺序线性表L中第1个元素的位序
	ElemType* p = L.elem;		//p的初值为顺序线性表L中第1个元素的存储位置

	/*i < L.length: 检查当前位置 i 是否在有效范围内（即 1 到 L.length - 1 之间）。
	* p != cur_e : 检查当前元素 * p 是否等于目标元素 cur_e。
	++i; : 如果当前元素不等于目标元素，则将位置 i 加 1，继续查找下一个元素。
	++p; : 如果当前元素不等于目标元素，则将指针 p 移动到下一个元素的位置。*/

	while (i < L.length && *p != cur_e) {
		++i;//位序后移
		++p;//存储位置后移
	}
	if (i == L.length) {//遍历完整个顺序线性表L 走到头了 跳出循环后 发现 i == L.length 说明没找到cur_e 也就没有相应的后继
		return INFEASIBLE;//如果 i 等于 L.length，表示未找到目标元素 cur_e，返回 INFEASIBLE，表示操作失败。
	}
	else {
		//位序合法 p指向的是cur_e的存储位置 要它的后继 理应++p
		next_e = *++p;		//将指针 p 移动到下一个位置，即指向 cur_e 的后继元素，并将该元素的值赋给 next_e。
		return OK;
	}
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

Status ListDelete(SqList& L, int i, ElemType& e) {
	//初始条件:顺序线性表L已存在 1<=i<=ListLength(L)
	//操作结果:删除顺序线性表L中的第i个数据元素,并用e返回其值,L的长度-1
	if (i<1 || i>L.length)//i的值不合法
		return ERROR;
	ElemType* p = L.elem + i - 1; //初始化指针 p 指向线性表L待删除数据元素的存储位置。
	ElemType* q = L.elem + L.length - 1;//初始化指针 q 指向线性表的最后一个数据元素的存储位置。

	e = *p;//将待删除的数据元素赋值给e

	for (p; p < q; p++)//从要删除的元素开始，将后面的元素依次向前移动一位，覆盖掉要删除的元素。
		*p = *(p+1);

	--L.length;
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