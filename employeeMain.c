//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

 

//gcc employeeMain.c employeeTable.c employeeTwo.c 

 

#include <string.h> 

#include <stdlib.h> 

#include "employee.h" 

int main(void){ 

    //defined in employeeSearchOne.c 

    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, double numberToFind); 

    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 

    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneNumberToFind);

    PtrToEmployee searchEmployeeBySalary(const Employee tablep[], int sizeTable, double salaryToFind);


 

    //defined in employeeTable.c 

    extern Employee EmployeeTable[];     

    extern const int EmployeeTableEntries;      

 

    PtrToEmployee matchPtr;  //Declaration 

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

 

    //Example not found 

    if (matchPtr != NULL) 

        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee ID is NOT found in the record\n"); 

 

    //Example found 

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 

    if (matchPtr != NULL) 

        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee Tony Bobcat is NOT found in the record\n"); 

    // Example: Search by phone number (not found)
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    if (matchPtr != NULL)
        printf("Employee with phone number 123-456-7890 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone number 123-456-7890 is NOT found in the record\n");

    // Example: Search by phone number (found)
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employee with phone number 909-555-2134 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone number 909-555-2134 is NOT found in the record\n");

    // Example: Search by salary (not found)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.30);
    if (matchPtr != NULL)
        printf("Employee with salary 4.30 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 4.30 is NOT found in the record\n");

    // Example: Search by salary (found)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if (matchPtr != NULL)
        printf("Employee with salary 7.80 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 7.80 is NOT found in the record\n");

    return EXIT_SUCCESS; 

} 