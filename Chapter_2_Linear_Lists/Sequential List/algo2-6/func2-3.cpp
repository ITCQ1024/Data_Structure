#include "c2-1.h"

Status equal(ElemType e1, ElemType e2) {
	//�ж��Ƿ���ȵĺ���
	if (e1 == e2)
		return TRUE;
	else
		return FALSE;
}


void print1(ElemType& e) {
	printf("%d ", e);
}

