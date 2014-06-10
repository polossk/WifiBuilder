/****
	*@PoloShen
	*Title:      WIFI Builder APP
	*File:       WifiBuilder.cpp
	*Build:      1.3
	*Build Time: 2014/03/08 08:00
*****/

/** Version Number **/
#define VERSION 1.3

/** Public Library **/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

/** Header Files **/
#include "MainInterface.h"
#include "SubInterface.h"
#include "BashFilesBuilder.h"
#include "HistoryDatabase.h"
#include "CoreProcess.h"
#include "HistoryInterface.h"
#include "PreFilesBuild.h"

/** Declared Namespace **/
/*
using namespace MainInterface;
using namespace SubInterface;
using namespace FilesExporter;
using namespace Database;
using namespace HistoryInterface;
using namespace Wifi;
*/

int main()
{
	PreFiles::BuildAll();
	while (1)
    {
        MainInterface::PrintMainInterface();
        cin >> MainInterface::OptionCh;
        switch (MainInterface::OptionCh)
        {
			case 1:{ Wifi::CallBuildWifi(); break; }
			case 2:{ HistoryInterface::CallHistory(); break; }
			case 3:{ SubInterface::CallAbout(); break; }
			case 4:{ SubInterface::CallHelp(); break; }
            case 5:{ MainInterface::CallExit(); break; }
			default:{ SubInterface::CallWrongInput(); break; }
        }
        if (MainInterface::ExitFlag) break;
    }
    return 0;
}
