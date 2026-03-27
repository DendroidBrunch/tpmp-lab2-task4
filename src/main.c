#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "file_io.h"

#define INPUT_FILE "data.txt"
#define OUTPUT_FILE "results.txt"

int main() {
    Person *people = NULL;
    int count = 0;
    int youngest_index = 0;
    if (create_sample_file(INPUT_FILE) != 0) {
        printf("Failed to create sample file. Exiting.\n");
        return 1;
    }
    if (display_file_contents(INPUT_FILE) != 0) {
        printf("Failed to display file contents.\n");
        return 1;
    }
    if (read_people_from_file(INPUT_FILE, &people, &count) != 0) {
        printf("Failed to read data from file.\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        printf("\nPerson #%d:\n", i + 1);
        print_person_info(&people[i]);
    }
    find_youngest(people, count, &youngest_index);
    print_person_info(&people[youngest_index]);
    if (save_results_to_file(OUTPUT_FILE, people, count, youngest_index) != 0) {
        printf("Failed to save results.\n");
        free(people);
        return 1;
    }
    if (display_file_contents(OUTPUT_FILE) != 0) {
        printf("Failed to display results file.\n");
    }
    free(people);
    return 0;
}
