#include "c2-1.h"

// ��������
Status ListDelete(SqList& L, int i, ElemType& e);

int main(int argc, char* argv[]) {
    SqList L;
    ElemType e;
    Status i;

    // ��ʼ�����Ա� L
    InitList(L);

    cout << endl;

    printf("��ʼ����:L.elem=%p L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);

    // �� L �ı�β���β��� 1~10
    for (int j = 1; j <= 10; j++)
        ListInsert(L, j, j);

    cout << endl;

    printf("��L�ı�β���β���1~10��:*L.elem = ");

    ListTraverse(L, print1);

    cout << endl;

    printf("��L�ı�β���β���1~10��:L.elem = %p L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);

    cout << endl;
	
	int len=ListLength(L);

    // ɾ���� 8 ���� 12 ��Ԫ��
    for (int j = len+2; j >= len-4; j--) {
        i = ListDelete(L, j, e);
        if (i == ERROR)
            printf("ɾ����%d��Ԫ��ʧ��\n\n", j);
        else
            printf("ɾ����%d��Ԫ�سɹ�,��ֵΪ%d\n\n", j, e);
    }

    printf("��ɾ��������,*L.elem = ");

    ListTraverse(L, print1);

    return 0;
}

// ɾ��������ɾ��˳�����Ա� L �е� i ��Ԫ��
Status ListDelete(SqList& L, int i, ElemType& e) {
    if (i < 1 || i > L.length)  // ���ɾ��λ�� i �Ƿ�����Ч��Χ��
        return ERROR;

    ElemType* p = L.elem + i - 1;  // ��ʼ��ָ�� p ָ��Ҫɾ����Ԫ�صĴ洢λ��
    ElemType* q = L.elem + L.length - 1;  // ��ʼ��ָ�� q ָ�����Ա�����һ��Ԫ�صĴ洢λ��

    e = *p;  // ��Ҫɾ����Ԫ�ظ�ֵ�� e

    // ��ɾ��λ�ú����Ԫ����ǰ�ƶ�һλ
    for (p; p < q; p++)
        *p = *(p + 1);

    --L.length;  // �������Ա�ĳ���
    return OK;
}