//? SECJ1023 Programming Technique II
//? Semester 1, 2020/2021
//? Tutorial Topic 5: String Manipulation
//? Program 2
//? Date: 30 November 2020 (Week 7)

//! Watch the video and code along
//! And the submit the complete program (program2.cpp) for the ATTENDANCE of Monday class

//? Your name:...................  Matric: ...................

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Person {
	private:
		string name, id;

	public:
		string getName() const;
		string getId() const;
		string getGender() const;
		int getAge() const;
		int getYearOfBirth() const;
		int getMonthOfBirth() const;
		int getDayOfBirth() const;
		void print() const;
	    void input();
};

string strToupper(string s){
	for (int i=0 ; i<s.length();i++)
	s[i]= toupper(s[i]);
	return s; 
}

const string MONTHS[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {
	
	Person p1;


	p1.input();
	
	cout << "output"<<endl
	     <<endl;
	p1.print();

	system("pause");

	return 0;
}

void Person::input()
{
	cout << "Enter your full name : ";
	
	getline(cin, name);
	
	name = strToupper(name);
	cout << "Enter your ID Number ";
	cin >> id;

}
string Person::getName() const {
	return name;
}
string Person::getId() const {
	return id;
}
void Person::print() const {
	cout << "Name    : " << name << endl;
	cout << "ID      : " << id << endl;
	cout << "Gender  : " << getGender()<< endl;
	cout << "Age     : " <<getAge() << " years old" << endl;
	cout << "DOB     : " <<getDayOfBirth()<< " " << MONTHS[getMonthOfBirth()-1]<<" "<< getYearOfBirth() <<  endl
	     << endl;
		
}

string Person::getGender()const
{
	string strLastDigit = id.substr(id.length()-1,1);
int lastDigit=	stoi(strLastDigit);
if (lastDigit %2 ==0 )return "Female";
else return "male";
}

int Person::getYearOfBirth()const 
{

string stryear = id.substr(0,2);

int year =stoi(stryear);
if ((year>= 0 )&& (year <= 18 )) year +=2000 ;
if ((year>= 19 )&& (year <= 99 )) year +=1900 ;

return year;
}

int Person::getMonthOfBirth()const 
{
string strmonth  = id.substr(2,2);

int month =stoi(strmonth);


return month;
}
int Person::getDayOfBirth()const 
{
return stoi(id.substr(4,2));
}

int Person::getAge() const
{
return 2019 - getYearOfBirth();

}
