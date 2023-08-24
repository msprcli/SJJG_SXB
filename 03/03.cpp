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
	// 首先进行扩容
	int* list2 = (int*)malloc(sizeof(int) * (dataStruct.length+1));
	// 数据拷贝进去
	for (int i = 0; i < dataStruct.length + 1; i++)
	{
		list2[i] = dataStruct.data[i];
	}
	// 替换
	dataStruct.data = list2;
	dataStruct.maxLength++;
	// 定义要插入的位置n：5 和要插入的数据e： 11
	int n = 5, e = 11;
	// 转换为下标
	n--;
	for (int i = dataStruct.length; i > n; i--)
	{
		dataStruct.data[i] = dataStruct.data[i - 1];
	}
	dataStruct.data[n] = e;
	dataStruct.length++;
	// 打印插入完成的数据
	printList(dataStruct);
}