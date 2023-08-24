#include <stdio.h>

#include<stdlib.h>//malloc��free������ͷ�ļ�����̬˳���ʹ��

// ��������󳤶�
constexpr auto MAXLENGTH = 10;

#pragma region ��̬˳���
typedef struct {
	// �þ�̬�ġ����顱�������
	int data[MAXLENGTH];
	// ˳���ǰ����
	int length;
}StaticStructList;

/// <summary>
/// ��ʼ����̬˳���
/// </summary>
/// <param name="L">˳���ָ��</param>
void initStaticStructList(StaticStructList& L) {
	for (int i = 0; i < MAXLENGTH; i++)
	{
		L.data[i] = i;
	}
	L.length = 0;
}

/// <summary>
/// ��ʾһ����̬˳���
/// </summary>
void showStaticStructList() {
	printf_s("---------------��ʼչʾ��̬˳���---------------\n");
	// ����һ����̬˳���
	StaticStructList  staticStructList;
	// ��ʼ��
	initStaticStructList(staticStructList);
	// ���
	for (int i = 0; i < MAXLENGTH; i++)
	{
		printf_s("{No.%d,data:%d}\n", i, staticStructList.data[i]);
	}
}
#pragma endregion

#pragma region ��̬˳���
typedef struct {
	// ��̬���������ָ��
	int* data;
	// ˳���ǰ����
	int length;
	// ˳�����������
	int MaxSize;
}TrendsStructList;

/// <summary>
/// ��ʼ��һ����̬��˳���
/// </summary>
/// <param name="L">��̬˳���ָ��</param>
void initTrendsStructList(TrendsStructList& L) {
	// ����malloc����һƬ�����Ĵ洢�ռ�
	L.data = (int*)malloc(sizeof(int) * MAXLENGTH);
	// ��ʼ��˳���ǰ����Ϊ0
	L.length = 0;
	// ��ʼ��˳�����󳤶�ΪĬ��ֵ
	L.MaxSize = MAXLENGTH;
	printf_s("˳����ʼ����ɣ�����Ϊ��%d����󳤶�Ϊ��%d\n", L.length, L.MaxSize);
}

/// <summary>
/// ���Ӷ�̬˳���ĳ���
/// </summary>
/// <param name="L">˳���ָ��</param>
/// <param name="increaseLength">Ҫ���ӵĳ���</param>
void increaseTrendsStructList(TrendsStructList& L, int increaseLength) {
	int len = L.MaxSize;
	int* p = L.data;
	L.data = (int*)malloc(sizeof(int) * (L.length + increaseLength));
	for (int i = 0; i < L.MaxSize; i++)
	{
		L.data[i] = p[i];
	}
	// ˳�����󳤶����Ӷ�Ӧֵ
	L.MaxSize += increaseLength;
	// �ͷ�ԭ���ڴ�ռ�
	free(p);
	printf_s("˳�����������ɣ�ԭ����Ϊ��%d�����Ӻ󳤶�Ϊ��%d\n", len, L.MaxSize);
}

/// <summary>
/// ʹ�������Ϊ˳���ֵ
/// </summary>
/// <param name="L">˳���ָ��</param>
/// <param name="len">��ֵ�Ŀ�ʼλ��</param>
/// <param name="len">��ֵ������</param>
void flushData(TrendsStructList& L, int start, int len) {
	for (int i = start; i < len; i++)
	{
		L.data[i] = rand() % 101;
	}
	L.length = len;
	printf_s("˳�������ˢ����ɣ�ˢ�·�ΧΪ%d-%d\n", start, (len - 1));
}

/// <summary>
/// ��ʾ��ǰ˳��������
/// </summary>
/// <param name="L">˳���ָ��</param>
void showTrendsStructListData(TrendsStructList& L) {
	for (int i = 0; i < L.MaxSize; i++)
	{
		printf_s("{No.%d,data:%d}\n", i, L.data[i]);
	}
}

/// <summary>
/// ��ʾһ����̬˳���
/// </summary>
void showTrendsStructList() {
	printf_s("---------------��ʼչʾ��̬˳���---------------\n");
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
	// ��ʾһ����̬˳���
	showStaticStructList();

	// ��ʾһ����̬˳���
	showTrendsStructList();
}