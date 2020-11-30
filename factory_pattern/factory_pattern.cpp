// factory_pattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class shoes {
public:
    virtual void show() = 0;
        
    
};
class nike_shoes: public shoes {
public:
    void show() {
        cout << "nike!" << endl;
    }
};
class adi_shoes : public shoes {
public:
    void show() {
        cout << "adi!" << endl;
    }
};

class shoes_factory {
public:
    virtual shoes* creat_shoes() = 0;
    virtual~shoes_factory(){}
    
};
class nike_factory: public shoes_factory {
public:

    shoes* creat_shoes(){
        return new nike_shoes();
    }
};
class adi_factory : public shoes_factory {
public:
    shoes* creat_shoes() {
        return new adi_shoes();
    }
};


int main()
{
    shoes_factory* n= new nike_factory();
    shoes* shoes1=n->creat_shoes();
    shoes1->show();
    shoes_factory* a = new adi_factory();
    shoes* shoes2 = a->creat_shoes();
    shoes2->show();


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
