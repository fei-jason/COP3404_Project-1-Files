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
#define HASH_TABLE_SEGMENTS 7 // Value used in the computeHash() function
#define MOD_SIZE 5 // Modulus value to use in the computeHash() function

/*
* Compute a hash value using the student name value
* studentName: name of student
* 
* returns: computed hash value
*/
int computeHash(char* studentName)
{
	int hash = 0;

	for (int i = 0; studentName[i] != '\0'; i++) {
		hash += studentName[i];
	}

	return hash % MOD_SIZE + HASH_TABLE_SEGMENTS;
}

/*
* Display the student data stored in the hash table.
* hashTable: hash table containing student data
* 
* returns: nothing
*/
void displayHashTable(struct student* hashTable[])
{
	printf("\n\n%-10s", "Hash Table Contents\n");
	for (int i = 0; i < 90; i++) {
		printf("-");
	}
	printf("\n");
	printf("%-5s %-25s %-15s %-20s %-15s %-5s\n", "Index",
                                                  "Name", 
                                                  "Number", 
                                                  "Email Address",
                                                  "Credits",
                                                  "GPA");
	printf("%-5s %-25s %-15s %-20s %-15s %-5s\n", "-----",
                                                  "-------------------------", 
                                                  "---------------", 
                                                  "--------------------",
                                                  "---------------",
                                                  "-----");

	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			// printf("%-25s %-15s %-15s %-5d %.1f\n", hashTable[i]->name, 
			// 									       hashTable[i]->number, 
			// 									       hashTable[i]->email,
			// 									       hashTable[i]->credits,
			// 									       hashTable[i]->gpa);
			displayRecord(hashTable[i], i);
		} 											   
	}
}

/*
* Initialize each element in the hash table to NULL.
* hashTable: hash table containing student data
* 
* returns: nothing
*/
void initializeTable(struct student* hashTable[])
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

/*
* Insert a student's data into the hash table.
* hashTable: hash table containing student data
* temp: student whose data will be inserted
* 
* returns: nothing
*/
void insertStudent(struct student* hashTable[], struct student* temp)
{
	// Do not forget to use the malloc() function to reserve space for the student structure
	// Do not forget to use the strcpy() function to store the string data in the hash table
	int hashValue = computeHash(temp->name);
	int originalHashValue = hashValue;
	bool inserted = false;
	bool dupName = false;

	while (!inserted) {
		if(hashTable[hashValue] == NULL) {
			hashTable[hashValue] = malloc(sizeof(struct student));
			strcpy(hashTable[hashValue]->name, temp->name);
			strcpy(hashTable[hashValue]->number, temp->number);
			strcpy(hashTable[hashValue]->email, temp->email);
			hashTable[hashValue]->credits = temp->credits;
			hashTable[hashValue]->gpa = temp->gpa;
			inserted = true;
		} else {
			if (hashTable[hashValue]->name == temp->name) {
				displayError(DuplicateName, hashTable[hashValue]->name);
				inserted = true;
				dupName = true;
			}
			hashValue++;
		}
	}
	if (!dupName) {
		printf("Added Student to Hash Table: %10s Target %d, Actual %d\n", temp->name, originalHashValue, hashValue);
	}
}