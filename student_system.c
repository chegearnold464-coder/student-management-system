#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50
#define UNITS 3

struct student {
    int admission_number;
    char name[50];
    float marks[UNITS];
    float average;
    
};
void register_student(struct student *s) {
    printf("\nEnter admission number: ");
    scanf("%d", &s->admission_number);

    getchar(); // Consume the newline character left by scanf

    printf("Enter student name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; // Remove newline character from name
    float total=0;
    for(int i=0; i<UNITS; i++) {
        printf("Enter marks for unit %d: ", i+1);
        scanf("%f", &s->marks[i]);
        total += s->marks[i];
    }
    s->average = total/UNITS;


    printf("\nStudent registered successfully!\n");
}

    void display_student(struct student *s) {
        printf("\n==============STUDENT REPORT================\n");
        printf("Admission Number: %d\n", s->admission_number);
        printf("Name: %s\n", s->name);
        printf("Average: %.2f\n", s->average);
    
        for(int i = 0; i < UNITS; i++) {
            printf("Marks for Unit %d: %.2f\n", i + 1, s->marks[i]);

        }

        printf("Average: %.2f\n", s->average);

        if(s->average >= 50) {
            printf("Result: Pass\n");
        } else {
            printf("Result: Fail\n");
        }

        printf("=========================================\n");
    }

    int main(){
        struct student students[MAX_STUDENTS];

        int count = 0;
        int choice;

        do{
            printf("\n============STUDENT MANAGEMENT SYSYEM============\n");
            printf("1. Register Student\n");
            printf("2. Display Student Report\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    if(count < MAX_STUDENTS) {
                        register_student(&students[count]);
                        count++;
                    } else {
                        printf("Maximum number of students reached!\n");
                    }
                    break;
                case 2:
                    if(count > 0) {
                        for(int i = 0; i < count; i++) {
                       display_student(&students[i]);
                        }
                    } else {
                        printf("No students registered yet!\n");
                    }
                    break;
                case 3:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } while(choice != 3);
    }
