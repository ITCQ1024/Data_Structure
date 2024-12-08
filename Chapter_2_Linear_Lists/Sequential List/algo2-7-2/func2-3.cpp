#include "c2-1.h"

void print1(ElemType& e) {
	printf("%d ", e);
}

int comp(ElemType e1, ElemType e2) {
	//根据e1<.=.>e2 分别返回 -1 0 1
	if (e1 == e2)
		return 0;
	else
		return (e1 - e2) / abs(e1 - e2);
}