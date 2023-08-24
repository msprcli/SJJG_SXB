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
	int numA[10] = { 1,2,3,5,7,9,11,15,35,50 };
	int numB[10] = { 1,3,5,8,9,10,20,35,50,60 };
	// 初始化顺序表A
	DataStruct LA{};
	LA.maxLength = MAXLENGTH;
	LA.length = MAXLENGTH;
	LA.data = numA;
	// 初始化顺序表B
	DataStruct LB{};
	LB.maxLength = MAXLENGTH;
	LB.length = MAXLENGTH;
	LB.data = numB;
	// 初始化顺序表C，用于存放交集
	DataStruct LC{};
	LC.maxLength = MAXLENGTH;
	LC.length = 0;
	LC.data = (int*)malloc(sizeof(int) * MAXLENGTH);

	int a = 0, b = 0, c = 0;
	while (a < MAXLENGTH && b < MAXLENGTH) {
		if (LA.data[a] < LB.data[b]) {
			a++;
		}
		else if (LA.data[a] == LB.data[b]) {
			LC.data[c] = LA.data[a];
			LC.length++;
			a++;
			b++;
			c++;
		}
		else {
			b++;
		}
	}

	// 打印取交集完成的数据
	printList(LC);
}