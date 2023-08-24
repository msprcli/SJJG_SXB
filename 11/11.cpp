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
	// 初始化顺序表A
	DataStruct LA{};
	LA.maxLength = MAXLENGTH;
	LA.length = MAXLENGTH;
	LA.data = (int*)malloc(sizeof(int) * MAXLENGTH);
	for (int i = 0; i < MAXLENGTH; i++)
	{
		LA.data[i] = i + 1;
	}
	printList(LA);

	int* temp = (int*)malloc(sizeof(int) * MAXLENGTH);
	for (int i = 0; i < MAXLENGTH; i++)
	{
		temp[MAXLENGTH - i - 1] = LA.data[i];
	}
	LA.data = temp;
	// 打印取逆置完成的数据
	printList(LA);
}