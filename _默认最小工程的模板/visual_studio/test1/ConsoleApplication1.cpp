#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>



int test1()
{
	unsigned int i = 12;
	unsigned long j = 34;
	unsigned long long k = 56;

	printf("\n-->test1\n");
	printf("%du,%u\n", i, i);     //int型无符号直接用%u,不要d和u同时用 ！
	printf("%lu,%ul\n", j, j);    //unsigned long 的prinf 不能用 %ul,只能%lu 
	printf("%llu,%ull\n", k, k);  //unsigned long long 的prinf 不能用 %ull,只能%llu 
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
	printf(str); //str一直是空，程序崩溃

/*

/*程序会崩溃，因为str没有申请到内存空间。编译器总是要为函数的每个参数制作临时副本，把str当做参数传入到 GetMemory中时，在GetMemory中为参数p申请到了一块堆内存了，然后函数执行完毕,这时候参数p就会退栈， 而p所指向的那一块堆内存并没有释放掉，而且也没有相应的指针指向这块内存的首地址，我们申请出来的堆内存就 永远无法使用了，这就造成了内存泄漏。每调用一次GetMemory函数，就泄漏一块内存。
	就象： int a = 100；
		int b = a； // 现在b等于a
		b = 500； // 现在能认为a = 500 ?
		显然不能认为a = 500，因为b只是等于a，但不是a！ 当b改变的时候，a并不会改变，b就不等于a了。
		因此，虽然p已经有new的内存，但str仍然是null 。
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

	/*程序输入为：hello。这个为地址传递，把str的地址通过参数传递给GetMemory函数，此时参数指针p
	是指向str，然后通过解引用取得str的首地址，把申请到堆空间的首地址赋值给str。此时str申请内
	存成功了。此外，在用malloc申请堆空间的时候，没有加上判断，if( p == NULL){ ……}；*/
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

