#define _CRT_SECURE_NO_WARNINGS  // 解决fopen等函数的安全警告
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "labinfo.h"


int ReadLabInfo() {
    int i = 0;

    LabInfo Lab[10] = { 0 };

    //获取文件中的信息
    FILE* fp;
    fp = fopen("LabInfo.txt", "rt");
    if (fp == NULL)
    {
        printf("错误：无法打开LabInfo.txt文件！\n");
        printf("请检查：1.文件是否存在 2.文件路径是否正确\n");
        system("pause");                                         // 暂停控制台，方便查看错误
        return 1;
    }

    char header[100];
    fgets(header, sizeof(header), fp);

    // 循环读取每一行，填充结构体数组
    while (i < 10 && fscanf(fp, "%s %s %s %s %d %d %d %s %s",
        Lab[i].no,
        Lab[i].labname,
        Lab[i].starttime,
        Lab[i].finishtime,
        &Lab[i].total,
        &Lab[i].stuCount,
        &Lab[i].posted,
        Lab[i].teaNo,
        Lab[i].teaName
    ) != EOF) {
        i++;  // 读取下一条，填充下一个结构体
    }

    printf("                    ===== 已发布的实验信息=====\n");
    printf("实验编号      实验名称        开始时间        结束时间         总席位    预约人数   老师编号  老师姓名\n");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < 3; i++) {
        // 判断是否已发布（posted=1）
        if (Lab[i].posted == 1) {

            // 格式化输出，保证排版整齐
            printf("%-12s %-10s %-16s %-20s %-10d %-8d %-9s %s\n",
                Lab[i].no,
                Lab[i].labname,
                Lab[i].starttime,
                Lab[i].finishtime,
                Lab[i].total,
                Lab[i].stuCount,
                Lab[i].teaNo,
                Lab[i].teaName);
        }
    }
    return 0;
}

struct tm* get_local_time() {
    // 1. 获取时间戳
    time_t current_timestamp = time(NULL);
    if (current_timestamp == (time_t)-1) {
        perror("获取时间戳失败");
        return NULL;
    }

    // 2. 转换为本地时间结构体
    struct tm* local_time = localtime(&current_timestamp);
    if (local_time == NULL) {
        perror("转换本地时间失败");
        return NULL;
    }
    return local_time;
}

int No2() {                                    //直接改main函数名
    // 调用封装的函数获取当前本地时间
    struct tm* now = get_local_time();
    if (now == NULL) {
        return 1; // 获取时间失败，退出程序
    }

    // 1. 先输出当前时间（精确到分钟）
    char time_str[50];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M", now);
    printf("当前本地时间：%s\n", time_str);

    // 2. 计算当前时间与14:00的分钟差值
    // 步骤1：将当前时间转换为当天的总分钟数（时*60 + 分）
    int current_total_min = now->tm_hour * 60 + now->tm_min;
    // 步骤2：14:00对应的总分钟数
    int target_total_min = 14 * 60 + 0;
    // 步骤3：计算差值（可能为正/负/0）
    int time_diff = current_total_min - target_total_min;

    // 3. 输出差值（区分“已过14点”“未到14点”“正好14点”）
    if (time_diff > 240) {
        printf("当前时间比14:00早 %d 分钟,可以预约\n", time_diff);
    }
    else  {
        printf("当前时间比14:00晚 %d 分钟，不可以预约\n", -time_diff); // 取绝对值
    }
    return 0;
}

int No3() {                                    //直接改main函数名
    // 调用封装的函数获取当前本地时间
    struct tm* now = get_local_time();
    if (now == NULL) {
        return 1; // 获取时间失败，退出程序
    }

    // 1. 先输出当前时间（精确到分钟）
    char time_str[50];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M", now);
    printf("当前本地时间：%s\n", time_str);

    
    int current_total_min = now->tm_hour * 60 + now->tm_min;
    int target_total_min = 14 * 60 + 0;
    int time_diff = current_total_min - target_total_min;

    // 3. 输出差值（区分“已过14点”“未到14点”“正好14点”）
    if (time_diff > 120) {
        printf("可以取消预约\n", time_diff);
    }
    else {
        printf("实验已经开始，不可以预约\n"); 
    }
   
    return 0;
}


int ReadExpInfo() {
    int i = 0;
    char ch[20];

    Grade Exp[10] = { 0 };

    //获取文件中的信息
    FILE* fp;
    fp = fopen("ExpGrade.txt", "rt");
    if (fp == NULL)
    {
        printf("错误：无法打开ExpGrade.txt文件！\n");
        printf("请检查：1.文件是否存在 2.文件路径是否正确\n");
        system("pause");                                         // 暂停控制台，方便查看错误
        return 1;
    }

    char header[100];
    fgets(header, sizeof(header), fp);

    // 循环读取每一行，填充结构体数组
    while (i < 10 && fscanf(fp, "%s %s %s %s %s %s %f",
        Exp[i].no,
        Exp[i].labname,
        Exp[i].stuNo,
        Exp[i].stuName,
        Exp[i].teaNo,
        Exp[i].teaName,
        &Exp[i].grade
    ) != EOF) {
        i++;  // 读取下一条，填充下一个结构体
    }

    printf("请输入你的学号：");
    gets(ch);

    printf("                     ===== 已发布的实验成绩信息=====\n");
    printf("   实验编号      实验名称          学号        学生姓名     老师编号  老师姓名      成绩\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    
    for (i = 0; i < 5 && (strcmp(Exp[i].stuNo, ch) == 0); i++) {

        printf("%-14s %-16s %-16s %-10s %-10s %-12s %-9.2f \n",
            Exp[i].no,
            Exp[i].labname,
            Exp[i].stuNo,
            Exp[i].stuName,
            Exp[i].teaNo,
            Exp[i].teaName,
            Exp[i].grade);
    }
    printf("\n");
    return 0;
}
