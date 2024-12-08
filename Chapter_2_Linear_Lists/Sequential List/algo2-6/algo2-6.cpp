#include "c2-1.h"

// ��������
int LocateElem(SqList L, ElemType e, Status(*comp)(ElemType, ElemType));

int main(int argc, char* argv[]) {
    SqList L;
    int k;
    ElemType e;

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

    // ����ֵΪ 10 �� 11 ��Ԫ��
    for (int j = 10; j <= 11; j++) {
        k = LocateElem(L, j, equal);
        if (k)
            printf("��%d��Ԫ�ص�ֵΪ%d\n\n", k, j);
        else
            printf("û��ֵΪ%d��Ԫ��\n\n", j);
    }

    return 0;
}

// ���Һ������������Ա� L �е�һ���� e ���� comp ��ϵ��Ԫ�ص�λ��
int LocateElem(SqList L, ElemType e, Status(*comp)(ElemType, ElemType)) {
    int i = 1;  // ��ʼ���������� i
    ElemType* p = L.elem + i - 1;  // ��ʼ��ָ�� p ָ�����Ա� L �ĵ�һ��Ԫ��

    // �������Ա� L �е�Ԫ�أ��������� comp ��ϵ��Ԫ��
    while (i <= L.length && !comp(*p++, e))
        ++i;

    // �������������Ԫ����δ�ҵ�����������Ԫ�أ����� 0
    if (i > L.length)
        return 0;
    else
        return i;  // �����ҵ���Ԫ�ص�λ��
}