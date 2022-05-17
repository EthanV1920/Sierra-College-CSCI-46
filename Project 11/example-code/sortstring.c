#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1000000

int ssearch_count = 0;
int scomp_count = 0;

char ** makeArray(int length);
void saveArray(char **a, int size);
void sortArray(char **a, int size);
char * linearSearch(char *t, char **a, int size);
int ssearch(const void *t, const void *e);

int scompare(const void *a, const void *b)
{
    scomp_count++;
    return strcmp(*(char **)a, *(char **)b);
}

int ssearch(const void *t, const void *e)
{
    ssearch_count++;
    char *tt = (char *)t;
    char **ee = (char **)e;

    return strcmp(tt, *ee);
}

int main()
{
    char ** arr = makeArray(LENGTH);
    //sortArray(arr, LENGTH);
    qsort(arr, LENGTH, sizeof(char *), scompare);
    saveArray(arr, LENGTH);
    printf("Sort comparisons: %d\n", scomp_count);

    char target[100];
    printf("What to find? ");
    scanf("%s", target);

    //char * found = linearSearch(target, arr, LENGTH);
    char **found = bsearch(target, arr, LENGTH, sizeof(char *), ssearch);
    printf("Search comparisons: %d\n", ssearch_count);
    if (found)
    {
        printf("Found: %s\n", *found);
    }
    else
    {
        printf("Didn't find it.\n");
    }
}

char ** makeArray(int length)
{
    // Allocate array of pointers to strings
    char **a = malloc(length * sizeof(char *));
    
    // Open rockyou file
    FILE *in = fopen("rockyou1m.txt", "r");
    if (!in)
    {
        fprintf(stderr, "Can't open rockyou file for reading: ");
        perror(NULL);
        exit(1);
    }

    // Fill array with strings
    for (int i = 0; i < length; i++)
    {
        char line[100];

        // Get a line from the file
        fgets(line, 100, in);

        // Trim newline
        char *nl = strchr(line, '\n');
        if (nl) *nl = '\0';

        // Allocate space for the string
        char *str = malloc(strlen(line) + 1);

        // Copy line into the new string
        strcpy(str, line);

        // Attach to array of strings
        a[i] = str;
    }

    // Close file
    fclose(in);

    // Return array
    return a;
}

void saveArray(char **a, int size)
{
    FILE *out = fopen("out.txt", "w");
    if (!out)
    {
        fprintf(stderr, "Can't open out.txt for writing: ");
        perror(NULL);
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(out, "%s\n", a[i]);
    }

    fclose(out);
}

void sortArray(char **a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (strcmp(a[j], a[j+1]) > 0)
            {
                char * temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


char * linearSearch(char *t, char **a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(a[i], t) == 0) return a[i];
    }

    return NULL;
}