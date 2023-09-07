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
* Display the selected error message using the provided error information.
* errorType: the type of error that occurred
* errorInfo: additional information about the error
* 
* returns: nothing
*/
void displayError(int errorType, char* errorInfo)
{
	switch (errorType) {
        case BlankRec:
            printf("Error : Blank Line Found\n");
            break;
        case ShortRec: 
            printf("Error : Short Record (%s)\n", errorInfo); 
            break;
        case CorruptRec:
            printf("Error : Corrupt Record (%s)\n", errorInfo);
            break;
        case NumLen:
            printf("Error : Student Number Not 9 Characters (%s)\n", errorInfo);
            break;
        case NumFormat:
            printf("Error : Student Number Is Invalid (%s)\n", errorInfo);
            break;
        case EmailLen:
            printf("Error : Student Email Not 17 Characters (%s)\n", errorInfo);
            break;
        case EmailFormat:
            printf ("Error : Student Email Format Is Invalid (%s)\n", errorInfo);
            break;
        case CreditsVal:
            printf("Error : Student Credit Not Less Than 150 (%s)\n", errorInfo);
            break;
        case GPAVal:
            printf("Error : Student GPA Not Less Than 4.0 (%s)\n", errorInfo);
            break;
        case DuplicateName:
            printf("Error : Duplicate Student Name (%s)\n", errorInfo);
            break;
        // case FileNotFound:
        //     printf("Error : Program Unable To Find Specified File (%s)\n", errorInfo);
        //     break;
        default:
            break;

    }
}