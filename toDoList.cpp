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
string TaskState;
string file;
string fileData;
string fileName;
string line;
vector<string> toDoList;

bool w = false; //USED TO CHECK IF THE TASK EXISTS
bool x = true; //USED TO KEEP THE PROGRAM RUNNING
bool y = false; //USED TO CHECK IF A FILE IS ACTIVE
bool z = false; //USED TO MAKE SURE YOU CAN ONLY SAVE ONCE A FILE HAS BEEN OPENED

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
    fileName = Task;

    int s = Task.length();
    toDoList.push_back("Josh's " + Task + " List");

    if (s > 0) {
        cout << "Successfully Created: " << Task << endl;
        s--;
    } else {
        cout << "Invalid Name Please Try Again" << endl;
    }
    z = true;

}

//LOADS OLD LIST OF TASKS FROM FILE
void loadList() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);

    ifstream file(fileName + ".txt");

    if (!file.is_open()) {
        cout << "No File Found, Please Restart Program or Create New List" << endl;
        return;
    }

    while (std::getline(file, fileData)) 
        toDoList.push_back(fileData);
    
    cout << endl;
    for(auto i : toDoList)
        cout << i << " " << endl;

    cout << "Successfully Loaded: " << Task << endl;
    z = true;

}

//SAVES CURRENT LIST TO FILE
void saveList() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);

    ofstream file(Task + ".txt");

    cout << "Successfully Saved: " << Task << endl;
}

//TAKES USER INPUT TO ADD A NEW TASK
void newTasks() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);

    toDoList.push_back("☐  " + Task);
    cout << "Successfully Added To The List: " << Task << endl;

}

//DELETES A TASK THE USER DOSENT WANT ANYMORE
void deleteTask() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);

    auto it = std::find_if(toDoList.begin(), toDoList.end(), [&](const string& item) {
        return item.find(Task) != string::npos;
    });

    if (it != toDoList.end()) {
        toDoList.erase(it);
        cout << "Successfully Deleted From The List: " << Task << endl;
    } else {
        cout << "Item Not Found" << endl;
    }

}

//CHECKS OR UNCHECKS A TASK WHETHER COMPLETED OR NOT
void taskState() {

    //LET USER KNOW THE TASK IS PROCESSING
    cout << "Processing Task" << endl;
    std::this_thread::sleep_for(3s);

    auto it = std::find_if(toDoList.begin(), toDoList.end(), [&](const string& item) {
        return item.find(Task) != string::npos;
    });

    if (it != toDoList.end()) {
        cout << "What Is The Task State? (Completed or Not Done): ";
        getline (cin, TaskState);

        if (TaskState == "Completed"|| TaskState == "completed") {
            toDoList.erase(it);
            toDoList.push_back("☑  " + Task);
            cout << "Successfully Altered Task To: " << TaskState << endl;
        } else if (TaskState == "Not Done"|| TaskState == "not done") {
            toDoList.erase(it);
            toDoList.push_back("☐  " + Task);
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
    cout << "If you have a file you want to load please enter the name of the file, if not type 'NO': ";
    getline (cin, fileName);

    if (fileName != "NO" || fileName != "no") {
        loadList();
    }

    while (x = true) {
        getUserInput();

        if (Operation == "New List" || Operation == "new list") {
            createNewList();
        } else if (Operation == "Load List" || Operation == "load list") {
            loadList();
        } else if (Operation == "Save List" && z == true|| Operation == "save list" && z == true) {
            saveList();
        } else if (Operation == "New Task" || Operation == "new task") {
            newTasks();
        } else if (Operation == "Delete Task" || Operation == "delete task") {
            deleteTask();
        } else if (Operation == "Task State" || Operation == "task state") {
            taskState();
        } else if (Operation == "Help" || Operation == "help") {
            cout << "New List: Creates a new list of tasks" << endl;
            cout << "Load List: Loads an old list of tasks from a file" << endl;
            cout << "Save List: Saves the current list to a file" << endl;
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
    std::this_thread::sleep_for(20ms);

    }
}