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
* Search the hash table for students using the provided search operation and query.
* hashTable: hash table containing student data
* searchType: type of search to perform
* searchString: query on which to perform the search
* 
* returns: nothing
*/
void performSearch(struct student* hashTable[], char* searchType, char* searchString)
{
    int searchTypeInt = strtol(searchType, &searchType, 10);
    int searchStringInt = 0;
    double searchStringDbl = 0;
    char* copy;

    switch(searchTypeInt) {
        case CreditsEq:
            searchStringInt = strtol(searchString, &searchString, 10);
            printf("\nSearching Records Where Credits Is %d\n", searchStringInt);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (hashTable[i]->credits == searchStringInt) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case CreditsLess:
            searchStringInt = strtol(searchString, &searchString, 10);
            printf("\nSearching Records Where Credits < %d\n", searchStringInt);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (hashTable[i]->credits < searchStringInt) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case CreditsMore:
            searchStringInt = strtol(searchString, &searchString, 10);
            printf("\nSearching Records Where Credits > %d\n", searchStringInt);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (hashTable[i]->credits > searchStringInt) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case Email:
            printf("\nSearching Records Where Email Is %s\n", searchString);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (strcmp(hashTable[i]->email, searchString) == 0) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case EmailPart:
            printf("\nSearching Records Where Email Contains %s\n", searchString);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    char* subString = strstr(hashTable[i]->email, searchString);
                    if (subString != NULL) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case FullName:
            printf("\nSearching Records Where Full Name Is %s\n", searchString);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (strcmp(hashTable[i]->name, searchString) == 0) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case FName:
            printf("\nSearching Records Where First Name Is %s\n", searchString);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    copy = strdup(hashTable[i]->name);
                    char* fName = strtok(copy, " ");
                    if(strcmp(fName, searchString) == 0) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case LName:
            printf("\nSearching Records Where Last Name Is %s\n", searchString);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    copy = strdup(hashTable[i]->name);
                    strtok(copy, " ");
                    char* lName = strtok(NULL, " ");
                    if(strcmp(lName, searchString) == 0) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case GPAEq:
            searchStringDbl = atof(searchString);
            printf("\nSearching Records Where GPA Is %.1f\n", searchStringDbl);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (hashTable[i]->gpa == searchStringDbl) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case GPALess:
            searchStringDbl = atof(searchString);
            printf("\nSearching Records Where GPA < %.1f\n", searchStringDbl);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (hashTable[i]->gpa < searchStringDbl) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case GPAMore:
            searchStringDbl = atof(searchString);
            printf("\nSearching Records Where GPA > %.1f\n", searchStringDbl);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (hashTable[i]->gpa > searchStringDbl) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case Num: 
            printf("\nSearching Records Where Student Number Is %s\n", searchString);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    if (strcmp(hashTable[i]->number, searchString) == 0) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        case NumPart:
            printf("\nSearching Records Where Student Number Contains %s\n", searchString);
            for(int i = 0; i < TABLE_SIZE; i++) {
                if(hashTable[i] != NULL) {
                    char* subString = strstr(hashTable[i]->number, searchString);
                    if (subString != NULL) {
                        displayRecord(hashTable[i], i);
                    }
                }
            }
            break;
        default:
            break;
    }

}