#include <iostream>
#include <string>
using namespace std;

	class Student{
		string name;
			public:
	
	Student(string n = "");
	string getName() const;

	void setName(string n);
	void print() const;
	};

	class Mentor:public Student{
	
			public:
	double cpa;
	
	Mentor(string n, double c);
	void print() const;

	};
	class Mentee:public Student{
	
	int level;
	Mentor mentor;
			public:
	Mentee(string n, int l);
	Mentee();
	
	void assignMentor(Mentor m);
	void removeMentor();
	string getMentorName();
	void print() const;

	};

	class Coach:public Mentor{
		
	string expertise;
			public:
	Coach(string n, double c, string e);
	void print() const;

	};

	class Support:public Mentor{
	
	string phone;
		public:	
	
	Support(string n, double c, string p);
	void print() const;

	};

	Student::Student(string n) : name(n) 	{}
	string Student::getName() const { return name; 	}
	
	void Student::setName(string n) { name = n; }
	void Student::print() const { cout << "Name : "+name << endl;	 }

	Mentor::Mentor(string n,double c):cpa(c){setName(n);	}
	void Mentor::print() const { cout << "Mentor Name : "+ getName() << endl;cout<<"CPA : ";cout<<cpa<<endl; 	}

	Mentee::Mentee(string n, int l):level(l),mentor(Mentor("",0)){setName(n);	}
	Mentee::Mentee():level(-1),mentor(Mentor("",0)){setName("");	}

	void Mentee::print() const 	{
	cout<<"Name : "+getName()<<"/n";
	cout<<"Level: "<<level<<endl;
	if(mentor.getName()!="")
	mentor.print();
	else
	cout<<"No mentor yet"<<"/n";
	}
	void Mentee::assignMentor(Mentor m){
	mentor=m;
	}
	void Mentee::removeMentor(){
	mentor=Mentor("",0);	
	}
	string Mentee::getMentorName(){
	return mentor.getName();
	}

	Coach::Coach(string n, double c, string e):Mentor(n,c),expertise(e){}
	void Coach::print() const { cout << "Coach Name : "+getName() << endl;cout<<"CPA : ";cout<<cpa<<endl;cout<<"Expertise : "+expertise<<endl;; }
	
	Support::Support(string n, double c, string p):Mentor(n,c),phone(p){}
	void Support::print() const { cout << "Support Name : "+getName()<<endl;cout<<"CPA : ";cout<<cpa<<endl;cout<<"Phone : "+phone<<endl; }


	int main()
	{

	Support support("Siti Aminah",3.98,"013-89001000");
	support.print();
	Coach coach("Ahmad Kamal",3.87,"Web Programming");
	coach.print();
	
	Mentee mentee[4];
	mentee[0]=Mentee("Abdul Samad",1);
	mentee[0].assignMentor(coach);
	
  
	mentee[1]=Mentee("Siti Nurdiana",1);
  
	mentee[2]=Mentee("Jazlan Kamal",1);
	mentee[2].assignMentor(support);
  
  
	mentee[3]=Mentee("Omar Abdullah",2);
	mentee[3].assignMentor(coach);
  
	for(int i=0;i<4;i++)
	{
	mentee[i].print();
	cout<<"--------"<<"/n";
	}
  
  
	mentee[3].removeMentor();
	for(int i=0;i<4;i++)
	{
	cout<<" Mentee Name: "<<mentee[i].getName()<<endl;
	if(mentee[i].getMentorName()!="")
	cout<<" Mentor Name: "<<mentee[i].getMentorName()<<"/n";
	else	
	cout<<" Mentor not assigned"<<"/n";	
	}
	return 0;
	}
