#include <stdio.h>
#include <stdlib.h>

constexpr int M_LENGTH = 10;
constexpr int N_LENGTH = 10;
constexpr int M_MEGAN_N = M_LENGTH + N_LENGTH;

typedef struct {
	int* data;
	int maxLength;
	int length;
} DataStruct;

const int MAXLENGTH = 10;

/// <summary>
/// 打印当前顺序表的长度和信息
/// </summary>
/// <param name="d">顺序表指针</param>
void printList(DataStruct& d) {
	printf("length: %d\n", d.length);
	printf("data: {");
	for (int i = 0; i < d.length - 1; i++) {
		printf("%d, ", d.data[i]);
	}
	if (d.length > 0) {
		printf("%d", d.data[d.length - 1]);
	}
	printf("}\n");
}


#pragma region 第一题
/// <summary>
/// 合并两个顺序表，元素都存储到新的表C中
/// </summary>
/// <param name="structA">顺序表A的地址</param>
/// <param name="structB">顺序表B的地址</param>
/// <returns>合并之后的顺序表C</returns>
DataStruct mergeDataStructs(DataStruct* structA, DataStruct* structB) {
	DataStruct mergedStruct{};
	mergedStruct.maxLength = structA->maxLength + structB->maxLength;
	mergedStruct.length = structA->length + structB->length;
	mergedStruct.data = (int*)malloc(sizeof(int) * mergedStruct.maxLength);
	for (int i = 0; i < structA->length; i++)
	{
		mergedStruct.data[i] = structA->data[i];
	}
	for (int i = 0; i < structB->length; i++)
	{
		mergedStruct.data[structA->length + i] = structB->data[i];
	}
	return mergedStruct;
}

/// <summary>
/// 任务1代码段：将两个顺序表合并，并将元素存储到新表C中
/// </summary>
void task1() {
	// 初始化两个结构体并赋初值
	DataStruct dataStructA{};
	DataStruct dataStructB{};

	dataStructA.maxLength = MAXLENGTH;
	dataStructB.maxLength = MAXLENGTH;
	dataStructA.length = 0;
	dataStructB.length = 0;
	dataStructA.data = (int*)malloc(sizeof(int) * MAXLENGTH);
	dataStructB.data = (int*)malloc(sizeof(int) * MAXLENGTH);

	for (int i = 0; i < MAXLENGTH; i++) {
		dataStructA.data[i] = i;
		dataStructB.data[i] = 19 - i;
		dataStructA.length++;
		dataStructB.length++;
	}

	// 显示两个结构体的内容
	printList(dataStructA);
	printList(dataStructB);

	// 执行合并
	DataStruct mergedStruct = mergeDataStructs(&dataStructA, &dataStructB);

	// 打印合并结果
	printList(mergedStruct);

	// 释放动态申请的内存
	free(dataStructA.data);
	free(dataStructB.data);
	free(mergedStruct.data);
}
#pragma endregion
#pragma region 第二题
void task2() {
	DataStruct structListA{};
	structListA.length = 0;
	structListA.maxLength = M_MEGAN_N;
	structListA.data = (int*)malloc(sizeof(int) * M_MEGAN_N);

	DataStruct structListB{};
	structListB.length = 0;
	structListB.maxLength = N_LENGTH;
	structListB.data = (int*)malloc(sizeof(int) * N_LENGTH);

	for (int i = 0; i < M_LENGTH; i++)
	{
		structListA.data[i] = i + 1;
		structListA.length++;
	}

	for (int i = 0; i < N_LENGTH; i++)
	{
		structListB.data[i] = i + 10;
		structListB.length++;
	}

	int* newData = (int*)malloc(sizeof(int) * M_MEGAN_N);

	int p = 0;
	int q = 0;
	int m = 0;
	while (true) {
		if (structListA.data[p] <= structListB.data[q]) {
			newData[m] = structListA.data[p];
			if (p < structListA.length) {
				p++;
			}
			else {
				break;
			}
		}
		else {
			newData[m] = structListB.data[q];
			if (q < structListB.length) {
				q++;
			}
			else {
				break;
			}

		}
		if (m < M_MEGAN_N) {
			m++;
		}
		else {
			break;
		}
	}
	while (p < structListA.length) {
		newData[m++] = structListA.data[p++];
	}
	while (q < structListB.length) {
		newData[m++] = structListB.data[q++];
	}
	structListA.length = M_MEGAN_N;
	structListA.data = newData;
	printList(structListA);
}
#pragma endregion
#pragma region 第三题
void task3() {
	// 初始化A
	DataStruct structListA{};
	structListA.length = 0;
	structListA.maxLength = M_MEGAN_N;
	structListA.data = (int*)malloc(sizeof(int) * M_MEGAN_N);
	// 前R个元素递增
	int R = 10;
	for (int i = 0; i < R; i++)
	{
		structListA.data[i] = i;
		structListA.length++;
	}
	// 后R个元素递减
	for (int i = R; i < M_MEGAN_N; i++)
	{
		structListA.data[i] = M_MEGAN_N + 10 - i;
		structListA.length++;
	}
	// 打印初始化完成的结果
	printList(structListA);
	// 冒泡排序，进行整理
	for (int i = 1; i < structListA.length; i++)
	{
		for (int j = 0; j < structListA.length-i; j++)
		{
			if (structListA.data[j] > structListA.data[j+1]) {
				int tmp = structListA.data[j];
				structListA.data[j] = structListA.data[j + 1];
				structListA.data[j+1] = tmp;
			}
		}
	}
	// 打印整理完的结果
	printList(structListA);
}
#pragma endregion

/// <summary>
/// 主程序
/// </summary>
/// <returns>null</returns>
int main() {

	// 第一题
	// task1();

	// 第二题
	// task2();

	// 第三题
	task3();
	return 0;
}