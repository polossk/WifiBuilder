/****
	*@PoloShen
	*Title:      WIFI Builder APP
	*File:       BashFilesBuilder.h
	*Build:      1.3
	*Build Time: 2014/03/08 08:00
*****/
#ifndef BASHFILESBUILDER_H_INCLUDED
#define BASHFILESBUILDER_H_INCLUDED

/** Public Library **/
#include <iostream>
#include <fstream>
using namespace std;

/** Namespace Files Exporter**/
namespace FilesExporter
{
    void ExportWifiBuilderCmdFile(string SSID, string PSWD)
    {
        ofstream outf1("创建WIFI.bat");
        outf1 << "@echo off" << endl;
        outf1 << "title Build Wifi    v" << VERSION << endl;
        outf1 << "Elevate netsh wlan stop hostednetwork" << endl;
        outf1 << "Elevate netsh wlan set hostednetwork mode=allow ssid=" << SSID;
        outf1 << " key=" << PSWD << endl;
        outf1 << "Elevate netsh wlan start hostednetwork" << endl;
        outf1 << "@echo 已经成功创建WIFI，用手机搜索 " << SSID << " 即可。" << endl;
        outf1 << "pause" << endl;
        outf1.close();
        return;
    }

    void ExportWifiSwitcherCmdFile(string SSID)
    {
        ofstream outf2("开启WIFI.bat");
        outf2 << "@echo off" << endl;
        outf2 << "title 启动 Wifi    v" << VERSION << endl;
        outf2 << "Elevate netsh wlan start hostednetwork" << endl;
        outf2 << "@echo WIFI已经开启，用手机搜索 " << SSID << " 即可。\n" << endl;
        outf2 << "pause" << endl;
        outf2.close();

        ofstream outf3("关闭WIFI.bat");
        outf3 << "@echo off" << endl;
        outf3 << "title 关闭 Wifi    v" << VERSION << endl;
        outf3 << "Elevate netsh wlan stop hostednetwork" << endl;
        outf3 << "@echo WIFI已经关闭，你将无法搜索到 " << SSID << " 。\n" << endl;
        outf3 << "pause" << endl;
        outf3.close();
        return;
    }

    void ExportWifiICSCmdFile(string VirtualWireless, string CurrentWireless)
    {
        ofstream outf4("ICS.bat");
        outf4 << "@echo off" << endl;
        outf4 << "title 连接共享    v" << VERSION << endl;
        outf4 << "Elevate cscript /nologo %~dp0\\ics.vbs ";
        outf4 << "\"" << VirtualWireless << "\" ";
        outf4 << "\"" << CurrentWireless << "\" ";
        outf4 << "\"on\"" << endl;
        outf4 << "@echo 共享设置完成，" << endl;
        outf4 << "pause" << endl;
        outf4.close();
    }
}

#endif // BASHFILESBUILDER_H_INCLUDED
