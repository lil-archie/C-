#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <cassert>
#include <string>
#include <unistd.h>
#include <signal.h>
// #include <sstream>
#include <sys/types.h>

int count = 0;

void Usage(std::string proc)
{
    std::cout << "\tUsage: \n\t";
    std::cout << proc << " �źű�� Ŀ�����\n"
        << std::endl;
}

// IO��Ч����ʵ�ǳ����£�
void myhandler(int signo)
{
    std::cout << "get a signal: " << signo << " count: " << count << std::endl;
    int n = alarm(10);
    std::cout << "return: " << n << std::endl;
    // alarm(0);
    // exit(0);
}

// ./mykill 9 1234
int main(int argc, char* argv[])
{
    std::cout << "pid: " << getpid() << std::endl;
    signal(SIGALRM, myhandler);
    alarm(10); //һ���Ե�

    while (true)
    {
        sleep(1);
    }


    //while(true) count++;
    // {
    //     // ��ӡ����ʾ����ӡ���磬IO
    //     //std::cout << "count : " << count++ << std::endl; // 1S ���ǵļ�����Ὣһ�������ۼƵ����٣�����
    // }

    // signal(SIGABRT, myhandler);
    // while (true)
    // {
    //     std::cout << "begin " << std::endl;
    //     sleep(1);
    //     abort(); // ���Լ�����ָ�����ź�
    //     std::cout << "end " << std::endl;
    // }
    // signal(SIGINT, myhandler);

    // while(true)
    // {
    //     sleep(1);
    //     raise(2);
    // }

    // if(argc != 3)
    // {
    //     Usage(argv[0]);
    //     exit(1);
    // }

    // // std::stringstream ss;
    // int signo = atoi(argv[1]); //?
    // int target_id = atoi(argv[2]); //?
    // int n = kill(target_id, signo);
    // if(n != 0)
    // {
    //     std::cerr << errno << " : " << strerror(errno) << std::endl;
    //     exit(2);
    // }
}

// // typedef void(*fun_t)();
// // void print()
// // {
// //     printf("hello world\n");
// // }
// // void show(int a, fun_t f)
// // {
// //     printf("hello show\n");
// // }

// // �Զ��巽��
// // signo���ض��źű����͸���ǰ���̵�ʱ��ִ��handler������ʱ��Ҫ�Զ�����Ӧ���źŸ�handler����
// // �����������Ը����е��ź�����ͬһ��������
// void handler(int signo)
// {
//     std::cout << "get a singal: " << signo << std::endl;
//     // exit(2);
// }

// int main()
// {
//     // 1. 2���źţ����̵�Ĭ�ϴ���������ֹ����
//     // 2. signal ���Խ��ж�ָ�����ź��趨�Զ��崦����
//     // 3. signal(2, handler)���������������ʱ��handler��������������û�У� ����ʲô��ֻ�Ǹ�����2���źŵĴ���������û�е���handlder����
//     // 4. ��ôhandler������ʲôʱ�򱻵��ã���2���źŲ�����ʱ��
//     // 5. Ĭ�����Ƕ�2���źŵĴ���������ֹ���̣�������signal(2, handler)�� ������ִ���û��������Զ��岶׽��

//     signal(SIGINT, handler);
//     signal(SIGQUIT, handler);

//     // for(int i = 1; i <= 31; i++)
//     // {
//     //     signal(i, handler);
//     // }

//     while(true)
//     {
//         std::cout << "����һ�����̣����������� ..., pid: " << getpid() << std::endl;
//         sleep(1);
//     }

//     return 0;
// }