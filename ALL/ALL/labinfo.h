// labinfo.h
#ifndef LABINFO_H  // 头文件保护宏（防止重复包含）
#define LABINFO_H

// 声明结构体（其他文件包含这个头文件后，就能使用这个结构体）
struct labinfo {
    char no[20];
    char labname[20];
    char starttime[40];
    char finishtime[40];
    int total;
    int stuCount;
    int posted;
    char teaNo[10];
    char teaName[20];
};
typedef struct labinfo LabInfo;


struct Studentinfo {
    char no[20];
    char name[20];
    char school[20];
    char major[20];
    char pin[10];
};
typedef struct Studentinfo Stu;
extern Stu stu[20];

struct ExpGrade {
    char no[20];
    char labname[20];
    char stuNo[20];
    char stuName[20];
    char teaNo[20];
    char teaName[20];
    float grade;
};
typedef struct ExpGrade Grade;

#endif  // LABINFO_H
#pragma once
