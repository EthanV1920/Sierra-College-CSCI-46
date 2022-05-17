#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 100000

float *makeArray(int length);
void saveArray(float *a, int size);
void sortArray(float *a, int size);
int fcompare(const void *a, const void *b);
float * linearSearch(float t, float *a, int size);
int fsearch(const void *t, const void *e);

// Return 0 if *a == *b
// Return neg if *a < *b
// Return pos if *a > *b
int fcompare(const void *a, const void *b)
{
    return (*(float *)a - *(float *)b);
}

// Return 0 if *t == *e
// Return neg if *t < *e
// Return pos if *t > *e
int fsearch(const void *t, const void *e)
{
    return *(float *)t - *(float *)e;
}

int main()
{
    float *arr = makeArray(LENGTH);
    //sortArray(arr, LENGTH);
    qsort(arr, LENGTH, sizeof(float), fcompare);
    saveArray(arr, LENGTH);

    float target;
    printf("What to find? ");
    scanf("%f", &target);

    //float *found = linearSearch(target, arr, LENGTH);
    float *found = bsearch(&target, arr, LENGTH, sizeof(float), fsearch);
    if (found)
    {
        printf("Found: %f\n", *found);
    }
    else
    {
        printf("Didn't find it.\n");
    }
}

float *makeArray(int length)
{
    // Seed random number generator
    srandom(time(NULL));

    // Allocate array
    float *a = malloc(length * sizeof(float));

    // Fill array with random numbers
    for (int i = 0; i < length; i++)
    {
        a[i] = (float)(int)(random() / 10000.0);
    }

    // Return array
    return a;
}

void saveArray(float *a, int size)
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
        fprintf(out, "%f\n", a[i]);
    }

    fclose(out);
}

void sortArray(float *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                float temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

float * linearSearch(float t, float *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == t)
        {
            return &a[i];
        }
    }

    return NULL;
}