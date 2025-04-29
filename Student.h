#pragma once
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Util.h"
#include "Person.h"
#include "Global.h"

class Student : public Person
{
private:
	string ConvertObjectToLine() override
	{
		string delimiter = "#//#";
		string line;
		line += getFirstName() + delimiter;
		line += getLastName() + delimiter;
		line += getPhoneNumber() + delimiter;
		line += getEmail() + delimiter;
		line += getPassword() + delimiter;
		line += getGender();
		return line;
	}

public:
	Student(Mode mode, string firstName, string lastName, string phoneNumber, string email, string password, string gender)
		: Person(mode, firstName, lastName, phoneNumber, email, password, gender)
	{
	}

	

	static vector<Student> LoadStudentDataFromFile()
	{
		vector<Person> persons = Person::LoadDataFromFile(STUDENTS_FILE);
		vector<Student> students;
		for (Person &person : persons)
		{
			students.push_back(Student(person.getMode(), person.getFirstName(), person.getLastName(), person.getPhoneNumber(), person.getEmail(), person.getPassword(), person.getGender()));
		}
		return students;
	}

	static Student Find(string phoneNumber, string password)
	{
		Person person = Person::Find(STUDENTS_FILE, phoneNumber, password);
		return Student(person.getMode(), person.getFirstName(), person.getLastName(), person.getPhoneNumber(), person.getEmail(), person.getPassword(), person.getGender());
	}

	static void SaveNewStudentToFile(vector<string> newStudentInfo)
	{
		Person::SaveNewToFile(STUDENTS_FILE, newStudentInfo);
	}

	static void SaveStudentsToFile(vector<Student> &allStudents)
	{
		vector<Person> persons;
		for (const Student &student : allStudents)
		{
			persons.push_back(student);
		}
		Person::SaveDataToFile(STUDENTS_FILE, persons);
	}
};