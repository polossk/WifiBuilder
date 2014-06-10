/****
	*@PoloShen
	*Title:      WIFI Builder APP
	*File:       SubInterface.h
	*Build:      1.3
	*Build Time: 2014/03/08 08:00
*****/
#ifndef SUBINTERFACE_H_INCLUDED
#define SUBINTERFACE_H_INCLUDED

/** Public Library **/
#include <iostream>
#include <cstdlib>
using namespace std;

/** Namespace Sub Interface **/
namespace SubInterface
{
    void CallAbout()
    {
        cout << "                                                          " << endl;
        cout << "+---------------------------++---------------------------+" << endl;
        cout << "|                           ||                           |" << endl;
        cout << "|                           || 制作人  ：           Shen |" << endl;
        cout << "|                           || 发布日期：     2014/03/08 |" << endl;
        cout << "|                           || 版本：                1.3 |" << endl;
        cout << "|                           || 联系方式：polossk@126.com |" << endl;
        cout << "|                           || 技术博客：                |" << endl;
        cout << "|                           ||     blog.csdn.net/polossk |" << endl;
        cout << "|                           ||                           |" << endl;
        cout << "+---------------------------++---------------------------+" << endl;
        cout << "                                                          " << endl;
        MainInterface::TapInterface(); return;
    }

    void CallHelp()
    {
        cout << "                                                          " << endl;
        cout << "    欢迎使用帮助，本程序主要能帮您解决配置了无线网卡的电脑" << endl;
        cout << "配置您自己的WIFI，从而帮助其他设备进行联网。不过有些问题需" << endl;
        cout << "要您提前了解：                                            " << endl;
        cout << "                                                          " << endl;
        cout << "     *本程序并不能实现一键操作，但是已经尽量简化您的操作；" << endl;
        cout << "     *本程序需要在一台配置了无线网卡的并且可以正常联网的设" << endl;
        cout << "      备上运行。                                          " << endl;
        cout << "     *请您注意，虽然能够开启WIFI，但是实际上依然消耗您原有" << endl;
        cout << "      网络连接的流量，如果您原有网络连接是按照流量计费的，" << endl;
        cout << "      请您务必酌情使用。                                  " << endl;
        cout << "                                                          " << endl;
        cout << "    本程序主要是通过创建简单的脚本来实现构建WIFI和WIFI的开" << endl;
        cout << "启与关闭的，尽量减少用户的操作难度。                      " << endl;
        cout << "                                                          " << endl;
        cout << "    建议您按照提示进行输入输出操作，以免影响您的使用。    " << endl;
        cout << "                                                          " << endl;
        cout << "    如果您已经构建好了自己的WIFI，那么当您需要WIFI时只需要" << endl;
        cout << "执行 开启WIFI.bat 即可，具体操作是，右击，选择以管理员身份" << endl;
        cout << "运行，就可以了。关闭WIFI时执行 关闭WIFI.bat 即可，同样右击" << endl;
        cout << "选择以管理员身份运行。                                    " << endl;
        cout << "                                                          " << endl;
        cout << "    如果您尚未构建好自己的WIFI，请您按照提示进行构建即可。" << endl;
        cout << "                                                          " << endl;
        MainInterface::TapInterface();
        return;
    }

    void CallWrongInput()
    {
        cout << "对不起，您输入了错误的指令，很抱歉不能为您服务。" << endl;
        cout << "请问您是否需要帮助？[Y/N]" << endl;
        string op; cin >> op;
        if (op == "Y" || op == "y") { CallHelp(); return; }
        else MainInterface::TapInterface();
        return;
    }
}

#endif // SUBINTERFACE_H_INCLUDED
