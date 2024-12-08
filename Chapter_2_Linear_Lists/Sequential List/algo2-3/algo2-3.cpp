#include "c2-1.h"

// ��ʼ�����Ա� L
void InitList(SqList& L);

int main(int argc, char* argv[]) {
    SqList L;  // ����һ�����Ա� L
    InitList(L);  // ��ʼ�����Ա� L
	cout<<endl;
    printf("L��ʼ����, L.elem = %p, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);  // ������Ա� L �ĳ�ʼ����Ϣ
    return 0;
}

// ��ʼ�����Ա� L
void InitList(SqList& L) {
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));  // Ϊ���Ա� L �����ʼ�洢�ռ�
    if (!L.elem)
        exit(OVERFLOW);  // �������ʧ�ܣ��˳�����
    L.length = 0;  // ��ʼ�����Ա� L �ĳ���Ϊ 0
    L.listsize = LIST_INIT_SIZE;  // ��ʼ�����Ա� L �Ĵ洢����Ϊ LIST_INIT_SIZE
}