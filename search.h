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

// Keywords used to perform appropriate search
enum searchTypes { CreditsEq, CreditsLess, CreditsMore, Email, EmailPart, FullName, FName, LName, GPAEq, GPALess, GPAMore, Num, NumPart };
				   
// Function Prototypes
void performSearch(struct student* hashTable[], char* type, char* string);