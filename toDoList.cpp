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
string TaskState;
string file;
string fileData;
string fileName;
string line;
string dashs;
vector<string> toDoList;

bool w = false; //USED TO CHECK IF THE TASK EXISTS
bool x = true; //USED TO KEEP THE PROGRAM RUNNING
bool y = false; //USED TO CHECK IF A FILE IS ACTIVE
bool z = false; //USED TO MAKE SURE YOU CAN ONLY SAVE ONCE A FILE HAS BEEN OPENED

//USER INPUT
void getUserInput () {
    cout << "What kind of operation do you want to do (Type 'Help' For Help): ";
    getline (cin, Operation);
}

//CREATES NEW LIST OF TASKS
void createNewList() {
    z = false;

    string newListName;
    cout << "Please enter your new list name: ";
    getline (cin, newListName);

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(1s);

    //RESETS THE LIST
    toDoList.clear();

    //CREATES A NEW FILE
    fileName = newListName;
    ofstream file(fileName + ".txt");

    int s = newListName.length();
    dashs = string(s, '-');
    toDoList.push_back("Your " + fileName + " List");
    toDoList.push_back(dashs + "----------");

    z = true;

}

//LOADS OLD LIST OF TASKS FROM FILE
void loadList() {
    z = false;

    string listName;
    cout << "Please enter the list you would like to load: ";
    getline (cin, listName);

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(1s);

    //RESETS THE LIST
    toDoList.clear();

    ifstream file(listName + ".txt");

    if (!file.is_open()) {
        cout << "No File Found, Please Try Again or Create New List" << endl;
        return;
    }

    fileName = listName;

    while (std::getline(file, fileData)) 
        toDoList.push_back(fileData);
    
    cout << "Successfully Loaded: " << listName << endl;

    z = true;

}

//TAKES USER INPUT TO ADD A NEW TASK
void newTasks() {

    string taskName;
    cout << "Please enter your new task name: ";
    getline (cin, taskName);

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(1s);

    toDoList.push_back("[ ]  " + taskName);
    cout << "Successfully Added To The List: " << taskName << endl;

}

//DELETES A TASK THE USER DOSENT WANT ANYMORE
void deleteTask() {

    string taskName;
    cout << "Please enter the task to delete: ";
    getline (cin, taskName);

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(1s);

    auto it = std::find_if(toDoList.begin(), toDoList.end(), [&](const string& item) {
        return item.find(taskName) != string::npos;
    });

    if (it != toDoList.end()) {
        toDoList.erase(it);
        cout << "Successfully Deleted From The List: " << taskName << endl;
    } else {
        cout << "Item Not Found" << endl;
    }

}

//CHECKS OR UNCHECKS A TASK WHETHER COMPLETED OR NOT
void taskState() {

    string taskName;
    cout << "Please enter the task to alter: ";
    getline (cin, taskName);

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(1s);

    auto it = std::find_if(toDoList.begin(), toDoList.end(), [&](const string& item) {
        return item.find(taskName) != string::npos;
    });

    if (it != toDoList.end()) {
        cout << "What Is The Task State? (Completed or Not Done): ";
        getline (cin, TaskState);

        if (TaskState == "Completed"|| TaskState == "completed") {
            toDoList.erase(it);
            toDoList.push_back("[X]  " + taskName);
            cout << "Successfully Altered Task To: " << TaskState << endl;
        } else if (TaskState == "Not Done"|| TaskState == "not done") {
            toDoList.erase(it);
            toDoList.push_back("[ ]  " + taskName);
            cout << "Successfully Altered Task To: " << TaskState << endl;
        } else {
            cout << "Invalid State Please Try Again" << endl;
        }
    } else {
        cout << "Item Not Found" << endl;
    }

}

//TRIGGERS THE CODE
int main() {
    string input;

    cout << "* Welcome To Josh's To Do List Generator and Editor! *" << endl << endl;
    cout << "If you have a list you want to load please press 'ENTER', if not type 'NO': ";
    getline (cin, input);

    if (input == "NO" || input == "no") {

    } else {
        loadList();
        cout << endl;
        for(auto i : toDoList)
            cout << i << " " << endl;
        cout << endl;
    }

    while (x = true) {
        getUserInput();

        if (Operation == "New List" || Operation == "new list") {
            createNewList();
        } else if (Operation == "Load List" || Operation == "load list") {
            loadList();
        } else if (Operation == "New Task" && z == true|| Operation == "new task" && z == true) {
            newTasks();
        } else if (Operation == "Delete Task" && z == true|| Operation == "delete task" && z == true) {
            deleteTask();
        } else if (Operation == "Task State" && z == true|| Operation == "task state" && z == true) {
            taskState();
        } else if (Operation == "Help" || Operation == "help") {
            cout << endl;
            cout << "New List: Creates a new list of tasks" << endl;
            cout << "Load List: Loads an old list of tasks from a file" << endl;
            cout << "New Task: Takes user input to add a new task" << endl;
            cout << "Delete Task: Deletes a task the user doesn't want anymore" << endl;
            cout << "Task State: Checks or unchecks a task whether completed or not" << endl;
        } else if (Operation == "Exit" || Operation == "exit") {
            cout << "Exiting Program" << endl;
            x = false;
            break;
        } else {
            cout << "Invalid Operation Please Try Again" << endl;
        }
    
    cout << endl;
    for(auto i : toDoList)
        cout << i << " " << endl;
    cout << endl;

    if (z == true) {
        cout << "Auto Saved File" << endl;

        ofstream file(fileName + ".txt");

        for (auto i : toDoList) {
            file << i << endl;
        }
    }
    std::this_thread::sleep_for(20ms);

    }
}