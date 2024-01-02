# Student Management System with Binary File using Singly Linked List

This is a simple console-based Student Management System implemented in C, utilizing a singly linked list to manage student records. 
The system enables users to input, print, count, search, modify, delete, and sort student information.
Additionally, student data is persisted to a binary file (`stu.info`) for data retention between program runs.

## Features

- **Input Student Information**: Users can input student details, including student number, name, and score.
- **Print Student Information**: Displays the details of all students currently in the system.
- **Statistic Student Information**: Provides the total count of students in the system.
- **Search Student Information**: Enables searching for a specific student by their student number.
- **Modify Student Information**: Allows users to update the name and score of a particular student.
- **Delete Student Information**: Permits the removal of a student from the system based on their student number.
- **Sort Students by Score**: Sorts the list of students based on their scores in ascending order.
- **Data Persistence**: Student data is saved to a binary file (`stu.info`) to maintain records across program executions.


## File Structure
StudentSystemManager.h: Header file containing necessary structure and function declarations.
main.c: Main program file where the menu and user interactions are implemented.
stu.info: Binary file to store student data persistently.
## Note
The program utilizes dynamic memory allocation for nodes, providing flexibility in managing student records.
Binary file (stu.info) is used to store and load student information, ensuring data persistence.
