#include <stdio.h>
#include <string.h>

// Structure to store student details
struct Student {
    int id;
    char name[50];
    float marks;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

int main() {
    struct Student students[100];
    int count = 0, choice;

    do {
        // Menu options
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a student
void addStudent(struct Student students[], int *count) {
    printf("\nEnter Student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[*count].name); // To allow spaces in the name
    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

// Function to search for a student by ID
void searchStudent(struct Student students[], int count) {
    int id, found = 0;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student Found! ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}

// Function to delete a student by ID
void deleteStudent(struct Student students[], int *count) {
    int id, found = 0;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < (*count) - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with ID %d deleted successfully!\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}