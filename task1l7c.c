#include <stdio.h>
#include <string.h>

typedef struct Student {
    int id;        
    char name[50]; 
    float gpa;     
} Student;

void insert(Student student1[], int n){
    for(int i = 0; i < n; i++){
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &student1[i].id);

        printf("Enter Name for student %d: ", i + 1);
        getchar(); 
        scanf(" %[^\n]s", student1[i].name);

        printf("Enter GPA for student %d: ", i + 1);
        scanf("%f", &student1[i].gpa);
    }
}

void prints(Student student1[], int n){
    for (int i = 0; i < n; i++) {
        printf("\nStudent (%d)\n", i + 1);
        printf("ID: %d\n", student1[i].id);
        printf("Name: %s\n", student1[i].name); 
        printf("GPA: %.2f\n", student1[i].gpa);
    }
}

int main() {
    int n;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
  
    Student student1[n];

    insert(student1, n);
    prints(student1, n);

    return 0;
}


 
