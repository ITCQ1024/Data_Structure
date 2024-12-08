#include "c2-1.h"
//��֪���Ա� LA �� LB �е�����Ԫ�ذ�ֵ�ǵݼ��������У���Ҫ�� LA ��LB �鲢Ϊһ���µ����Ա� LC, LC �е�����Ԫ���԰�ֵ�ǵݼ��������С�
//���磬��LA = (3, 5, 8, 11)LB = (2, 6, 8, 9, ll, 15, 20)
//��LC = (2, 3, 5, 6, 8, 8, 9, ll, ll, 15, 20)
// ��������
void MergeList(SqList La, SqList Lb, SqList& Lc);

int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int a[4] = { 3, 5, 8, 11 };  // �������� a������Ԫ�� 3, 5, 8, 11
    int b[7] = { 2, 6, 8, 9, 11, 15, 20 };  // �������� b������Ԫ�� 2, 6, 8, 9, 11, 15, 20
    int len_a_arry = sizeof(a) / sizeof(a[0]);  // �������� a �ĳ���
    int len_b_array = sizeof(b) / sizeof(b[0]);  // �������� b �ĳ���

    // ��ʼ�����Ա� La �� Lb
    InitList(La);
    InitList(Lb);

    cout << endl;

    // ������ a �е�Ԫ�ز��뵽���Ա� La ��
    for (int i = 0; i < len_a_arry; i++)
        ListInsert(La, i + 1, a[i]);

    // ������Ա� La ������
    cout << "La = ";
    ListTraverse(La, print1);
    cout << endl;

    // ������ b �е�Ԫ�ز��뵽���Ա� Lb ��
    for (int i = 0; i < len_b_array; i++)
        ListInsert(Lb, i + 1, b[i]);

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
    Lc.listsize = Lc.length = La.length + Lb.length;  // �������Ա� Lc �Ĵ洢�����ͳ���
    ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));  // Ϊ���Ա� Lc ����洢�ռ�
    if (!Lc.elem)
        exit(OVERFLOW);  // �������ʧ�ܣ��˳�����
    ElemType* pa_last = La.elem + La.length - 1;  // ��ʼ��ָ�� pa_last ָ�����Ա� La �����һ��Ԫ��
    ElemType* pb_last = Lb.elem + Lb.length - 1;  // ��ʼ��ָ�� pb_last ָ�����Ա� Lb �����һ��Ԫ��

    // �ϲ� La �� Lb �е�Ԫ�ص� Lc ��
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb)
            *pc++ = *pa++;  // ��� La �е�Ԫ��С�ڵ��� Lb �е�Ԫ�أ��� La �е�Ԫ�ز��뵽 Lc ��
        else
            *pc++ = *pb++;  // ���򣬽� Lb �е�Ԫ�ز��뵽 Lc ��
    }

    // ��� La �л���ʣ��Ԫ�أ�������뵽 Lc ��
    while (pa <= pa_last)
        *pc++ = *pa++;

    // ��� Lb �л���ʣ��Ԫ�أ�������뵽 Lc ��
    while (pb <= pb_last)
        *pc++ = *pb++;
}