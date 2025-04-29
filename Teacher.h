#pragma once
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Util.h"
#include "Person.h"
#include "Global.h"

class Teacher : public Person
{
private:
	// No private functions needed
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
	Teacher(Mode mode, string firstName, string lastName, string phoneNumber, string email, string password, string gender)
		: Person(mode, firstName, lastName, phoneNumber, email, password, gender)
	{
	}

	static Teacher Find(string phoneNumber, string password)
	{
		Person person = Person::Find(TEACHERS_FILE, phoneNumber, password);
		return Teacher(person.getMode(), person.getFirstName(), person.getLastName(), person.getPhoneNumber(), person.getEmail(), person.getPassword(), person.getGender());
	}

	static void SaveNewTeacherToFile(vector<string> newTeacherInfo)
	{
		Person::SaveNewToFile(TEACHERS_FILE, newTeacherInfo);
	}

	static vector<Teacher> LoadAllTeachersInSystem()
	{
		vector<Person> persons = Person::LoadDataFromFile(TEACHERS_FILE);
		vector<Teacher> teachers;
		for (Person &person : persons)
		{
			teachers.push_back(Teacher(person.getMode(), person.getFirstName(), person.getLastName(), person.getPhoneNumber(), person.getEmail(), person.getPassword(), person.getGender()));
		}
		return teachers;
	}

	static void SaveTeacherToFile(vector<Teacher> &allTeachers)
	{
		vector<Person> persons;
		for (const Teacher &teacher : allTeachers)
		{
			persons.push_back(teacher);
		}
		Person::SaveDataToFile(TEACHERS_FILE, persons);
	}
};
