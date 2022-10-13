#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "creator.h"
#include "reporter.h"

using namespace std;

struct params{
    char filename[55];
    int numberOfRecords;
};

void *creator_func(void *varg)
{
    sleep(1);
    params *thread_args = (params*)varg;
    Creator creator(thread_args->filename, thread_args->numberOfRecords);
    creator.createFile();
    creator.printFile();
    pthread_exit(0);
}

int main(){
    char binaryFileName[55], reportName[55];
    int numberOfRecords, salary;
    
    cout << "Enter binary file name:" << endl;
    cin >> binaryFileName;
    cout << "Enter number of records: " << endl; 
    cin >> numberOfRecords;
    
    params thread_params;
    strcpy(thread_params.filename, binaryFileName);
    thread_params.numberOfRecords = numberOfRecords;

    pthread_t creatorId;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&creatorId, &attr, creator_func, &thread_params);
    int s = pthread_join(creatorId, NULL);

    cout << "Enter report name: " << endl;
    cin >> reportName;
    cout << "Enter salary: " << endl;
    cin >> salary;
    Reporter reporter(reportName, binaryFileName, salary);
    reporter.makeReport();
    return 0;
}