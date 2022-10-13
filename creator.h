#pragma once

#include <iostream>
#include <string>
#include "employee.h"
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

class Creator{

private:

    char filename[55];
    int numberOfRecords;

    ifstream binaryIn;
    ofstream binaryOut;

public:

    Creator(char filename[55], int numberOfRecords) : numberOfRecords(numberOfRecords) {
        strcpy(this->filename, filename);
        binaryOut.open(filename, ios::binary);
        binaryIn.open(filename, ios::binary);
    }

    void createFile(){
        Employee e;
        cout << "Enter records:" << endl;
        for (int i = 0; i < numberOfRecords; ++i){
            cin >> e.num >> e.name >> e.hours;
            binaryOut.write((char *)&e, sizeof(Employee));
        }
    }

    void printFile(){
        Employee e;
        cout << "Binary file " << filename << " contains: " << endl;
        while (!binaryIn.eof())
        {
            binaryIn.read((char *)&e, sizeof(Employee));
            cout << e.num << " " << e.name << " " << e.hours << endl;
        }
    }


    ~Creator(){
        binaryOut.close();
        binaryIn.close();
    }

};