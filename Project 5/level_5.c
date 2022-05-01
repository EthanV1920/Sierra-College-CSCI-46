// Ethan Vosburg
// April 30 2022

// Write a program that scans the raw data of a storage device to find and
// recover lost images. Must display the number of images and recover the
// images correctly. 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

// Function prototypes. Don't change these.
uint8_t *read_card(char *fname, int *size);
void save_jpeg(uint8_t *data, int size, char *filename);
void recover(uint8_t *data, int size);
int compare_array(int *arr1, int *arr2, int arrSize);
void printArray(int interger_array[]);

#define RAW_FILE "card.raw"

int main()
{
    // Read the card.raw file into an array of bytes (uint8_t)
    int card_length;
    uint8_t *card_data = read_card(RAW_FILE, &card_length);
    
    

    // Recover the images
    recover(card_data, card_length);
}

uint8_t *read_card(char *filename, int *size)
{

    struct stat st;
    if (stat(filename, &st) == -1)
    {
        fprintf(stderr, "Can't get info about %s\n", filename);
        exit(1);
    }
    int len = st.st_size;
    uint8_t *raw = malloc(len * sizeof(uint8_t));
    
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        fprintf(stderr, "Can't open %s for reading\n", filename);
        exit(1);
    }
    
    fread(raw, 1, len, fp);
    fclose(fp);
    
    *size = len;
    return raw;
}

void save_jpeg(uint8_t *data, int size, char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp)
    {
        fprintf(stderr, "Can't write to %s\n", filename);
        exit(1);
    }
    
    fwrite(data, 1, size, fp);
    fclose(fp);   
}

void recover(uint8_t *data, int size){
    int img_count = 0;
    int block_count = 0;

    int data_check[4];
    int *data_check_ptr;
    data_check_ptr = data_check;

    // int array[5] = {11,2,3,5,6};
    // int (*a)[5] = &array;   

    int SOIa[4] = {255, 216, 255, 224};
    int *SOIaPtr = SOIa;

    int SOIb[4] = {255, 216, 255, 225};
    int *SOIbPtr = SOIb;
    // int SOIa[4] = {255, 216, 255, 224}
    // int SOIa[4] = {255, 216, 255, 224}
    // int SOIa[4] = {255, 216, 255, 224}


    for(int i = 0; i < 512*1200; i+=512){
        // data_check_ptr = {data[i], data[i+1], data[i+2], data[i+3]};
        for(int j = 0; j< 4; j++){
            data_check_ptr[j] = data[i+j];
        }

        // printf("%d", data_check[0]);
        
        // switch (data[i])
        // {
        // case (data[i] == 255 && data[i+1] == 216 && data[i+2] == 255 && data[i+3] == 224):
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }

        // block_count++;
        // if(data[i] == 255 && data[i+1] == 216 && data[i+2] == 255 && data[i+3] == 224){
        //     img_count++;
        //     printf("found %d in %d blocks\n", img_count, block_count);
        // }
        // if(data[i] == 255 && data[i+1] == 216 && data[i+2] == 255 && data[i+3] == 225){
        //     img_count++;
        //     printf("found %d in %d blocks\n", img_count, block_count);
        // }

        printArray(data_check);


        if(compare_array(data_check_ptr, SOIbPtr, 4)){
            img_count++;
            printf("found %d in %d blocks\n", img_count, block_count);
        }
    }

    printf("TOTAL: found %d in %d blocks", img_count, block_count);

}

int compare_array(int *arr1, int *arr2, int arrSize){
    int isSame = 1;

    for(int i = 0; i < arrSize; i++){
        if(arr1[i] != arr2[i]){
            isSame = 0;
        }
    }
    return isSame;

}

void printArray(int interger_array[]){
  for (int j = 0; j < 4; j++ ) {
      printf("Element[%d] = %d\n", j, interger_array[j] );
   }
}