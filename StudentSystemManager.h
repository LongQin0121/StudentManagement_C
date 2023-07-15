# include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//student information

typedef struct Student{
    int stuNum;
    char name[20];
    int score;
} Student;


//NODE  information

typedef struct _Node{
    Student student;
   struct _Node * next;
} Node;

void welcome();
void inputStudent(Node * head);
void printStudent(Node * head);
void countStudent(Node * head);
void findStundent(Node * head);
void saveStudent(Node * head);
void loadStudent(Node * head);
void modifyStudent(Node * head);
void deleteStudent(Node *head);
void sortStudent(Node * head);