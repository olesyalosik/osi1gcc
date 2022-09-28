#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

class Creator{

    char filename[55];

    int numberOfRecords;

    FILE *file;
public:

    Creator() : filename(""), numberOfRecords(0), file(NULL) {} 

    void createFile(){
        cout << "Enter filename:" << endl;
        cin >> filename;
        cout << "Enter number of records:" << endl;
        cin >> numberOfRecords;
        file = new FILE;
        file = fopen(filename, "wb");
        Employee e;
        cout << "Enter records:" << endl;
        for (int i = 0; i < numberOfRecords; ++i){
            cin >> e.num >> e.name >> e.hours;
            fwrite(&e, sizeof(Employee), 1, file);
        }
        fclose(file);
    }

};