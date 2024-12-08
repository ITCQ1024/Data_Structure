#include "c2-1.h"

// ��������
Status ListInsert(SqList& L, int i, ElemType e);

int main(int argc, char* argv[]) {
    SqList L;  // ����һ�����Ա� L

    InitList(L);  // ��ʼ�����Ա� L

    cout << endl;

    printf("L��ʼ����, L.elem = %p, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);  // ������Ա� L �ĳ�ʼ����Ϣ

    cout << endl;

    // �� L �ı�β���β��� 1~10
    for (int i = 1; i <= 10; i++)
        ListInsert(L, i, i);

    printf("��L�ı�β���β���1~10��:");

    ListTraverse(L, print1);  // ������������Ա� L ������

    cout << endl;

    return 0;
}

// ���뺯������˳�����Ա� L �ĵ� i ��λ�ò���Ԫ�� e
Status ListInsert(SqList& L, int i, ElemType e) {//�㷨2.4
    // ��ʼ����:˳�����Ա�L�Ѵ��� 1<=i<=ListLength(L)+1
    // �������:��˳�����Ա�L�еĵ� i �� λ���ϲ����µ�����Ԫ��e, L�ĳ���+1

    if (i < 1 || i > L.length + 1)  // ����λ�� i ���Ϸ�
        return ERROR;

    if (L.length >= L.listsize) {  // ������Ա�ĳ����Ѿ��ﵽ�򳬹���ǰ�Ĵ洢����
        ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));  // ���·����ڴ棬���Ӵ洢����
        if (!newbase)
            exit(OVERFLOW);  // �������ʧ�ܣ��˳�����
        L.elem = newbase;  // ���»�ַ
        L.listsize += LIST_INCREMENT;  // ���Ӵ洢����
    }

    ElemType* p = L.elem + L.length - 1;  // ��ʼ��ָ�� p ָ�����Ա�����һ��Ԫ�صĴ洢λ��
    ElemType* q = L.elem + i - 1;  // ��ʼ��ָ�� q ָ�����λ�õĴ洢λ��

    for (p; p >= q; --p)  // ���ڽ�����λ�ü�������Ԫ������ƶ�һλ
        *(p + 1) = *p;  // ����ǰԪ�� *p �ƶ�����һ��λ�� *(p + 1)

    *q = e;  // ����Ԫ�� e
    ++L.length;  // ��+1
    return OK;
}