#include <iostream>

using namespace std;

// 抽象接口类
class Control
{
public:
    virtual void Start() = 0;
    virtual void ShutDown() = 0;
};

// 主机
class Host : public Control
{
public:
    void Start() override
    {
        cout << "Host Start." << endl; 
    }

    void ShutDown() override
    {
        cout << "Host ShutDown." << endl;
    }
};

// 显示器
class Screen : public Control
{
public:
    void Start() override
    {
        cout << "Screen Start." << endl;
    }

    void ShutDown() override
    {
        cout << "Screen ShutDown." << endl;
    }
};

// 外设
class Interface : public Control
{
public:
    void Start() override
    {
        cout << "Interface Start." << endl;
    }

    void ShutDown() override
    {
        cout << "Interface ShutDown." << endl;
    }
};


// 客户端类  电脑
class Computer
{
public:
    void Start()
    {
        m_host.Start();
        m_screen.Start();
        m_interface.Start();
        cout << "Computer Start." << endl;
    }

    void ShutDown()
    {
        m_host.ShutDown();
        m_screen.ShutDown();
        m_interface.ShutDown();
        cout << "Computer ShutDown." << endl;
    }

private:
    Host m_host;
    Screen m_screen;
    Interface m_interface;
};

int main()
{
    Computer computer;
    computer.Start();

    // do something

    computer.ShutDown();
    return 0;
}