/****
	*@PoloShen
	*Title:      WIFI Builder APP
	*File:       MainInterface.h
	*Build:      1.3
	*Build Time: 2014/03/08 08:00
*****/
#ifndef MAININTERFACE_H_INCLUDED
#define MAININTERFACE_H_INCLUDED

/** Public Library **/
#include <iostream>
#include <cstdlib>
using namespace std;

/** Namespace Main Interface **/
namespace MainInterface
{
    bool    ExitFlag = 0;
    int     OptionCh = 0;
    void PrintMainInterface()
    {
        system("title Wifi Builder v1.3 -By Shen");
        cout << "                /***********************\\" << endl;
        cout << "                *      WIFI Builder     *" << endl;
        cout << "                *           By Shen     *" << endl;
        cout << "                \\***********************/" << endl;
        cout << endl;
        cout << "欢迎使用本应用，没有图形化界面非常抱歉=。=" << endl;
        cout << "请输入你的选项：" << endl;
        cout << "    1: 创建你的Wifi热点" << endl;
        cout << "    2: 查看WIfi热点历史" << endl;
        cout << "    3: 关于" << endl;
        cout << "    4: 帮助" << endl;
        cout << "    5: 退出" << endl;
        cout << endl;
    }

    void CallExit()
    {
        ExitFlag = 1;
        cout << "谢谢您的使用" << endl;
        cout << "再见！" << endl;
        return;
    }

    void TapInterface()
    {
        cout << "是否需要帮您返回主菜单？[Y/N]" << endl;
        string op; cin >> op;
        if (op == "Y" || op == "y") { return; }
        else cout << "是否退出本程序？[Y/N]" << endl;
        cin >> op;
        if (op == "Y" || op == "y") { CallExit(); return; }
        return;
    }
}

#endif // MAININTERFACE_H_INCLUDED
