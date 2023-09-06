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

// Keywords used to display appropriate error message
enum errors { BlankRec, ShortRec, CorruptRec , NameLen, NumLen, NumFormat, EmailLen, EmailFormat, CreditsVal, GPAVal, DuplicateName};

// Function Prototypes
void displayError(int errorType, char* errorInfo);