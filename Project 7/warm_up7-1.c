// Ethan Vosburg
// May 5, 2022

// The user input is compared to the longer string and then takes action as follows:

//   - If the input is contained within the longer string, ignore it. Use strstr to perform the search.
//   - If the user input is less than the longer string (as indicated by the return value from strcmp), 
//     prepend the input onto the longer string with a space separating them.
//   - If the input is greater than the longer string, append it with a space separating them.


#include <stdio.h>
#include <string.h>

int main(){
    char main_str[1000],
        temp_str[20];

    char *tempPtr = temp_str;
    usrIn(tempPtr);
    
    strcat(main_str, temp_str);
    printf("\n%s", main_str);
}

void usrIn(char *tempStr){
    char newline = "\n";
    char usrInput[20];
    fgets(usrInput, 20, stdin);
    for(int i = 0; i < strchr(usrInput, newline); i++){
        tempStr[i] = usrInput[i];
    }
}