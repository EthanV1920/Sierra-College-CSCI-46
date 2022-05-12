// Ethan Vosburg
// May 10, 2022

// As stated above, the overall functionality is similar to Warm-Up 7.1 with some key differences:

//     The main function will need to be declared using argc and argv: int main(int argc, char *argv[])
//     The strings will come from the command line via the argv array.
//     There is no need for the special DONE input; the program ends when the last argument from the command line is consumed.
//     The program should display the longer string as it is being built up to verify correct operation.

#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    char main_str[1000],
        main_str_temp[980],
        temp_str[20];
    char *temp_str_ptr = temp_str;
    // *strchr(argv, '\n') = '\0';

    strcat(main_str, argv[1]);
    strcat(main_str, " ");
    printf("%s\n", main_str);

    for(int i = 2; i<argc; i++){
        strcpy(temp_str, argv[i]);

        if(!strstr(main_str, temp_str)){
            if(strcmp(temp_str, main_str)>0){
                strcat(main_str, temp_str);
                strcat(main_str, " ");
            }
            if(strcmp(temp_str, main_str)<0){
                strcpy(main_str_temp, main_str);
                strcpy(main_str, temp_str);
                strcat(main_str, " ");
                strcat(main_str, main_str_temp);
            }
        }

        printf("%s\n", main_str);
    }
}

    