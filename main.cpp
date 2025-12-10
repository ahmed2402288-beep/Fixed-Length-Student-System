#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
string record ;
private:
string id;
string name ;
string age ;
string gpa ;
public:
void setdata();
void getdata();
void pack();
void unpack();
void insert();
void display();
void search(string key);

};
void Student::setdata(){
cout << "Enter ID: ";
cin>>id;
cout<< "Enter Name: ";
cin>>name;
cout << "Enter Age: ";
cin>>age;
cout << "Enter GPA: ";
cin>>gpa;
}
void Student::getdata(){
cout<<"Enter ID:"<<id<<endl;
cout<<"Enter Name:"<<name<<endl;
cout<<"Enter Age:"<<age<<endl;
cout<<"Enter GPA:"<<gpa<<endl;
cout<<"----------------------------------------"<<endl;
}
void Student::pack(){
record=id+"|"+name+"|"+age+"|"+gpa+"#";
}
void Student::unpack(){
int pos = 0;
pos = record.find("|");
id = record.substr(0, pos);
record = record.substr(pos + 1);
pos = record.find("|");
name = record.substr(0, pos);
record = record.substr(pos + 1);
pos = record.find("|");
age = record.substr(0, pos);
record = record.substr(pos + 1);
pos = record.find("|");
gpa = record.substr(0, pos);
}
void Student::insert() {
fstream file("student.txt", ios::out | ios::app);
setdata();
pack();
file << record<<endl ;
file.close();
}
void Student::display(){
fstream file("student.txt" , ios::in);
while (getline(file, record)) {
unpack();
getdata();
}
file.close();
}
void Student::search(string key){
fstream file("student.txt" ,ios::in);
bool found = false;
int count=0;
int pos=-1;
while (getline(file, record)){
unpack();
if (id == key) {
pos=count;
cout << "Record Found"<<pos<<endl;
getdata();
break;
}
}
file.close();
}

int main() {
Student S ;
string key ;
S.insert();
S.display();
cout<<"Enter ID to search:";
cin>>key;
S.search(key);
return 0 ;
}



