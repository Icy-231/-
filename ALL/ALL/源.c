#define _CRT_SECURE_NO_WARNINGS  // 解决fopen等函数的安全警告
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "labinfo.h" 
#include "func.h"

void initDisplay();

void main() {
	
	initDisplay();

	char opt;
	scanf("%c",&opt);

	while (opt != 'G') {
		switch (opt) {
		case 'A':ReadLabInfo(); break;//查阅可预约的实验
		case 'B':No2(); break;//预约实验
		case 'C':No3(); break;//取消实验
		case 'D':ReadLabInfo(); break;
		case 'E':No50(); printf("\n"); break;//修改个人信息
		case 'F':ReadExpInfo(); break;//查询成绩
			
		}
		scanf("%c", &opt);
		clear_input_buffer();
		
	}
	printf("已退出学生系统");
	printf("\n");
}


void initDisplay()
{
	for (int i = 1; i < 5; i++) printf("\n");
	printf("\t\t\t       学生登陆系统                 \n");
	printf("\t\t\t************************************\n");
	printf("\t\t\t*      A.查询可以预约的实验         \n");
	printf("\t\t\t*      B.预约实验                   \n");
	printf("\t\t\t*      C.取消预约                   \n");
	printf("\t\t\t*      D.查询已预约的实验           \n");
	printf("\t\t\t*      E.修改个人信息               \n");
	printf("\t\t\t*      F.查询实验成绩               \n");
	printf("\t\t\t*      G.退出学生系统               \n");
	printf("\t\t\t************************************\n");
}
