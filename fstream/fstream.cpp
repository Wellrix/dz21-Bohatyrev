#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void task14(string S) {
    ofstream file(S);
    if (file.is_open()) {
        cout << "True" << endl;
        file.close();
    }
    else {
        cout << "False" << endl;
    }
}

void task15(string filename, int N) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) return;

    for (int i = 1; i <= N; i++) {
        int val = i * 2;
        file.write(reinterpret_cast<char*>(&val), sizeof(val));
    }
    file.close();
}

void task16(string SA, string SB, string SC, string SD) {
    ifstream fa(SA, ios::binary);
    ifstream fb(SB, ios::binary);
    ifstream fc(SC, ios::binary);
    ofstream fd(SD, ios::binary);

    if (!fa.is_open() || !fb.is_open() || !fc.is_open() || !fd.is_open()) return;

    int a, b, c;
    while (fa.read(reinterpret_cast<char*>(&a), sizeof(a))) {
        fb.read(reinterpret_cast<char*>(&b), sizeof(b));
        fc.read(reinterpret_cast<char*>(&c), sizeof(c));

        fd.write(reinterpret_cast<char*>(&a), sizeof(a));
        fd.write(reinterpret_cast<char*>(&b), sizeof(b));
        fd.write(reinterpret_cast<char*>(&c), sizeof(c));
    }

    fa.close();
    fb.close();
    fc.close();
    fd.close();
}

void task17(string inputTask, string daysFile, string monthsFile) {
    ifstream fin(inputTask);
    ofstream fdays(daysFile, ios::binary);
    ofstream fmonths(monthsFile, ios::binary);

    if (!fin.is_open() || !fdays.is_open() || !fmonths.is_open()) return;

    string date;
    while (fin >> date) {
        if (date.length() >= 5) {
            int day = stoi(date.substr(0, 2));
            int month = stoi(date.substr(3, 2));

            fdays.write(reinterpret_cast<char*>(&day), sizeof(day));
            fmonths.write(reinterpret_cast<char*>(&month), sizeof(month));
        }
    }

    fin.close();
    fdays.close();
    fmonths.close();
}

void task18(string inputTask, string outputTask) {
    ifstream fin(inputTask);
    ofstream fout(outputTask);

    if (!fin.is_open() || !fout.is_open()) return;

    string date;
    while (fin >> date) {
        if (date.length() >= 5) {
            string month = date.substr(3, 2);
            if (month == "06" || month == "07" || month == "08") {
                fout << date << endl;
            }
        }
    }

    fin.close();
    fout.close();
}

void task19(string f1_path, string f2_path, string g_path) {
    ifstream f2(f2_path);
    if (!f2.is_open()) return;
    string target, replacement;
    f2 >> target >> replacement;
    f2.close();

    ifstream f1(f1_path);
    ofstream g(g_path);
    if (!f1.is_open() || !g.is_open()) return;

    string word = "";
    char ch;
    while (f1.get(ch)) {
        if (isalnum(ch) || ch == '-' || (ch & 0x80)) {
            word += ch;
        }
        else {
            if (!word.empty()) {
                if (word == target) g << replacement;
                else g << word;
                word = "";
            }
            g << ch;
        }
    }
    if (!word.empty()) {
        if (word == target) g << replacement;
        else g << word;
    }

    f1.close();
    g.close();
}

void task20(string f_path, string g_path, int option) {
    ifstream f(f_path);
    ofstream g(g_path);
    if (!f.is_open() || !g.is_open()) return;

    string lastName, firstName, middleName;
    while (f >> lastName >> firstName >> middleName) {
        if (option == 1) {
            g << firstName << " " << middleName << " " << lastName << endl;
        }
        else if (option == 2) {
            string init = "";
            init += firstName[0];
            init += ".";
            init += middleName[0];
            init += ".";
            g << lastName << " " << init << endl;
        }
    }

    f.close();
    g.close();
}

int main() {
    string S = "test_file.txt";
    task14(S);

    int N = 7;
    task15("numbers.bin", N);

    task16("SA.bin", "SB.bin", "SC.bin", "SD.bin");

    task17("dates.txt", "days.bin", "months.bin");

    task18("dates.txt", "summer.txt");

    task19("f1.txt", "f2.txt", "g.txt");

    int option = 1;
    task20("f.txt", "g.txt", option);

    return 0;
}