#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  int PRN;
  int marks_in_subject_1;
  int marks_in_subject_2;
  int marks_in_subject_3;
  int total_marks;
  float percentage;
  char result[10];
};

void take_user_input(struct Student students[], int n) {

  for (int i = 0; i < n; i++) {

    printf("\nEnter details for student %d:\n", i + 1);

    printf("Enter name: ");
    scanf(" %49[^\n]", students[i].name);

    printf("Enter PRN: ");
    scanf("%d", &students[i].PRN);

    printf("Enter marks in subject 1: ");
    scanf("%d", &students[i].marks_in_subject_1);

    printf("Enter marks in subject 2: ");
    scanf("%d", &students[i].marks_in_subject_2);

    printf("Enter marks in subject 3: ");
    scanf("%d", &students[i].marks_in_subject_3);
  }
}

void calculate_result(struct Student students[], int n) {

  for (int i = 0; i < n; i++) {

    students[i].total_marks = students[i].marks_in_subject_1 +
                              students[i].marks_in_subject_2 +
                              students[i].marks_in_subject_3;

    students[i].percentage = students[i].total_marks / 3.0;

    if (students[i].marks_in_subject_1 >= 35 &&
        students[i].marks_in_subject_2 >= 35 &&
        students[i].marks_in_subject_3 >= 35) {

      strcpy(students[i].result, "PASS");

    } else {

      strcpy(students[i].result, "FAIL");
    }
  }
}

void display_result(struct Student students[], int n) {

  for (int i = 0; i < n; i++) {

    printf("\n===== Student Result =====\n");

    printf("Name: %s\n", students[i].name);
    printf("PRN: %d\n", students[i].PRN);

    printf("Subject 1 Marks: %d\n", students[i].marks_in_subject_1);
    printf("Subject 2 Marks: %d\n", students[i].marks_in_subject_2);
    printf("Subject 3 Marks: %d\n", students[i].marks_in_subject_3);

    printf("Total Marks: %d / 300\n", students[i].total_marks);
    printf("Percentage: %.2f%%\n", students[i].percentage);

    printf("Result: %s\n", students[i].result);
  }
}

int main() {

  int n;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  if (n < 1 || n > 100) {
    printf("Invalid number of students.\n");
    return EXIT_FAILURE;
  }

  struct Student students[100];

  take_user_input(students, n);

  calculate_result(students, n);

  display_result(students, n);

  return 0;
}
