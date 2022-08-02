#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

char* bin = new char[9];

int strlen(char* s) {
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++)
		count++;
	return count;
}
int* stoa(char *str) {

	int *ascii = new int[strlen(str)];

	for (int i = 0; str[i] != '\0'; i++) {
		ascii[i] = (int) str[i];
	}
	return ascii;
}
char* itob(int x) {

	int count = 128;

	char w = '0';
	for (int i = 0; i < 8; i++) {
		if (count <= x) {
			x -= count;
			w = '1';
		} else
			w = '0';
		bin[i] = w;
		count /= 2;
	}
	bin[8] = '\0';
	return bin;

}

void store(char *s) {
	ofstream file;
	file.open("BinaryData.txt", ios::app);
	int *x = stoa(s);
	for (int i = 0; i < strlen(s); i++) {
		file << (itob(x[i])) << " ";

	}
	delete[] x;
	delete[] s;
	file << endl;
	file.close();

}
char* stoc(string line) {
	char *x = new char[line.length()];
	for (int i = 0; i < line.length(); i++) {
		x[i] = line[i];
	}
	return x;
}

string line;
int length(const string& x) {
	int i = 0;
	for (; x[i] != '\0'; i++)
		;
	return i;
}
void split(char token, string *& obj, int & ntokens) {

	ntokens = 0;
	int len = length(line);
	for (int i = 0; i < len; i++) {
		if (line[i] == token || line[i + 1] == '\0')
			ntokens++;
	}
	obj = new string[ntokens];

	int x = 0;
	for (int i = 0, z = 0; i < ntokens; i++) {
		for (; line[x] != token && line[x] != '\0'; x++, z++) {
			obj[i] += line[x];
		}
		x++;
		obj[i][8] = '\0';
	}
}
void display(string x) {
	cout << x << endl;
}
int StoI(string s) {

	int integer = 0;
	int i = 0;
	int add = 1;
	bool check = true;

	for (; check == true; i++) {
		if (((int) s[i] < 48 || (int) s[i] > 57 || s[i] == '\0') && s[i] != ' ')
			check = false;
	}
	i--;

	for (; i >= 0; i--) {
		if ((int) s[i] > 47 && (int) s[i] < 58) {
			integer += ((int) s[i] - 48) * add;
			add *= 10;
		}
	}
	return integer;
}
int BtoA(int x) {
	int y, z = 10, w = 1;
	int total = 0;
	int mid = 0;
	int exponent = 0;
	int count;
	count = x;
	while (count / w >= 1) {
		y = x % z;
		y = y / w;
		mid = (y * pow(2, exponent));
		total += mid;
		z = z * 10;
		w = w * 10;
		exponent++;
	}
	x = 0;
	return total;
}

void Convert() {
	ifstream file1;
	ofstream file2;
	file1.open("BinaryData.txt");
	file2.open("ConvertedData.txt");

	string *x;
	int n = 0;
	if (file1.is_open() && file2.is_open()) {

		while (getline(file1, line)) {
			split(' ', x, n);
			for (int i = 0; i < n; i++) {
				file2 << (char) BtoA(StoI(x[i]));
			}
			file2 << endl;
		}
	} else
		cout << "File not found." << endl;

}

void DeConvert() {
	ifstream file2;
	string line2;
	cout << "Enter File Name/Location:";
	string x;
	cin >> x;
	file2.open(x.c_str());
	if (file2.is_open()) {
		while (getline(file2, line2)) {
			store(stoc(line2));

		}
		cout<<"Done!\n";
	} else 
		cout << "File not found.";
	
}
char *s = new char[8192];

void display(int *ascii) {
	for (int i = 0; i < strlen(s); i++) {
		cout << ascii[i] << " ";
	}
	cout << endl;
}
void display(char *s) {
	for (int i = 0; s[i] != '\0'; i++) {
		cout << s[i];
	}
	cout << " ";
}
void store() {
	ofstream file;
	file.open("BinaryData.txt", ios::app);

	for (int i = 0; i < strlen(s); i++) {
		file << (itob(stoa(s)[i])) << " ";

	}
	file << endl;
	file.close();

}

int main() {
	int num;
	do{
	cout << "\n1. Covert File To Binary.\n";
	cout << "2. Convert Binary to File.\n";
	cout << "3. Convert String to Binary.\n";
	cout<<"4. Exit.\n";

	cin >> num;
	switch (num) {
	case 1:
		DeConvert();
		break;
	case 2:
		Convert();
		cout<<"Done!\n";
		break;
	case 3:
		cin.ignore();
		for (int i = 0;; i++) {
			cout << "Enter line " << i + 1 << ":";
			cin.getline(s, 4096);
			store();
		}
	}
	} while (num!=4);

	return 0;
}

