/****
	*@PoloShen
	*Title:      WIFI Builder APP
	*File:       HistoryDatabase.h
	*Build:      1.3
	*Build Time: 2014/03/08 08:00
*****/
#ifndef HISTORYDATABASE_H_INCLUDED
#define HISTORYDATABASE_H_INCLUDED

/** Public Library **/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/** Namespace Cipher **/
namespace Cipher
{
    const int radix[5] = {1, 3, 5, 7, 11};

    char EnCodeChar(char c, int key){ return c = c ^ key; }

    char DeCodeChar(char c, int key){ return c ^ key; }

    string EnCodeString(string s)
    {
        int sz = s.size();
        string res = "";
        for (int i = 0; i < sz; i++)
        {
            char ch = EnCodeChar(s[i], radix[i % 5]);
            res += ch;
        }
        return res;
    }

    string DeCodeString(string s)
    {
        int sz = s.size();
        string res = "";
        for (int i = 0; i < sz; i++)
        {
            char ch = DeCodeChar(s[i], radix[i % 5]);
            res += ch;
        }
        return res;
    }
}

/** Namespace Database **/
namespace Database{
    const string FileName = "HistoryDatabase.out";

    class Datatype
    {
    public:
        Datatype(){ SSID = ""; PSWD = ""; }
        Datatype(string s, string p)
        {
            SSID = Cipher::EnCodeString(s);
            PSWD = Cipher::EnCodeString(p);
        }
        string ShowSSID() const { return SSID; }
        string ShowPSWD() const { return PSWD; }
        void ExportData() const
        {
            ofstream Data(FileName.c_str(), ios::out);
            Data << SSID << endl;
            Data << PSWD << endl;
            Data.close();
            return;
        }
        friend ostream& operator<<(ostream& os, const Datatype& d)
        {
            os << "        当前使用的Wifi名称为：\n\t\t";
            os << Cipher::DeCodeString(d.ShowSSID()) << endl;
            os << "        当前密码是：\n\t\t";
            os << Cipher::DeCodeString(d.ShowPSWD()) << endl;
            os << "        请牢记。" << endl;
            return os;
        }
    private:
        string SSID;
        string PSWD;
    };

    void ExportDatabaseFiles(Datatype d)
    {
        d.ExportData();
    }

    bool ReadDatabaseFiles()
    {
        ifstream fin;
        fin.open(FileName.c_str());
        if (fin.fail())
        {
            cout << "        您还没有使用过本程序，暂时没有历史数据。" << endl;
            cout << "        将直接返回至主界面。" << endl;
            return 1;
        }
        else
        {
            string s, p;
            fin >> s >> p; fin.close();
            s = Cipher::DeCodeString(s);
            p = Cipher::DeCodeString(p);
            Datatype d(s, p);
            cout << d << endl;
            return 0;
        }
    }
}

#endif // HISTORYDATABASE_H_INCLUDED
