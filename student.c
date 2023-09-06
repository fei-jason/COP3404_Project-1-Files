/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 1.
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/

#include "headers.h"

/*
* Display a student's data.
* temp: student whose data will be displayed
* index: location of the student within the hash table
* 
* returns: nothing
*/
void displayRecord(struct student* temp, int index)
{
    printf("%-5d %-25s %-15s %-20s %-15d %.1f\n", index,
                                                  temp->name, 
                                                  temp->number, 
                                                  temp->email,
                                                  temp->credits,
                                                  temp->gpa);

}

/*
* Test if student's email address has valid format.
* temp: student data to test
* 
* returns: true if email address format is valid; otherwise, false
*/
bool testEmailFormat(struct student temp)
{
	if (temp.email[0] != 'u' || temp.email[9] != '@' || temp.email[13] != '.') {
        return false;
    }
    if (temp.email[10] != 'u' || temp.email[11] != 'f' || temp.email[12] != 'b') {
        return false;
    }
    if (temp.email[14] != 'e' || temp.email[15] != 'd' || temp.email[16] != 'u') {
        return false;
    }
    return true;
}

/*
* Test student's data for errors.
* temp: student data to test
* 
* returns: true if student data is valid; otherwise, false
*/
bool testStudentData(struct student temp)
{   
    size_t nameLen = strlen(temp.name);
    size_t numLen = strlen(temp.number);
    size_t emailLen = strlen(temp.email);
    
	if (nameLen < 5 || nameLen > 20) { 
        displayError(NameLen, temp.name);
        return false;
    }

    if (temp.number[0] != 'u') {
        displayError(NumFormat, temp.number);
        return false;
    }

    if (numLen != 9) {
        displayError(NumLen, temp.number);
        return false;
    }

    if(emailLen != 17) {
        displayError(EmailLen, temp.email);
        return false;
    }
    
    if (!testEmailFormat(temp)) {
        displayError(EmailFormat, temp.email);
        return false;
    }

    if (temp.credits < 0 || temp.credits > 150) {
        char strCredits[5];
        sprintf(strCredits, "%d", temp.credits);
        displayError(CreditsVal, strCredits);
        return false;
    }

    if (temp.gpa < 0 || temp.gpa > 4.0) {
        char strGPA[5];
        sprintf(strGPA, ".2%f", temp.gpa);
        displayError(GPAVal, strGPA);
        return false;
    }

    return true;
}