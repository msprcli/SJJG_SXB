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
	// 查找最小的元素
	// 定义最小值和下标
	int num = 65535, flag = 0;
	for (int i = 0; i < dataStruct.length; i++)
	{
		if (dataStruct.data[i] < num) {
			num = dataStruct.data[i];
			flag = i;
		}
	}
	dataStruct.data[flag] = dataStruct.data[dataStruct.length - 1];

	// 打印插入完成的数据
	printList(dataStruct);
}