#include <iostream>
#include <string>
using namespace std;

// =====================================================
// STUDENT MANAGEMENT SYSTEM
// Using ARRAY + LINKED LIST
// =====================================================

const int MAX_STUDENTS = 100;

// =====================================================
// LINKED LIST NODE
// This stores EXTRA DATA / SUBJECT DETAILS
// =====================================================

struct Subject
{
    string subjectName;
    float marks;
    float attendance;

    Subject *next;
};

// =====================================================
// STUDENT STRUCTURE
// Main student information will be stored in ARRAY
// =====================================================

struct Student
{
    int rollNo;
    string name;
    string branch;
    int semester;

    string phone;
    string email;
    string address;

    float cgpa;

    // Pointer to linked list of subjects
    Subject *subjectHead;
};

// =====================================================
// ARRAY
// =====================================================

Student students[MAX_STUDENTS];

int studentCount = 0;

// =====================================================
// FIND STUDENT INDEX
// =====================================================

int findStudent(int rollNo)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == rollNo)
        {
            return i;
        }
    }

    return -1;
}

// =====================================================
// ADD STUDENT
// =====================================================

void addStudent()
{
    if (studentCount >= MAX_STUDENTS)
    {
        cout << "\nStudent limit reached!\n";
        return;
    }

    Student s;

    cout << "\n====================================\n";
    cout << "          ADD NEW STUDENT\n";
    cout << "====================================\n";

    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    // Check duplicate roll number
    if (findStudent(s.rollNo) != -1)
    {
        cout << "\nThis Roll Number already exists!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter Branch: ";
    getline(cin, s.branch);

    cout << "Enter Semester: ";
    cin >> s.semester;

    cin.ignore();

    cout << "Enter Phone Number: ";
    getline(cin, s.phone);

    cout << "Enter Email: ";
    getline(cin, s.email);

    cout << "Enter Address: ";
    getline(cin, s.address);

    cout << "Enter CGPA: ";
    cin >> s.cgpa;

    // Initially no subject
    s.subjectHead = NULL;

    // Store student in array
    students[studentCount] = s;

    studentCount++;

    cout << "\n====================================\n";
    cout << " Student added successfully!\n";
    cout << "====================================\n";
}

// =====================================================
// DISPLAY SUBJECT LINKED LIST
// =====================================================

void displaySubjects(Subject *head)
{
    if (head == NULL)
    {
        cout << "\nNo extra/subject data available.\n";
        return;
    }

    Subject *temp = head;

    cout << "\n----------- SUBJECT DETAILS -----------\n";

    int number = 1;

    while (temp != NULL)
    {
        cout << "\nSubject " << number << endl;
        cout << "Subject Name : " << temp->subjectName << endl;
        cout << "Marks        : " << temp->marks << endl;
        cout << "Attendance   : " << temp->attendance << "%" << endl;

        temp = temp->next;
        number++;
    }

    cout << "---------------------------------------\n";
}

// =====================================================
// DISPLAY ONE STUDENT
// =====================================================

void displayOneStudent(Student &s)
{
    cout << "\n====================================\n";
    cout << "          STUDENT DETAILS\n";
    cout << "====================================\n";

    cout << "Roll Number : " << s.rollNo << endl;
    cout << "Name        : " << s.name << endl;
    cout << "Branch      : " << s.branch << endl;
    cout << "Semester    : " << s.semester << endl;

    cout << "Phone       : " << s.phone << endl;
    cout << "Email       : " << s.email << endl;
    cout << "Address     : " << s.address << endl;

    cout << "CGPA        : " << s.cgpa << endl;

    // Display linked list data
    displaySubjects(s.subjectHead);

    cout << "====================================\n";
}

// =====================================================
// DISPLAY ALL STUDENTS
// =====================================================

void displayAllStudents()
{
    if (studentCount == 0)
    {
        cout << "\nNo student records available!\n";
        return;
    }

    cout << "\n\n====================================\n";
    cout << "        ALL STUDENT RECORDS\n";
    cout << "====================================\n";

    for (int i = 0; i < studentCount; i++)
    {
        displayOneStudent(students[i]);
    }
}

// =====================================================
// SEARCH STUDENT
// =====================================================

void searchStudent()
{
    int rollNo;

    cout << "\nEnter Roll Number to search: ";
    cin >> rollNo;

    int index = findStudent(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    cout << "\nStudent found successfully!\n";

    displayOneStudent(students[index]);
}

// =====================================================
// UPDATE STUDENT
// =====================================================

void updateStudent()
{
    int rollNo;

    cout << "\nEnter Roll Number to update: ";
    cin >> rollNo;

    int index = findStudent(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    Student &s = students[index];

    cin.ignore();

    cout << "\nEnter New Name: ";
    getline(cin, s.name);

    cout << "Enter New Branch: ";
    getline(cin, s.branch);

    cout << "Enter New Semester: ";
    cin >> s.semester;

    cin.ignore();

    cout << "Enter New Phone Number: ";
    getline(cin, s.phone);

    cout << "Enter New Email: ";
    getline(cin, s.email);

    cout << "Enter New Address: ";
    getline(cin, s.address);

    cout << "Enter New CGPA: ";
    cin >> s.cgpa;

    cout << "\nStudent details updated successfully!\n";
}

// =====================================================
// ADD EXTRA DATA / SUBJECT
// =====================================================

void addSubject()
{
    int rollNo;

    cout << "\nEnter Student Roll Number: ";
    cin >> rollNo;

    int index = findStudent(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    // Create new linked-list node
    Subject *newSubject = new Subject;

    cin.ignore();

    cout << "Enter Subject Name: ";
    getline(cin, newSubject->subjectName);

    cout << "Enter Marks: ";
    cin >> newSubject->marks;

    cout << "Enter Attendance (%): ";
    cin >> newSubject->attendance;

    newSubject->next = NULL;

    // -------------------------------------------------
    // Insert at end of linked list
    // -------------------------------------------------

    if (students[index].subjectHead == NULL)
    {
        students[index].subjectHead = newSubject;
    }
    else
    {
        Subject *temp = students[index].subjectHead;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSubject;
    }

    cout << "\nSubject/extra data added successfully!\n";
}

// =====================================================
// DELETE SUBJECT / EXTRA DATA
// =====================================================

void deleteSubject()
{
    int rollNo;

    cout << "\nEnter Student Roll Number: ";
    cin >> rollNo;

    int index = findStudent(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    if (students[index].subjectHead == NULL)
    {
        cout << "\nNo subject data available!\n";
        return;
    }

    cin.ignore();

    string subjectName;

    cout << "Enter Subject Name to delete: ";
    getline(cin, subjectName);

    Subject *temp = students[index].subjectHead;
    Subject *previous = NULL;

    // Search subject
    while (temp != NULL &&
           temp->subjectName != subjectName)
    {
        previous = temp;
        temp = temp->next;
    }

    // Subject not found
    if (temp == NULL)
    {
        cout << "\nSubject not found!\n";
        return;
    }

    // If first node
    if (previous == NULL)
    {
        students[index].subjectHead = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    delete temp;

    cout << "\nSubject deleted successfully!\n";
}

// =====================================================
// DELETE STUDENT
// =====================================================

void deleteStudent()
{
    int rollNo;

    cout << "\nEnter Roll Number to delete: ";
    cin >> rollNo;

    int index = findStudent(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    // -------------------------------------------------
    // First delete all linked-list subject nodes
    // -------------------------------------------------

    Subject *temp = students[index].subjectHead;

    while (temp != NULL)
    {
        Subject *deleteNode = temp;

        temp = temp->next;

        delete deleteNode;
    }

    // -------------------------------------------------
    // Shift array elements
    // -------------------------------------------------

    for (int i = index; i < studentCount - 1; i++)
    {
        students[i] = students[i + 1];
    }

    studentCount--;

    cout << "\nStudent deleted successfully!\n";
}

// =====================================================
// DISPLAY SUBJECTS OF PARTICULAR STUDENT
// =====================================================

void showStudentSubjects()
{
    int rollNo;

    cout << "\nEnter Student Roll Number: ";
    cin >> rollNo;

    int index = findStudent(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    cout << "\nStudent Name: "
         << students[index].name << endl;

    displaySubjects(students[index].subjectHead);
}

// =====================================================
// MAIN MENU
// =====================================================

int main()
{
    int choice;

    while (true)
    {
        cout << "\n\n";
        cout << "================================================\n";
        cout << "          STUDENT MANAGEMENT SYSTEM\n";
        cout << "================================================\n";

        cout << "\n1.  Add Student";
        cout << "\n2.  Display All Students";
        cout << "\n3.  Search Student";
        cout << "\n4.  Update Student";
        cout << "\n5.  Delete Student";

        cout << "\n\n--- EXTRA DATA / LINKED LIST ---";

        cout << "\n6.  Add Subject / Extra Data";
        cout << "\n7.  Display Student's Subjects";
        cout << "\n8.  Delete Subject";

        cout << "\n\n9.  Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayAllStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            addSubject();
            break;

        case 7:
            showStudentSubjects();
            break;

        case 8:
            deleteSubject();
            break;

        case 9:
            cout << "\nThank you for using Student Management System!\n";
            return 0;

        default:
            cout << "\nInvalid choice! Please enter 1-9.\n";
        }
    }

    return 0;
}