#define  _CRT_SECURE_NO_WARNINGS 1

#include "processBar.h"
#include <string.h>
#include <unistd.h>

const char* lable = "|/-\\";
char bar[NUM];

#define GREEN "\033[0;32;32m"
#define NONE "\033[m"

// v2: ����α����õ�
void processbar(int rate)
{
    if (rate < 0 || rate > 100) return;

    int len = strlen(lable);
    printf(GREEN"[%-100s]"NONE"[%d%%][%c]\r", bar, rate, lable[rate % len]); // û��\n,��û������ˢ�£���Ϊ��ʾ��ģʽ����ˢ��
    fflush(stdout);
    bar[rate++] = BODY;
    if (rate < 100) bar[rate] = RIGHT;
}

void initbar()
{
    memset(bar, '\0', sizeof(bar));
}


// v1
//void processbar(int speed)
//{
//    char bar[NUM];
//    memset(bar, '\0', sizeof(bar));
//    int len = strlen(lable);
//
//    int cnt = 0;
//    while(cnt <= TOP)
//    {
//        printf("[%-100s][%d%%][%c]\r", bar, cnt, lable[cnt%len]); // û��\n,��û������ˢ�£���Ϊ��ʾ��ģʽ����ˢ��
//        fflush(stdout);
//        bar[cnt++] = BODY;
//        if(cnt < 100) bar[cnt] = RIGHT;
//        usleep(speed); 
//    }
//
//    printf("\n");
//}
#pragma once

#include <stdio.h>

#define NUM 102
#define TOP 100
#define BODY '='
#define RIGHT '>'


extern void processbar(int rate);
extern void initbar();
