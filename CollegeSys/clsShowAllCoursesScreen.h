#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "clsCourse.h"
#include "clsInputValidate.h"
using namespace std;

class clsShowAllCoursesScreen
{
private:
    // Function to print a single course row
    static void PrintCourse(clsCourse& course) {
        cout << "| " << setw(25) << left << course.CourseName
            << "| " << setw(15) << left << course.CourseHours;

        // Print up to 3 prerequisites, ensuring correct alignment
        for (int i = 0; i < 3; i++) {
            if (i < course.CoursePreq.size()) {
                cout << "| " << setw(25) << left << course.CoursePreq[i];
            }
            else {
                cout << "| " << setw(20) << left << " "; // Empty space for missing prerequisites
            }
        }

        cout << "\n";
    }
public:
    // Function to display all courses in a well-formatted table
    static void ShowAllCourses() {
        vector<clsCourse> vCourses = clsCourse::GetAllCourses();

        cout << "\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------\n";
        cout << "| " << setw(25) << left << "Course Name"
            << "| " << setw(15) << left << "Course Hours"
            << "| " << setw(25) << left << "Prerequisite 1"
            << "| " << setw(25) << left << "Prerequisite 2"
            << "| " << setw(25) << left << "Prerequisite 3"
            << "\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------\n";

        for (clsCourse& course : vCourses) {
            PrintCourse(course);
        }

        cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    }

};

