//ͷ�ļ���Header File����C / C++����е�һ���ļ����ͣ�ͨ�����������������������궨�塢���Ͷ���ȡ�
//ͷ�ļ����������ṩ�ӿں�������ʹ�ö��Դ�ļ����Թ�����ͬ�Ķ�����������Ӷ������ظ��������ߴ���Ŀ�ά���ԡ�


//��һ���Ǳ�׼��Ԥ����ָ�����ȷ��ͷ�ļ�ֻ������һ�Ρ���Ȼ�����Ǳ�׼��һ���֣���������ִ���������֧������
#pragma once

//c1.h (������)

#include <string.h> //�ַ������������� strlen��strcpy ��
#include <ctype.h> //�ַ����������� isalpha��isdigit ��
#include <malloc.h> //�ڴ���亯������ malloc��free ��
#include <limits.h> //�����˸����������͵����ֵ����Сֵ���� INT_MAX��INT_MIN ��
#include <stdio.h>  //��׼��������������� printf��scanf��EOF��NULL ��
#include <stdlib.h> //ͨ�ù��ߺ������� atoi��exit ��
#include <io.h> // �ļ���������������� eof ��
#include <math.h> //��ѧ�������� floor��ceil��abs ��
#include <process.h> //���̿��ƺ������� exit ��
#include <iostream> //C++ ��׼������������� cout��cin ��
using namespace std;

// �������״̬��
//��Щ�Ǻ궨�壬���ڶ���һЩ����ֵ��ͨ�����ڱ�ʾ����ִ�еĽ��״̬�����������
#define TRUE 1 //��ʾ�棬ֵΪ 1
#define FALSE 0 //��ʾ�٣�ֵΪ 0
#define OK 1 //��ʾ�����ɹ���ֵΪ 1
#define ERROR 0 //��ʾ����ʧ�ܣ�ֵΪ 0
#define INFEASIBLE -1 //��ʾ���������У�ֵΪ -1
//#define OVERFLOW -2 ��Ϊmath.h���Ѷ���OVERFLOW��ֵΪ3 ��ȥ������

typedef int Status; //Status�Ǻ���������, ��ֵ�Ǻ������״̬����,��OK�� ����Ϊ int ���ͣ����ڱ�ʾ�����Ľ��״̬��
typedef int Boolean;//Boolean�ǲ�������,��ֵ��TRUE��FALSE ����Ϊ int ���ͣ����ڱ�ʾ����ֵ�����٣���


//ͷ�ļ� c1.h ��Ҫ�����˸��ֱ�׼��ͷ�ļ��İ���ָ��Լ�һЩ�궨������Ͷ��塣
//��Щ���������Ϊ�����Ĵ����ṩ�˱�Ҫ�Ľӿں͹��ߣ�ʹ�ô������ģ�黯������ά����