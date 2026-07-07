#include <iostream>
#include <string>
using namespace std;    

void task1()
{
	int n;
	string s;

	cout << "Enter the number of strings: ";
	cin >> n;
	cout << "Enter the strings: ";
	cin.ignore();
	getline(cin, s); 

	if (s.length() > n) {
		s.erase(0,s.length() - n);
	}
	else if( s.length() < n ) {
		s.insert(0, n - s.length(), '.');
	}

	cout << "Modified string: " << s << endl;

}

void task2(){
	int n1;
	string s1;

	int n2;
	string s2;

	cout << "enter first num" << endl;
	cin >> n1;
	cout << "enter sec num" << endl;
	cin >> n2;

	cout << "enter first string" << endl;
	cin >> s1;
	cout << "enter sec string" << endl;
	cin >> s2;


	string s = s1.substr(0, n1) + s2.substr(s2.length() - n2);

	cout << "result " << s << endl;


}

void task3() {
	
	char C;
	cout << "Enter a cha: " << endl;
	cin >> C;
	string s;
	cout << "Enter a string: " << endl;
	cin.ignore();
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == C) {
			s.insert(i, 1, C);
			i++;
		}
	}


	cout << "Modified string: " << s << endl;
}

void task4() {
	string s0, s;
	char C;

	cout << "Enter a string: " << endl;
	getline(cin, s);
	cout << "Enter a char: " << endl;
	cin >> C; 
	cin.ignore();
	cout << "Enter a string to insert: " << endl;
	getline(cin, s0);
	for (int i = static_cast<int>(s.length()) - 1; i >= 0; i--) {
		if (s[i] == C) {
			s.insert(i, s0);
		}
	}

	cout << "Modified string: " << s << endl;

	
}

void task5() {
	string s0, s;
	char C;

	cout << "Enter a string: " << endl;
	getline(cin, s);
	cout << "Enter a char: " << endl;
	cin >> C;
	cin.ignore();
	cout << "Enter a string to insert: " << endl;
	getline(cin, s0);
	for (int i = static_cast<int>(s.length()) - 1; i >= 0; i--) {
		if (s[i] == C) {
			s.insert(i + 1, s0);
		}
	}

	cout << "Modified string: " << s << endl;

}

void task6() {
	string s, s0;
	cout << "Enter a string: " << endl;
	getline(cin, s);
	cout << "word: " << endl;
	getline(cin, s0);

	if (s.find(s0) != string::npos) {
		cout << "true " << endl;
	}
	else {
		cout << "false " << endl;
	}

}

void task7() {

	string s, s0;
	cout << "Enter a string: " << endl;
	getline(cin, s);
	cout << "word: " << endl;
	getline(cin, s0);

	size_t pos = s.find(s0, 0);
	int count = 0;
	while (pos != string::npos) {
		count++;
		pos = s.find(s0, pos + s0.length());
	}
	cout << count << endl;
}

void task8() {
	string s1, s2;
	cout << "Enter a string: " << endl; 
	getline(cin, s1);
	cout << "Enter a substring: " << endl;
	cin >> s2;
	if (s1.find(s2) == -1) {
		cout << "Substring not found in the string." << endl;
	}
	else {
		int pos = s1.find(s2);
		s1.erase(pos, s2.length());
		cout << "Modified string: " << s1 << endl;
	}

}

void task9() {
	string s1, s2;
	cout << "Enter a string: " << endl;
	getline(cin, s1);
	cout << "Enter a substring: " << endl;
	cin >> s2;
	if (s1.find(s2) == -1) {
		cout << "Substring not found in the string." << endl;
	}
	else {
		while (s1.find(s2) != -1) {
			int pos = s1.find(s2);
			s1.erase(pos, s2.length());
		}
		cout << "Modified string: " << s1 << endl;
	}
}

void task10() {
	
	string s, s1, s2;	

	cout << "Enter a string: " << endl;
	getline(cin, s);
	cout << "enter a substring to replace: " << endl;
	getline(cin, s1);
	cout << "enter the replacement substring: " << endl;
	getline(cin, s2);

	int pos = s.find(s1);
	if (pos == -1) {
		cout << "Substring not found in the string." << endl;
	}
	else {
		s.replace(pos, s1.length(), s2);
		cout << "Modified string: " << s << endl;
	}

}

void task11() {
	string s, s1, s2;

	cout << "Enter a string: " << endl;
	getline(cin, s);
	cout << "enter a substring to replace: " << endl;
	getline(cin, s1);
	cout << "enter the replacement substring: " << endl;
	getline(cin, s2);

	int pos = s.find(s1);
	if (pos == -1) {
		cout << "Substring not found in the string." << endl;
	}
	else {
		while (s.find(s1) != -1) {
			int pos = s.find(s1);
			s.replace(pos, s1.length(), s2);
		}
		cout << "Modified string: " << s << endl;
	}
}

void task12() {
	string text;
	cout << "Enter a string for encryption: ";
	getline(cin, text);

	string encrypted = "";
	for (size_t i = 0; i < text.length(); i += 2) {
		encrypted += text[i];
	}

	int lastOdd = (text.length() % 2 == 0) ? text.length() - 1 : text.length() - 2;

	for (int i = lastOdd; i >= 1; i -= 2) {
		encrypted += text[i];
	}

	cout << "Encrypted string: " << encrypted << endl;

	
}

void task13() {
	string text;
	cout << "Enter a string for decryption: ";
	getline(cin, text);

	int mid = (text.length() + 1) / 2;
	string decrypted = "";

	for (int i = 0; i < mid; i++) {
		decrypted += text[i];
		if (text.length() - 1 - i >= mid) {
			decrypted += text[text.length() - 1 - i];
		}
	}

	cout << "Decrypted string: " << decrypted << endl;
}

int main()
{
	/*task1();*/

	/*task2();*/

	/*task3();*/

	/*task4();*/

	/*task5();*/

	/*task6();*/

	/*task7();*/

	/*task8();*/

	/*task9();*/

	/*task10();*/

	/*task11();*/

	/*task12();*/

	/*task13();*/

	return 0;
}


