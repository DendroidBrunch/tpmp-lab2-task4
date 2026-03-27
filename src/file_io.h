#ifndef FILE_IO_H
#define FILE_IO_H

#include "person.h"

int create_sample_file(const char *filename);
int display_file_contents(const char *filename);
int read_people_from_file(const char *filename, Person **people, int *count);
int save_results_to_file(const char *filename, Person *people, int count, int youngest_index);

#endif
