
#include <string.h>
#include <stdio.h>
#include "my_strlen.h"
#include "my_strncpy.h"

void test_mystrlen(void)
{
    printf("\n");
    printf("Test my_strlen.\n");
    char *test_string;

    test_string = "A very very very very very long string";
    if (strlen(test_string) != my_strlen(test_string))
        printf("\tTest 1: Failed");
    else
        printf("\tTest 1: Passed");
    printf("\n");

    test_string = "A short string";
    if (strlen(test_string) != my_strlen(test_string))
        printf("\tTest 2: Failed");
    else
        printf("\tTest 2: Passed");
    printf("\n");

    test_string = ""; // An empty string
    if (strlen(test_string) != my_strlen(test_string))
        printf("\tTest 3: Failed");
    else
        printf("\tTest 3: Passed");
    printf("\n");

    test_string = (char *)calloc(10, sizeof(char)); // A dynamic string
    if (strlen(test_string) != my_strlen(test_string))
        printf("\tTest 4: Failed");
    else
        printf("\tTest 4: Passed");
    free(test_string);
    printf("\n");
}

void test_mystrncpy(void)
{
    printf("\n");
    printf("Test my_strncpy.\n");
    char source[100];
    char destination[100];

    strcpy(source, "A very very very very very long string");
    my_strncpy(destination, source, strlen(source));
    destination[strlen(source)] = '\0';
    if (strcmp(source, destination))
        printf("\tTest 1: Failed");
    else
        printf("\tTest 1: Passed");
    printf("\n");

    strcpy(source, "A short string");
    my_strncpy(destination, source, strlen(source));
    destination[strlen(source)] = '\0';
    if (strcmp(source, destination))
        printf("\tTest 2: Failed");
    else
        printf("\tTest 2: Passed");
    printf("\n");

    strcpy(source, "String"); // Overlapping strings
    char *destination_overlap = source + 1;
    char source_perf[100];
    strcpy(source_perf, "String");
    char *destination_perf = source_perf + 1;
    strncpy(destination_perf, source_perf, 3);
    my_strncpy(destination_overlap, source, 3);
    if (strcmp(source_perf, source))
        printf("\tTest 3: Failed");
    else
        printf("\tTest 3: Passed");
    printf("\n");
}

int main()
{
    test_mystrlen();

    test_mystrncpy();

    return 0;
}