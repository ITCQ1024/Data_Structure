//
//#include "c2-1.h"
//
//
//int main(int argc, char* argv[]) {
//	Status i;
//	ElemType e,e1,e2;
//	SqList L;
//	int k;
//
//	InitList(L);
//
//	printf("初始化后:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
//
//	for (int j = 1; j <= 5; j++)
//		i = ListInsert(L, 1, j);
//	
//	cout << endl;
//
//	printf("在L的表头依次插入1~5后:*L.elem = ");
//
//	for (int j = 1; j <= 5; j++)
//		cout << *(L.elem + j - 1) << " ";
//
//	cout << endl << endl;
//
//	printf("在L的表头依次插入1~5后:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
//	
//	cout << endl;
//
//	i = ListEmpty(L);
//
//	printf("L是否为空:i=%d(1:是 0:否)\n", i);
//
//	cout << endl;
//
//	ClearList(L);
//
//	i = ListEmpty(L);
//
//	printf("L是否为空:i=%d(1:是 0:否)\n", i);
//
//	cout << endl;
//
//	printf("清空L后:L.elem = %p L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);
//	
//	cout << endl;
//
//	for (int j = 1; j <= 10; j++)
//		i = ListInsert(L, j, j);
//
//
//	printf("在L的表尾依次插入1~10后:*L.elem = ");
//
//	for (int j = 1; j <= 10; j++)
//		cout << *(L.elem + j - 1) << " ";
//
//	cout << endl << endl;
//
//	printf("在L的表尾依次插入1~10后:L.elem = %p L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);
//
//
//
//	cout << endl;
//
//	ListInsert(L, 1, 0);
//	printf("在L的表头依次插入0后:*L.elem = ");
//
//
//	for (int j = 1; j <= ListLength(L); j++)
//		cout << *(L.elem + j - 1) << " ";
//
//	cout << endl << endl;
//
//	printf("在L的表头依次插入0后:*L.elem = %p (基址有可能改变) L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);
//
//	cout << endl;
//
//	GetElem(L, 5, e);
//
//	printf("第5个元素的值为:%d\n", e);
//
//	cout << endl;
//
//	for (int j = 10; j <= 11; j++) {
//		k = LocateElem(L, j, equal);
//		if (k)
//			printf("第%d个元素的值为%d\n\n", k, j);
//		else
//			printf("没有值为%d的元素\n\n", j);
//	}
//
//	for (int j = 3; j <= 4; j++) {
//		k=LocateElem(L, j,square);
//		if (k)
//			printf("第%d个元素的值为%d的平方\n\n", k, j);
//		else
//			printf("没有值为%d的平方的元素\n\n", j);
//	}
//
//	for (int j = 1; j <= 2; j++) {
//		GetElem(L, j, e2);
//		i = PriorElem(L, e2, e1);
//		if (i == INFEASIBLE)
//			printf("元素%d无前驱\n\n", e2);
//		else
//			printf("元素%d的前驱为%d\n\n", e2, e1);
//	}
//
//	for (int j = ListLength(L) - 1; j <= ListLength(L); j++) {
//		GetElem(L, j, e1);
//		i = NextElem(L, e1, e2);
//		if (i == INFEASIBLE)
//			printf("元素%d无后继\n\n", e1);
//		else
//			printf("元素%d的后继为%d\n\n", e1, e2);
//	}
//
//	k = ListLength(L);
//
//	for (int j = k + 1; j >= k; j--) {
//		i = ListDelete(L, j, e);
//		if (i == ERROR)
//			printf("删除第%d个元素失败\n\n", j);
//		else
//			printf("删除第%d个元素成功,其值为%d\n\n",j, e);
//		
//	}
//
//	printf("依次输出L的元素:");
//
//	ListTraverse(L, print1);
//
//	cout << endl;
//
//	printf("L的元素值加倍后:");
//
//	ListTraverse(L, doubleValue);
//
//	cout << endl;
//
//	ListTraverse(L, print1);
//
//	cout << endl;
//
//	DestroyList(L);
//
//	printf("销毁L后:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
//
//	return 0;
//}