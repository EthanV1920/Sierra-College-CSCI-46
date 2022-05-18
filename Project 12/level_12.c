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

int main()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    double secsSinceEpoch = now.tv_sec + now.tv_usec / 1000000.0;
    printf("%lf\n", secsSinceEpoch);
}