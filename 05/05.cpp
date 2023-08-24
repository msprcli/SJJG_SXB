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
	int s = 2, t = 8;
	int newSize = dataStruct.length;
	// 定义一个新数组存放flag
	int* list2 = (int*)malloc(sizeof(int) * newSize);
	// 下述写法时间复杂度优于每判断一个就删除一个的写法
	// 首先轮询一次判断每个对象是否在范围内
	for (int i = 0; i < dataStruct.length; i++)
	{
		if (dataStruct.data[i] > s && dataStruct.data[i] < t) {
			list2[i] = 1;
			newSize--;
		}
		else {
			list2[i] = 0;
		}
	}
	int j = 0;
	// 循环，对于不在剔除范围的数据进行拷贝
	for (int i = 0; i < dataStruct.length; i++)
	{
		if (list2[i] == 0) {
			list2[j] = dataStruct.data[i];
			j++;
		}
	}
	dataStruct.length = j;
	// 将剩余内容赋值为空避免造成干扰
	for (; j < dataStruct.length; j++)
	{
		list2[j] = NULL;
	}
	// 重新赋值
	dataStruct.data = list2;
	// 打印插入完成的数据
	printList(dataStruct);
}