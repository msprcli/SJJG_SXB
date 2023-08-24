#include <stdio.h>

#include<stdlib.h>//malloc、free函数的头文件，动态顺序表使用

// 定义表的最大长度
constexpr auto MAXLENGTH = 10;

#pragma region 静态顺序表
typedef struct {
	// 用静态的“数组”存放数据
	int data[MAXLENGTH];
	// 顺序表当前长度
	int length;
}StaticStructList;

/// <summary>
/// 初始化静态顺序表
/// </summary>
/// <param name="L">顺序表指针</param>
void initStaticStructList(StaticStructList& L) {
	for (int i = 0; i < MAXLENGTH; i++)
	{
		L.data[i] = i;
	}
	L.length = 0;
}

/// <summary>
/// 显示一个静态顺序表
/// </summary>
void showStaticStructList() {
	printf_s("---------------开始展示静态顺序表---------------\n");
	// 定义一个静态顺序表
	StaticStructList  staticStructList;
	// 初始化
	initStaticStructList(staticStructList);
	// 输出
	for (int i = 0; i < MAXLENGTH; i++)
	{
		printf_s("{No.%d,data:%d}\n", i, staticStructList.data[i]);
	}
}
#pragma endregion

#pragma region 动态顺序表
typedef struct {
	// 动态分配数组的指针
	int* data;
	// 顺序表当前长度
	int length;
	// 顺序表的最大容量
	int MaxSize;
}TrendsStructList;

/// <summary>
/// 初始化一个动态的顺序表
/// </summary>
/// <param name="L">动态顺序表指针</param>
void initTrendsStructList(TrendsStructList& L) {
	// 利用malloc申请一片连续的存储空间
	L.data = (int*)malloc(sizeof(int) * MAXLENGTH);
	// 初始化顺序表当前长度为0
	L.length = 0;
	// 初始化顺序表最大长度为默认值
	L.MaxSize = MAXLENGTH;
	printf_s("顺序表初始化完成，长度为：%d，最大长度为：%d\n", L.length, L.MaxSize);
}

/// <summary>
/// 增加动态顺序表的长度
/// </summary>
/// <param name="L">顺序表指针</param>
/// <param name="increaseLength">要增加的长度</param>
void increaseTrendsStructList(TrendsStructList& L, int increaseLength) {
	int len = L.MaxSize;
	int* p = L.data;
	L.data = (int*)malloc(sizeof(int) * (L.length + increaseLength));
	for (int i = 0; i < L.MaxSize; i++)
	{
		L.data[i] = p[i];
	}
	// 顺序表最大长度增加对应值
	L.MaxSize += increaseLength;
	// 释放原有内存空间
	free(p);
	printf_s("顺序表长度增加完成，原长度为：%d，增加后长度为：%d\n", len, L.MaxSize);
}

/// <summary>
/// 使用随机数为顺序表赋值
/// </summary>
/// <param name="L">顺序表指针</param>
/// <param name="len">赋值的开始位置</param>
/// <param name="len">赋值的数量</param>
void flushData(TrendsStructList& L, int start, int len) {
	for (int i = start; i < len; i++)
	{
		L.data[i] = rand() % 101;
	}
	L.length = len;
	printf_s("顺序表数据刷新完成，刷新范围为%d-%d\n", start, (len - 1));
}

/// <summary>
/// 显示当前顺序表的数据
/// </summary>
/// <param name="L">顺序表指针</param>
void showTrendsStructListData(TrendsStructList& L) {
	for (int i = 0; i < L.MaxSize; i++)
	{
		printf_s("{No.%d,data:%d}\n", i, L.data[i]);
	}
}

/// <summary>
/// 显示一个动态顺序表
/// </summary>
void showTrendsStructList() {
	printf_s("---------------开始展示动态顺序表---------------\n");
	TrendsStructList trendsStructList;
	initTrendsStructList(trendsStructList);
	flushData(trendsStructList, 0, 8);
	showTrendsStructListData(trendsStructList);
	increaseTrendsStructList(trendsStructList, 10);
	flushData(trendsStructList, 8, 20);
	showTrendsStructListData(trendsStructList);
}
#pragma endregion


int main() {
	// 显示一个静态顺序表
	showStaticStructList();

	// 显示一个动态顺序表
	showTrendsStructList();
}