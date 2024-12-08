//头文件（Header File）是C / C++编程中的一种文件类型，通常用于声明函数、变量、宏定义、类型定义等。
//头文件的作用是提供接口和声明，使得多个源文件可以共享相同的定义和声明，从而避免重复定义和提高代码的可维护性。


//是一个非标准的预处理指令，用于确保头文件只被包含一次。虽然它不是标准的一部分，但大多数现代编译器都支持它。
#pragma once

//c1.h (程序名)

#include <string.h> //字符串处理函数，如 strlen、strcpy 等
#include <ctype.h> //字符处理函数，如 isalpha、isdigit 等
#include <malloc.h> //内存分配函数，如 malloc、free 等
#include <limits.h> //定义了各种数据类型的最大值和最小值，如 INT_MAX、INT_MIN 等
#include <stdio.h>  //标准输入输出函数，如 printf、scanf、EOF、NULL 等
#include <stdlib.h> //通用工具函数，如 atoi、exit 等
#include <io.h> // 文件输入输出函数，如 eof 等
#include <math.h> //数学函数，如 floor、ceil、abs 等
#include <process.h> //进程控制函数，如 exit 等
#include <iostream> //C++ 标准输入输出流，如 cout、cin 等
using namespace std;

// 函数结果状态码
//这些是宏定义，用于定义一些常量值，通常用于表示函数执行的结果状态。具体包括：
#define TRUE 1 //表示真，值为 1
#define FALSE 0 //表示假，值为 0
#define OK 1 //表示操作成功，值为 1
#define ERROR 0 //表示操作失败，值为 0
#define INFEASIBLE -1 //表示操作不可行，值为 -1
//#define OVERFLOW -2 因为math.h种已定义OVERFLOW的值为3 故去掉此行

typedef int Status; //Status是函数的类型, 其值是函数结果状态代码,如OK等 定义为 int 类型，用于表示函数的结果状态。
typedef int Boolean;//Boolean是布尔类型,其值是TRUE或FALSE 定义为 int 类型，用于表示布尔值（真或假）。


//头文件 c1.h 主要包含了各种标准库头文件的包含指令，以及一些宏定义和类型定义。
//这些定义和声明为后续的代码提供了必要的接口和工具，使得代码更加模块化和易于维护。