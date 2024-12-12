/*
 * @Date: 2024-12-13 00:43:44
 * @LastEditors: HashMap2020 && xjd_aiit_1960_thj@163.com
 * @LastEditTime: 2024-12-13 01:33:01
 * @FilePath: \LinkList\main2-2.cpp
 */
// main2-2.cppʱ��֤��������bo2-2.cpp��������

#include "bo2-2.cpp"
#include "func2-3.cpp"

int main(int argc, char *argv[])
{
     LinkList L;
     ElemType e, e1, e2;
     Status i;

     // ��ʼ������
     InitList(L);
     cout << "��ʼ��L��,L = " << L << "\tL->data = " << L->data << "\tL->next = " << L->next << endl
          << endl;

     // ������ͷ�����β���1~5
     for (int j = 1; j <= 5; j++)
          i = ListInsert(L, 1, j);
     cout << "��L�ı�ͷ���β���1~5��: L = ";
     ListTraverse(L, print); // ���ζ�Ԫ�ص���print(),���Ԫ�ص�ֵ
     cout << endl;

     // �ж������Ƿ�Ϊ��
     i = ListEmpty(L);
     cout << "L�Ƿ�Ϊ��[1:�� 0:��]:" << i << endl
          << endl;

     // �������
     ClearList(L);
     cout << "���L��,L = ";
     ListTraverse(L, print);
     cout << endl;

     // �ٴ��ж������Ƿ�Ϊ��
     i = ListEmpty(L);
     cout << "L�Ƿ�Ϊ��[1:�� 0:��]:" << i << endl
          << endl;

     // ������β�����β���1~10
     for (int j = 1; j <= 10; j++)
          ListInsert(L, j, j);
     cout << "��L�ı�β���β���1~10��,L = ";
     ListTraverse(L, print);
     cout << endl;

     // ��ȡ�����е�5��Ԫ�ص�ֵ
     GetElem(L, 5, e);
     cout << "L�е�5��Ԫ�ص�ֵΪ:" << e << endl
          << endl;

     // ����������ֵΪ0��1��Ԫ��
     for (int j = 0; j <= 1; j++)
     {
          int k = LocateElem(L, j, equal);
          if (k)
               cout << "��" << k << "��Ԫ�ص�ֵ��" << j << endl
                    << endl;
          else
               cout << "û��ֵΪ" << j << "Ԫ��" << endl
                    << endl;
     }

     // ��ȡ�����е�1�͵�2��Ԫ�ص�ǰ��
     for (int j = 1; j <= 2; j++)
     {
          GetElem(L, j, e2);
          i = PriorElem(L, e2, e1);
          if (i == INFEASIBLE)
               cout << "Ԫ��" << e2 << "��ǰ��" << endl
                    << endl;
          else
               cout << "Ԫ��" << e2 << "��ǰ��Ϊ" << e1 << endl
                    << endl;
     }

     // ��ȡ�����е�����1�͵�2��Ԫ�صĺ��
     for (int j = ListLength(L) - 1; j <= ListLength(L); j++)
     {
          GetElem(L, j, e1);
          i = NextElem(L, e1, e2);
          if (i == INFEASIBLE)
               cout << "Ԫ��" << e1 << "�޺��" << endl
                    << endl;
          else
               cout << "Ԫ��" << e1 << "�ĺ��Ϊ" << e2 << endl
                    << endl;
     }

     // ��ȡ������
     int k = ListLength(L);

     // ɾ�����������һ��Ԫ��
     for (int j = k + 1; j >= k; j--)
     {
          i = ListDelete(L, j, e);
          if (i == ERROR)
               cout << "ɾ����" << j << "��Ԫ��ʧ��~~~" << endl
                    << endl;
          else
               cout << "ɾ����" << j << "��Ԫ�سɹ�,��ֵΪ:" << e << endl
                    << endl;
     }

     // �����������Ԫ��
     cout << "�������L��Ԫ��:";
     ListTraverse(L, print);

     cout << endl;

     // ��������
     DestroyList(L);
     cout << "����L��,L = " << L << "\tL->data = " << L->data << "\tL->next = " << L->next << endl
          << endl;
     return 0;
}