#include "c2-1.h"

Status equal(ElemType e1, ElemType e2) {
	//判断是否相等的函数
	if (e1 == e2)
		return TRUE;
	else
		return FALSE;
}

int comp(ElemType e1, ElemType e2) {
	//根据e1<.=.>e2 分别返回 -1 0 1
	if (e1 == e2)
		return 0;
	else
		return (e1 - e2) / abs(e1 - e2);
}

void print(ElemType e) {
	printf("%d", e);
}

void print1(ElemType& e) {
	printf("%d ", e);
}

void printf2(ElemType e) {
	printf("%c", e);
}

Status square(ElemType e1, ElemType e2) {
	//数据元素判定函数(平方关系) LocateElem()调用的函数
	if (e1 == e2 * e2)
		return TRUE;
	else
		return FALSE;
}

void doubleValue(ElemType& e) {
	//ListTraverse()调用的另一函数(元素加倍)
	e *= 2;
}