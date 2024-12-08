//���������������Ա� LA �� LB �ֱ��ʾ�������� A �� B(�����Ա��е�����Ԫ�ؼ�Ϊ�����еĳ�Ա����
//��Ҫ��һ���µļ��� A = A U B �����Ҫ������Ա�������
//�������������Ա� LA, ���������Ա� LB �ж������������Ա� LA �е�����Ԫ�ز��뵽���Ա� LA ��ȥ��
//ֻҪ�����Ա� LB ������ȡ��ÿ������Ԫ�أ�����ֵ�����Ա� LA �н��в�ã��������ڣ������֮��
//�����������̿��������㷨����֮��
#include "c2-1.h"

// ��������
void MergeList(SqList La, SqList Lb, SqList& Lc);

int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    
    // ��ʼ�����Ա� La �� Lb
    InitList(La);
    InitList(Lb);

    // �����Ա� La �� Lb �в�������
    for (int i = 1; i <= 5; i++) {
        ListInsert(La, i, i);  // �� La �в��� 1, 2, 3, 4, 5
        ListInsert(Lb, i, i * 2);  // �� Lb �в��� 2, 4, 6, 8, 10
    }

    // ������Ա� La ������
    cout << "La = ";
    ListTraverse(La, print1);
    cout << endl;

    // ������Ա� Lb ������
    cout << "Lb = ";
    ListTraverse(Lb, print1);
    cout << endl;

    // ���� MergeList �������� La �� Lb �ϲ��� Lc ��
    MergeList(La, Lb, Lc);

    // ����ϲ�������Ա� Lc ������
    cout << "Lc = ";
    ListTraverse(Lc, print1);

    return 0;
}

// �ϲ������������Ա� La �� Lb �ϲ������Ա� Lc ��
void MergeList(SqList La, SqList Lb, SqList& Lc) {
    ElemType* pa = La.elem;  // ��ʼ��ָ�� pa ָ�����Ա� La �ĵ�һ��Ԫ��
    ElemType* pb = Lb.elem;  // ��ʼ��ָ�� pb ָ�����Ա� Lb �ĵ�һ��Ԫ��
    Lc.listsize = La.length + Lb.length;  // �������Ա� Lc �Ĵ洢����
    ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));  // Ϊ���Ա� Lc ����洢�ռ�
    if (!Lc.elem)
        exit(OVERFLOW);  // �������ʧ�ܣ��˳�����
    ElemType* pa_last = La.elem + La.length - 1;  // ��ʼ��ָ�� pa_last ָ�����Ա� La �����һ��Ԫ��
    ElemType* pb_last = Lb.elem + Lb.length - 1;  // ��ʼ��ָ�� pb_last ָ�����Ա� Lb �����һ��Ԫ��

    // �ϲ� La �� Lb �е�Ԫ�ص� Lc ��
    while (pa <= pa_last && pb <= pb_last) {
        switch (comp(*pa, *pb)) {
            case 0:  // ��� La �� Lb �е�Ԫ����ȣ����� Lb �е�Ԫ��
                pb++;
                break;
            case -1:  // ��� La �е�Ԫ��С�� Lb �е�Ԫ�أ��� La �е�Ԫ�ز��뵽 Lc ��
                *pc = *pa;
                ++pc;
                ++pa;
                break;
            case 1:  // ��� La �е�Ԫ�ش��� Lb �е�Ԫ�أ��� Lb �е�Ԫ�ز��뵽 Lc ��
                *pc = *pb;
                ++pc;
                ++pb;
                break;
        }
    }

    // ��� La �л���ʣ��Ԫ�أ�������뵽 Lc ��
    while (pa <= pa_last)
        *pc++ = *pa++;

    // ��� Lb �л���ʣ��Ԫ�أ�������뵽 Lc ��
    while (pb <= pb_last)
        *pc++ = *pb++;

    Lc.length = pc - Lc.elem;  // �������Ա� Lc �ĳ���
}