#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Employee
{
private:
	char name[30], position[30];		//이름, 직급
	int employeeId, age, year, off;		//고유 번호, 나이, 근속연수, 남은 연차 수
public:
	Employee(const char* name1, const char* position1, int employeeId, int age, int year, int off) 
		: employeeId(employeeId), age(age), year(year), off(off)
	{
		strncpy(this->name, name1, sizeof(this->name) - 1);
		this->name[sizeof(this->name) - 1] = '\0';	//복사된 문자열의 끝에 널 문자를 수동으로 추가
		strncpy(this->position, position1, sizeof(this->position) - 1);
		this->position[sizeof(this->position) - 1] = '\0';
	}

	int GetEmployeeId() { return employeeId; }
	const char* GetPosition() { return position; }
	const char* GetName() { return name; }
	int GetAge() { return age; }
	int GetYear() { return year; }
	int GetOff() { return off; }

	virtual void ShowInfo() {
		printf("ID: %d, 이름: %s, 직급: %s, 나이: %d, 근속연수: %d, 남은 연차 수: %d\n"
			, employeeId, position, name, age, year, off);
	}
};

class Manager : public Employee
{
private:
	int sub;
public:
	Manager(const char* name, const char* position, int employeeId, int age, int year, int sub, int off)
		: Employee(name, position, employeeId, age, year, off), sub(sub) {}

		void ShowInfo() override
	{
			printf("Manager ID: %d, 직급: %s, 이름: %s, 나이: %d, 근속연수: %d, 남은 연차 수: %d, 부하의 수: %d\n",
				GetEmployeeId(), GetPosition(), GetName(), GetAge(), GetYear(), GetOff(), sub);
	}
};

class Developer : public Employee
{
private:
	char Language[15];
public:
	Developer(const char* name, const char* position, int employeeId, int age, int year, int off, const char* Language)
		:Employee(name, position, employeeId, age, year, off)
	{
		strncpy(this->Language, Language, sizeof(this->Language) - 1);
		this->Language[sizeof(this->Language) - 1] = '\0';
	}

	void ShowInfo() override
	{
		printf("Developer ID: %d, 직급: %s, 이름: %s, 나이: %d, 근속연수: %d, 남은 연차 수: %d, 사용하는 프로그램 언어: %s\n",
			GetEmployeeId(), GetPosition(), GetName(), GetAge(), GetYear(), GetOff(), Language);
	}
};

int main()
{
	Manager manager("Kim", "팀장", 1, 37, 7, 12, 10);
	Developer developer("Lee", "사원", 2, 27, 1, 7, "C++");

	Employee* employee1 = &manager;
	Employee* employee2 = &developer;

	employee1->ShowInfo();
	employee2->ShowInfo();
}

