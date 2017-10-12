/***********************************************************************
	The implementation file for course.h, which describes a college
	course.
		John Dolan		School of EECS		Summer2013
**************************************************************************/

/**
*	@file course.cc
*	@author John Dolan
*	@date Summer 2013
*/

#include "course.h"
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

course::course(){
    hours = 0.0;
}

/**
*	/breif gathers the users input
*	/details Takes a user input stream and cconverts it into a course number
*		 a grade recieved, and an amount of credit hours and outputs
*		 the values to the screen
*	/param a stream
*	/return none
*/

void course::input(std::istream& ins){
    if(ins == cin){
	cout<<"Course Number: ";
	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
	cout<<"Grade received: ";
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
 	cout<<"Credit hours: ";
    	ins>>hours;
	upper_course();   // makes all lower case letters into caps
    }
    else{
    	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
    	ins>>hours;
    }
}

/**
*	/breif outputs a course object
*	/details outputs the course number, grade, and credit hours of a course object.
*		 can be used to output to either the screeen, or a file depending on the
*		 ostream given to it.
*	/param a stream
*	/return none
*/

void course::output(std::ostream& outs)const{
    if(outs == cout){
	outs<<"Course Number:"<<course_number<<endl;
	outs<<"Grade received:"<<grade<<endl;
	outs<<"Credit hours:"<<setprecision(2)<<hours<<endl;
      }
     else{
        outs<<course_number<<endl;
        outs<<grade<<endl;
        outs<<setprecision(2)<<hours<<endl;
      }
}

/**
*	/breif converts a lettergrade to a value
*	/details Takes a given letter value and runs it through a series of if statements
*		 to convert it to its associated numerical value that is returned
*	/param none
*	/return a double
*/

double course::get_number_grade()const{
    if(grade == "A") return 4.0;
    if(grade == "A-") return 3.667;
    if(grade == "B+") return 3.333;
    if(grade == "B") return 3.0;
    if(grade == "B-") return 2.667;
    if(grade == "C+") return 2.333;
    if(grade == "C") return 2.0; 
    if(grade == "C-") return 1.667;
    if(grade == "D+") return 1.333; 
    if(grade == "D") return 1.0;
    if(grade == "D-") return 0.667; 
    if(grade == "F") return 0.0;
    else return 0;
}

void course::set_course(std::string num, std::string grad, double hrs){
	course_number = num;
	grade = grad;
	hours = hrs;
}

istream& operator >>(istream& ins, course& c){
    c.input(ins);
    return ins;
}

ostream& operator <<(ostream& outs, const course& c){
    c.output(outs);
    return outs;
}

void course::upper_course(){
    for(int i =0; i<course_number.length(); ++i)
	course_number[i] = toupper(course_number[i]);
}
