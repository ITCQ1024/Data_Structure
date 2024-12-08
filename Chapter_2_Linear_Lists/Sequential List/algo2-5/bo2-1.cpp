//Basic Operations ÿ�ִ洢�ṹ��һ����������������� bo(bo ��ʾ��������)��ͷ



#include "c2-1.h"

void InitList(SqList& L) {
	//�������:����һ���յ�˳�����Ա�L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);//�洢�ռ����ʧ��
	L.length = 0;//�ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE;//��ʼ���洢����
}


int ListLength(SqList L) {
	//��ʼ����:˳�����Ա�L�Ѿ�����.������� : ����L������Ԫ�صĸ���
	return L.length;
}

//������λ�� i �Ƿ�����Ч��Χ�ڣ����������Ч��Χ�ڣ����� ERROR��
//������Ա�ĳ����Ѿ��ﵽ�򳬹���ǰ�Ĵ洢���������·����ڴ棬���Ӵ洢������
//������λ�ü�������Ԫ������ƶ�һλ��Ϊ��Ԫ���ڳ��ռ䡣
//����Ԫ�� e ���뵽ָ��λ�á�
//�������Ա�ĳ��ȡ�
//���� OK����ʾ��������ɹ���

Status ListInsert(SqList& L, int i, ElemType e) {//�㷨2.4
	//��ʼ����:˳�����Ա�L�Ѵ��� 1<=i<=ListLength(L)+1
	//�������:��˳�����Ա�L�еĵ� i �� λ���ϲ����µ�����Ԫ��e, L�ĳ���+1

	if (i<1 || i>L.length + 1)//����λ��i���Ϸ�
		return ERROR;
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);//�洢�ռ����ʧ��
		L.elem = newbase;//�»�ַ
		L.listsize += LIST_INCREMENT;//���Ӵ洢����
	}

	ElemType* p = L.elem + L.length - 1;//��ʼ��ָ�� p ָ�����Ա�����һ��Ԫ�صĴ洢λ�á�
	ElemType* q = L.elem + i - 1;//��ʼ��ָ�� q ָ�����λ�õĴ洢λ�á�

	for (p; p >= q; --p) //���ڽ�����λ�ü�������Ԫ������ƶ�һλ
		*(p + 1) = *p;//����ǰԪ�� *p �ƶ�����һ��λ�� *(p + 1)��

	*q = e;//����e
	++L.length;//��+1
	return OK;
}


//����˳�����Ա�
//���� visit ��һ������ָ�룬ָ��һ������ ElemType& ���Ͳ����ĺ������ú������ڴ������Ա��е�ÿ��Ԫ�ء�

//ListTraverse() ����Ҫ����visit() ������visit()  ��ListTraverse()���βΡ���
//Ϊvisit() ����һ���ض��ĺ�������������һ��������һ�ຯ���� ���Գ���Ϊ�������βΡ���
//�������βε�������ָ����visit() �ĺ������ͣ�Ҳ���Ǻ�������ֵ������(void)����������
//��ָ����visit()  �����βεĸ���(1��)������(ElemType����������)���������������ĺ���
//(����ֵΪvoid ���ͣ���һһ���βΣ�������ΪElemType&)����������ΪListTraverse() ��
//����ʵ�Ρ�

void ListTraverse(SqList L, void(*visit)(ElemType&)) {
	//��ʼ����:˳�����Ա�L�Ѵ��� 
	//�������:���ζ�L��ÿ������Ԫ�ص��ú���visit()
	//	      visit()���βμ���& ���� ��������ͨ������visit()�ı�����Ԫ�ص�ֵ
	ElemType* p = L.elem;//��ʼ��ָ�� p ָ�����Ա�L�е�һ������Ԫ�صĴ洢λ��
	for (int i = 0; i < L.length; i++)
		visit(*p++);
	printf("\n");
}