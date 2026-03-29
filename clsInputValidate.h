#pragma once
#include<iostream>
#include<string>
#include"ClsDate.h"
using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(int number,int from ,int to)
	{
		return (number<=to && number>=from) ? true : false;
	}
	static bool IsNumberBetween(double number, double from, double to)
	{
		return (number<=to && number>=from) ? true : false;
	}
	static bool IsNumberBetween(short number, short from, short to) 
	{
		return (number <= to && number >= from) ? true : false;
	}
	static bool IsNumberBetween(float number, float from, float to)
	{
		return (number <= to && number >= from) ? true : false;
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) 
	{
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
			(clsDate::IsDate1BeforDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))

			{
			return true;
		    }
		return false;
	}

	static int ReadIntNumber(string mssg="Invalid Number, Enter again : \n")
	{
		int number;
		while (!(cin>>number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << mssg;
		}
		return number;
	}
	static short ReadShortNumber(string mssg = "Invalid Number, Enter again : \n")
	{
		short number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << mssg;
		}
		return number;
	}
	static double ReadDblNumber(string mssg = "Invalid Number, Enter again : \n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << mssg;
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string mssg)
	{
		int num= ReadIntNumber();
		while (!IsNumberBetween(num, From, To)) {
			cout << mssg;
			num =ReadIntNumber(mssg);
		}
		return num;
	}
	static double ReadDblNumberBetween(double From, double To, string mssg)
	{
		double num = ReadDblNumber();
		while (!IsNumberBetween(num, From, To)) {
			cout << mssg;
			num = ReadDblNumber(mssg);
		}
		return num;
	}
	static short ReadShortNumberBetween(short From, short To, string mssg)
	{
		short num = ReadShortNumber();
		while (!IsNumberBetween(num, From, To)) {
			cout << mssg;
			num = ReadShortNumber(mssg);
		}
		return num;
	}
	static bool IsValideDate(clsDate Date)
	{
		return clsDate::isvalide(Date);
	}

	static string ReadString()
	{
		string s1="";
		getline(cin >> ws, s1);
		return s1;
	}
	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
};

