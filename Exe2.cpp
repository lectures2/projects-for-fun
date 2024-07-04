// Programming Technique II (SECJ1023)
// Semester 1, 2020/2021

// Exercise 2: Composition

// Write your name and your partner's name.
// Only one submission is required per pair
// Submit only the source code file.
// Use only one source code file for this exercise. However, class declaration and definition
//  must be separated within the same file.

//! Pair Programming - Members Names and Location
//! Name 1:ZHOU CHENXING A19EC4034 (skudai)
//! Name 2:SEIFELDIN TAHA ABDELRAHIM TOHAMI A19EC3030 (skudai)

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define MAXTERM 10

class Term
{
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0); // given
    string toString() const; // given

    int coefficient() const;
    int evaluate(int x) const;
};


// 5x^2 + 2x

class Polynomial
{
private:
    int nTerm;
    Term terms[MAXTERM];
public:
    Polynomial();
    void read();
	int evaluate(int x) const;
	Term term(int e) const;
	
	Term largestTerm() const;
	
};

//--------------------------------------------------------------------------------------------
// Class Term Definition
//--------------------------------------------------------------------------------------------
Term::Term(int c, int e) : coef(c), exp(e) {}

int Term::coefficient() const{return coef;}

int Term::evaluate(int x) const {}
// The code for the method toString() is given
string Term::toString() const
{
    if (coef == 0)
        return "";
    if (exp == 0)
        return to_string(coef);

    string strTerm;

    switch (coef)
    {
    case -1:
        strTerm = "-x";
        break;
    case 1:
        strTerm = "x";
        break;
    default:
        strTerm = to_string(coef) + "x"; //the rest, is of form, eg. 3x^2
    }

    if (exp != 1)
        strTerm += "^" + to_string(exp);

    return strTerm;
}

//--------------------------------------------------------------------------------------------
// Class Polynomial Definition
//--------------------------------------------------------------------------------------------

Polynomial::Polynomial() {nTerm=0;}
void Polynomial::read()
{
    cin >> nTerm;

    for (int i=0; i<nTerm; i++){
    	
	}
        
}

int Polynomial::evaluate(int x) const; {

 for (int i=0; i<nTerm; i++){
 	
 	
 }

}
// Polynomial: 5x^2 - 7x + 5
// p.term(2) => Term(5,2)
// p.term(3) => term(0,0)
Term Polynomial::term (int e) const{
	
	for (int i=0; i<nTerm; i++){
 	
 }
 
 // how to return a zero term
 
 return term(0,0);
 
}
//--------------------------------------------------------------------------------------------
// Main Function
//--------------------------------------------------------------------------------------------
int main()
{
    cout << endl;

    cout << "Polynomial Information" << endl;
    cout << "----------------------" << endl;
    cout << " Equation     :  f(x) = "  << endl;
    cout << " Degree       :  "  << endl;
    cout << " Constant     :  " << endl;
    cout << " Largest Term :  "  << endl;
    cout << endl;

    
    // The code for getting the x values from user input is given
    int n;
    int x[10]; 

    cout << "Polynomial Evaluation" << endl;
    cout << "----------------------" << endl;
    cout << "Enter how many x values => ";
    cin >> n;

    cout << "Enter the x values => ";
    for (int i=0; i<n; i++)  
        cin >> x[i];
    
    cout << endl;
    cout << " x  \tf(x)" << endl;
    cout << "----\t----" << endl;

    cout << endl;
    system("pause");
    return 0;
}



