#pragma warning(disable:4996)
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class clsDate
{
private:
	short _day = 1;
	short _month = 1;
	short _year = 1900;
	vector <string> split(string s1, string delim) {
		vector<string> vstring;
		string sword = " ";
		short pos = 0;
		while ((pos = s1.find(delim)) != string::npos) {
			sword = s1.substr(0, pos);
			if (sword != "") {
				vstring.push_back(sword);
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != "") {
			vstring.push_back(sword);
		}
		return vstring;
	}
public:
	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}
	clsDate(string sdate) {
		vector<string> vdate;
		vdate = split(sdate, "/");
		_day = stoi(vdate[0]);
		_month = stoi(vdate[1]);
		_year = stoi(vdate[2]);
	}
	clsDate(short d, short m, short y) {
		_day = d;
		_month = m;
		_year = y;
	}
	clsDate(short dnum, short y) {
		clsDate date1 = GetDateFromDayOrderInYear(dnum, y);
		_day = date1.day;
		_month = date1.month;
		_year = date1.year;
	}
	void setDay(short day) {
		_day = day;
	}
	short getDay() {
		return _day;

	}
	__declspec(property(get = getDay, put = setDay)) short day;
	void setMonth(short month) {
		_month = month;
	}
	short getMonth() {
		return _month;

	}
	__declspec(property(get = getMonth, put = setMonth)) short month;
	void setYear(short year) {
		_year = year;
	}
	short getYear() {
		return _year;

	}
	__declspec(property(get = getYear, put = setYear)) short year;
	void print() {
		cout << DateTostring() << endl;

	}
	static void printMonthCalender(short m, short y) {
		int NumberOfDays;
		int current = DayOfWeekOrder(1, m, y);
		NumberOfDays = numberOfDaysInAMonth(m, y);
		printf("\n__________________%s__________________\n\n",
			MonthShortName(m).c_str());
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");
		int i;
		for ( i = 0; i < current; i++)
		{
			printf("    ");
		}
		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7) {
				i = 0;
				printf("\n");
			}
		}
		printf("\n ____________________________________\n");

	}
	void printMonthCalender() 
	{
		printMonthCalender(_month, _year);
	}
	void printYearCalender(int year) {
		printf("\n_____________________________________\n\n");
		printf("          Calender -%d\n ", _year);
		printf("______________________________________\n");
		for (int i = 1; i <= 12; i++)
		{
			printMonthCalender(i, year);
		}
		return;
	}
	void printYearCalender()
	{
		printYearCalender(_year);
	}
	static bool isvalide(clsDate date) {
		if (date.day < 1 || date.day>31) {
			return false;
		}
		if (date.month < 1 || date.month>12)
			return false;
		if (date.month == 2) {
			if (leapyear(date.year)) {
				if (date.day > 29)
					return false;
			}
			else
			{
				if (date.day > 28)
					return false;
			}
		}
		short daysinmonth = numberOfDaysInAMonth(date.month, date.year);
		if (date.day > daysinmonth) {
			return false;
		}
		return true;
	}
	bool isvalide() {
		return isvalide(*this);
	}
	static bool IsDate1BeforDate2(clsDate date1, clsDate date2) {
		return (date1.year < date2.year ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true :(date1.month==date2.month?date1.day<date2.day : false)):false);
	}
	bool IsDateBeforDate2(clsDate date) {
		return date.IsDate1BeforDate2(*this, date);
	}
	static string DateTostring(clsDate date) {
		return (to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year));
	}
	string DateTostring() {
		return DateTostring(*this);
	}
	static clsDate GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		short day, month, year;
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
		return clsDate(day, month, year);
	}
	static bool leapyear(short yearr) {
		return ((yearr % 4 == 0 && yearr % 100 != 0) || (yearr % 400 == 0));
	}
	bool leapyear() {
		return leapyear(_year);
	}
	static short numberOfDaysInAMonth(short m, short y) {
		if (m < 1 || m>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (m == 2) ? (leapyear(y) ? 29 : 28) : days[m - 1];
	}
	short numberOfDaysInAMonth() {
		return numberOfDaysInAMonth(_month, _year);
	}
	static short NumberOfDaysInYear(short y) {
		return leapyear(y) ? 365 : 364;
	}
	short  NumberOfDaysInYear() {
		return  NumberOfDaysInYear(_year);
	}
	static short NumberOfHoursInYear(short y) {
		return NumberOfDaysInYear(y) * 24;
	}
	short NumberOfHoursInYear() {
		return  NumberOfHoursInYear(_year);
	}
	static int NumberOfMinInYear(short y) {
		return  NumberOfHoursInYear(y) * 60;
	}
	int NumberOfMinInYear() {
		return  NumberOfHoursInYear(_year);
	}
	static int NumberOfSecInYear(short y) {
		return  NumberOfMinInYear(y)*60;
	}
	int NumberOfSecInYear() {
		return  NumberOfMinInYear(_year);
	}
	static short NumberOfHoursInMonth(short m, short y)
	{
		return numberOfDaysInAMonth(m, y) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return numberOfDaysInAMonth(_month, _year);
	}
	static int NumberOfMinInMonth(short m, short y) 
	{
		return NumberOfHoursInMonth(m, y) * 60;
	}
	int NumberOfMinInMonth() 
	{
		return NumberOfHoursInMonth(_month, _year);
	}
	static int NumberOfSecInMonth(short m, short y) 
	{
		return NumberOfMinInMonth(m, y) * 60;
	}
	int NumberOfSecInMonth() 
	{
		return NumberOfMinInMonth(_month, _year);
	}
	static short DayOfWeekOrder(short day, short month, short year) 
	{
		short a, m, y;
		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder() 
	{
		return DayOfWeekOrder(_day, _month, _year);
	}
	static string DayShortName(short DayOfWeekOrder)
	{
		string arr[] = { "Sun","Mon","Tue","Wed","THu","Fri","Sat" };
		return arr[DayOfWeekOrder];
	}
	string DayShortName() {
		return DayShortName(DayOfWeekOrder());
	}
	static string MonthShortName(short monthnumber) 
	{
		string months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul"
		,"Aug","Sep","Oct","Nov","Dec" };
		return months[monthnumber - 1];
	}
     string MonthShortName()
	 {
		return MonthShortName(_month);
	}
	static short DaysFromTheBeginingOfTheYear(short day, short month, short year)
	{
		short TotalDays = 0;
		for (int i = 1; i <= month - 1; i++)
		{
			TotalDays += numberOfDaysInAMonth(i, year);
		}
		TotalDays += day;
		return TotalDays;
	}
	short DaysFromTheBeginingOfTheYear() 
	{
		return DaysFromTheBeginingOfTheYear(_day, _month, _year);
	}
	static clsDate GetDateFromDayOrderInYear(short dateorderinyear, short year) {
		clsDate date;
		short RemaningDays = dateorderinyear;
		date.year = year;
		date.month = 1;
		short MonthDay = 0;
		while (true) {
			MonthDay = numberOfDaysInAMonth(date.month, year);
			if (RemaningDays > MonthDay)
			{
				RemaningDays -= MonthDay;
				date.month++;

			}
			else
			{
				date.day = RemaningDays;
				break;
			}
		}
		return date;
	}
	void AddDays(short days) {
		short RemaningDays = days + DaysFromTheBeginingOfTheYear(_day, _month, _year);
		short MonthDays = 0;
		_month = 1;
		while (true) {
			MonthDays = numberOfDaysInAMonth(_month, _year);
			if (RemaningDays > MonthDays)
			{
				RemaningDays -= MonthDays;
				_month++;
				if (_month > 12)
				{
					_month = 1;
					_year++;
				}

			}
			else
			{
				_day = RemaningDays;
				break;
			}

		}
	}
		static bool IsDate1EqualDate2(clsDate date1, clsDate date2) 
		{
			return(date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
		}
		bool IsDate1EqualDate2(clsDate date) {
			return IsDate1EqualDate2(*this, date);
		}
		static bool IsLastDayInMonth(clsDate date) 
		{
			return (date.day == numberOfDaysInAMonth(date.month, date.year));
		}
		bool IsLastDayInMonth()
		{
			return IsLastDayInMonth(*this);
		}
		static bool IsLastMonthInYear(short month) 
		{
			return (month == 12);
		}
		static clsDate AddOneDay(clsDate date) 
		{
			if (IsLastDayInMonth(date))
			{
				if (IsLastMonthInYear(date.month) {
					date.day = 1;
					date.month = 1;
					date.year++;
				}
				else {
					date.day = 1;
					date.month++;
				}
			}
			else {
				date.day++;
			}
			return date;
		}
		void AddOneDay() {
			*this = AddOneDay(*this);
		}
		static void SwapDates(clsDate& date1, clsDate& date2) {
			clsDate TempDATE;
			TempDATE = date1;
			date1 = date2;
			date2 = TempDATE;
		}
		static int GetDifferenceInDays(clsDate date1, clsDate date2, bool IncludeEndDay = false) {
			int Days = 0;
			short SwapFlagValue = 1;
			if (!IsDate1BeforDate2(date1, date2)) {
				SwapDates(date1, date2);
				SwapFlagValue = -1;

			}
			while (IsDate1BeforDate2(date1, date2)) {
				Days++;
				date1 = AddOneDay(date1);
			}
			return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;

		}
		int GetDifferenceInDays(clsDate date2, bool IncludeEndDay = false)
		{
			return  GetDifferenceInDays(*this, date2, IncludeEndDay);
		}
		static short CalculateMyAgeInDays(clsDate DateOfBirth) {
			return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
		}
		static clsDate IncreaseDateByOneWeek(clsDate & date) {
			for (int i = 0; i < 7; i++)
			{
				date = AddOneDay(date);
			}
			return date;
		}
		void IncreaseDateByOneWeek()
		{
			IncreaseDateByOneWeek(*this);
		}
		clsDate IncreaseDateByXWeek(short weeks, clsDate & date)
		{
			for (int i = 0; i < weeks; i++)
			{
				date = IncreaseDateByOneWeek(date);
			}return date;
		}
		void IncreaseDateByXWeek(short w)
		{
			IncreaseDateByXWeek(w, *this);
		}
		clsDate IncreaseDateByOneMonth(clsDate & date)
		{
			if (date.month == 12) {
				date.month = 1;
				date.year++;
			}
			else
			{
				date.month++;
			}
			short NumberOfDaysInCurrentMonth = numberOfDaysInAMonth(date.month, date.year);
			if (date.day > NumberOfDaysInCurrentMonth) {
				date.day = NumberOfDaysInCurrentMonth;
			}
			return date;
		}
		void IncreaseDateByOneMonth() {
			IncreaseDateByOneMonth(*this);
		}
		clsDate IncreaseDateByXDay(short Days, clsDate & date) 
		{
			for (int i = 0; i < Days; i++)
			{
				date = AddOneDay(date);
			}
			return date;
		}
		void IncreaseDateByXDay(short day) 
		{
			IncreaseDateByXDay(day, *this);
		}
		clsDate IncreaseDateByXMonth(short Month, clsDate & date) {
			for (int i = 0; i < Month; i++)
			{
				date = IncreaseDateByOneMonth(date);
			}
			return date;
		}
		void IncreaseDateByXMonth(short m)
		{
			IncreaseDateByXMonth(m, *this);
		}
		static clsDate IncreaseDateByOneYear(clsDate & date)
		{
			date.year++;
			return date;
		}
		void IncreaseDateByOneYear() {
			IncreaseDateByOneYear(*this);
		}
		static clsDate IncreaseDateByXYear(short y, clsDate & date) {
			date.year += y;
			return date;
		}
		void IncreaseDateByXYear(short y) {
			IncreaseDateByXYear(y);
		}
		clsDate  IncreaseDateByOneDecade(clsDate & date) {
			date.year += 10;
			return date;
		}
		void IncreaseDateByOneDecade() {
			IncreaseDateByOneDecade(*this);
		}
		clsDate IncreaseDateByXDecade(short D, clsDate & date) {
			date.year += D * 10;
			return date;
		}
		void IncreaseDateByXDecade(short D) {
			IncreaseDateByXDecade(D, *this);
		}
		clsDate  IncreaseDateByOneCentury(clsDate & date) {
			date.year += 100;
			return date;
		}
		void IncreaseDateByOneCentury() {
			IncreaseDateByOneCentury(*this);
		}
		clsDate  IncreaseDateByOneMillennium(clsDate & date) {
			date.year += 1000;
			return date;
		}
		void IncreaseDateByOneMillennium() {
			IncreaseDateByOneMillennium(*this);
		}
		static clsDate DecreaseDateByOneDay(clsDate date) {
			if (date.day == 1) {
				if (date.month == 1) {
					date.month = 12;
					date.day = 31;
					date.year--;
				}
				else {
					date.month--;
					date.day = numberOfDaysInAMonth(date.month, date.year);
				}
			}
			else
				date.day--;
			return date;
		}
		void DecreaseDateByOneDay() {
			DecreaseDateByOneDay(*this);
		}
		static clsDate DecreaseDateByOneWeek(clsDate & date) {
			for (int i = 0; i < 7; i++)
			{
				date = DecreaseDateByOneDay(date);
			}
			return date;
		}
		void DecreaseDateByOneWeek() {
			DecreaseDateByOneWeek(*this);
		}
		static clsDate DecreaseDateByXWeek(short w, clsDate & date) {
			for (int i = 0; i < w; i++)
			{
				date = DecreaseDateByOneWeek(date);
			}
			return date;
		}
		void DecreaseDateByXWeek(short w) {
			DecreaseDateByXWeek(w, *this);
		}
		static clsDate DecreaseDateByOneMonth(clsDate & date) {
			if (date.month == 1) {
				date.month = 12;
				date.year--;
			}
			else
				date.month--;
			short NumberOfDayesInCurrentMonth = numberOfDaysInAMonth(date.month, date.year);
			if (date.day > NumberOfDayesInCurrentMonth) {
				date.day = NumberOfDayesInCurrentMonth;
			}
			return date;
		}
		void DecreaseDateByOneMonth() {
			DecreaseDateByOneMonth(*this);
		}
		static clsDate DecreaseDateByXDays(short Days, clsDate & date) {
			for (int i = 0; i < Days; i++)
			{
				date = DecreaseDateByOneDay(date);
			}
			return date;
		}
		void DecreaseDateByXDays(short D) {
			DecreaseDateByXDays(D, *this);
		}
		static clsDate DecreaseDateByXMonth(short M, clsDate & date) {
			for (int i = 0; i < M; i++)
			{
				date = DecreaseDateByOneMonth(date);
			}
			return date;
		}
		void DecreaseDateByXMonth(short m) {
			DecreaseDateByXMonth(m, *this);
		}
		static clsDate DecreaseDateByOneYear(clsDate & date) {
			date.year--;
			return date;
		}
		void DecreaseDateByOneYear() {
			DecreaseDateByOneYear(*this);
		}
		static clsDate DecreaseDateByXYear(short Y, clsDate & date) {
			date.year -= Y;
			return date;
		}
		void DecreaseDateByXYear(short y) {
			DecreaseDateByXYear(y, *this);
		}
		static clsDate DecreaseDateByOneDecade(clsDate & date) {
			date.year -= 10;
			return date;
		}
		void DecreaseDateByOneDecade() {
			DecreaseDateByOneDecade(*this);
		}
		static clsDate DecreaseDateByXDecade(short d, clsDate & date) {
			date.year -= d * 10;
			return date;
		}
		void DecreaseDateByXDecade(short d) {
			DecreaseDateByXDecade(d, *this);
		}
		static clsDate DecreaseDateByOneCentury(clsDate & date) {
			date.year -= 100;
			return date;
		}
		void DecreaseDateByOneCentury() {
			DecreaseDateByOneCentury(*this);
		}
		static clsDate DecreaseDateByOneMillennium(clsDate & date) {
			date.year -= 1000;
			return date;
		}
		void DecreaseDateByOneMillennium() {
			DecreaseDateByOneMillennium(*this);
		}
		static short IsEndOfWeek(clsDate date) {
			return DayOfWeekOrder(date.day, date.month, date.year) == 6;
		}
		short  IsEndOfWeek() {
			return IsEndOfWeek(*this);
		}
		static bool IsWeekEnd(clsDate date) {
			short DayIndex = DayOfWeekOrder(date.day, date.month, date.year);
			return (DayIndex == 5 || DayIndex == 6);
		}
		bool IsWeekEnd() {
			return IsWeekEnd(*this);
		}
		static bool IsBusinessDay(clsDate date) {
			return !IsWeekEnd(date);
		}
		bool IsBusinessDay() {
			return IsBusinessDay(*this);
		}
		static short DaysUntilTheEndOfWeek(clsDate date) {
			return 6 - (DayOfWeekOrder(date.day, date.month, date.year));
		}
		short DaysUntilTheEndOfWeek() {
			return  DaysUntilTheEndOfWeek(*this);
		}
		static short DaysUntilTheEndOfMonth(clsDate date) {
			clsDate days;
			days.day = numberOfDaysInAMonth(date.month, date.year);
			days.month = date.month;
			days.year = date.year;
			return GetDifferenceInDays(date, days, true);
		}
		short DaysUntilTheEndOfMonth() {
			return DaysUntilTheEndOfMonth(*this);
		}
		static short DaysUntilTheEndOfYear(clsDate date) {
			clsDate EndOfYearDate;
			EndOfYearDate.day = 31;
			EndOfYearDate.month = 12;
			EndOfYearDate.year = date.year;
			return GetDifferenceInDays(date, EndOfYearDate, true);
		}
		short DaysUntilTheEndOfYear() {
			return DaysUntilTheEndOfYear(*this);
		}
		static short CalculateBusinessDays(clsDate datefrom, clsDate dateto)
		{
			short dayWork = 0;
			while (IsDate1BeforDate2(datefrom, dateto)) {
				if (IsBusinessDay(datefrom)) {
					dayWork++;
				}
				datefrom = AddOneDay(datefrom);
			}
			return dayWork;
		}
		static short CalculateVacationDays(clsDate datefrom, clsDate dateto)
		{
		
			return CalculateBusinessDays(datefrom, dateto);
		}
		static clsDate CalculateVacationReturnDate(clsDate datefrom, short VacationDays)
		{
			short WeekEndCounter = 0;
			for (short i = 0; i < VacationDays; i++)
			{
				if (IsWeekEnd(datefrom)) {
					WeekEndCounter++;
				}
				datefrom = AddOneDay(datefrom);
			}
			for (short i = 0; i < WeekEndCounter; i++)
			{
				datefrom = AddOneDay(datefrom);
			}

			return datefrom;
		}
		static bool IsDate1AfterDate2(clsDate date1, clsDate date2) {
			return (!IsDate1BeforDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
		}
		bool IsDate1AfterDate2(clsDate date2) {
			return IsDate1AfterDate2(*this, date2);
		}
		enum enDateCompare { Befor = -1, Equal = 0, After = 1 };
		static enDateCompare CompareDates(clsDate date1, clsDate date2) 
		{
			if (IsDate1BeforDate2(date1, date2)) {
				return enDateCompare::Befor;
			}
			if (IsDate1EqualDate2(date1, date2)) {
				return enDateCompare::Equal;
			}
			return enDateCompare::After;
		}
		enDateCompare CompareDates(clsDate date2) {
			return CompareDates(*this, date2);
		}

     };

