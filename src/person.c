#include <stdio.h>
#include <string.h>
#include "person.h"

int compare_dates(Date d1, Date d2) {
    if (d1.year != d2.year)
        return d1.year - d2.year;
    if (d1.month != d2.month)
        return d1.month - d2.month;
    return d1.day - d2.day;
}

void find_youngest(Person *people, int count, int *youngest_index) {
    *youngest_index = 0;
    for (int i = 1; i < count; i++) {
        if (compare_dates(people[i].birth_date, people[*youngest_index].birth_date) > 0) {
            *youngest_index = i;
        }
    }
}

void print_person_info(Person *p) {
    printf("---------------------------------\n");
    printf("Surname: %s\n", p->surname);
    printf("Name: %s\n", p->name);
    printf("Patronymic: %s\n", p->patronymic);
    printf("Gender: %s\n", p->gender);
    printf("Nationality: %s\n", p->nationality);
    printf("Height: %.1f cm\n", p->height);
    printf("Weight: %.1f kg\n", p->weight);
    printf("Birth Date: %04d-%02d-%02d\n", 
           p->birth_date.year, p->birth_date.month, p->birth_date.day);
    printf("Phone: %s\n", p->phone);
    printf("Address:\n");
    printf("  Postal Code: %s\n", p->address.postal_code);
    printf("  Country: %s\n", p->address.country);
    printf("  Region: %s\n", p->address.region);
    printf("  District: %s\n", p->address.district);
    printf("  City: %s\n", p->address.city);
    printf("  Street: %s\n", p->address.street);
    printf("  House: %s\n", p->address.house);
    printf("  Apartment: %s\n", p->address.apartment);
}

void print_person_to_file(FILE *file, Person *p) {
    fprintf(file, "----------------------------------------\n");
    fprintf(file, "Surname: %s\n", p->surname);
    fprintf(file, "Name: %s\n", p->name);
    fprintf(file, "Patronymic: %s\n", p->patronymic);
    fprintf(file, "Gender: %s\n", p->gender);
    fprintf(file, "Nationality: %s\n", p->nationality);
    fprintf(file, "Height: %.1f cm\n", p->height);
    fprintf(file, "Weight: %.1f kg\n", p->weight);
    fprintf(file, "Birth Date: %04d-%02d-%02d\n", 
           p->birth_date.year, p->birth_date.month, p->birth_date.day);
    fprintf(file, "Phone: %s\n", p->phone);
    fprintf(file, "Address:\n");
    fprintf(file, "  Postal Code: %s\n", p->address.postal_code);
    fprintf(file, "  Country: %s\n", p->address.country);
    fprintf(file, "  Region: %s\n", p->address.region);
    fprintf(file, "  District: %s\n", p->address.district);
    fprintf(file, "  City: %s\n", p->address.city);
    fprintf(file, "  Street: %s\n", p->address.street);
    fprintf(file, "  House: %s\n", p->address.house);
    fprintf(file, "  Apartment: %s\n", p->address.apartment);
}
