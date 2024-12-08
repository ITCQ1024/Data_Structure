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

void DestroyList(SqList& L) {
	//��ʼ����:˳�����Ա�L�Ѿ�����. �������:����˳�����Ա�L
	free(L.elem); //ʹ�� free �����ͷ�֮ǰͨ�� malloc ������ڴ档����ͷ� L.elem ָ����ڴ�ռ䣬��ֹ�ڴ�й©��
	L.elem = NULL;//�� L.elem ָ������Ϊ NULL���Ա�������ָ�����⡣����ָ����ָ�����ͷ��ڴ��ָ�룬���ܻᵼ��δ������Ϊ
	L.length = 0;
	L.listsize = 0;
}

//�����ó���
//ֻ�ǽ� L.length ����Ϊ 0��û���ͷŻ����³�ʼ���洢�ռ䣬��ô���Ա�Ĵ洢�ռ���Ȼ���ڣ�ֻ�ǳ��ȱ�����Ϊ 0��
//����ζ����Ȼ���Ա����߼��ϱ�����ˣ���ʵ�ʵĴ洢�ռ䲢û�б��ͷţ��������Ԫ��ʱ�Ḳ��ԭ�е�����

void ClearList(SqList& L) {
	//��ʼ����:˳�����Ա�L�Ѿ�����. �������:��L����Ϊ�ձ�
	L.length = 0;
}

//void ClearList(SqList& L) {
//	 ��ʼ����:˳�����Ա�L�Ѿ�����. �������:��L����Ϊ�ձ�
//	free(L.elem);  // �ͷ�ԭ�еĴ洢�ռ�
//	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));  // ���·����ʼ��С�Ĵ洢�ռ�
//	if (!L.elem)
//		exit(OVERFLOW);  // �洢�ռ����ʧ��
//	L.length = 0;  // ���ó���
//	L.listsize = LIST_INIT_SIZE;  // ���ô洢����
//}
//
//void ClearList(SqList& L) {
//	 ��ʼ����:˳�����Ա�L�Ѿ�����. �������:��L����Ϊ�ձ�
//	memset(L.elem, 0, L.listsize * sizeof(ElemType));  // ���洢�ռ��е�����ȫ������Ϊ 0
//	L.length = 0;  // ���ó���
//}
//
//void ClearList(SqList& L) {
//	 ��ʼ����:˳�����Ա�L�Ѿ�����. �������:��L����Ϊ�ձ�
//	L.length = 0;
//}


//���һ���Ѿ����ڵ�˳�����Ա� L �Ƿ�Ϊ��
Status ListEmpty(SqList L) {
	//��ʼ����:˳�����Ա�L�Ѿ�����.������� : ��LΪ�ձ� �򷵻�TRUE ���� ���� FALSE
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L) {
	//��ʼ����:˳�����Ա�L�Ѿ�����.������� : ����L������Ԫ�صĸ���
	return L.length;
}

Status GetElem(SqList L, int i, ElemType& e) {
	//��ʼ����:˳�����Ա�L�Ѵ��� 1<=i<=ListLength(L) �������:��e����L�е�i��Ԫ�ص�ֵ
	//���λ�� i �Ƿ�����Ч��Χ�ڣ��� 1 �� L.length ֮�䣩�����������Ч��Χ�ڣ����� ERROR����ʾ����ʧ�ܡ�
	if (i<1 || i>L.length)
		return ERROR;
	else
		e = *(L.elem + i - 1);// e = L.elem[i - 1] �� e = *(L.elem + i - 1) �ڹ���������ȫ�ȼ۵�
		//�����±����: e = L.elem[i - 1] ��ֱ�ۣ�������⡣
		//ָ������ : e = *(L.elem + i - 1) ���ӽ��ײ�ʵ�֣�������һЩ����¸���Ч��
	return OK;
}


//����ָ�� compare

//��C�����У�����ָ����һ�������ָ�����ͣ���ָ��һ����������ڵ�ַ������ָ�������Ϊ�������ݸ������������Ӷ�ʵ�ֻص����ơ�
//Status(*compare)(ElemType, ElemType) ��һ������ָ�����ͣ��������� LocateElem �����Ĳ�����


//LocateElem()����ҲҪ����һ�ຯ��compare()�� ��LocateElem() �������������Կ��� : 
//Ҫ�����ຯ������2���βΣ������;�ΪElemType; �����ķ���ֵΪStatus���͡�
//������ˣ�����LocateElem() ������˵��(��ʼ����)����compare()������2���β������
//������ʱ������ֵΪ1; ����Ϊ0��ֻ���������������ĺ���������Ϊ���compare()������ʵ�κ�����

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	//��ʼ����:˳�����Ա�L�Ѵ��� compare()������Ԫ���ж�����(����Ϊ1 ����Ϊ0)
	//�������:����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��
	//		  ��������Ԫ�ز����� �򷵻�ֵΪ0 �㷨2.6

	int i = 1;//i�ĳ�ֵΪ��һ��Ԫ�ص�λ��
	ElemType* p = L.elem;//p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
	while (i <= L.length && !compare(*p++, e)) //*p++ ++ �����ȼ����� * *p++ �ȼ��� *p p++
		++i;

	if (i <= L.length)
		return i;
	else
		return 0;
}


//cur_e Ҫ����ǰ����Ԫ�ء�  pre_e��cur_e ��ǰ��Ԫ��

