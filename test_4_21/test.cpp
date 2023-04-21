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
    std::cout << proc << " 信号编号 目标进程\n"
        << std::endl;
}

// IO的效率其实非常低下！
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
    alarm(10); //一次性的

    while (true)
    {
        sleep(1);
    }


    //while(true) count++;
    // {
    //     // 打印，显示器打印网络，IO
    //     //std::cout << "count : " << count++ << std::endl; // 1S 我们的计算机会将一个整数累计到多少，算力
    // }

    // signal(SIGABRT, myhandler);
    // while (true)
    // {
    //     std::cout << "begin " << std::endl;
    //     sleep(1);
    //     abort(); // 给自己发送指定的信号
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

// // 自定义方法
// // signo：特定信号被发送给当前进程的时候，执行handler方法的时候，要自动填充对应的信号给handler方法
// // 我们甚至可以给所有的信号设置同一个处理函数
// void handler(int signo)
// {
//     std::cout << "get a singal: " << signo << std::endl;
//     // exit(2);
// }

// int main()
// {
//     // 1. 2号信号，进程的默认处理动作是终止进程
//     // 2. signal 可以进行对指定的信号设定自定义处理动作
//     // 3. signal(2, handler)调用完这个函数的时候，handler方法被调用了吗？没有！ 做了什么？只是更改了2号信号的处理动作，并没有调动handlder方法
//     // 4. 那么handler方法，什么时候被调用？当2号信号产生的时候！
//     // 5. 默认我们对2号信号的处理动作：终止进程，我们用signal(2, handler)， 我们在执行用户动作的自定义捕捉！

//     signal(SIGINT, handler);
//     signal(SIGQUIT, handler);

//     // for(int i = 1; i <= 31; i++)
//     // {
//     //     signal(i, handler);
//     // }

//     while(true)
//     {
//         std::cout << "我是一个进程，我正在运行 ..., pid: " << getpid() << std::endl;
//         sleep(1);
//     }

//     return 0;
// }