#include "var.h"

void var::set_var(const int _int)
{
	this->_int = _int;
	this->what_is_it = 1;
	this->_string.clear();
	
}
void var::get_var() const
{
	switch (this->what_is_it)
	{
	case 1:
		cout << this->_int << endl;
		break;
	case 2:
		cout << this->_double << endl;
		break;
	case 3:
		cout << this->_string << endl;
		break;
	default:
		break;
	}
}
void var::set_var(const double _double)
{	
	var::_double = _double;	
	this->what_is_it = 2;
}

void var::set_var(const string _string)
{
	var::_string = _string;
	this->what_is_it = 3;
}


string different_str(const string& str1, const string& str2)
{
	string different_str;
	for (unsigned int i = 0; i < str1.size(); i++) {
		for (unsigned int j = 0; j < str2.size(); j++) {
			if (str1[i] != str2[j]) { different_str.push_back(str1[i]); }
		}
	}
	return different_str;
}

string divide_str(const string& str1, const string& str2)
{
	string different_str;
	bool temp =1;
	for (unsigned int i = 0; i < str1.size(); i++) {
		temp = 1;
		for (unsigned int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) {
				temp *=1;
			}
			else
			{
				temp *= 1;
			}
		}
		if (temp) { different_str.push_back(str1[i]); }
	}
	return different_str;
}

string muiple_str(const string& str1, const string& str2)
{
	string different_str;
	for (unsigned int i = 0; i < str1.size(); i++) {
		for (unsigned int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) { different_str.push_back(str1[i]); }
		}
	}
	return different_str;
}

string muiple_str_int(const string& str1, const unsigned int& str2)
{
	string temp  = str1;
	for (unsigned int i = 0; i < str2; i++) {
		temp += temp;
	}
	return temp;
}

string muiple_str_double(const string& str1, const double& str2)
{
	string temp = str1;
	for (unsigned int i = 0; i < str2; i++) {
		temp += temp;
	}
	return temp;
}

bool var::operator==(const var& other) const
{
	return _int == other._int && _double == other._double && _string == other._string && what_is_it == other.what_is_it;
}

bool var::operator!=(const var& other) const
{
	return _int != other._int && _double != other._double && _string != other._string && what_is_it != other.what_is_it;
}

const var& var::operator=(const var& _var)
{
	if (_var.what_is_it == 1) {
		this->what_is_it = _var.what_is_it;
		this->_int = _var._int;
		return *this;
	}
	else if (_var.what_is_it == 2)
	{
		this->what_is_it = _var.what_is_it;
		this->_double = _var._double;
		return *this;
	}
	else if (_var.what_is_it == 3)
	{
		this->what_is_it = _var.what_is_it;
		this->_string = _var._string;
		return *this;
	}
}

const var& var::operator=(const int _int)
{
	this->set_var(_int);
	return *this;
}

const var& var::operator=(const double _double)
{
	this->set_var(_double);
	return *this;
}

const var& var::operator=(const string _string)
{
	this->set_var(_string);
	return *this;
}

bool var::operator>(const var& other) const
{
	if (this->what_is_it != other.what_is_it) {
		return 0;
	}
	else
	{
		switch (other.what_is_it)
		{
		case 1:
			return this->_int > other._int;
		case 2:
			return this->_double > other._double;
		case 3:
			return this->_string.size() > other._string.size();
		default:
			break;
		}
	}
}

bool var::operator<(const var& other) const
{
	if (this->what_is_it != other.what_is_it) {
		return 0;
	}
	else
	{
		switch (other.what_is_it)
		{
		case 1:
			return this->_int < other._int;
		case 2:
			return this->_double < other._double;
		case 3:
			return this->_string.size() < other._string.size();
		default:
			break;
		}
	}
}

bool var::operator<=(const var& other) const
{
	if (this->what_is_it != other.what_is_it) {
		return 0;
	}
	else
	{
		switch (other.what_is_it)
		{
		case 1:
			return this->_int <= other._int;
		case 2:
			return this->_double <= other._double;
		case 3:
			return this->_string.size() <= other._string.size();
		default:
			break;
		}
	}
}

bool var::operator>=(const var& other) const
{
	if (this->what_is_it != other.what_is_it) {
		return 0;
	}
	else
	{
		switch (other.what_is_it)
		{
		case 1:
			return this->_int >= other._int;
		case 2:
			return this->_double >= other._double;
		case 3:
			return this->_string.size() >= other._string.size();
		default:
			break;
		}
	}
}

const var& var::operator+=(const var& _var)
{
	if (this->what_is_it == 1) {
		switch (_var.what_is_it)
		{
		case 1:
			this->_int += _var._int;
			return *this;
			break;
		case 2:
			this->_int += _var._double;
			return *this;
			break;
		case 3:
			this->_int += stoi(_var._string);
			return *this;
		default:
			break;

		}
	}
	else if (this->what_is_it == 2)
	{
		switch (_var.what_is_it)
		{
		case 1:
			this->_double += _var._int;
			return *this;
			break;
		case 2:
			this->_double += _var._double;
			return *this;
			break;
		case 3:
			this->_double += stod(_var._string);
			return *this;
		default:
			break;

		}

	}
	else if (this->what_is_it == 3)
	{
		switch (_var.what_is_it)
		{
		case 1:
			this->_string += to_string(_var._int);
			return *this;
		case 2:
			this->_string += to_string(_var._double);
			return *this;
		case 3:
			this->_string += _var._string;
			return *this;

		default:
			break;

		}
	}
}

