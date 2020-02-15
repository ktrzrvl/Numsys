#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class NumConverter {
	int x;
	int flag;

	int CharToNum(char c);
	char NumToChar(int x);

public:
	NumConverter(string num, int sys);
	string Convert(int sys);
};

int NumConverter::CharToNum(char c) {
	if (c >= '0' && c <= '9'){
		return c - '0';
	}
	if (c >= 'a' && c <= 'z'){
		return c - 'a' + 10;
	}
	if (c >= 'A' && c <= 'Z'){
		return c - 'A' + 10;
	}
	return -1;
}

char NumConverter::NumToChar(int x) {
	if (x <= 9) {
		return x + '0';
	}
	return x + 'A' - 10;
}

NumConverter::NumConverter(string num, int sys) {
	x = 0;
	if (num[0] == '-') {
		flag = 1;
		for (int i = 1; i < num.length(); i++) {
		x = x * sys + CharToNum(num[i]);
		}
	}
	else {
		for (int i = 0; i < num.length(); i++) {
			x = x * sys + CharToNum(num[i]);
		}
	}
}

string NumConverter::Convert(int sys) {
	int x1 = x;	
	string number = "";
	while (x1 > 0) {
		int a = x1 % sys;
		number += NumToChar(a);
		x1 /= sys;
	}
	if (flag == 1) {
		number += '-';
		for (int i = 0, j = number.length() - 1; i < j; i++, j--) {
		char tmp = number[i];
		number[i] = number[j];
		number[j] = tmp;
		}
	}
	else {
		for (int i = 0, j = number.length() - 1; i < j; i++, j--) {
			char tmp = number[i];
			number[i] = number[j];
			number[j] = tmp;
		}
	}
	return number;
}


int main() {
	int syst, syst1;
	string numb;
	cout << "enter number and system" << endl;
	cin >> numb >> syst;
	NumConverter conv(numb, syst);
	cout << "enter system you want to convert to" << endl;
	cin >> syst1;
	cout << "convertered: " << conv.Convert(syst1) << endl;
}