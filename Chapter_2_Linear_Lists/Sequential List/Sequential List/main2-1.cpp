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
//	printf("��ʼ����:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
//
//	for (int j = 1; j <= 5; j++)
//		i = ListInsert(L, 1, j);
//	
//	cout << endl;
//
//	printf("��L�ı�ͷ���β���1~5��:*L.elem = ");
//
//	for (int j = 1; j <= 5; j++)
//		cout << *(L.elem + j - 1) << " ";
//
//	cout << endl << endl;
//
//	printf("��L�ı�ͷ���β���1~5��:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
//	
//	cout << endl;
//
//	i = ListEmpty(L);
//
//	printf("L�Ƿ�Ϊ��:i=%d(1:�� 0:��)\n", i);
//
//	cout << endl;
//
//	ClearList(L);
//
//	i = ListEmpty(L);
//
//	printf("L�Ƿ�Ϊ��:i=%d(1:�� 0:��)\n", i);
//
//	cout << endl;
//
//	printf("���L��:L.elem = %p L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);
//	
//	cout << endl;
//
//	for (int j = 1; j <= 10; j++)
//		i = ListInsert(L, j, j);
//
//
//	printf("��L�ı�β���β���1~10��:*L.elem = ");
//
//	for (int j = 1; j <= 10; j++)
//		cout << *(L.elem + j - 1) << " ";
//
//	cout << endl << endl;
//
//	printf("��L�ı�β���β���1~10��:L.elem = %p L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);
//
//
//
//	cout << endl;
//
//	ListInsert(L, 1, 0);
//	printf("��L�ı�ͷ���β���0��:*L.elem = ");
//
//
//	for (int j = 1; j <= ListLength(L); j++)
//		cout << *(L.elem + j - 1) << " ";
//
//	cout << endl << endl;
//
//	printf("��L�ı�ͷ���β���0��:*L.elem = %p (��ַ�п��ܸı�) L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);
//
//	cout << endl;
//
//	GetElem(L, 5, e);
//
//	printf("��5��Ԫ�ص�ֵΪ:%d\n", e);
//
//	cout << endl;
//
//	for (int j = 10; j <= 11; j++) {
//		k = LocateElem(L, j, equal);
//		if (k)
//			printf("��%d��Ԫ�ص�ֵΪ%d\n\n", k, j);
//		else
//			printf("û��ֵΪ%d��Ԫ��\n\n", j);
//	}
//
//	for (int j = 3; j <= 4; j++) {
//		k=LocateElem(L, j,square);
//		if (k)
//			printf("��%d��Ԫ�ص�ֵΪ%d��ƽ��\n\n", k, j);
//		else
//			printf("û��ֵΪ%d��ƽ����Ԫ��\n\n", j);
//	}
//
//	for (int j = 1; j <= 2; j++) {
//		GetElem(L, j, e2);
//		i = PriorElem(L, e2, e1);
//		if (i == INFEASIBLE)
//			printf("Ԫ��%d��ǰ��\n\n", e2);
//		else
//			printf("Ԫ��%d��ǰ��Ϊ%d\n\n", e2, e1);
//	}
//
//	for (int j = ListLength(L) - 1; j <= ListLength(L); j++) {
//		GetElem(L, j, e1);
//		i = NextElem(L, e1, e2);
//		if (i == INFEASIBLE)
//			printf("Ԫ��%d�޺��\n\n", e1);
//		else
//			printf("Ԫ��%d�ĺ��Ϊ%d\n\n", e1, e2);
//	}
//
//	k = ListLength(L);
//
//	for (int j = k + 1; j >= k; j--) {
//		i = ListDelete(L, j, e);
//		if (i == ERROR)
//			printf("ɾ����%d��Ԫ��ʧ��\n\n", j);
//		else
//			printf("ɾ����%d��Ԫ�سɹ�,��ֵΪ%d\n\n",j, e);
//		
//	}
//
//	printf("�������L��Ԫ��:");
//
//	ListTraverse(L, print1);
//
//	cout << endl;
//
//	printf("L��Ԫ��ֵ�ӱ���:");
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
//	printf("����L��:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
//
//	return 0;
//}