const var& var::operator-=(const var& _var)
{
	if (this->what_is_it == 1) {
		switch (_var.what_is_it)
		{
		case 1:
			this->_int -= _var._int;
			return *this;
			break;
		case 2:
			this->_int -= _var._double;
			return *this;
			break;
		case 3:
			this->_int -= stoi(_var._string);
			return *this;
		default:
			break;

		}
	}
	else if (this->what_is_it == 2)
	{
		switch (_var.what_is_it)
		{
		case 1:
			this->_double -= _var._int;
			return *this;
			break;
		case 2:
			this->_double -= _var._double;
			return *this;
			break;
		case 3:
			this->_double -= stod(_var._string);
			return *this;
		default:
			break;

		}

	}
	else if (this->what_is_it == 3)
	{
		switch (_var.what_is_it)
		{
		case 1:
			return *this;
		case 2:
			return *this;
		case 3:
			this->_string =  _var._string;
			return *this;

		default:
			break;

		}
	}
}

const var operator+(const var& _var1, const var& _var2)
{
	if (_var1.what_is_it == 1) {
		switch (_var2.what_is_it)
		{
		case 1:
			return var(int(_var1._int + _var2._int), 1);
			break;
		case 2:
			return var(int(_var1._int + _var2._double), 1);
			break;
		case 3:
			try {
				int temp = stoi(_var2._string);
				return var(int(_var1._int + temp), 1);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad INT string\n";
				return var(int(_var1._int), 1);
			}
		default:
			break;
		}
	}
	else if (_var1.what_is_it == 2)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(double(_var1._double + _var2._int), 2);
		case 2:
			return var(double(_var1._double + _var2._double), 2);
		case 3:
			try {
				double temp = stod(_var2._string);
				return var(double(_var1._double + temp), 2);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad DOUBLE string\n";
				return var(double(_var1._double), 2);
			}
		default:
			break;
		}

	}
	else if (_var1.what_is_it == 3)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(_var1._string + to_string(_var2._int), 3);
		case 2:
			return var(_var1._string + to_string(_var2._double), 3);
		case 3:
			return var(_var1._string + _var2._string, 3);

		default:
			break;

		}
	}
}

const var operator-(const var& _var1, const var& _var2)
{
	if (_var1.what_is_it == 1) {
		switch (_var2.what_is_it)
		{
		case 1:
			return var(int(_var1._int - _var2._int), 1);
			break;
		case 2:
			return var(int(_var1._int - _var2._double), 1);
			break;
		case 3:
			try {
				int temp = stoi(_var2._string);
				return var(int(_var1._int - temp), 1);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad INT string\n";
				return var(int(_var1._int), 1);
			}
			break;
		default:
			break;
		}
	}
	else if (_var1.what_is_it == 2)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(double(_var1._double - _var2._int), 2);
		case 2:
			return var(double(_var1._double - _var2._double), 2);
		case 3:
			try {
				double temp = stod(_var2._string);
				return var(double(_var1._double - temp), 2);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad DOUBLE string\n";
				return var(double(_var1._double), 2);
			}
		default:
			break;
		}

	}
	else if (_var1.what_is_it == 3)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(_var1._string, 3);
		case 2:
			return var(_var1._string, 3);
		case 3:
			return var(different_str(_var1._string, (_var2._string)), 3);

		default:
			break;

		}
	}
}

const var operator*(const var& _var1, const var& _var2)
{
	if (_var1.what_is_it == 1) {
		switch (_var2.what_is_it)
		{
		case 1:
			return var(int(_var1._int * _var2._int), 1);
			break;
		case 2:
			return var(int(_var1._int * _var2._double), 1);
			break;
		case 3:
			try {
				int temp = stoi(_var2._string);
				return var(int(_var1._int * temp), 1);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad INT string\n";
				return var(int(_var1._int), 1);
			}
			break;
		default:
			break;
		}
	}
	else if (_var1.what_is_it == 2)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(double(_var1._double * _var2._int), 2);
		case 2:
			return var(double(_var1._double * _var2._double), 2);
		case 3:
			try {
				double temp = stod(_var2._string);
				return var(double(_var1._double * temp), 2);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad DOUBLE string\n";
				return var(double(_var1._double), 2);
			}
		default:
			break;
		}

	}
	else if (_var1.what_is_it == 3)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(muiple_str_int(_var1._string, _var2._int), 3);
		case 2:
			return var(muiple_str_double(_var1._string, _var2._double),  3);
		case 3:
			return var(muiple_str(_var1._string, (_var2._string)), 3);

		default:
			break;

		}
	}
}

const var operator/(const var& _var1, const var& _var2)
{
	if (_var1.what_is_it == 1) {
		switch (_var2.what_is_it)
		{
		case 1:
			return var(int(_var1._int / _var2._int), 1);
			break;
		case 2:
			return var(int(_var1._int / _var2._double), 1);
			break;
		case 3:
			try {
				int temp = stoi(_var2._string);
				return var(int(_var1._int / temp), 1);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad INT string\n";
				return var(int(_var1._int), 1);
			}
			break;
		default:
			break;
		}
	}
	else if (_var1.what_is_it == 2)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(double(_var1._double / _var2._int), 2);
		case 2:
			return var(double(_var1._double / _var2._double), 2);
		case 3:
			try {
				double temp = stod(_var2._string);
				return var(double(_var1._double / temp), 2);
			}
			catch (invalid_argument e) {
				cout << "\nYou have a bad DOUBLE string\n";
				return var(double(_var1._double), 2);
			}
		default:
			break;
		}

	}
	else if (_var1.what_is_it == 3)
	{
		switch (_var2.what_is_it)
		{
		case 1:
			return var(_var1._string, 3);
		case 2:
			return var(_var1._string, 3);
		case 3:
			return var(divide_str(_var1._string, (_var2._string)), 3);

		default:
			break;

		}
	}
}
