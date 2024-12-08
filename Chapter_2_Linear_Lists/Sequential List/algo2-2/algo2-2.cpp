//��֪���Ա� LA �� LB �е�����Ԫ�ذ�ֵ�ǵݼ��������У���Ҫ�� LA ��LB �鲢Ϊһ���µ����Ա� LC, LC �е�����Ԫ���԰�ֵ�ǵݼ��������С�
//���磬��LA = (3, 5, 8, 11)LB = (2, 6, 8, 9, ll, 15, 20)
//��LC = (2, 3, 5, 6, 8, 8, 9, ll, ll, 15, 20)
#include "c2-1.h"

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
    int i = 0, j = 0, k = 0;  // ��ʼ���������� i, j, k
    int La_len = ListLength(La);  // ��ȡ���Ա� La �ĳ���
    int Lb_len = ListLength(Lb);  // ��ȡ���Ա� Lb �ĳ���
    ElemType ai, bj;  // ���ڴ洢�� La �� Lb �л�ȡ��Ԫ��

    // ��ʼ�����Ա� Lc
    InitList(Lc);

    // �ϲ� La �� Lb �е�Ԫ�ص� Lc ��
    while (i < La_len && j < Lb_len) {
        // ��ȡ La �еĵ� i+1 ��Ԫ��
        GetElem(La, i + 1, ai);
        // ��ȡ Lb �еĵ� j+1 ��Ԫ��
        GetElem(Lb, j + 1, bj);

        // �Ƚ� ai �� bj������С��Ԫ�ز��뵽 Lc ��
        if (ai <= bj) {
            ListInsert(Lc, ++k, ai);  // �� ai ���뵽 Lc ��
            ++i;  // �ƶ� La ������
        }
        else {
            ListInsert(Lc, ++k, bj);  // �� bj ���뵽 Lc ��
            ++j;  // �ƶ� Lb ������
        }
    }

    // ��� La �л���ʣ��Ԫ�أ�������뵽 Lc ��
    while (i < La_len) {
        GetElem(La, ++i, ai);  // ��ȡ La �е���һ��Ԫ��
        ListInsert(Lc, ++k, ai);  // �� ai ���뵽 Lc ��
    }

    // ��� Lb �л���ʣ��Ԫ�أ�������뵽 Lc ��
    while (j < Lb_len) {
        GetElem(Lb, ++j, bj);  // ��ȡ Lb �е���һ��Ԫ��
        ListInsert(Lc, ++k, bj);  // �� bj ���뵽 Lc ��
    }
}