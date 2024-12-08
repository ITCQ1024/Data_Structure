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