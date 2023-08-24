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
		printf_s( "%d ,", d.data[i]);
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
		dataStruct.data[i] = i;
		dataStruct.length++;
	}
	// 打印初始化完成的数据
	printList(dataStruct);
	// 随机删除
	int randCode = rand() % 10;
	randCode = 10;
	printf_s("要删除的元素为第：%d 个，数据为：%d \n", randCode,dataStruct.data[randCode-1]);
	// 删除，用后面的数据把他顶掉
	for (int i = randCode - 1; i < 10; i++)
	{
		dataStruct.data[i] = dataStruct.data[i + 1];
	}
	dataStruct.data[dataStruct.length - 1] = NULL;
	dataStruct.length--;
	// 打印删除完成的数据
	printList(dataStruct);
}