// observer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <list>
#include <string>
using namespace std;
class bank {

private:
   
public:
    string name;
    bank(string name) {
        this->name = name;
    }
    void update() {
        cout << name << " 想来收钱" << endl;
    }
};
class person {
private:
    string name;
    unordered_set<bank*>banks;
public:
    person(string name) {
        this->name = name;
    }
    void borrow(bank* b) {
        cout << "借了" << b->name << "的钱" << endl;
        if(banks.find(b)==banks.end())
        banks.insert(b);
    }
    void have_money() {
        cout << "我中彩票了" << endl;
        update_banks();
    }
    void update_banks() {
        for (auto it : banks) {
            it->update();
        }
    }
};
int main()
{
    bank* a = new bank("中行");
    bank* b = new bank("建行");
    bank* c = new bank("工行");
    person* zhang = new person("子航");
    zhang->borrow(a);
    zhang->borrow(b);
    zhang->borrow(c);
    zhang->have_money();
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
