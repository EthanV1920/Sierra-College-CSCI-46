// Ethan Vosburg
// May 17, 2022

// This program is fairly simple. It opens a connection to one of the servers
// (fremont, london, mumbai, sydney, or newark). It sends a line of data (the data
// doesn't matter) and receives the response, measuring the time interval.

// Send a total of three lines of data and receive three responses. Display the
// average round-trip time in milliseconds.

// As noted above, the server responds with two numbers for each line of text it
// receives. However, there's nothing you need to do with the numbers.

// The name of the server comes from the command line. The name of the server
// should be prepended to the string ".cs.sierracollege.edu" to form the complete
// server hostname. For example, if the user enters "fremont", the complete
// hostname is "fremont.cs.sierracollege.edu"

// When opening a connection to the server, be sure to check for possible
// errors by looking at the return value. A return value of -1 indicates an
// error happened.

#include <stdio.h>
#include <sys/time.h>
#include <libsocket/libinetsocket.h>
#include <unistd.h>
#include <stdlib.h>

#define PING_COUNT 3

int main(int argc, char *argv[])
{
    // Declare Variables
    double totalTime = 0, startTime = 0, finishTime = 0;
    struct timeval now;
    int iterations = PING_COUNT;
    char response[100];
    char address[100];
    sprintf(address, "%s.cs.sierracollege.edu", argv[1]);

    printf("Connecting to %s...\n", address);
    int fd = create_inet_stream_socket(address, "5055", LIBSOCKET_IPv4, 0);
    if (fd < 0)
    {
        printf("Can't make connection\n");
        exit(1);
    }
    
    // Convert to FILE *
    FILE *s = fdopen(fd, "r+");
    
    sleep(1);
    printf("Connected\n");        

    // Communicate with server
    for(int i = 0; i < iterations; i++){
        printf("Sending ping...");
        gettimeofday(&now, NULL);
        startTime = now.tv_sec + now.tv_usec / 1000000.0;

        fprintf(s, "ping\n");      
        fgets(response, 100, s);
        
        gettimeofday(&now, NULL);
        finishTime = now.tv_sec + now.tv_usec / 1000000.0;

        printf("Received Ping %d - TIME: %.3fms\n", i+1, (finishTime-startTime)*1000);

        totalTime += (finishTime-startTime);
        startTime = 0, finishTime = 0;
    }

    // Print AVETIME
    printf("AVETIME: %.3fms\n", (totalTime/iterations)*1000);
    
    // Close the connection
    fclose(s);
    close(fd);

}
