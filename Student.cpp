/*
 * Student.cpp
 *
 *  Created on: 27.12.2015 г.
 *      Author: Petar
 */

#include<iostream>
#include "Date.h"
#include<string.h>
#include <ctime>
#include<fstream>
#include<vector>
#include <sstream>
#include <stdlib.h>
using namespace std;
class Student {
private:
	string ime;
	int fnum;
	Date date;
	float marks;
public:
	Student() :
			date(0, 0, 0) {
		ime = "";
		fnum = 0;
		marks = 0.0;
	}
	Student(string name, int number, Date date1, float marks_new) {
		ime = name;
		fnum = number;
		date = date1;
		marks = marks_new;
	}

	const Date& getDate() const {
		return date;
	}

	void setDate(const Date& date) {
		this->date = date;
	}

	int getFnum() const {
		return fnum;
	}

	void setFnum(int fnum) {
		this->fnum = fnum;
	}

	const string& getIme() const {
		return ime;
	}

	void setIme(const string& ime) {
		this->ime = ime;
	}

	int timeInYears(Student student);

	float getMarks() const {
		return marks;
	}

	void setMarks(float marks) {
		this->marks = marks;
	}

	friend ostream& operator<<(ostream& out, const Student& student);
};
int Student::timeInYears(Student student) {
	time_t currentTime;
	struct tm *localTime;

	time(&currentTime);
	localTime = localtime(&currentTime);
	int Day = localTime->tm_mday;
	int month = localTime->tm_mon + 1;
	int Year = localTime->tm_year + 1900;
	int days = student.getDate().getDay();
	int months = student.getDate().getmonth();
	int years = student.getDate().getYear();
	int diff = Year - years;
	if (month < months) {
		diff--;
		if (diff < 0)
			diff = 0;
		return diff;
	} else if (month == months) {
		if (Day < days) {
			diff--;
			if (diff < 0)
				diff = 0;
			return diff;
		} else if (diff < 0)
			diff = 0;
		return diff;
	}
	if (diff < 0)
		diff = 0;
	return diff;
}

