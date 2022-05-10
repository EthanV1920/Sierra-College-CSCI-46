// Ethan Vosburg
// May 5, 2022

// The user input is compared to the longer string and then takes action as follows:

//   - If the input is contained within the longer string, ignore it. Use strstr to perform the search.
//   - If the user input is less than the longer string (as indicated by the return value from strcmp), 
//     prepend the input onto the longer string with a space separating them.
//   - If the input is greater than the longer string, append it with a space separating them.


#include <stdio.h>
#include <string.h>

void usrIn(char *temp_str_ptr);

int main(){
    char main_str[1000],
        main_str_temp[980],
        temp_str[20];
    char *temp_str_ptr = temp_str;

    usrIn(temp_str_ptr);
    strcat(main_str, temp_str);
    strcat(main_str, " ");
    printf("%s", main_str);

    while (1){
        usrIn(temp_str_ptr);

        if(strcmp(temp_str, "DONE")==0){
            printf("%s", main_str);
            break;
        }
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

        printf("%s", main_str);
        
    }
}

void usrIn(char *temp_str_ptr){
    char usrInput[20];
    printf("\nEnter a string: ");
    fgets(usrInput, 20, stdin);
    *strchr(usrInput, '\n') = '\0';
    strcpy(temp_str_ptr, usrInput);
    // printf("%s -- ", temp_str_ptr);

}