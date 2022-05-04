#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

int main(){
    uint8_t *data1 = "01";
    uint8_t *data2 = "a2";
    int rec = (int)(((unsigned)data2 << 8) | data1 );

    printf("    %X -- %d\n", rec, rec);
    // printf("values are %X and %X\ndecimals are %d and %d", array[0], array[1], array[0], array[1]);

}

                // if(compare_array(data_check_ptr, SOF0Ptr, 2)){
                //     printf("    NOTE: found SOF0\n  Skipping: %d\n", skip(data_check_ptr, data, i, j));
                //     j = j + skip(data_check_ptr, data, i, j);
                // }
                // if(compare_array(data_check_ptr, SOF2Ptr, 2)){
                //     printf("    NOTE: found SOF2\n  Skipping: %d\n", skip(data_check_ptr, data, i, j));
                //     j = j + skip(data_check_ptr, data, i, j);
                // }
                // if(compare_array(data_check_ptr, DHTPtr, 2)){
                //     printf("    NOTE: found DHT\n  Skipping: %d\n", skip(data_check_ptr, data, i, j));
                //     j = j + skip(data_check_ptr, data, i, j);
                // }
                // if(compare_array(data_check_ptr, DQTPtr, 2)){
                //     printf("    NOTE: found DQT\n  Skipping: %d\n", skip(data_check_ptr, data, i, j));
                //     j = j + skip(data_check_ptr, data, i, j);
                // }
                // if(compare_array(data_check_ptr, SOSPtr, 2)){
                //     printf("    NOTE: found SOS\n  Skipping: %d\n", skip(data_check_ptr, data, i, j));
                //     j = j + skip(data_check_ptr, data, i, j);
                // }
                // if(compare_array(data_check_ptr, COMPtr, 2)){
                //     printf("    NOTE: found COM\n  Skipping: %d\n", skip(data_check_ptr, data, i, j));
                //     j = j + skip(data_check_ptr, data, i, j);
                // }
                // if(compare_array(data_check_ptr, EOIPtr, 2)){
                //     JPEGfinish = j;
                //     printf("    NOTE: found EOI\n   S: %d F: %d\n", JPEGstart, JPEGfinish);
                //     i=i + ((JPEGfinish-JPEGstart)-(JPEGfinish-JPEGstart)%512)+1;
                //     break;
                // }