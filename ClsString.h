#pragma once
#include<iostream>
#include<vector>
using namespace std;
class ClsString
{
private:
	string _value;
public:
	ClsString() {
		_value = "";
	}
	ClsString(string Value) {
		_value = Value;
	}
	void SetValue(string Value) {
		_value = Value;
	}
	string GetValue() {
		return _value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;
	static short Length(string s1) {
		return s1.length();
	}
	short Length() {
		return _value.length();
	}
	static short CountWords(string s1) {
		short count = 0;
		string delim = " ";
		short pos = 0;
		string sword;
		while (pos = s1.find(delim) != std::string::npos) {
			sword = s1.substr(0, pos);
			if (sword != " ") {
				count++;
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != " ") {
			count++;
		}
		return count;
	}
	short CountWords() {
		return CountWords(_value);
	}
	static string UpperFirstLetterOfEachWord(string s1) {
		bool IsFirstLetter = true;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && IsFirstLetter) {
				s1[i] = toupper(s1[i]);
			}
			IsFirstLetter = (s1[i] == ' ' ? true : false);
		}
		return s1;
	}
	void UpperFirstLetterOfEachWord() {
		_value=UpperFirstLetterOfEachWord(_value);
	}
	static string LowerFirstLetterOfEachWord(string s1) {
		bool IsFirstLetter = true;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && IsFirstLetter) {
				s1[i] = tolower(s1[i]);
			}
			IsFirstLetter = (s1[i] == ' ' ? true : false);
		}
		return s1;
	}
	void LowerFirstLetterOfEachWord() {
		_value = LowerFirstLetterOfEachWord(_value);
	}
	static string UpperAllString(string s1) {
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = toupper(s1[i]);
		}
		return s1;
	}
	void UpperAllString() {
		_value = UpperAllString(_value);
	}
	static string LowerAllString(string s1) {
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = tolower(s1[i]);
		}
		return s1;
	}
	void LowerAllString() {
		_value = LowerAllString(_value);
	}
	static char InvertLetterCase(char ch1) {
		return isupper(ch1) ? tolower(ch1) : toupper(ch1);
	}
	static string InvertAllLetterCase(string s1) {
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = InvertLetterCase(s1[i]);
		}return s1;
	}
	void InvertAllLetterCase() {
		_value = InvertAllLetterCase(_value);
	}
	enum enWhattoCount{SmallLeter=0,CapitalLetter=1,All=2};
	static short CountLetters(string s1, enWhattoCount WhatToCount = enWhattoCount::All) {
		if (WhatToCount == enWhattoCount::All) {
			return s1.length();
		}
		short count = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (WhatToCount == enWhattoCount::SmallLeter && islower(s1[i]))
				count++;
			if (WhatToCount == enWhattoCount::CapitalLetter && isupper(s1[i]))
				count++;
		}
		return count;
	}
	static short CountCapitalLetter(string s1) {
		short count = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (isupper(s1[i]))
				count++;
		}
		return count;
	}
	short CountCapitalLetter() {
		return CountCapitalLetter(_value);
	}
	static short CountSmallLetter(string s1) {
		short count = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (islower(s1[i]))
				count++;
		}
		return count;
	}
	short CountSmallLetter() {
		return CountSmallLetter(_value);
	}
	static short CountSpecificLetter(string s1, char ch, bool MatchL = true)
	{
		short count = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (MatchL) {
				if(s1[i]==ch)
				count++;
			}
			else
			{
				if (tolower(s1[i]) == islower(ch))
					count++;
			}

		}
		return count;
	}
	short CountSpecificLetter(char ch, bool MatchL = true) {
		return CountSpecificLetter(_value, ch, MatchL);
	}
	static bool IsVowel(char ch) {
		ch = tolower(ch);
		return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
	}
	static short CountVowels(string s1) {
		short count = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] == IsVowel(s1[i]);
			count++;
		}
		return count;
	}
	short CountVowels() {
		return CountVowels(_value);
	}
	static vector<string> split(string s1, string delim) {
		vector<string> vstring;
		short pos = 0;
		string sword;
		while (pos = s1.find(delim) != std::string::npos) {
			sword = s1.substr(0, pos);
			if (sword != " ") {
				vstring.push_back(sword);
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != " ") {
			vstring.push_back(s1);
		}
		return vstring;
	}
	vector<string> split(string delim) {
		return split(_value, delim);
	}
	static string TrimLeft(string s1) {
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ')
				return s1.substr(i, s1.length() - i);
		}
		return " ";
	}
	void TrimLeft() {
		_value = TrimLeft(_value);
	}
	static string TrimRight(string s1) {
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ')
				return s1.substr(0, i + 1);
		}
		return " ";
	}
	void TrimRight() {
		_value = TrimRight(_value);
	}
	static string Trim(string s1) {
		return TrimLeft(TrimRight(s1));
	}
	void Trim() {
		_value = Trim(_value);
	}
	static string JoinString(vector<string> vstring, string delim) {
		string s1 = " ";
		for (string& s : vstring) {
			s1 = s1 + s + delim;
		}
		return s1.substr(0, s1.length() - delim.length());
	}
	static string ReversWordsInString(string s1) {
		vector<string> vstring;
		string s2 = " ";
		vstring = split(s1, " ");
		vector<string>::iterator iter = vstring.end();
		while (iter != vstring.begin()) {
			iter--;
			s2 += *iter + " ";
		}
		s2 = s2.substr(0, s2.length() - 1);
		return s2;

	}
	void ReversWordsInString() {
		_value = ReversWordsInString(_value);
	}
	static string ReplaceWord(string s1, string StringToReplace, string sReplaceTo, bool MatchCase = true) {
		vector<string> vstring=split(s1," ");
		for (string& s : vstring) {
			if (MatchCase) {
				if (s == StringToReplace) {
					s = sReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
					s = sReplaceTo;
			}
		}
		return JoinString(vstring, " ");

	}
	string ReplaceWord(string StringToReplace, string sReplaceTo, bool MatchCase = true) {
		return ReplaceWord(_value, StringToReplace, sReplaceTo, MatchCase);
	}
	static string RemovePunctuations(string s1) {
		string s2 = " ";
		for (int i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
				s2 += s1[i];
		}
		return s2;
	}
	void RemovePunctuations() {
		_value = RemovePunctuations(_value);
	}
};

