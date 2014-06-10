/****
*@PoloShen
*Title:      WIFI Builder APP
*File:       BashFilesBuilder.h
*Build:      1.3
*Build Time: 2014/03/08 08:00
*****/
#ifndef PREFILESBUILD_H_INCLUDED
#define PREFILESBUILD_H_INCLUDED

/** Public Library **/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/** Namespace PreFiles Exporter**/
namespace PreFiles
{
	void ExportElevate()
	{
		const string FileName = "Elevate.js";
		ifstream fin;
		fin.open(FileName.c_str());
		if (fin.fail())
		{
			fin.close();
			ofstream js(FileName.c_str());
			js << "\/\/Elevate <exefile> <arguments>" << endl;
			js << "var command = WScript.Arguments.Item(0);" << endl;
			js << "var argument = \"\";" << endl;
			js << "for (var i = 1; i < WScript.Arguments.Count(); ++i){" << endl;
			js << "    argument += WScript.Arguments.Item(i) + \" \";" << endl;
			js << "}" << endl;
			js << "try{" << endl;
			js << "    var shellapp = new ActiveXObject(\"Shell.Application\");" << endl;
			js << "    shellapp.ShellExecute(command, argument, null, \"runas\", 1);" << endl;
			js << "}" << endl;
			js << "catch (e){" << endl;
			js << "    WScript.Echo(\"Something wrong: \" + e.description);" << endl;
            js << "}" << endl;
			js.close();
		}
		else return;
	}

