#include "c2-1.h"

Status equal(ElemType e1, ElemType e2) {
	//�ж��Ƿ���ȵĺ���
	if (e1 == e2)
		return TRUE;
	else
		return FALSE;
}

int comp(ElemType e1, ElemType e2) {
	//����e1<.=.>e2 �ֱ𷵻� -1 0 1
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
	//����Ԫ���ж�����(ƽ����ϵ) LocateElem()���õĺ���
	if (e1 == e2 * e2)
		return TRUE;
	else
		return FALSE;
}

void doubleValue(ElemType& e) {
	//ListTraverse()���õ���һ����(Ԫ�ؼӱ�)
	e *= 2;
}