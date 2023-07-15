#include "StudentSystemManager.h"

int main(){
    //Create a dummy node
    Node * head = malloc(sizeof(Node));
    head->next = NULL;
    loadStudent(head);
    while(1){
        welcome();
        printf("Input your choice:\n");
        char c = _getch();  //scanf()   getchar()   get the enter

        switch(c){
            case '1':     //Input student information!
                inputStudent(head);
                break; 
            case '2':
                printStudent(head);
                break; 
            case '3':
                countStudent(head);
                break;
            case '4': 
                findStundent(head);
                break; 
            case '5':
                modifyStudent(head);
                break; 
            case '6': 
                deleteStudent(head);
                break;
            case '7': 
                sortStudent(head);
                break; 
            case '8':
                system("cls");
                printf("Bye Bye!\n");
                return 0;
                break;
            default:
                printf("Please enter valid number.\n");
                break;
        }
    }
    return 0;
}

void welcome(){
    printf("************************************************\n");
    printf("*\tSTUDENT SCORE MANAGEMENT SYSTEM\t\t*\n");
    printf("************************************************\n");
    printf("*\tPlease choose function list:\t\t*\n");
    printf("************************************************\n");
    printf("* \t1.Input student information\t\t*\n");
    printf("* \t2.Print student information\t\t*\n");
    printf("* \t3.Statistic student information\t\t*\n"); 
    printf("* \t4.Search student information\t\t*\n"); 
    printf("* \t5.Modify student information\t\t*\n");
    printf("* \t6.Delete student information\t\t*\n"); 
    printf("* \t7.Sort student based on score\t\t*\n"); 
    printf("* \t8.Exit the System\t\t\t*\n");
    printf("************************************************\n");    
}

void inputStudent(Node * head){
  Node * fresh =  malloc(sizeof(Node));
  fresh ->next = NULL;
  printf("Please input the NUMBER ,NAME ,SCORE of the student:\n");
  scanf("%d%s%d",&fresh->student.stuNum,fresh ->student.name,&fresh->student.score);
  
  Node * move = head;
  while(move->next != NULL){
    move = move->next;
  }
//append to the tail,first come ,first service
    move->next = fresh;

    saveStudent(head);
    //pause the program
   system("pause");
    //clear console
    system("cls");
}

void printStudent(Node * head){
    Node * move = head ->next;
    while(move != NULL){
        printf("Number:%d Name:%s Score:%d \n",move->student.stuNum,move->student.name,move->student.score);
        move = move->next;
    }
    system("pause");
    system("cls");
}

void countStudent(Node * head){
    int count = 0;
    Node *move = head ->next;
    while(move != NULL){
        count++;
        move = move->next;
    }
    printf("The total number of student is %d\n",count);
    system("pause");
   // system("cls");
}

void findStundent(Node * head){
    printf("Please intput the NO. of the student:\n");
    int stuNum_d;
    scanf("%d",&stuNum_d);
    Node *move = head->next;
    while(move != NULL){

        if(stuNum_d == move ->student.stuNum){
            printf("NO. is %d Name is %s Score is %d\n",move->student.stuNum,move->student.name,move->student.stuNum);
            system("pause");
            system("cls");
            return; // not break
        }
        move = move->next;
    }
    printf("NOT FOUND INFORAMTION OF THIS STUDENT\n");
    system("pause");
    system("cls");
}

void saveStudent(Node * head){
    //open the file
    FILE * file = fopen("./stu.info","w");   //rewrite next time;
    if(file == NULL){
        printf("Open file failed!\n");
        return;
    }
    Node * move = head->next;

    while(move != NULL){
        //write the struct into the file
        if(fwrite(&move->student,sizeof(Student),1,file)!=1){
            printf("Write Failure\n");
            return ;
        }
        move = move ->next;
    }
    fclose(file);     
}

void loadStudent(Node * head){
    FILE * file = fopen("./stu.info","r");
    if(!file){
        printf("NOT FOUND FILE,SKIP READING!\n");
        return;
    }   
    //create a new node
    Node * fresh = malloc(sizeof(Node));
    fresh->next = NULL;
    Node * move = head;
    while(fread(& fresh->student,sizeof(Student),1,file)==1){
        move->next = fresh;
        move = fresh;
        fresh = malloc(sizeof(Node));
        fresh ->next =NULL;
    }
    free(fresh);
    fclose(file);
    printf("\tRead is successful\t\n"); 
}

void modifyStudent(Node * head){
    printf("Please input the NO. of the student that  you wannt to modify.");
    int No;
    scanf("%d",&No);
    Node * move = head->next;
    while(move != NULL){
        if(move->student.stuNum == No){
            printf("Please enter student name ,score\n");
            scanf("%s%d",&move->student.name,&move->student.score);
            saveStudent(head);
            printf("Modify Success");
            system("pause");
            system("cls");
            return;
        }
        move = move->next;
    }
    printf("Not Found student information");
    system("pause");
    system("cls");
}

void deleteStudent(Node *head){
    printf("Please enter the No of the student you wanna delete");
    int No = 0;
    scanf("%d",&No);

    Node * move = head;
    while(move->next != NULL){
        if(move->next->student.stuNum == No){
            Node * temp = move->next;
            move->next = move->next->next;
            free(temp);
            temp = NULL;
            saveStudent(head);
            printf("Delete success\n");
            system("pause");
            system("cls");
            return;
        }
        move = move->next;
    }
}

void sortStudent(Node * head){

    if (head == NULL || head->next == NULL) {
        // No need to sort an empty list or a list with only one node
        return;
    }

    Node* turn;
    Node* move;
    Student temp;

    for (turn = head->next; turn->next != NULL; turn = turn->next) {
        for (move = turn->next; move != NULL; move = move->next) {
            if (turn->student.score > move->student.score) {
                // Swap the students' data
                temp = move->student;
                move->student = turn->student;
                turn->student = temp;
            }
        }    
    }
    printf("Here is the sorted student based on score\n");
    printStudent(head);
}

