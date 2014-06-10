/****
	*@PoloShen
	*Title:      WIFI Builder APP
	*File:       HistoryInterface.h
	*Build:      1.3
	*Build Time: 2014/03/08 08:00
*****/
#ifndef HISTORYINTERFACE_H_INCLUDED
#define HISTORYINTERFACE_H_INCLUDED

/** Public Library **/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/** Namespace History Interface **/
namespace HistoryInterface
{
    bool    ExitFlag = 0;
    int     OptionCh = 0;
    void PrintInterface()
    {
        cout << "    请输入你的选项：" << endl;
        cout << "        1: 查看以前的Wifi名与密码" << endl;
        cout << "        2: 修改Wifi名称" << endl;
        cout << "        3: 修改Wifi密码" << endl;
        cout << "        4: 退出" << endl;
        return;
    }

    void CallExit(){ ExitFlag = 1; return; }

    void CallShow(){ ExitFlag = Database::ReadDatabaseFiles(); }

    void CallEditSSID()
    {
        cout << "        请输入新的Wifi名称：" << endl;
        string SSID, PSWD;
        ifstream fin(Database::FileName.c_str());
        if (fin.fail())
        {
            cout << "        您还没有使用过本程序，暂时没有历史数据。" << endl;
            cout << "        将直接返回至主界面。" << endl;
            CallExit();
            return;
        }
        else
        {
            string s, p;
            fin >> s >> p; fin.close();
            cin >> SSID;
            cout << "        正在重新构建，请稍后" << endl;
            PSWD = Cipher::DeCodeString(p);
            Wifi::BuildWifi(SSID, PSWD);
            Wifi::BuildData(SSID, PSWD);
        }
        cout << "        构建完成，您的Wifi名称已经更新" << endl;
        return;
    }

    void CallEditPSWD()
    {
        cout << "        请输入新的Wifi密码：" << endl;
        string SSID, PSWD;
        ifstream fin(Database::FileName.c_str());
        if (fin.fail())
        {
            cout << "        您还没有使用过本程序，暂时没有历史数据。" << endl;
            cout << "        将直接返回至主界面。" << endl;
            CallExit();
            return;
        }
        else
        {
            string s, p;
            fin >> s >> p; fin.close();
            cin >> PSWD;
            cout << "        正在重新构建，请稍后" << endl;
            SSID = Cipher::DeCodeString(s);
            Wifi::BuildWifi(SSID, PSWD);
            Wifi::BuildData(SSID, PSWD);
        }
        cout << "        构建完成，您的Wifi密码已经更新" << endl;
        return;
    }

    void CallHistory()
    {
        while (1)
        {
            PrintInterface();
            cin >> OptionCh;
            switch (OptionCh)
            {
                case 1:{ CallShow(); break; }
                case 2:{ CallEditSSID(); break; }
                case 3:{ CallEditPSWD(); break; }
                case 4:{ CallExit(); break; }
                default :{ SubInterface::CallWrongInput(); break; }
            }
            if (ExitFlag) break;
        }
    }
}

#endif // HISTORYINTERFACE_H_INCLUDED
