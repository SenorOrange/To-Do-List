#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

string Operation;
string Task;
vector<string> toDoList;

//USER INPUT
void getUserInput () {
    cout << "What kind of operation do you want to do: ";
    getline (cin, Operation);
    cout << "State details of operation: ";
    getline (cin, Task);
}

//CREATES NEW LIST OF TASKS
void createNewList() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);

    //CREATES A NEW FILE
    ofstream file(Task + ".txt");

    cout << "New List Created Called: " << Task;
}

//LOADS OLD LIST OF TASKS FROM FILE
void loadList() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);
    cout << "Successfully Loaded: " << Task;
}

//SAVES CURRENT LIST TO FILE
void saveList() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);

    ofstream file(Task + ".txt");
    cout << "Successfully Saved: " << Task;
}

//TAKES USER INPUT TO ADD A NEW TASK
void newTasks() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);
    cout << "Successfully Added To The List: " << Task;
}

//DELETES A TASK THE USER DOSENT WANT ANYMORE
void deleteTask() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);
    cout << "Successfully Deleted From The List: " << Task;
}

//CHECKS OR UNCHECKS A TASK WHETHER COMPLETED OR NOT
void taskState() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);
    cout << "Successfully Altered Task To: " << Task;
}

//TRIGGERS THE CODE
int main() {
    getUserInput();

    if (Operation == "New List") {
        createNewList();
    } else if (Operation == "Load List") {
        loadList();
    } else if (Operation == "Save List") {
        saveList();
    } else if (Operation == "New Task") {
        newTasks();
    } else if (Operation == "Delete Task") {
        deleteTask();
    } else if (Operation == "Task State") {
        taskState();
    } else {
        cout << "Invalid Operation Please Try Again";
    }
    
    
    std::this_thread::sleep_for(20ms);
    return 0;
}