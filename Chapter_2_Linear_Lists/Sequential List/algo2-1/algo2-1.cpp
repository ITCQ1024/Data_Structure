//���������������Ա� LA �� LB �ֱ��ʾ�������� A �� B(�����Ա��е�����Ԫ�ؼ�Ϊ�����еĳ�Ա����
//��Ҫ��һ���µļ��� A = A U B �����Ҫ������Ա�������
//�������������Ա� LA, ���������Ա� LB �ж������������Ա� LA �е�����Ԫ�ز��뵽���Ա� LA ��ȥ��
//ֻҪ�����Ա� LB ������ȡ��ÿ������Ԫ�أ�����ֵ�����Ա� LA �н��в�ã��������ڣ������֮��
//�����������̿��������㷨����֮��
#include "c2-1.h"

// ��������
void Union(SqList& La, SqList Lb);

int main(int argc, char* argv[]) {
    SqList La, Lb;

    // ��ʼ�����Ա� La �� Lb
    InitList(La);
    InitList(Lb);

    // �����Ա� La �� Lb �в�������
    for (int i = 1; i <= 5; i++) {
        ListInsert(La, i, i);        // �� La �в��� 1, 2, 3, 4, 5
        ListInsert(Lb, i, i * 2);    // �� Lb �в��� 2, 4, 6, 8, 10
    }

    // ������Ա� La �� Lb ������
    cout << "La = ";
    ListTraverse(La, print1);

    cout << endl;
    cout << "Lb = ";
    ListTraverse(Lb, print1);
    cout << endl;

    // ���� Union �������� Lb �е�Ԫ�غϲ��� La ��
    Union(La, Lb);

    // ����ϲ�������Ա� La ������
    cout << "new La = ";
    ListTraverse(La, print1);
    cout << endl;
    return 0;
}

// �ϲ������������Ա� Lb �е�Ԫ�غϲ������Ա� La ��
void Union(SqList& La, SqList Lb) {
    ElemType e;  // ���ڴ洢�� Lb �л�ȡ��Ԫ��

    // ��ȡ���Ա� La �� Lb �ĳ���
    int len_A = ListLength(La);
    int len_B = ListLength(Lb);

    // �������Ա� Lb �е�ÿ��Ԫ��
    for (int i = 1; i <= len_B; i++) {
        // ��ȡ Lb �еĵ� i ��Ԫ��
        GetElem(Lb, i, e);

        // ��� Lb �е�Ԫ�� e �Ƿ������ La ��
        // ��������ڣ��� e ���뵽 La ��
        if (!LocateElem(La, e, equal))
            ListInsert(La, ++len_A, e);
    }
}