#include <iostream>
#include<string>
using namespace std;
class teacher
{
public:
	string name;
	string dept;
	teacher(string name,string dept)
	{
		this->name = name;
		this->dept = dept;
	}
	teacher(teacher& obj)//coustamized copy with changes
	{
		obj.dept = "Arts";
		obj.name = "Ali";
	
		this->name=obj.name;
		this->dept = obj.dept;
	}
	void getinfo()
	{
		cout << "Your department is:" << this->dept << endl;
		cout << "Your name is:" << this->name << endl;
	}

	// Method to check if teacher is from CS department
	bool isCSTeacher()
	{
		return (this->dept == "Computer science");
	}

	// Method to update department
	void updateDepartment(string newDept)
	{
		this->dept = newDept;
		cout << "Department updated to: " << newDept << endl;
	}
};
int main()
{
	teacher t1("javeria", "Computer science");
	t1.getinfo();
	teacher t2(t1);
	t2.getinfo();
}