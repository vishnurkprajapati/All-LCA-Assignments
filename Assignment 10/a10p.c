#include <stdio.h>

int is_leap_year(int year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int get_days(int month, int year) {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month == 2 && is_leap_year(year))
    return 29;

  return days[month - 1];
}

int main(void) {
  const char *months[] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};

  int year;

  printf("Enter year: ");
  if (scanf("%d", &year) != 1 || year < 1) {
    printf("Invalid year!\n");
    return 1;
  }

  long long previous_days = year - 1LL;

  int weekday = (previous_days * 365 + previous_days / 4 - previous_days / 100 +
                 previous_days / 400 + 1) %
                7;

  printf("\n          CALENDAR - %d\n", year);

  for (int month = 0; month < 12; month++) {
    int days = get_days(month + 1, year);

    printf("\n       %s\n", months[month]);
    printf(" Su Mo Tu We Th Fr Sa\n");

    for (int i = 0; i < weekday; i++)
      printf("   ");

    for (int day = 1; day <= days; day++) {
      printf("%3d", day);

      weekday = (weekday + 1) % 7;

      if (weekday == 0)
        printf("\n");
    }

    if (weekday != 0)
      printf("\n");
  }

  return 0;
}
