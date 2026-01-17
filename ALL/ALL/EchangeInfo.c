#define _CRT_SECURE_NO_WARNINGS  // 解决fopen等函数的安全警告
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "labinfo.h"

Stu stu[20];

void clear_input_buffer() {
	while (getchar() != '\n'); // 读取并丢弃缓冲区中所有字符，直到遇到换行符
}

void change(Stu* p) {
	int n = 0;

	printf("                    ===== 学生信息=====\n");
	printf("       学号       学生姓名     学院名称        专业名称        密码\n");
	printf("------------------------------------------------------------------------------------------------------\n");

	printf("%16s %-10s %-10s %-8s %-s\n",
		p->no,
		p->name,
		p->school,
		p->major,
		p->pin);
	printf("你要修改几号元素（1为姓名，2为学院，3为专业，4为密码）\n");
	scanf_s("%d", &n);
	clear_input_buffer();

	switch (n) {
	case 1:gets_s(p->name,20);
		break;
	case 2:gets_s(p->school,20);
		break;
	case 3:gets_s(p->major,20);
		break;
	case 4:gets_s(p->pin,10);
		break;
	default:printf("输入错误");
	}
}

int No50() {
	Stu stu[20];
	Stu* pstu = stu;
	int i = 0;
	char ch[20];

	//获取文件中的信息
	FILE* fp;
	fp = fopen("stuinfo.txt", "rt");
	if (fp == NULL)
	{
		printf("错误：无法打开stuinfo.txt文件！\n");
		printf("请检查：1.文件是否存在 2.文件路径是否正确\n");
		system("pause");                                         // 暂停控制台，方便查看错误
		return 1;
	}

	char header[100];
	fgets(header, sizeof(header), fp);

	// 循环读取每一行，填充结构体数组
	while (i < 10 && fscanf(fp, "%s %s %s %s %s",
		stu[i].no,
		stu[i].name,
		stu[i].school,
		stu[i].major,
		stu[i].pin
	) != EOF) {
		i++;  // 读取下一条，填充下一个结构体
	}


	printf("请输入你的学号：");
	gets(ch);
	//clear_input_buffer();
	
	for (i = 0; i < 20; i++) {
		if (strcmp(stu[i].no, ch) == 0) { break; }
	}

	change(&stu[i]);

	printf("修改后您的信息为\n");
	printf("                    ===== 学生信息=====\n");
	printf("       学号       学生姓名     学院名称        专业名称        密码\n");
	printf("------------------------------------------------------------------------------------------------------\n");

	printf("%16s %-10s %-10s %-8s %-s",
		stu[i].no,
		stu[i].name,
		stu[i].school,
		stu[i].major,
		stu[i].pin);

	return 0;
	printf("\n");
}