#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>



int test1()
{
	unsigned int i = 12;
	unsigned long j = 34;
	unsigned long long k = 56;

	printf("\n-->test1\n");
	printf("%du,%u\n", i, i);     //int���޷���ֱ����%u,��Ҫd��uͬʱ�� ��
	printf("%lu,%ul\n", j, j);    //unsigned long ��prinf ������ %ul,ֻ��%lu 
	printf("%llu,%ull\n", k, k);  //unsigned long long ��prinf ������ %ull,ֻ��%llu 
	return 0;
}

/**********************************************/
void GetMemory1(char *p)
{
	p = (char *)malloc(100);
}

void test2(void)
{
	char *str = NULL;

	printf("\n-->test2\n");
	GetMemory1(str);
	strcpy(str, "hello world");
	printf(str); //strһֱ�ǿգ��������

/*

/*������������Ϊstrû�����뵽�ڴ�ռ䡣����������ҪΪ������ÿ������������ʱ��������str�����������뵽 GetMemory��ʱ����GetMemory��Ϊ����p���뵽��һ����ڴ��ˣ�Ȼ����ִ�����,��ʱ�����p�ͻ���ջ�� ��p��ָ�����һ����ڴ沢û���ͷŵ�������Ҳû����Ӧ��ָ��ָ������ڴ���׵�ַ��������������Ķ��ڴ�� ��Զ�޷�ʹ���ˣ����������ڴ�й©��ÿ����һ��GetMemory��������й©һ���ڴ档
	���� int a = 100��
		int b = a�� // ����b����a
		b = 500�� // ��������Ϊa = 500 ?
		��Ȼ������Ϊa = 500����Ϊbֻ�ǵ���a��������a�� ��b�ı��ʱ��a������ı䣬b�Ͳ�����a�ˡ�
		��ˣ���Ȼp�Ѿ���new���ڴ棬��str��Ȼ��null ��
*/
}
/**********************************************/

void GetMemory2(char **p, int num)
{
	*p = (char *)malloc(num);
}

void test3(void)
{
	char *str = NULL;

	printf("\n-->test3\n");
	GetMemory2(&str, 100);
	strcpy(str, "hello");
	printf(str);

	/*��������Ϊ��hello�����Ϊ��ַ���ݣ���str�ĵ�ַͨ���������ݸ�GetMemory��������ʱ����ָ��p
	��ָ��str��Ȼ��ͨ��������ȡ��str���׵�ַ�������뵽�ѿռ���׵�ַ��ֵ��str����ʱstr������
	��ɹ��ˡ����⣬����malloc����ѿռ��ʱ��û�м����жϣ�if( p == NULL){ ����}��*/
}



/**********************************************/


int test4(void)
{
	printf("\n-->test4\n");

}

int main()
{
	char key[1] = { 0 };
	test1();
//	test2();
	test3();
	test4();
	scanf(key);
}

