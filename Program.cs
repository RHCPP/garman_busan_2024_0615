﻿#include <stdio.h>

using System.Runtime.CompilerServices;
using System.Security.Cryptography;

struct student
{
    int num;
    double grade;

};

int main(void);
{
    struct student s1;
    s1.num = 2;
    s1.grade = 2.7;
    printf("학번 : %d\n", s1.num);
    printf("학번 : %.1lf\n", s1.grade);

return 0;
}