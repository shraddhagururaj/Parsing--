#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("samplecsv.csv", "r");                           //open the csv file

    if (!fp) 
    {
        printf("Cannot open file!\n");
        return 0;
    }

    char buf[1024];                                                    //to store the data read from the file
    int row_count = 0;
    int field_count = 0;
    while (fgets(buf, 1024, fp)) 
    {
        field_count = 0;
        row_count++;

        if (row_count == 1) 
        {
            continue;                                                    //do not process header
        }

        char *read_field = strtok(buf, ",");
        while (read_field)
        {
            if (field_count == 0) 
            {
                printf("First Name:\t");
            }

            if (field_count == 1) 
            {
                printf("Last Name:\t");
            }

            if (field_count == 2) 
            {
                printf("Phone Number:\t");
            }
            if (field_count == 3)
            {
                printf("Job Title:\t");
            }

            printf("%s\n", read_field);                                    //print the comma separated values
            read_field = strtok(NULL, ",");

            field_count++;
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}
