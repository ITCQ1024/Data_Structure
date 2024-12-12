/*
 * @Date: 2024-12-13 00:43:44
 * @LastEditors: HashMap2020 && xjd_aiit_1960_thj@163.com
 * @LastEditTime: 2024-12-13 01:33:01
 * @FilePath: \LinkList\main2-2.cpp
 */
// main2-2.cpp时验证基本操作bo2-2.cpp的主程序

#include "bo2-2.cpp"
#include "func2-3.cpp"

int main(int argc, char *argv[])
{
     LinkList L;
     ElemType e, e1, e2;
     Status i;

     // 初始化链表
     InitList(L);
     cout << "初始化L后,L = " << L << "\tL->data = " << L->data << "\tL->next = " << L->next << endl
          << endl;

     // 在链表头部依次插入1~5
     for (int j = 1; j <= 5; j++)
          i = ListInsert(L, 1, j);
     cout << "在L的表头依次插入1~5后: L = ";
     ListTraverse(L, print); // 依次对元素调用print(),输出元素的值
     cout << endl;

     // 判断链表是否为空
     i = ListEmpty(L);
     cout << "L是否为空[1:是 0:否]:" << i << endl
          << endl;

     // 清空链表
     ClearList(L);
     cout << "清空L后,L = ";
     ListTraverse(L, print);
     cout << endl;

     // 再次判断链表是否为空
     i = ListEmpty(L);
     cout << "L是否为空[1:是 0:否]:" << i << endl
          << endl;

     // 在链表尾部依次插入1~10
     for (int j = 1; j <= 10; j++)
          ListInsert(L, j, j);
     cout << "在L的表尾依次插入1~10后,L = ";
     ListTraverse(L, print);
     cout << endl;

     // 获取链表中第5个元素的值
     GetElem(L, 5, e);
     cout << "L中第5个元素的值为:" << e << endl
          << endl;

     // 查找链表中值为0和1的元素
     for (int j = 0; j <= 1; j++)
     {
          int k = LocateElem(L, j, equal);
          if (k)
               cout << "第" << k << "个元素的值是" << j << endl
                    << endl;
          else
               cout << "没有值为" << j << "元素" << endl
                    << endl;
     }

     // 获取链表中第1和第2个元素的前驱
     for (int j = 1; j <= 2; j++)
     {
          GetElem(L, j, e2);
          i = PriorElem(L, e2, e1);
          if (i == INFEASIBLE)
               cout << "元素" << e2 << "无前驱" << endl
                    << endl;
          else
               cout << "元素" << e2 << "的前驱为" << e1 << endl
                    << endl;
     }

     // 获取链表中倒数第1和第2个元素的后继
     for (int j = ListLength(L) - 1; j <= ListLength(L); j++)
     {
          GetElem(L, j, e1);
          i = NextElem(L, e1, e2);
          if (i == INFEASIBLE)
               cout << "元素" << e1 << "无后继" << endl
                    << endl;
          else
               cout << "元素" << e1 << "的后继为" << e2 << endl
                    << endl;
     }

     // 获取链表长度
     int k = ListLength(L);

     // 删除链表中最后一个元素
     for (int j = k + 1; j >= k; j--)
     {
          i = ListDelete(L, j, e);
          if (i == ERROR)
               cout << "删除第" << j << "个元素失败~~~" << endl
                    << endl;
          else
               cout << "删除第" << j << "个元素成功,其值为:" << e << endl
                    << endl;
     }

     // 遍历链表并输出元素
     cout << "依次输出L的元素:";
     ListTraverse(L, print);

     cout << endl;

     // 销毁链表
     DestroyList(L);
     cout << "销毁L后,L = " << L << "\tL->data = " << L->data << "\tL->next = " << L->next << endl
          << endl;
     return 0;
}