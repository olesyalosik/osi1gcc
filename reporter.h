#pragma once

#include <fstream>
#include <iostream>
#include <cstdio>
#include "employee.h"
#include <vector>
#include <string>

using namespace std;

class Reporter
{

private:
    char reportName[55];
    char binaryName[55];
    int salary;
    ofstream out;
    ifstream binaryIn;
    vector<Employee> employees;

public:
    Reporter(char reportName[55], char binaryName[55], int salary) :salary(salary) {
        strcpy(this->binaryName, binaryName);
        strcpy(this->reportName, reportName);
        out.open(reportName);
        binaryIn.open(binaryName, ios::binary);
    }

    void makeReport()
    {
        Employee e;
        while (true)
        {
            binaryIn.read((char *)&e, sizeof(Employee));
            if (binaryIn.eof()) break;
            employees.push_back(e);
        }
        out << "Отчет по файлу " << binaryName << endl;
        for (int i = 0; i < employees.size(); i++){
            out << employees[i].num << " " << employees[i].name << " " << employees[i].hours << " " << employees[i].hours * salary << endl;
        }

    }

    ~Reporter(){
        out.close();
        binaryIn.close();
    }
};