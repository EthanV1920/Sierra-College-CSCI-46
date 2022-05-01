# Notes for Level 5 CSI

## Objective

Write a program that scans the raw data of a storage device to find and recover lost images. Must display the number of images and recover the images correctly. 

## Step 1: Getting Familiar with the Data

Finding the number of photos in the raw data and which block they reside in:

```
void recover(uint8_t *data, int size){
    int img_count = 0;
    int block_count = 0;

    for(int i = 0; i < size; i+=512){    
        block_count++;
        if(data[i] == 255 && data[i+1] == 216 && data[i+2] == 255 && data[i+3] == 224){
            img_count++;
            printf("found %d in %d blocks\n", img_count, block_count);
        }
        if(data[i] == 255 && data[i+1] == 216 && data[i+2] == 255 && data[i+3] == 225){
            img_count++;
            printf("found %d in %d blocks\n", img_count, block_count);
        }
    }
}


```

## Step 2: Looking for Sequences

Need to find sequences to allow movement through the data quickly. Code will look for markers then find the length of each relevant section then skip through the section to find the EOI marker.

[![Alt text](https://ih1.redbubble.net/image.34570371.6973/flat,800x800,070,f.u1.jpg)](https://ih1.redbubble.net/image.34570371.6973/flat,800x800,070,f.u1.jpg)

### JPEG Markers
|  						  							  								 Short name  							 						 					                                       |  						  							  								 Bytes  							 						 					                                       |  						  							  								 Payload  							 						 					                                       |  						  							  								 Name  							 						 					                                       |  						  							  								 Comments  							 						 					                                       |
|---|---|---|---|---|
|  						  							  								 SOI  							 						 					                                       |  						  							  								 0xFF, 0xD8  							 						 					                                       |  						  							  								 none  							 						 					                                       |  						  							  								 Start Of Image  							 						 					                                       |  					     |
|  						  							  								 SOF0  							 						 					                                       |  						  							  								 0xFF, 0xC0  							 						 					                                       |  						  							  								 variable size  							 						 					                                       |  						  							  								 Start Of Frame (baseline DCT)  							 						 					                                       |  						  							  								 Indicates that this is a baseline DCT-based JPEG, and specifies the width, height, number of components, and component subsampling (e.g., 4:2:0).  							 						 					                                       |
|  						  							  								 SOF2  							 						 					                                       |  						  							  								 0xFF, 0xC2  							 						 					                                       |  						  							  								 variable size  							 						 					                                       |  						  							  								 Start Of Frame (progressive DCT)  							 						 					                                       |  						  							  								 Indicates that this is a progressive DCT-based JPEG, and specifies the width, height, number of components, and component subsampling (e.g., 4:2:0).  							 						 					                                       |
|  						  							  								 DHT  							 						 					                                       |  						  							  								 0xFF, 0xC4  							 						 					                                       |  						  							  								 variable size  							 						 					                                       |  						  							  								 Define Huffman Table(s)  							 						 					                                       |  						  							  								 Specifies one or more Huffman tables.  							 						 					                                       |
|  						  							  								 DQT  							 						 					                                       |  						  							  								 0xFF, 0xDB  							 						 					                                       |  						  							  								 variable size  							 						 					                                       |  						  							  								 Define Quantization Table(s)  							 						 					                                       |  						  							  								 Specifies one or more quantization tables.  							 						 					                                       |
|  						  							  								 DRI  							 						 					                                       |  						  							  								 0xFF, 0xDD  							 						 					                                       |  						  							  								 4 bytes  							 						 					                                       |  						  							  								 Define Restart Interval  							 						 					                                       |  						  							  								 Specifies the interval between RSTn markers, in Minimum Coded Units (MCUs). This marker is followed by two bytes indicating the fixed size so it can be treated like any other variable size segment.  							 						 					                                       |
|  						  							  								 SOS  							 						 					                                       |  						  							  								 0xFF, 0xDA  							 						 					                                       |  						  							  								 variable size  							 						 					                                       |  						  							  								 Start Of Scan  							 						 					                                       |  						  							  								 Begins a top-to-bottom scan of the image. In baseline DCT JPEG images, there is generally a single scan. Progressive DCT JPEG images usually contain multiple scans. This marker specifies which slice of data it will contain, and is immediately followed by entropy-coded data.  							 						 					                                       |
|  						  							  								 RSTn  							 						 					                                       |  						  							  								 0xFF, 0xDn (n=0..7)  							 						 					                                       |  						  							  								 none  							 						 					                                       |  						  							  								 Restart  							 						 					                                       |  						  							  								 Inserted every r macroblocks, where r is the restart interval set by a DRI marker. Not used if there was no DRI marker. The low three bits of the marker code cycle in value from 0 to 7.  							 						 					                                       |
|  						  							  								 APPn  							 						 					                                       |  						  							  								 0xFF, 0xEn  							 						 					                                       |  						  							  								 variable size  							 						 					                                       |  						  							  								 Application- specific  							 						 					                                       |  						  							  								 For example, an Exif JPEG file uses an APP1 marker to store metadata, laid out in a structure based closely on TIFF.  							 						 					                                       |
|  						  							  								 COM  							 						 					                                       |  						  							  								 0xFF, 0xFE  							 						 					                                       |  						  							  								 variable size  							 						 					                                       |  						  							  								 Comment  							 						 					                                       |  						  							  								 Contains a text comment.  							 						 					                                       |
|  						  							  								 EOI  							 						 					                                       |  						  							  								 0xFF, 0xD9  							 						 					                                       |  						  							  								 none  							 						 					                                       |  						  							  								 End Of Image  							 						 					                                       |  					     |





This caused a big problem. Make sure you don't make this mistake...

```
int data_check[4];
int *data_check_ptr;
*data_check_ptr = data_check; //This is in correct

data_check_ptr = data_check; // This is correct

```