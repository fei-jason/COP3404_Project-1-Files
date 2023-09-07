/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 1.
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/

#include "headers.h"

// Constants
#define INPUT_BUF_SIZE 60 // Size of the buffer used to read records from input file
#define	SEARCH_BUF_SIZE 25 // Size of the buffer used to read records from search file

// Function Prototypes
struct student createStudent(char record[]);
void processInputFile(struct student* hashTable[], char* filename);
void processSearchFile(struct student* hashTable[], char* filename);
bool testRecord(char record[]);

int main(int argc, char *argv[])
{
	struct student* hashTable[TABLE_SIZE];
	initializeTable(hashTable);

	printf("%-10s", "Hash Table Logs\n");
	for (int i = 0; i < 90; i++) {
		printf("-");
	}
	printf("\n");

	processInputFile(hashTable, argv[1]);
	displayHashTable(hashTable);
}

/* 
* Create a student using the provided data.
* record: String of student data
* 
* returns: The student containing the provided data
*/
struct student createStudent(char record[])
{
	// Do not forget to use the following functions:
	// strtok() - splits a string into separate parts
	// strcpy() - copies string data from one variable to another
	// strtol() - converts a string to its integer value
	// atof() 	- converts a string to its double value
	struct student student;

	char* copy = strdup(record);
	char temp[20];

	strcpy(student.name, strtok(copy, ","));
	strcpy(student.number, strtok(NULL, ","));
	strcpy(student.email, strtok(NULL, ","));
	strcpy(temp, strtok(NULL, ","));

	long credits = strtol(temp, &copy, 10);
	student.credits = credits;
	student.gpa = atof(strtok(NULL, ","));

	return student;
}

/*
* Read records from the input file and load student data into the hash table.
* hashTable: hash table containing student data
* filename: name of file containing student records
* 
* returns: nothing
*/
void processInputFile(struct student* hashTable[], char* filename)
{
	// Do not forget to use the following functions:
	// memset() - fill the buffer array with the specified character
	
	FILE* ptr;
	char record[INPUT_BUF_SIZE];
	struct student newStudent;

	ptr = fopen(filename, "r");
	if (ptr == NULL){
		//perform error handling here
	}
	
	while (fgets(record, INPUT_BUF_SIZE, ptr) != NULL) {
		if (testRecord(record)) {
			newStudent = createStudent(record);

			if (testStudentData(newStudent)) {
				insertStudent(hashTable, &newStudent);
			}
		} 
		
	}

	memset(record, '\0', sizeof(record));
	fclose(ptr);
}

/*
* Extra Credit: Search the student data contained in the hash table.
* hashTable: hash table containing student data
* filename: name of file containing search requests
*
* returns: nothing
*/
void processSearchFile(struct student* hashTable[], char* filename)
{
	// Do not forget to use the following functions:
	// strtok() - splits a string into separate parts
	// memset() - fill the buffer array with the specified character
}

/*
* Perform tests on the provided record to see if it is a valid record.
* record: String of student data
* 
* returns: true if no errors exists; otherwise, false
*/
bool testRecord(char record[])
{
	// Do not forget to use the following functions:
	// strcspn() - returns index of specified character a string
	// strncpy() - copies the specified number of characters between strings
	int strLen = strcspn(record, "");
	int commaCnt = 0;
	int newLineChar = 0;
	char errorMessage[strLen + 1];

	for (int i = 0; record[i] != '\0'; i++) {
		if (record[i] == ',') {
			commaCnt++;
		}
	}

	//errors
	if (record[0] == '\n' || record[0] == '\r') {
		displayError(BlankRec, NULL);
		return false;
	}	

	if (strLen < 35 || strLen > 60) {
		newLineChar = strcspn(record, "\n");
		strncpy(errorMessage, record, newLineChar);
		displayError(ShortRec, errorMessage);
		return false;
	}	

	if (commaCnt != 4) {
		newLineChar = strcspn(record, "\n");
		strncpy(errorMessage, record, newLineChar);

		displayError(CorruptRec, errorMessage);
		commaCnt == 0;
		return false;
	}	

	return true;
}