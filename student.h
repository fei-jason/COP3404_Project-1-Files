/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 1.
*
*  DO NOT MODIFY THIS FILE WITHOUT PERMISSION
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/
#pragma once

// Constants
#define EMAIL_SIZE 18 // Size of the student email address field
#define NAME_SIZE 24 // Size of the student name field
#define NUMBER_SIZE 10 // Size of the student number field

// Structures
struct student
{
	char name[NAME_SIZE];
	char number[NUMBER_SIZE];
	char email[EMAIL_SIZE];
	int credits;
	double gpa;
};

// Function Prototypes
void displayRecord(struct student* temp, int index);
bool testEmailFormat(struct student temp);
bool testStudentData(struct student temp);