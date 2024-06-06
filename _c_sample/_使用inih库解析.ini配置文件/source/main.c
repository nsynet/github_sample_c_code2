#include <stdio.h>
#include <stdlib.h>
#include "ini.h"

//回调函数，用于处理 INI 文件中的每一行
int handler(void* user, const char* section, const char* name, const char* value) {
	printf("Section: %s, Name: %s, Value: %s\n", section, name, value);
	return 1;  //返回 1 表示继续解析，返回 0 表示停止解析
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <config_file>\n", argv[0]);
		return 1;
	}

	//使用 INIh 库解析 INI 文件
	if (ini_parse(argv[1], handler, NULL) < 0) {
		fprintf(stderr, "Can't load '%s'\n", argv[1]);
		return 1;
	}

	return 0;
}
