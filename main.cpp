#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define size 47
using namespace std;

char record[size];

class Student {

private:
char id[10];
char name[20];
char age[3];
char gpa[4];
char level[10];

public:
void setdata();
void getdata();
void pack();
void unpack();
void insert();
void display();
void search(string key);
void update(string key);
void Delete(string key);
};

void Student::setdata(){
cout << "Enter ID: ";
cin >> id;

cout << "Enter Name: ";
cin >> name;

cout << "Enter Age: ";
cin >> age;
cout << "Enter GPA: ";
cin >> gpa;

cout << "Enter Level: ";
cin >> level;
}

void Student::getdata(){
cout << "ID: " << id << endl;
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
cout << "GPA: " << gpa << endl;
cout << "Level: " << level << endl;
cout << "----------------------------------------" << endl;
}

void Student::pack() {
string temp = string(id) + "|" + string(name) + "|" + string(age) + "|" + string(gpa) + "|" + string(level);
strncpy(record, temp.c_str(), size - 1);

}

void Student::unpack(){
string temp = record;
int pos;

pos = temp.find("|");
strcpy(id, temp.substr(0, pos).c_str());
temp = temp.substr(pos + 1);

pos = temp.find("|");
strcpy(name, temp.substr(0, pos).c_str());
temp = temp.substr(pos + 1);

pos = temp.find("|");
strcpy(age, temp.substr(0, pos).c_str());
temp = temp.substr(pos + 1);

pos = temp.find("|");
strcpy(gpa, temp.substr(0, pos).c_str());
temp = temp.substr(pos + 1);

strcpy(level, temp.c_str());
}

void Student::insert() {
fstream file("student.txt", ios::out | ios::app);
setdata();
pack();
file << record << endl;
file.close();
}

void Student::display(){
fstream file("student.txt", ios::in);
string line;
while (getline(file, line)) {
strncpy(record, line.c_str(), size - 1);

unpack();
getdata();
}
file.close();
}

void Student::search(string key){
fstream file("student.txt", ios::in);
string line;
bool found = false;

while (getline(file, line)) {
strncpy(record, line.c_str(), size - 1);
unpack();

if (string(id) == key) {
cout << "Record Found" << endl;
getdata();
found = true;
break;
}
}

if (!found)
cout << "ID Not Found" << endl;

file.close();
}

void Student::update(string key){
fstream file("student.txt", ios::in);
fstream temp("temp.txt", ios::out);

string line;
bool found = false;

while (getline(file, line)) {
strncpy(record, line.c_str(), size - 1);
unpack();

if (string(id) == key) {
cout << "Enter New Data:" << endl;
setdata();
pack();
temp << record << endl;
found = true;
} else {
temp << line << endl;
}
}

file.close();
temp.close();

remove("student.txt");
rename("temp.txt", "student.txt");

if (found)
cout << "Update Success" << endl;
else
cout << "ID Not Found" << endl;
}

void Student::Delete(string key){
fstream file("student.txt", ios::in);
fstream temp("temp.txt", ios::out);

string line;
bool found = false;

while (getline(file, line)) {
strncpy(record, line.c_str(), size - 1);
unpack();

if (string(id) == key) {
found = true;
} else {
temp << line << endl;
}
}

file.close();
temp.close();

remove("student.txt");
rename("temp.txt", "student.txt");

if (found)
cout << "Delete Success" << endl;
else
cout << "ID Not Found" << endl;
}

int main() {
Student S;
string key;

S.insert();
S.display();

cout << "Enter ID to search: "<<endl;
cin >> key;
S.search(key);

cout << "Update ID: "<<endl;
cin >> key;
S.update(key);

cout << "Delete ID: "<<endl;
cin >> key;
S.Delete(key);

cout << "Final Data:"<<endl;
S.display();

    return 0;
}


