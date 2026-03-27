#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "person.h"

int create_sample_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file %s\n", filename);
        return -1;
    }
    fprintf(file, "Ivanov Ivan Ivanovich Male Russian 185.5 85.5 1990 5 15 +79101234567 123456 Russia Moscow Region Moscow District Moscow Lenina Street 15 45\n");
    fprintf(file, "Petrova Anna Sergeevna Female Russian 170.0 60.0 1995 8 22 +79207654321 234567 Russia Leningrad Region St. Petersburg District St. Petersburg Nevsky Street 25 78\n");
    fprintf(file, "Smith John William Male American 180.0 75.0 1988 3 10 +79301112233 345678 USA California Los Angeles County Los Angeles Hollywood Blvd 100 200\n");
    fprintf(file, "Kuznetsova Maria Dmitrievna Female Russian 165.0 55.0 2000 12 1 +79409998877 456789 Russia Moscow Region Moscow District Moscow Tverskaya Street 10 5\n");
    fprintf(file, "Lee David Michael Male Chinese 175.0 70.0 1992 7 18 +79504445566 567890 China Beijing Beijing Beijing Chaoyang District Chang'an Avenue 50 300\n"); 
    fclose(file);
    printf("Sample file '%s' created successfully.\n", filename);
    return 0;
}

int display_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    printf("\nFile Contents: %s\n", filename);
    int line_num = 1;
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", line_num++, line);
    }
    fclose(file);
    return 0;
}

int read_people_from_file(const char *filename, Person **people, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s for reading\n", filename);
        return -1;
    }
    int lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') lines++;
    }
    if (lines > 0) lines++;
    rewind(file);
    *people = (Person *)malloc(lines * sizeof(Person));
    *count = 0;
    while (fscanf(file, "%49s %49s %49s %9s %29s %f %f %d %d %d %19s %9s %29s %29s %29s %29s %49s %9s %9s",
                  (*people)[*count].surname,
                  (*people)[*count].name,
                  (*people)[*count].patronymic,
                  (*people)[*count].gender,
                  (*people)[*count].nationality,
                  &(*people)[*count].height,
                  &(*people)[*count].weight,
                  &(*people)[*count].birth_date.year,
                  &(*people)[*count].birth_date.month,
                  &(*people)[*count].birth_date.day,
                  (*people)[*count].phone,
                  (*people)[*count].address.postal_code,
                  (*people)[*count].address.country,
                  (*people)[*count].address.region,
                  (*people)[*count].address.district,
                  (*people)[*count].address.city,
                  (*people)[*count].address.street,
                  (*people)[*count].address.house,
                  (*people)[*count].address.apartment) == 19) {
        (*count)++;
    }
    fclose(file);
    return 0;
}

int save_results_to_file(const char *filename, Person *people, int count, int youngest_index) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "The youngest person is:\n");
    print_person_to_file(file, &people[youngest_index]);
    fclose(file);
    printf("\nResults saved to '%s'\n", filename);
    return 0;
}
