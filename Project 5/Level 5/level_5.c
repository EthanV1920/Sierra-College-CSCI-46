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
void reassign(int *cpArr, uint8_t *srcArr, int index, int amount);

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

    // No/Fixed Payload
    int SOIa[4] = {255, 216, 255, 224};
    int *SOIaPtr = SOIa;
    int SOIb[4] = {255, 216, 255, 225};
    int *SOIbPtr = SOIb;
    int DRI[4] = {255, 221, 0, 0};
    int *DRIPtr = DRI;
    int EOI[4] = {255, 217, 0, 0};
    int *EOIPtr = EOI;

    // Variable Payload
    int SOF0[4] = {255, 192, 0, 0};
    int *SOF0Ptr = SOF0;
    int SOF2[4] = {255, 194, 0, 0};
    int *SOF2Ptr = SOF2;
    int DHT[4] = {255, 196, 0, 0};
    int *DHTPtr = DHT;
    int DQT[4] = {255, 219, 0, 0};
    int *DQTPtr = DQT;
    int SOS[4] = {255, 218, 0, 0};
    int *SOSPtr = SOS;
    int COM[4] = {255, 254, 0, 0};
    int *COMPtr = COM;
    
    
    

    for(int i = 0; i < size; i+=512){
        for(int j = 0; j< 4; j++){
            data_check_ptr[j] = data[i+j];
        }

        // printf("%d", data_check[0]);

        block_count++;


        if(compare_array(data_check_ptr, SOIaPtr, 4) || compare_array(data_check_ptr, SOIbPtr, 4)){
            for(int k = i; k < data; k+=2){
                for(int j = k; j< 2; j++){
                data_check_ptr[j] = data[k+j];
            }

            img_count++;
            printf("NOTE:  found %d in %d blocks\n", img_count, block_count);
        }
     
    }

    printf("\nTOTAL: found %d in %d blocks", img_count, block_count);

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

void reassign(int *cpArr, uint8_t *srcArr, int index, int amount){
    for(int i = index; i< amount; i++){
    data_check_ptr[i] = data[index+i];
    }
            
}

void printArray(int interger_array[]){
  for (int j = 0; j < 4; j++ ) {
      printf("Element[%d] = %d\n", j, interger_array[j] );
   }
}