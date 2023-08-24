#include <stdio.h>
#include <corecrt_malloc.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int maxLength;
	int length;
}DataStruct;

constexpr auto MAXLENGTH = 10;

/// <summary>
/// 打印当前顺序表的长度和信息
/// </summary>
/// <param name="d">顺序表指针</param>
void printList(DataStruct& d) {
	printf_s("length:%d\n", d.length);
	printf_s("data:{ ");
	for (int i = 0; i < d.length - 1; i++)
	{
		printf_s("%d ,", d.data[i]);
	}
	printf_s("%d }\n", d.data[d.length - 1]);
}

/// <summary>
/// 主程序
/// </summary>
/// <returns>null</returns>
int main() {
	DataStruct dataStruct{};
	// 初始化顺序表
	dataStruct.maxLength = MAXLENGTH;
	dataStruct.length = 0;
	dataStruct.data = (int*)malloc(sizeof(int) * MAXLENGTH);
	// 赋初值
	for (int i = 0; i < 10; i++)
	{
		dataStruct.data[i] = rand() % 10;
		dataStruct.length++;
	}
	// 打印初始化完成的数据
	printList(dataStruct);
	int s = 1, t = 5;
	int newSize = dataStruct.length + s - t - 1;
	// 定义一个新数组存放flag
	int* list2 = (int*)malloc(sizeof(int) * newSize);
	int n = 0;
	for (int i = 0; i < s - 1; i++)
	{
		list2[n] = dataStruct.data[i];
		n++;
	}
	for (int i = t; i < dataStruct.length; i++)
	{
		list2[n] = dataStruct.data[i];
		n++;
	}
	dataStruct.length = n;
	dataStruct.data = list2;
	// 打印修改完成的数据
	printList(dataStruct);
}