//��ʼ��λ�� i Ϊ 2��ָ�� p ָ�����Ա�ĵڶ���Ԫ�ء�
//�������Ա��е�Ԫ�أ�����Ŀ��Ԫ�� cur_e��
//����ҵ�Ŀ��Ԫ�� cur_e������ǰ��Ԫ�ص�ֵ���� pre_e�������� OK��
//�������������Ԫ����δ�ҵ�Ŀ��Ԫ�� cur_e���򷵻� INFEASIBLE����ʾ����ʧ�ܡ�
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e) {
	//��ʼ����:˳�����Ա�L�Ѵ���
	//�������:��cur_e��L������Ԫ�� �Ҳ��ǵ�һ�� ����pre_e��������ǰ��
	//		  �������ʧ�� pre_e�޶���
	int i = 2; //i�ĳ�ֵΪ˳�����Ա�L�е�2��Ԫ�ص�λ��
	ElemType* p = L.elem + 1;//p�ĳ�ֵΪ˳�����Ա�L�е�2��Ԫ�صĴ洢λ��

	/*i <= L.length: ��鵱ǰλ�� i �Ƿ�����Ч��Χ�ڣ��� 2 �� L.length ֮�䣩��
	* p != cur_e : ��鵱ǰԪ�� * p �Ƿ����Ŀ��Ԫ�� cur_e��
	++i; : �����ǰԪ�ز�����Ŀ��Ԫ�أ���λ�� i �� 1������������һ��Ԫ�ء�
	++p; : �����ǰԪ�ز�����Ŀ��Ԫ�أ���ָ�� p �ƶ�����һ��Ԫ�ص�λ��*/
	while (i <= L.length && *p != cur_e) {
		++i;//λ�����
		++p;//�洢λ�ú���
	}

	if (i > L.length) {//����������˳�����Ա�L �ߵ�ͷ�� ����ѭ���� ���� i >L.length ˵��û�ҵ�cur_e Ҳ��û����Ӧ��ǰ��
		return INFEASIBLE;//��� i ��������Ч��Χ����ʾδ�ҵ�Ŀ��Ԫ�� cur_e������ INFEASIBLE����ʾ����ʧ�ܡ�
	}
	else {
		//λ��Ϸ� pָ�����cur_e�Ĵ洢λ�� Ҫ����ǰ�� ��Ӧ--p
		pre_e = *--p;//��ָ�� p ����һ��λ�ã���ָ�� cur_e ��ǰ��Ԫ�أ�������Ԫ�ص�ֵ���� pre_e
		return OK;
	}
}

//��ʼ��λ�� i Ϊ 1��ָ�� p ָ�����Ա�ĵ�һ��Ԫ�ء�
//�������Ա��е�Ԫ�أ�����Ŀ��Ԫ�� cur_e��
//����ҵ�Ŀ��Ԫ�� cur_e��������Ԫ�ص�ֵ���� next_e�������� OK��
//�������������Ԫ����δ�ҵ�Ŀ��Ԫ�� cur_e���򷵻� INFEASIBLE����ʾ����ʧ�ܡ�
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e) {
	//��ʼ����:˳�����Ա�L�Ѵ���
	//�������:��cur_e��L������Ԫ�� �Ҳ������һ�� ����next_e�������ĺ��
	//		  �������ʧ�� next_e�޶���
	int i = 1;					//i�ĳ�ֵΪ˳�����Ա�L�е�1��Ԫ�ص�λ��
	ElemType* p = L.elem;		//p�ĳ�ֵΪ˳�����Ա�L�е�1��Ԫ�صĴ洢λ��

	/*i < L.length: ��鵱ǰλ�� i �Ƿ�����Ч��Χ�ڣ��� 1 �� L.length - 1 ֮�䣩��
	* p != cur_e : ��鵱ǰԪ�� * p �Ƿ����Ŀ��Ԫ�� cur_e��
	++i; : �����ǰԪ�ز�����Ŀ��Ԫ�أ���λ�� i �� 1������������һ��Ԫ�ء�
	++p; : �����ǰԪ�ز�����Ŀ��Ԫ�أ���ָ�� p �ƶ�����һ��Ԫ�ص�λ�á�*/

	while (i < L.length && *p != cur_e) {
		++i;//λ�����
		++p;//�洢λ�ú���
	}
	if (i == L.length) {//����������˳�����Ա�L �ߵ�ͷ�� ����ѭ���� ���� i == L.length ˵��û�ҵ�cur_e Ҳ��û����Ӧ�ĺ��
		return INFEASIBLE;//��� i ���� L.length����ʾδ�ҵ�Ŀ��Ԫ�� cur_e������ INFEASIBLE����ʾ����ʧ�ܡ�
	}
	else {
		//λ��Ϸ� pָ�����cur_e�Ĵ洢λ�� Ҫ���ĺ�� ��Ӧ++p
		next_e = *++p;		//��ָ�� p �ƶ�����һ��λ�ã���ָ�� cur_e �ĺ��Ԫ�أ�������Ԫ�ص�ֵ���� next_e��
		return OK;
	}
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

Status ListDelete(SqList& L, int i, ElemType& e) {
	//��ʼ����:˳�����Ա�L�Ѵ��� 1<=i<=ListLength(L)
	//�������:ɾ��˳�����Ա�L�еĵ�i������Ԫ��,����e������ֵ,L�ĳ���-1
	if (i<1 || i>L.length)//i��ֵ���Ϸ�
		return ERROR;
	ElemType* p = L.elem + i - 1; //��ʼ��ָ�� p ָ�����Ա�L��ɾ������Ԫ�صĴ洢λ�á�
	ElemType* q = L.elem + L.length - 1;//��ʼ��ָ�� q ָ�����Ա�����һ������Ԫ�صĴ洢λ�á�

	e = *p;//����ɾ��������Ԫ�ظ�ֵ��e

	for (p; p < q; p++)//��Ҫɾ����Ԫ�ؿ�ʼ���������Ԫ��������ǰ�ƶ�һλ�����ǵ�Ҫɾ����Ԫ�ء�
		*p = *(p+1);

	--L.length;
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