//ostream& operator<<(ostream& out, const Student& student) {
//	out << student.getDate() << ""
//	return out;
//}
bool dayCheck(int days) {
	if (days > 0 && days < 32)
		return true;
	return false;
}
bool monthCheck(int month) {
	if (month > 0 && month < 13)
		return true;
	return false;
}
bool yearCheck(int year) {
	if (year > 1950 && year < 2016)
		return true;
	return false;
}
bool marksCheck(float marks) {
	if (marks >= 2.00 && marks <= 6.00)
		return true;
	return false;
}
inline string& ltrim(std::string& s, const char* t = " \t\n\r\f\v") {
	s.erase(0, s.find_first_not_of(t));
	return s;
}
inline string& rtrim(std::string& s, const char* t = " \t\n\r\f\v") {
	s.erase(s.find_last_not_of(t) + 1);
	return s;
}
inline string& trim(std::string& s, const char* t = " \t\n\r\f\v") {
	return ltrim(rtrim(s, t), t);
}
Student enterAStudent() {
	Student student;
	string name;
	int fnumber, day, month, year;
	float marks;
	cout << "Enter the name of a student" << '\n';
	getline(std::cin, name);
	trim(name);
	cout << "Enter the faculty number" << '\n';
	cin >> fnumber;
	cout << "Enter the day of birth" << '\n';
	cin >> day;
	bool checkDays = dayCheck(day);
	while (!checkDays) {
		cout << "Incorrect value of day.The value has to be between 1 and 31"
				<< '\n';
		cin >> day;
		checkDays = dayCheck(day);
	}
	cout << "Enter the month of birth" << '\n';
	cin >> month;
	bool checkMonth = monthCheck(month);
	while (!checkMonth) {
		cout << "Incorrect value of month.The value has to be between 1 and 12"
				<< '\n';
		cin >> month;
		checkMonth = monthCheck(month);
	}
	cout << "Enter the year of birth" << '\n';
	cin >> year;
	bool checkYear = yearCheck(year);
	while (!checkYear) {
		cout
				<< "Incorrect value of year.The value has to be between 1950 and 2016"
				<< '\n';
		cin >> year;
		checkYear = yearCheck(year);
	}
	cout << "Enter the average performance" << endl;
	cin >> marks;
	bool checkMarks = marksCheck(marks);
	while (!checkMarks) {
		cout
				<< "Incorrect value of average performance.The value has to be between 2.00 and 6.00"
				<< '\n';
		cin >> marks;
		checkMarks = marksCheck(marks);
	}
	Date dateOfStudent;
	dateOfStudent.setDay(day);
	dateOfStudent.setmonth(month);
	dateOfStudent.setYear(year);
	student.setIme(name);
	student.setFnum(fnumber);
	student.setDate(dateOfStudent);
	student.setMarks(marks);
	return student;
}
void printAStudent(Student student) {
	if ((student.getDate().getmonth() > 0 && student.getDate().getmonth() < 10)
			&& (student.getDate().getmonth() > 0
					&& student.getDate().getmonth() < 10)) {
		cout << student.getIme() << " " << student.getFnum() << " " << "0"
				<< student.getDate().getDay() << "." << "0"
				<< student.getDate().getmonth() << "."
				<< student.getDate().getYear() << " " << student.getMarks();
	} else if (student.getDate().getmonth() > 0
			&& student.getDate().getmonth() < 10) {
		cout << student.getIme() << " " << student.getFnum() << " "
				<< student.getDate().getDay() << "." << "0"
				<< student.getDate().getmonth() << "."
				<< student.getDate().getYear() << " " << student.getMarks();
	} else if (student.getDate().getDay() > 0
			&& student.getDate().getDay() < 10) {
		cout << student.getIme() << " " << student.getFnum() << " " << "0"
				<< student.getDate().getDay() << "."
				<< student.getDate().getmonth() << "."
				<< student.getDate().getYear() << " " << student.getMarks();
	} else {
		cout << student.getIme() << " " << student.getFnum() << " "
				<< student.getDate().getDay() << "."
				<< student.getDate().getmonth() << "."
				<< student.getDate().getYear() << " " << student.getMarks();
	}
}
void writeInFile(Student student) {
	ofstream studentsFile("students.txt", ios_base::app);
	studentsFile << student.getIme() << "_" << student.getFnum() << "_"
			<< student.getDate().getDay() << "." << student.getDate().getmonth()
			<< "." << student.getDate().getYear() << "_" << student.getMarks()
			<< "\n";
	studentsFile.close();
}
vector<string> split(const string& s, char c) {
	istringstream ss(s);
	vector < string > v;
	string substr;
	while (getline(ss, substr, c)) {
		v.push_back(substr);
	}
	return v;
}
vector<string> readFromFile() {
	ifstream inFile;
	inFile.open("students.txt");
	if (inFile.fail()) {
		cout << "Error in opening a file" << '\n';
		exit(1);
	}
	vector < string > lines;
	while (!inFile.eof()) {
		string line;
		getline(inFile, line);
		lines.push_back(line);
	}
	return lines;
}
void allStudents() {
	vector<Student> students;
	Date date;
	vector < string > lines = readFromFile();
	for (string line : lines) {
		Student student;
		vector < string > studentwithoutdate = split(line, '_');
		student.setIme(studentwithoutdate[0]);
		cout << studentwithoutdate[0] << '\n';
		int fnums = atoi(studentwithoutdate[1].c_str());
		student.setFnum(fnums);
		cout << fnums << '\n';
		float marks = stof(studentwithoutdate[3]);
		student.setMarks(marks);
		cout << marks << '\n';
		vector < string > vec = split(studentwithoutdate[2], '.');
		int day = atoi(vec[0].c_str());
		int month = atoi(vec[1].c_str());
		int year = atoi(vec[2].c_str());
		cout << day << month << year << '\n';
		date.setDay(day);
		date.setmonth(month);
		date.setYear(year);
		student.setDate(date);
		students.push_back(student);
	}
//	return students;
}
//vector<Student> getAllBetween18and26() {
//	vector<Student> allstudents = allStudents();
//	vector<Student> allStudentBetween18and26;
//	Student student;
//	for (unsigned int i = 0; i < allstudents.size(); i++) {
//		int differ = student.timeInYears(allstudents[i]);
//		if (differ > 17 && differ < 26) {
//			allStudentBetween18and26.push_back(allstudents[i]);
//		}
//	}
//	return allStudentBetween18and26;
//}
int main() {
	allStudents();

//	vector<Student> students = getAllBetween18and26();
//	for (unsigned int i = 0; i < students.size(); i++) {
//		printAStudent(students[i]);
//		cout << '\n';
//	}
//	vector<Student> allstud = allStudents();
//	for (unsigned int i = 0; i < allstud.size(); i++) {
//		printAStudent(allstud[i]);
//		cout << '\n';
//	}
//	cout << allstud;
//	Student student = enterAStudent();
//	cout << " IN MAIN METHOD " << endl;
//	cout << " NAME  NUMBER  DATE  MARKS" << endl;
//	printAStudent(student);
//	writeInFile(student);
//	Student student;
//	Date date;
//	date.setDay(1);
//	date.setmonth(1);
//	date.setYear(2015);
//	student.setDate(date);
//	int differ = student.timeInYears(student);
//	cout << "The student is on " << differ;
}
