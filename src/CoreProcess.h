/****
	*@PoloShen
	*Title:      WIFI Builder APP
	*File:       CoreProcess.h
	*Build:      1.3
	*Build Time: 2014/03/08 08:00
*****/
#ifndef COREPROCESS_H_INCLUDED
#define COREPROCESS_H_INCLUDED

/** Public Library **/
#include <iostream>
#include <cstdlib>
using namespace std;

/** Namespace Wifi **/
namespace Wifi
{
    string getSSID()
    {
        string SSID;
        cout << "    请给您的WIFI命名，英文，大小写均可，中间不要有空格。  " << endl;
        cin >> SSID;
        return SSID;
    }

    string getPSWD()
    {
        string PSWD;
        cout << "    请输入您WIFI的密码，注意，长度大于8位，不要有空格。   " << endl;
        cin >> PSWD;
        return PSWD;
    }

    string getCW()
    {
        string CurrentWireless;
        getchar();
        while (1)
        {
            cout << "    请输入当前正在使用的网络连接名称（一般为本地连接，宽带" << endl;
            cout << "用户一般为宽带连接），以回车结束。                        " << endl;
            getline(cin, CurrentWireless);
            cout << "您刚刚输入的是：\n" << endl;
            cout << CurrentWireless << endl << endl;
            cout << "是否正确？[Y/N]" << endl;
            string op; cin >> op;
            if (op == "Y" || op == "y") { break; }
        }
        return CurrentWireless;
    }

	string getVW()
	{
		string VirtualWireless;
		getchar();
		while (1)
		{
			cout << "    请输入新增的无线网络连接名称（一般为 本地连接 2 ），请" << endl;
			cout << "务必正确输入，以回车结束。                                " << endl;
			getline(cin, VirtualWireless);
			cout << "您刚刚输入的是：\n" << endl;
			cout << VirtualWireless << endl << endl;
			cout << "是否正确？[Y/N]" << endl;
			string op; cin >> op;
			if (op == "Y"|| op == "y") {
				break;
			}
        }
        return VirtualWireless;
    }

    void BuildData(string s, string p)
    {
        Database::Datatype d(s, p);
        Database::ExportDatabaseFiles(d);
    }

    void BuildWifi(string SSID, string PSWD)
    {
        cout << "    正在构建批处理文件...                                 " << endl;
        FilesExporter::ExportWifiBuilderCmdFile(SSID, PSWD);
        FilesExporter::ExportWifiSwitcherCmdFile(SSID);
        BuildData(SSID, PSWD);
        cout << "    正在运行批处理文件...                                 " << endl;
        system("创建WIFI.bat");
        cout << "    运行完成                                              " << endl;
        cout << "                                                          " << endl;
    }

    void BuildICS()
    {
        cout << "    请右击任务栏上的网络连接图标，打开网络与共享中心，在左" << endl;
        cout << "边栏找到更改适配器设置，便可以看到正在使用的网络连接名称和" << endl;
        cout << "新增加的WIFI连接名称。                                    " << endl;
        string CurrentWireless = getCW();
        string VirtualWireless = getVW();
        cout << "    正在为您构建网络共享设置，请稍后...                   " << endl;
        FilesExporter::ExportWifiICSCmdFile(VirtualWireless, CurrentWireless);
        system("ICS.bat");
        cout << "    构建完成                                              " << endl;
        cout << "                                                          " << endl;
    }

    void CallBuildWifi()
    {
        cout << "    开始创建您的WIFI。                                    " << endl;
        string SSID = getSSID();
        string PSWD = getPSWD();
        BuildWifi(SSID, PSWD);
        BuildICS();
        cout << "                                                          " << endl;
        cout << "WIFI搭建全部完成：                                        " << endl;
        cout << "    * 使用WIFI请选择 开启WIFI.bat 右键以管理员身份运行；  " << endl;
        cout << "    * 关闭WIFI请选择 关闭WIFI.bat 右键以管理员身份运行；  " << endl;
        cout << "即将返回主界面" << endl; system("pause"); return;
    }
}

#endif // COREPROCESS_H_INCLUDED
