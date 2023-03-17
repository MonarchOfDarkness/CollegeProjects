#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Employee {
    string name;
    int nKeysPossessed;
    string keys[5];
};

bool reader(string input_filename, Employee employees[], int& nEmployees) {
    
    ifstream infile(input_filename.c_str());
    
    if (!infile) {
        return false;
    }
    
    infile >> nEmployees;
    infile.ignore();
    
    for (int i = 0; i < nEmployees; i++) {
        getline(infile, employees[i].name);
        
        infile >> employees[i].nKeysPossessed;
        
        for (int j = 0; j < employees[i].nKeysPossessed; j++) {
            infile >> employees[i].keys[j];
        }
        
        infile.ignore();
    }
    infile.close();
    return true;
}

void writer(string output_filename, Employee employees[], int nEmployees) {
    ofstream outfile(output_filename);
    outfile << nEmployees << "\n";
    for (int i = 0; i < nEmployees; i++) {
        outfile << employees[i].name << "\n" << employees[i].nKeysPossessed << " ";
        for (int j = 0; j < employees[i].nKeysPossessed; j++) {
            outfile << employees[i].keys[j];
            if (j != employees[i].nKeysPossessed - 1) {
                outfile << " ";
                }
        }
        outfile << "\n";
    }
    outfile.close();
}

bool addKeyForEmployee(Employee employees[], int nEmployees, string emp_name, string newKey) {
    for (int i = 0; i < nEmployees; i++) {
        if (employees[i].name == emp_name) {
            if (employees[i].nKeysPossessed >= 5) {
                cout << "This employee already has 5 keys!\n" << endl;
                return false;
            }
            for (int j = 0; j < employees[i].nKeysPossessed; j++) {
                if (employees[i].keys[j] == newKey) {
                    cout << "This employee already has this key!\n" << endl;
                    return false;
                }
            }
            employees[i].keys[employees[i].nKeysPossessed++] = newKey;
            return true;
        }
    }
    cout << "Cannot find the specified employee!" << endl;
    return false;
}

bool returnAKey(Employee employees[], int nEmployees, string emp_name, string returnKey) {
    for (int i = 0; i < nEmployees; i++) {
        if (employees[i].name == emp_name) {
            for (int j = 0; j < employees[i].nKeysPossessed; j++) {
                if (employees[i].keys[j] == returnKey) {
                    employees[i].keys[j] = employees[i].keys[--employees[i].nKeysPossessed];
                    return true;
                }
            }
            cout << "This employee does not have the specified key!" << endl;
            return false;
        }
    }
    cout << "Cannot find the specified employee!" << endl;
    return false;
}


int main() {
    
    string keyFileName, outputFileName;
    
    string input_filename;
    Employee employees[100];
    int numOfEmployee;
    
    cout << "Please enter key file name to start: ";
    cin >> input_filename;

    bool fileExists = reader(input_filename, employees, numOfEmployee);
    
    if (!fileExists) {
        cout << "File not found, exiting the program..." << endl;
        return 1;
    }

    while (true) {
        cout << "Please select from the following options: " << endl;
        cout << "  1. show all employees and their keys" << endl;
        cout << "  2. show the keys an employee possesses" << endl;
        cout << "  3. show which employees possess a specific key" << endl;
        cout << "  4. add a key to an employee" << endl;
        cout << "  5. return a key by an employee" << endl;
        cout << "  6. save the current key status" << endl;
        cout << "  7. exit the program" << endl;

        int option;
        cin >> option;

        switch (option) {
            case 1:
            {
                for (int i = 0; i < numOfEmployee; i++) {
                    Employee emp = employees[i];
                    cout << "Name: " << emp.name << endl;
                    cout << "Keys possessed:";
                    for (int j = 0; j < emp.nKeysPossessed; j++) {
                        cout << " " << emp.keys[j];
                    }
                    cout << " ";
                    cout << endl;
                }
                cout << endl;
                break;
            }
                
            case 2: {
                
                cout << "Please enter employee's name: ";
                string emp_name;
                bool found = false;
                cin.ignore();
                getline(cin, emp_name);
                for(int i=0; i<numOfEmployee; i++) {
                    if (employees[i].name == emp_name){
                         cout << emp_name << " possess the following keys:";
                         for (int j = 0; j < employees[i].nKeysPossessed; j++) {
                            cout << " " << employees[i].keys[j];
                        }
                        cout << " ";
                        cout << endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                     cout << "Cannot find the specified employee!" << endl;
                }
                
                cout<<endl;
                break;
            }
            
            case 3:
            {
                string key;
                cout << "Please enter a key: ";
                cin.ignore();
                getline(cin, key);

                bool found = false;
                for (int i = 0; i < numOfEmployee; i++) {
                     Employee e = employees[i];
                     for (int j = 0; j < e.nKeysPossessed; j++) {
                          if (e.keys[j] == key) {
                               found = true;
                               cout << e.name << ", ";
                               break;
            }
        }
    }

    if (found) {
        cout << "possess this key." << endl;
    } else {
        cout << "No one possesses this key." << endl;
    }

    cout << endl;
    break;
            }
                
            case 4: {
                
                string name; 
                string key;
                bool found = false;
                
                cout << "Please enter employee's name: ";
                cin.ignore();
                getline(cin, name);
                
                for(int i=0; i<numOfEmployee; i++) {
                    if (employees[i].name == name){
                        cout << "Please enter a new key: ";
                        cin >> key;
                        bool success = addKeyForEmployee(employees, numOfEmployee, name, key);
                        if (success) {
                            cout << "Key added successfully." << endl << endl;
                        }
                        found = true;
                        break;
                    }
                }
                
                if(!found){
                     cout << "Cannot find the specified employee!" << endl << endl;
                }
                break;
            }
                
            case 5: {
                string emp_name, returnKey;
                cout << "Please enter employee's name: ";
                cin.ignore();
                getline(cin, emp_name);

                cout << "Please enter the returned key: ";
                cin >> returnKey;
                if(returnAKey(employees, numOfEmployee, emp_name, returnKey)){
                    cout<<"Key returned successfully." << endl;                    
                }
                cout<<endl;
                break;       
            }
                
            case 6:{
                    
                string outputFilename;
                cout << "Please enter output file name: ";
                cin >> outputFilename;
            
                // call writer function to write current key information to output file
                writer(outputFilename, employees, numOfEmployee);

                break;
                }
                

            case 7:
            {
                writer("keys_updated.txt", employees, numOfEmployee);                    
                    
                cout << "Thank you for using the system! Goodbye!" << endl;
                
                // exit the program
                exit(0);
                break;
            }
                
            default:
                cout<<"Not a valid option. Please try again.\n" << endl;
                    
        }
    }
}
