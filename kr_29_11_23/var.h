#pragma once
#include <iostream>
#include <string>
using namespace std;
class var
{
private:
	int _int;
	double _double;
	string _string;
	short what_is_it;// 1 - int; 2 - double; 3 - string
public:
	//void set_var(const int _int);
	void set_var(const double _double);
	void set_var(const string _string);
	void set_var(const int _int);

	void get_var()const;//

	var() : _int{}, _double{}, _string{}, what_is_it{} {}
	explicit var(int _int) : _int{ _int }, _double{}, _string{}, what_is_it{1} {
	}
	explicit var(double _double) : _double{_double}, _int{}, _string{}, what_is_it{ 2 } {}
	explicit var(string _string) : _int{}, _double{}, _string{_string}, what_is_it{ 3 } {}
	var(const var& _var) :what_is_it{ _var.what_is_it }, _int{}, _double{}, _string{} {
		switch (what_is_it)
		{
		case 1:
			_int  = _var._int; 

			break;
		case 2:
			_double  = _var._double; 

			break;
		case 3:
			_string = _var._string;

			break;
		default:
			break;
		}
	}
	~var() {};


	bool operator==(const var& other) const;
	bool operator!=(const var& other) const;

	const var& operator=(const var& _var);
	const var& operator=(const int _int);
	const var& operator=(const double _double);
	const var& operator=(const string _string);

	friend const var operator+(const var& _var1, const var& _var2);
	friend const var operator-(const var& _var1, const var& _var2);
	friend const var operator*(const var& _var1, const var& _var2);

	friend const var operator/(const var& _var1, const var& _var2);
	bool operator>(const var& other)const;
	bool operator<(const var& other)const;
	bool operator<=(const var& other)const;
	bool operator>=(const var& other)const;

	const var& operator +=(const var& _var);
	const var& operator -=(const var& _var);

	var(int _int, double _double, const string& _string, short what_is_it) : _int(_int), _double(_double), _string(_string), what_is_it(what_is_it) {};// тут делегирование для удобства при работе с операторамаи
	var(int _int, short what_is_it) : var(_int, {}, {}, what_is_it) {};
	var(double _double, short what_is_it) : var({}, _double, {}, what_is_it) {};
	var(string _string, short what_is_it) : var({}, {}, _string, what_is_it) {};
};
	string different_str(const string& str1, const string& str2);
	string divide_str(const string& str1, const string& str2);
	string muiple_str(const string& str1, const string& str2);
	string muiple_str_int(const string& str1, const unsigned int& str2);
	string muiple_str_double(const string& str1, const  double& str2);