	void ExportICS()
	{
		const string FileName = "ICS.vbs";
		ifstream fin;
		fin.open(FileName.c_str());
		if (fin.fail())
		{
			fin.close();
			ofstream ics(FileName.c_str());
			ics << "OPTION EXPLICIT" << endl;
			ics << "DIM ICSSC_DEFAULT, CONNECTION_PUBLIC, CONNECTION_PRIVATE, CONNECTION_ALL" << endl;
			ics << "DIM NetSharingManager" << endl;
			ics << "DIM PublicConnection, PrivateConnection" << endl;
			ics << "DIM EveryConnectionCollection" << endl;
			ics << "DIM objArgs" << endl;
			ics << "DIM priv_con, publ_con" << endl;
			ics << "" << endl;
			ics << "dim switch" << endl;
			ics << "" << endl;
			ics << "ICSSC_DEFAULT         = 0" << endl;
			ics << "CONNECTION_PUBLIC     = 0" << endl;
			ics << "CONNECTION_PRIVATE    = 1" << endl;
            ics << "CONNECTION_ALL        = 2" << endl;
            ics << "" << endl;
            ics << "Main()" << endl;
            ics << "" << endl;
            ics << "sub Main()" << endl;
            ics << "    Set objArgs = WScript.Arguments" << endl;
            ics << "    if objArgs.Count = 3 then" << endl;
            ics << "        priv_con = objArgs(0)" << endl;
            ics << "		publ_con = objArgs(1)" << endl;
            ics << "		switch = objArgs(2)" << endl;
            ics << "" << endl;
            ics << "        if Initialize() = TRUE then" << endl;
            ics << "            GetConnectionObjects()" << endl;
            ics << "            FirewallTestByName priv_con,publ_con" << endl;
            ics << "        end if" << endl;
            ics << "" << endl;
            ics << "    else" << endl;
            ics << "        DIM szMsg" << endl;
            ics << "        if Initialize() = TRUE then" << endl;
            ics << "            GetConnectionObjects()" << endl;
			ics << "            FirewallTestByName \"list\",\"list\"" << endl;
			ics << "        end if" << endl;
			ics << "        szMsg = \"To share your internet connection, please provide \" & _" << endl;
			ics << "				\"the name of the private and public connections as the argument.\" & _" << endl;
			ics << "				vbCRLF & vbCRLF & \"Usage:\" & vbCRLF & \"       \" & WScript.scriptname & _" << endl;
			ics << "				\" \" & chr(34) & \"Private Connection Name\" & chr(34) & \" \" & _" << endl;
			ics << "				chr(34) & \"Public Connection Name\" & chr(34)" << endl;
			ics << "        WScript.Echo( szMsg & vbCRLF & vbCRLF)" << endl;
			ics << "    end if" << endl;
			ics << "end sub" << endl;
			ics << "" << endl;
			ics << "sub FirewallTestByName(con1,con2)" << endl;
			ics << "	on error resume next" << endl;
			ics << "    DIM Item" << endl;
			ics << "    DIM EveryConnection" << endl;
			ics << "    DIM objNCProps" << endl;
			ics << "    DIM szMsg" << endl;
			ics << "    DIM bFound1,bFound2" << endl;
			ics << "    WScript.echo(vbCRLF & vbCRLF)" << endl;
			ics << "    bFound1 = false" << endl;
			ics << "    bFound2 = false" << endl;
			ics << "    for each Item in EveryConnectionCollection" << endl;
			ics << "        set EveryConnection = NetSharingManager.INetSharingConfigurationForINetConnection(Item)" << endl;
			ics << "        set objNCProps = NetSharingManager.NetConnectionProps(Item)" << endl;
			ics << "        szMsg = \"Name: \"       & objNCProps.Name & vbCRLF & _" << endl;
			ics << "                \"Guid: \"       & objNCProps.Guid & vbCRLF & _" << endl;
			ics << "                \"DeviceName: \" & objNCProps.DeviceName & vbCRLF & _" << endl;
			ics << "                \"Status: \"     & objNCProps.Status & vbCRLF & _" << endl;
			ics << "                \"MediaType: \"  & objNCProps.MediaType" << endl;
			ics << "        if EveryConnection.SharingEnabled then" << endl;
			ics << "            szMsg = szMsg & vbCRLF & _" << endl;
			ics << "                    \"SharingEnabled\" & vbCRLF & _" << endl;
			ics << "                    \"SharingType: \" & ConvertConnectionTypeToString(EveryConnection.SharingConnectionType)" << endl;
			ics << "        end if" << endl;
			ics << "        if objNCProps.Name = con1 then" << endl;
			ics << "            bFound1 = true" << endl;
			ics << "            if EveryConnection.SharingEnabled = False and switch=\"on\" then" << endl;
			ics << "                szMsg = szMsg & vbCRLF & \"Not Shared... Enabling private connection share...\"" << endl;
			ics << "                WScript.Echo(szMsg)" << endl;
			ics << "                EveryConnection.EnableSharing CONNECTION_PRIVATE" << endl;
			ics << "                szMsg = \" Shared!\"" << endl;
			ics << "						elseif(switch = \"off\") then " << endl;
			ics << "								szMsg = szMsg & vbCRLF & _" << endl;
			ics << "										\"Shared... DisEnabling private connection share...\"" << endl;
			ics << "                WScript.Echo(szMsg)" << endl;
            ics << "								EveryConnection.EnableSharing CONNECTION_ALL" << endl;
			ics << "            end if" << endl;
			ics << "        end if" << endl;
			ics << "        if objNCProps.Name = con2 then" << endl;
			ics << "            bFound2 = true" << endl;
			ics << "            if EveryConnection.SharingEnabled = False and switch=\"on\" then" << endl;
			ics << "                szMsg = szMsg & vbCRLF & \"Not Shared... Enabling public connection share...\"" << endl;
			ics << "                WScript.Echo(szMsg)" << endl;
			ics << "                EveryConnection.EnableSharing CONNECTION_PUBLIC" << endl;
			ics << "                szMsg = \" Shared!\"" << endl;
			ics << "						elseif(switch = \"off\") then" << endl;
			ics << "								szMsg = szMsg & vbCRLF & _" << endl;
			ics << "										\"Shared... DisEnabling public connection share...\"" << endl;
			ics << "                WScript.Echo(szMsg)" << endl;
			ics << "								EveryConnection.EnableSharing CONNECTION_ALL" << endl;
			ics << "			end if" << endl;
			ics << "        end if" << endl;
			ics << "        WScript.Echo(szMsg & vbCRLF & vbCRLF)" << endl;
			ics << "    next" << endl;
			ics << "    if( con1 <> \"list\" ) then" << endl;
			ics << "        if( bFound1 = false ) then" << endl;
			ics << "            WScript.Echo( \"Connection \" & chr(34) & con1 & chr(34) & \" was not found\" )" << endl;
			ics << "        end if" << endl;
			ics << "        if( bFound2 = false ) then" << endl;
			ics << "            WScript.Echo( \"Connection \" & chr(34) & con2 & chr(34) & \" was not found\" )" << endl;
			ics << "        end if" << endl;
			ics << "    end if" << endl;
			ics << "end sub" << endl;
			ics << "" << endl;
			ics << "function Initialize()" << endl;
			ics << "    DIM bReturn" << endl;
			ics << "    bReturn = FALSE" << endl;
			ics << "    set NetSharingManager = Wscript.CreateObject(\"HNetCfg.HNetShare.1\")" << endl;
			ics << "    if (IsObject(NetSharingManager)) = FALSE then" << endl;
			ics << "        Wscript.Echo(\"Unable to get the HNetCfg.HnetShare.1 object\")" << endl;
			ics << "    else" << endl;
			ics << "        if (IsNull(NetSharingManager.SharingInstalled) = TRUE) then" << endl;
			ics << "            Wscript.Echo(\"Sharing isn't available on this platform.\")" << endl;
			ics << "        else" << endl;
			ics << "            bReturn = TRUE" << endl;
			ics << "        end if" << endl;
			ics << "    end if" << endl;
			ics << "    Initialize = bReturn" << endl;
			ics << "end function" << endl;
			ics << "" << endl;
			ics << "function GetConnectionObjects()" << endl;
			ics << "    DIM bReturn" << endl;
			ics << "    DIM Item" << endl;
			ics << "    bReturn = TRUE" << endl;
			ics << "    if GetConnection(CONNECTION_PUBLIC) = FALSE then" << endl;
			ics << "        bReturn = FALSE" << endl;
			ics << "    end if" << endl;
			ics << "    if GetConnection(CONNECTION_PRIVATE) = FALSE then" << endl;
			ics << "        bReturn = FALSE" << endl;
			ics << "    end if" << endl;
			ics << "    if GetConnection(CONNECTION_ALL) = FALSE then" << endl;
			ics << "        bReturn = FALSE" << endl;
			ics << "    end if" << endl;
			ics << "    GetConnectionObjects = bReturn" << endl;
			ics << "end function" << endl;
			ics << "" << endl;
			ics << "function GetConnection(CONNECTION_TYPE)" << endl;
			ics << "    DIM bReturn" << endl;
			ics << "    DIM Connection" << endl;
			ics << "    DIM Item" << endl;
			ics << "    bReturn = TRUE" << endl;
			ics << "    if (CONNECTION_PUBLIC = CONNECTION_TYPE) then" << endl;
			ics << "        set Connection = NetSharingManager.EnumPublicConnections(ICSSC_DEFAULT)" << endl;
			ics << "        if (Connection.Count > 0) and (Connection.Count < 2) then" << endl;
			ics << "            for each Item in Connection" << endl;
			ics << "                set PublicConnection = NetSharingManager.INetSharingConfigurationForINetConnection(Item)" << endl;
			ics << "            next" << endl;
			ics << "        else" << endl;
			ics << "            bReturn = FALSE" << endl;
			ics << "        end if" << endl;
			ics << "    elseif (CONNECTION_PRIVATE = CONNECTION_TYPE) then" << endl;
			ics << "        set Connection = NetSharingManager.EnumPrivateConnections(ICSSC_DEFAULT)" << endl;
			ics << "        if (Connection.Count > 0) and (Connection.Count < 2) then" << endl;
			ics << "            for each Item in Connection" << endl;
			ics << "                set PrivateConnection = NetSharingManager.INetSharingConfigurationForINetConnection(Item)" << endl;
			ics << "            next" << endl;
			ics << "        else" << endl;
			ics << "            bReturn = FALSE" << endl;
			ics << "        end if" << endl;
			ics << "    elseif (CONNECTION_ALL = CONNECTION_TYPE) then" << endl;
			ics << "        set Connection = NetSharingManager.EnumEveryConnection" << endl;
			ics << "        if (Connection.Count > 0) then" << endl;
			ics << "            set EveryConnectionCollection = Connection" << endl;
			ics << "        else" << endl;
			ics << "            bReturn = FALSE" << endl;
			ics << "        end if" << endl;
			ics << "    else" << endl;
			ics << "        bReturn = FALSE" << endl;
			ics << "    end if" << endl;
			ics << "    if (TRUE = bReturn)  then" << endl;
			ics << "        if (Connection.Count = 0) then" << endl;
			ics << "            Wscript.Echo(\"No \" + CStr(ConvertConnectionTypeToString(CONNECTION_TYPE)) + \" connections exist (Connection.Count gave us 0)\")" << endl;
			ics << "            bReturn = FALSE" << endl;
			ics << "        'valid to have more than 1 connection returned from EnumEveryConnection" << endl;
			ics << "        elseif (Connection.Count > 1) and (CONNECTION_ALL <> CONNECTION_TYPE) then" << endl;
			ics << "            Wscript.Echo(\"ERROR: There was more than one \" + ConvertConnectionTypeToString(CONNECTION_TYPE) + \" connection (\" + CStr(Connection.Count) + \")\")" << endl;
			ics << "            bReturn = FALSE" << endl;
			ics << "        end if" << endl;
			ics << "    end if" << endl;
			ics << "    Wscript.Echo(CStr(Connection.Count) + \" objects for connection type \" + ConvertConnectionTypeToString(CONNECTION_TYPE))" << endl;
			ics << "    GetConnection = bReturn" << endl;
			ics << "end function" << endl;
			ics << "" << endl;
			ics << "function ConvertConnectionTypeToString(ConnectionID)" << endl;
			ics << "    DIM ConnectionString" << endl;
			ics << "    if (ConnectionID = CONNECTION_PUBLIC) then" << endl;
			ics << "        ConnectionString = \"public\"" << endl;
			ics << "    elseif (ConnectionID = CONNECTION_PRIVATE) then" << endl;
			ics << "        ConnectionString = \"private\"" << endl;
			ics << "    elseif (ConnectionID = CONNECTION_ALL) then" << endl;
			ics << "        ConnectionString = \"all\"" << endl;
			ics << "    else" << endl;
			ics << "        ConnectionString = \"Unknown: \" + CStr(ConnectionID)" << endl;
			ics << "    end if" << endl;
			ics << "    ConvertConnectionTypeToString = ConnectionString" << endl;
			ics << "end function" << endl;
			ics.close();
		}
		else return;
	}

	void BuildAll()
	{
		ExportElevate();
		ExportICS();
	}
}


#endif // PREFILESBUILD_H_INCLUDED
