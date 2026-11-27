#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int choice;
    char string_1[100], string_2[100], character, substring[50];
    char *pointer;

    while (1) {
        printf("\n===== String Operations Menu =====\n");
        printf("1. Find length (strlen)\n");
        printf("2. Copy string (strcpy)\n");
        printf("3. Concatenate strings (strcat)\n");
        printf("4. Compare strings (strcmp)\n");
        printf("5. Find character (strchr)\n");
        printf("6. Find substring (strstr)\n");
        printf("7. Tokenize string (strtok)\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n') { /* I don't like loops without a body*/ }
            continue;
        }
        (void)getchar();   // consume trailing newline; result intentionally discarded, compiler recommended :)

        switch (choice) {
            case 1: // Find length
                printf("Enter string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                printf("Length = %zu\n", strlen(string_1));
                break;

            case 2: // Copy string
                printf("Enter source string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                strcpy(string_2, string_1);
                printf("Copied string: %s\n", string_2);
                break;

            case 3: // Concatenate strings
                printf("Enter first string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                printf("Enter second string: ");
                fgets(string_2, sizeof(string_2), stdin);
                string_2[strcspn(string_2, "\n")] = '\0';
                strcat(string_1, string_2);
                printf("Concatenated string: %s\n", string_1);
                break;

            case 4: // Compare strings
                printf("Enter first string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                printf("Enter second string: ");
                fgets(string_2, sizeof(string_2), stdin);
                string_2[strcspn(string_2, "\n")] = '\0';
                int result = strcmp(string_1, string_2);
                if (result == 0) {
                    printf("Strings are equal.\n");
                } else if (result < 0) {
                    printf("First string is alphabetically smaller.\n");
                } else {
                    printf("First string is alphabetically greater.\n");
                }
                break;

            case 5: // Find character
                printf("Enter string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                printf("Enter character to find: ");
                scanf(" %c", &character);
                (void)getchar(); // Consume newline
                pointer = strchr(string_1, character);
                if (pointer != NULL) {
                    printf("Character '%c' found at index %ld.\n", character, pointer - string_1);
                } else {
                    printf("Character '%c' not found.\n", character);
                }
                break;

            case 6: // Find substring
                printf("Enter main string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                printf("Enter substring to find: ");
                fgets(substring, sizeof(substring), stdin);
                substring[strcspn(substring, "\n")] = '\0';
                pointer = strstr(string_1, substring);
                if (pointer != NULL) {
                    printf("Substring \"%s\" found at index %ld.\n", substring, pointer - string_1);
                } else {
                    printf("Substring \"%s\" not found.\n", substring);
                }
                break;

            case 7: // Tokenize string
                printf("Enter string to tokenize: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                printf("Enter delimiter(s) (e.g., space or comma): ");
                fgets(string_2, sizeof(string_2), stdin);
                string_2[strcspn(string_2, "\n")] = '\0';
                printf("Tokens:\n");
                pointer = strtok(string_1, string_2);
                while (pointer != NULL) {
                    printf(" - %s\n", pointer);
                    pointer = strtok(NULL, string_2);
                }
                break;

            case 8: // Convert to uppercase
                printf("Enter string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                for (int index = 0; string_1[index] != '\0'; index++) {
                    string_1[index] = toupper((unsigned char)string_1[index]);
                }
                printf("Uppercase string: %s\n", string_1);
                break;

            case 9: // Convert to lowercase
                printf("Enter string: ");
                fgets(string_1, sizeof(string_1), stdin);
                string_1[strcspn(string_1, "\n")] = '\0';
                for (int index = 0; string_1[index] != '\0'; index++) {
                    string_1[index] = tolower((unsigned char)string_1[index]);
                }
                printf("Lowercase string: %s\n", string_1);
                break;

            case 10: // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please select between 1 and 10.\n");
        }
    }

    return 0;
}
