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
int skip(uint8_t *data, int i);

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
    int E0[4] = {255, 224, 0, 0};
    int *E0Ptr = E0;
    int E1[4] = {255, 225, 0, 0};
    int *E1Ptr = E1;

    
    int JPEGstart;
    int JPEGfinish;

    
    char tempName[15];
    

    for(int i = 0; i < size; i+=512){
        reassign(data_check_ptr, data, i, 4);
        block_count++;


       
        if(compare_array(data_check_ptr, SOIaPtr, 2) || compare_array(data_check_ptr, SOIbPtr, 2)){
            reassign(data_check_ptr, data, i+2, 4);
            if(compare_array(data_check_ptr, E0Ptr, 2) || compare_array(data_check_ptr, E1Ptr, 2)){
                printf("size: %d i: %d\n", size, i/16 );
                printf("    NOTE: found E0 or E1        %d\n",skip(data,i) );
                img_count++;
                JPEGstart = i+1;
            
                for(int j = i; j<size; j++){ 
                    reassign(data_check_ptr, data, j, 2);
                    if(compare_array(data_check_ptr, SOF0Ptr, 2)){
                        printf("    NOTE: found SOF0\n");
                        j = j + skip(data,j);
                    }
                    if(compare_array(data_check_ptr, SOF2Ptr, 2)){
                        printf("    NOTE: found SOF2\n");
                        j = j + skip(data,j);
                    }
                    if(compare_array(data_check_ptr, DHTPtr, 2)){
                        printf("    NOTE: found DHT\n");
                        j = j + skip(data,j);
                    }
                    if(compare_array(data_check_ptr, DQTPtr, 2)){
                        printf("    NOTE: found DQT\n");
                        j = j + skip(data,j);
                    }
                    if(compare_array(data_check_ptr, SOSPtr, 2)){
                        printf("    NOTE: found SOS\n");
                        j = j + skip(data,j);
                    }
                    if(compare_array(data_check_ptr, COMPtr, 2)){
                        printf("    NOTE: found COM\n");
                        j = j + skip(data,j);
                    }
                    if(compare_array(data_check_ptr, EOIPtr, 2)){
                        JPEGfinish = j;
                        printf("    NOTE: found EOI\n");
                        i=i + ((JPEGfinish-JPEGstart)-(JPEGfinish-JPEGstart)%512);
                        printf("size: %d i: %d\n", size, i );
                        break;
                    }
                    
                    
                    
                    
                    
                //     // printf("    INDEX: %d\n", i);


                    uint8_t *tempBuf = malloc(JPEGfinish-JPEGstart);
                    for(int k = 0; k < (JPEGfinish-JPEGstart); k++){
                        tempBuf[k] = data[JPEGstart+k];
                    }
                    sprintf(tempName, "image %d.jpeg", img_count);
                    save_jpeg(tempBuf, JPEGfinish-JPEGstart, tempName);
                    free(tempBuf);
                }
            }
            
            
            printf("NOTE:  found %d in %d blocks\n", img_count, block_count);
        }
     
    }

    // printf("\nTOTAL: found %d in %d blocks", img_count, block_count);

}

int skip(uint8_t *data, int i){
    // char temp[1];
    // uint8_t temp[sizeof(uint8_t)*2];
    // memcpy(&temp, data[j],1);
    // memcpy(&temp, data[j+1],1);
        
    // for(int k = -4; k<12; k++){
    //     printf("    %d : %X\n", j+k, (char)data[j+k]);
    // }
    // snprintf(temp, 1, "%X%X", (char)data[j+2], (char)data[j+3]);

    int rec = (int)(((unsigned)data[i+3] << 8) | data[i+2] );

    printf("    %X -- %d\n", rec, rec);
    // sprintf(temp, "%X%X", (char)data[j], (char)data[j+1]);
    // unsigned char buf = data[i+j+1] + data[i+j+2];
    return rec;
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
    for(int i = 0; i< amount; i++){
        cpArr[i] = srcArr[index+i];
    }            
}

void printArray(int interger_array[]){
  for (int j = 0; j < 4; j++ ) {
      printf("Element[%d] = %d\n", j, interger_array[j] );
   }
}