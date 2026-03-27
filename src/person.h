#ifndef PERSON_H
#define PERSON_H

#define MAX_NAME_LEN 50
#define MAX_NATIONALITY_LEN 30
#define MAX_PHONE_LEN 20
#define MAX_ADDRESS_LEN 200
#define MAX_COUNTRY_LEN 30
#define MAX_REGION_LEN 30
#define MAX_DISTRICT_LEN 30
#define MAX_CITY_LEN 30
#define MAX_STREET_LEN 50

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char surname[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    char patronymic[MAX_NAME_LEN];
    char gender[10];
    char nationality[MAX_NATIONALITY_LEN];
    float height;
    float weight;
    Date birth_date;
    char phone[MAX_PHONE_LEN];
 
    struct {
        char postal_code[10];
        char country[MAX_COUNTRY_LEN];
        char region[MAX_REGION_LEN];
        char district[MAX_DISTRICT_LEN];
        char city[MAX_CITY_LEN];
        char street[MAX_STREET_LEN];
        char house[10];
        char apartment[10];
    } address;
} Person;

int compare_dates(Date d1, Date d2);
void find_youngest(Person *people, int count, int *youngest_index);
void print_person_info(Person *p);
void print_person_to_file(FILE *file, Person *p);

#endif
