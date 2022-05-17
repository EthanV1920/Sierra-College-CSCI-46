#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int hp;
    char type[10];
} pokemon;

// Function prototypes
void printPokemon(const pokemon *p);
pokemon * searchPokedex(const char *t, pokemon dex[], int length);
pokemon * loadPokedex(char *filename, int *size);

int pcompare(const void *a, const void *b)
{
    int cmp = strcmp(((pokemon *)a)->name, ((pokemon *)b)->name);
    if (cmp == 0)
    {
        return ((pokemon *)a)->hp - ((pokemon *)b)->hp;
    }
    else
    {
        return cmp;
    }
}

int psearch(const void *t, const void *e)
{
    char *tt = (char *)t;
    pokemon *ee = (pokemon *)e;

    return strcmp(tt, ee->name);
}

int main(int argc, char *argv[])
{
    // Check number of command line args
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    // Load pokedex
    pokemon *pokedex;
    int count;
    pokedex = loadPokedex(argv[1], &count);

    // Sort pokedex by name
    qsort(pokedex, count, sizeof(pokemon), pcompare);

    // Print out pokedex
    for (int i = 0; i < count; i++)
    {
        printf("%d: ", i);
        printPokemon(&pokedex[i]);
        printf("\n");
    }

    char target[20];
    printf("Enter the name of a pokemon to find: ");
    fgets(target, 20, stdin);

    // Trim newline
    char *nl = strchr(target, '\n');
    if (nl) *nl = '\0';

    // Search for target pokemon
    //pokemon *found = searchPokedex(target, pokedex, count);
    pokemon *found = bsearch(target, pokedex, count, sizeof(pokemon), psearch);
    if (found)
    {
        printf("Found! ");
        printPokemon(found);
        printf("\n");
    }
    else
    {
        printf("Awww, didn't find it.\n");
    }
}

void printPokemon(const pokemon *p)
{
    printf("%s %d %s", p->name, p->hp, p->type);
}

// Given the name of a target pokemon to find,
// the array of pokemon to search through,
// and the length of the array,
// return the found pokemon or NULL.
pokemon * searchPokedex(const char *t, pokemon dex[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // Compare target name with name from pokedex
        if (strcmp(t, dex[i].name) == 0)
        {
            return &dex[i];
        }
    }
    return NULL;
}

pokemon *loadPokedex(char *filename, int *size)
{
    FILE *pf = fopen(filename, "r");
    if (!pf)
    {
        fprintf(stderr, "Can't open %s for reading: ", filename);
        perror(NULL);
        exit(1);
    }

    pokemon *pokedex = malloc(10 * sizeof(pokemon));
    int count = 0;

    char line[100];
    while(fgets(line, 100, pf) != NULL)
    {
        sscanf(line, "%[^,],%d,%s", pokedex[count].name, &pokedex[count].hp, pokedex[count].type);
        count++;
    }

    // Close pokemon file
    fclose(pf);

    // Return pokemon array
    *size = count;
    return pokedex;
}