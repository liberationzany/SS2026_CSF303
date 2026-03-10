#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int digitSum(int n) {
    if (n < 0) n = -n;
    int sum = 0; 
    while (n > 0) {
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countVowels(string s) {
    int count = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = (char)tolower((unsigned char)s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

string reverseString(string s) {
    string out = "";
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        out = out + s[i];
    }
    return out;
}

string toUpper(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
    return s;
}

string toLower(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = (char)tolower((unsigned char)s[i]);
    }
    return s;
}

string getInitials(string name) {
    string initials = "";
    bool start = true;
    for (int i = 0; i < (int)name.size(); i++) {
        if (name[i] == ' ') {
            start = true;
        } else if (start) {
            initials = initials + name[i] + ".";
            start = false;
        }
    }
    return initials;
}

int firstNameLength(string name) {
    int len = 0;
    for (int i = 0; i < (int)name.size(); i++) {
        if (name[i] == ' ') break;
        len++;
    }
    return len;
}

class Student {
private:
    string name;
    int studentNumber;
    vector<float> marks;

public:
    Student(string n, int sn) {
        name = n;
        studentNumber = sn;
    }

    void addMark(float m) {
        marks.push_back(m);
    }

    float getAverage() {
        if (marks.size() == 0) return 0;
        float sum = 0;
        for (int i = 0; i < (int)marks.size(); i++) {
            sum = sum + marks[i];
        }
        return sum / (float)marks.size();
    }

    float getHighest() {
        if (marks.size() == 0) return 0;
        float high = marks[0];
        for (int i = 1; i < (int)marks.size(); i++) {
            if (marks[i] > high) high = marks[i];
        }
        return high;
    }

    float getLowest() {
        if (marks.size() == 0) return 0;
        float low = marks[0];
        for (int i = 1; i < (int)marks.size(); i++) {
            if (marks[i] < low) low = marks[i];
        }
        return low;
    }

    string getClassification() {
        float avg = getAverage();
        if (avg >= 75) return "Distinction";
        if (avg >= 60) return "Merit";
        if (avg >= 40) return "Pass";
        return "Fail";
    }

    void printReport() {
        cout << "================================================" << endl;
        cout << "ACADEMIC REPORT" << endl;
        cout << "================================================" << endl;
        cout << "Student Name : " << name << endl;
        cout << "Student No : " << studentNumber << endl;
        cout << "Marks Entered : " << marks.size() << endl;
        cout << "Marks : ";
        for (int i = 0; i < (int)marks.size(); i++) {
            cout << marks[i] << ' ';
        }
        cout << endl;
        cout << "Average : " << getAverage() << endl;
        cout << "Highest : " << getHighest() << endl;
        cout << "Lowest : " << getLowest() << endl;
        cout << "Classification: " << getClassification() << endl;
        cout << "================================================" << endl;
    }
};

int main() {
    const int CURRENT_YEAR = 2026;

    string fullName = "Tenzin Wangchuk";
    string firstName = "Tenzin";
    int studentNumber = 20240101;
    string course = "BSc Computer Science";

    // Q01 Personal Introduction
    cout << "=============================" << endl;
    cout << "Student Profile" << endl;
    cout << "=============================" << endl;
    cout << "Name : " << fullName << endl;
    cout << "Student No : " << studentNumber << endl;
    cout << "Course : " << course << endl;
    cout << "=============================" << endl << endl;

    // Q02 Arithmetic with Student Number
    cout << "Student Number : " << studentNumber << endl;
    cout << "Digit Sum : " << digitSum(studentNumber) << endl;
    if (studentNumber % 2 == 0) cout << "Odd / Even : Even" << endl;
    else cout << "Odd / Even : Odd" << endl;
    cout << "Remainder (% 7) : " << (studentNumber % 7) << endl;
    cout << "Multiplied by 3 : " << (studentNumber * 3) << endl;
    cout << endl;

    // Q03 String Manipulation & Analysis
    cout << "Full Name : " << fullName << endl;
    cout << "Total Length : " << fullName.size() << endl;
    cout << "Uppercase : " << toUpper(fullName) << endl;
    cout << "Lowercase : " << toLower(fullName) << endl;
    cout << "Initials : " << getInitials(fullName) << endl;
    cout << "First Name Len : " << firstNameLength(fullName) << endl;
    cout << endl;

    // Q04 User Input & Type Conversion
    string inputName;
    int inputStudentNo = 0;
    int age = 0;
    cout << "Enter your name : ";
    getline(cin, inputName);
    cout << "Enter student number : ";
    cin >> inputStudentNo;
    cout << "Enter your age : ";
    cin >> age;
    int yearOfBirth = CURRENT_YEAR - age;
    int yearAt100 = yearOfBirth + 100;
    cout << "----------------------------------------" << endl;
    cout << "Summary" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Name : " << inputName << endl;
    cout << "Student No : " << inputStudentNo << endl;
    cout << "Year of Birth : " << yearOfBirth << endl;
    cout << "Year at Age 100: " << yearAt100 << endl;
    cout << endl;

    // Q05 Conditional Grade Classification
    float mark = 0;
    cout << "Enter mark: ";
    cin >> mark;
    cout << "----------------------------------------" << endl;
    if (mark < 0 || mark > 100) {
        cout << "Error: mark must be between 0 and 100." << endl;
    } else {
        string grade;
        if (mark >= 75) grade = "Distinction";
        else if (mark >= 60) grade = "Merit";
        else if (mark >= 40) grade = "Pass";
        else grade = "Fail";
        cout << "Student : " << fullName << " (" << studentNumber << ")" << endl;
        cout << "Mark : " << mark << endl;
        cout << "Grade : " << grade << endl;
        if (grade == "Fail") cout << "Result : Sorry, " << firstName << ". You have failed." << endl;
        else cout << "Result : Congratulations, " << firstName << "! You have passed." << endl;
    }
    cout << "----------------------------------------" << endl << endl;

    // Q06 Loop-Based Pattern Generation
    cout << "Name repeated (" << firstName.size() << " times):" << endl;
    for (int i = 0; i < (int)firstName.size(); i++) {
        cout << firstName << endl;
    }
    cout << "Triangle (height = " << fullName.size() << "):" << endl;
    for (int i = 1; i <= (int)fullName.size(); i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    int lastDigit = studentNumber % 10;
    if (lastDigit < 0) lastDigit = -lastDigit;
    cout << "Times Table for " << lastDigit << " (last digit of " << studentNumber << "):" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << lastDigit << " x " << i << " = " << (lastDigit * i) << endl;
    }
    cout << endl;

    // Q07 Array Operations & Statistics
    int tenzin_marks[5] = {85, 72, 90, 65, 78};
    cout << "Student: " << fullName << " | No: " << studentNumber << endl;
    cout << "------------------------------------------" << endl;
    cout << "Index Mark Bar" << endl;
    int highest = tenzin_marks[0];
    int lowest = tenzin_marks[0];
    int total = 0;
    for (int i = 0; i < 5; i++) {
        int markVal = tenzin_marks[i];
        if (markVal > highest) highest = markVal;
        if (markVal < lowest) lowest = markVal;
        total = total + markVal;
        cout << "[" << i << "] " << markVal << " ";
        for (int s = 0; s < markVal / 10; s++) {
            cout << "*";
        }
        cout << endl;
    }
    double avg = (double)total / 5.0;
    int aboveAvg = 0;
    for (int i = 0; i < 5; i++) {
        if (tenzin_marks[i] > avg) aboveAvg++;
    }
    cout << "------------------------------------------" << endl;
    cout << "Highest : " << highest << endl;
    cout << "Lowest : " << lowest << endl;
    cout << "Average : " << fixed << setprecision(2) << avg << endl;
    cout << "Above Average: " << aboveAvg << " mark(s)" << endl;
    cout << endl;

    // Q08 Function Design & Modular Programming
    cout << "========================================" << endl;
    cout << "Function Results for " << fullName << endl;
    cout << "Student No: " << studentNumber << endl;
    cout << "========================================" << endl;
    cout << "digitSum(" << studentNumber << ") : " << digitSum(studentNumber) << endl;
    cout << "isPrime(" << studentNumber << ") : " << (isPrime(studentNumber) ? "Yes" : "No") << endl;
    cout << "countVowels(" << fullName << ") : " << countVowels(fullName) << endl;
    cout << "reverseString(" << fullName << "): " << reverseString(fullName) << endl;
    cout << "========================================" << endl << endl;

    // Q09 Vector & Dynamic Collections
    vector<int> v20240101;
    cout << "Enter 6 values: ";
    for (int i = 0; i < 6; i++) {
        int val;
        cin >> val;
        v20240101.push_back(val);
    }
    cout << "Original : ";
    for (int i = 0; i < (int)v20240101.size(); i++) {
        cout << v20240101[i] << ' ';
    }
    cout << endl;
    // simple bubble sort
    for (int i = 0; i < (int)v20240101.size(); i++) {
        for (int j = 0; j < (int)v20240101.size() - 1; j++) {
            if (v20240101[j] > v20240101[j + 1]) {
                int temp = v20240101[j];
                v20240101[j] = v20240101[j + 1];
                v20240101[j + 1] = temp;
            }
        }
    }
    cout << "Sorted : ";
    for (int i = 0; i < (int)v20240101.size(); i++) {
        cout << v20240101[i] << ' ';
    }
    cout << endl;
    int minVal = v20240101[0];
    int maxVal = v20240101[0];
    int sumVal = 0;
    for (int i = 0; i < (int)v20240101.size(); i++) {
        if (v20240101[i] < minVal) minVal = v20240101[i];
        if (v20240101[i] > maxVal) maxVal = v20240101[i];
        sumVal = sumVal + v20240101[i];
    }
    double avgVal = (double)sumVal / v20240101.size();
    cout << "Min : " << minVal << endl;
    cout << "Max : " << maxVal << endl;
    cout << "Sum : " << sumVal << endl;
    cout << "Average : " << fixed << setprecision(2) << avgVal << endl;
    cout << "After removing below average:" << endl;
    for (int i = 0; i < (int)v20240101.size(); i++) {
        if (v20240101[i] >= avgVal) cout << v20240101[i] << ' ';
    }
    cout << endl << endl;

    // Q10 Classes & Object-Oriented Design
    Student student(fullName, studentNumber);
    student.addMark(88);
    student.addMark(76);
    student.addMark(91);
    student.addMark(65);
    student.addMark(83);
    student.printReport();

    return 0;
}