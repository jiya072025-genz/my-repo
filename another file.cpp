#include <iostream>
#include<string>
using namespace std;
class student
{
public:
	string name;
	int* cgpaptr;

	student(string name, int cgpa)
	{
		this->name = name;
		cgpaptr = new int;
		*cgpaptr = cgpa;
	}
	//destructor
	~student()
	{
		cout << "deleting the dynamic memory from heap\n";
		delete cgpaptr;
	}

	void getinfo()
	{
		cout << "Name:" << name << endl;;
		cout << "cgpa:" << *cgpaptr << endl;
	}
};
int main()
{
	student s1("Javeria",3.5);
	s1.getinfo();
}
