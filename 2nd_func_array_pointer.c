#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 50

typedef struct {
    int roll;
    char name[NAME_LEN];
    float marks;
} Student;

void inputStudent(Student *s, int index) {
    printf("\nStudent %d\n", index + 1);

    printf("Roll: ");
    scanf("%d", &s->roll);

    printf("Name: ");
    scanf(" %49[^\n]", s->name);

    printf("Marks: ");
    scanf("%f", &s->marks);
}

void printStudent(const Student *s) {
    printf("Roll: %d | Name: %s | Marks: %.2f\n", s->roll, s->name, s->marks);
}

float averageMarks(const Student *arr, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) sum += arr[i].marks;
    return n > 0 ? sum / n : 0.0f;
}

int main(void) {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid count.\n");
        return 1;
    }

    Student *students = (Student *)malloc(n * sizeof(Student));
    if (!students) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        inputStudent(&students[i], i);      // pass pointer to struct
        // Alternatively: inputStudent(students + i, i);
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < n; i++) {
        printStudent(&students[i]);         // pass pointer to const struct
    }

    printf("\nAverage marks: %.2f\n", averageMarks(students, n));

    free(students);
    return 0;
}




