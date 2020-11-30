// threadtest_condition_variable.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include<condition_variable>
using namespace std;


class thread_condition_variable {
private:
    mutex mymutex;
public:
    int k = 0;
    condition_variable con;
    void printA() {
        cout << "A " << "threadID: "<<this_thread::get_id()<<endl;
        k = 1;
        con.notify_all();
    }
    void printB() {
        unique_lock<mutex>uni_lock(mymutex);
        con.wait(uni_lock, [this]() {
            return k == 1;});
        cout << "B " << "threadID: " << this_thread::get_id() << endl;
        k = 2;
        con.notify_all();
    }
    void printC() {
        unique_lock<mutex>uni_lock(mymutex);
        con.wait(uni_lock, [this]() {
            return k == 2;});
        cout << "C " << "threadID: " << this_thread::get_id()<< endl;
    }
};

int main()
{
    int n = 0;
    while (n < 10) {
        n++;
        thread_condition_variable a;
        thread A(&thread_condition_variable::printA, &a);
        thread B(&thread_condition_variable::printB, &a);
        thread C(&thread_condition_variable::printC, &a);
        A.join();
        B.join();
        C.join();

    }
    std::cout << "you win";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
