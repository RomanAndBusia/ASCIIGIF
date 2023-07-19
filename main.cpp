#include "pch.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <random>
#include <list>;
namespace fs = std::filesystem;

using namespace std;

const char colors[] = {'1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
list <string> cl = { "1","2","3","4","5","6","7","8","9","a","b","c","d","e","f" };
int main()
{
	string path = "frames/";
	fstream fl;
	string str;
	int color;
	string timeout;
	int delay;
	const char * cmd;
	while (true)
	{
		cout << "Type timeout (ms):";
		cin >> timeout;
		try
		{
			delay = stoi(timeout);
			break;
		}
		catch (exception e)
		{
			cout << "Error! " << endl;
		}
	} 
	while (true)
	{
		for (const auto& entry : fs::directory_iterator(path))
		{
			fl.open(entry.path());
			while (getline(fl, str))
			{
				cout << str << endl;
			}
			fl.close();
			Sleep(delay);
			auto a = cl.begin();
			advance(a, rand() % 15);
			string c = "color " + *a;
			cmd = c.c_str();
			system(cmd);
			system("cls");
		}
	}
}
