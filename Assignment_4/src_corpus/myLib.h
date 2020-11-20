#ifndef MY_LIB_H
#define MY_LIB_H

#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <openssl/md5.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>


// acmonitor.c functions and structures
// typedef struct entry {

// 	int uid; /* user id (positive integer) */
// 	int access_type; /* access type values [0-2] */
// 	int action_denied; /* is action denied values [0-1] */
// 	int tmp;

// 	time_t date; /* file access date */
// 	time_t time; /* file access time */

// 	char *file; /* filename (string) */
// 	char *fingerprint; /* file fingerprint */

// 	struct entry* next;
// }entry_t;

void usage(void);


void initLog(void);
// void  list_unauthorized_accesses(FILE*);

// void list_file_modifications(FILE*, char*);

int action_access = 0; // a variable to control the access of a file.

// the fopen and fwrite functions of the logger.c file

FILE* fopen(const char *, const char *);

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

// my functions

/**********************************************************************
* This function creates and stores all the necessary information for  *
* each log entry. UID, File_name, Date, Timestamp, Access type,       *
* Is action denied flag, File fingerprint 							  *
***********************************************************************/

void log_entry(const char*, unsigned const char );

/**********************************************************************
* This function creates and stores all the necessary information for  *
* each log entry. UID, File_name, Date, Timestamp, Access type,       *
* Is action denied flag, File fingerprint. Used for fwrite.			  *
***********************************************************************/

void wlog_entry(FILE* , unsigned const char );

/**********************************************************************
* This function creates and stores all the necessary information for  *
* each log entry that the user has no access.					      * 							  *
***********************************************************************/
void noLog(const char* , unsigned const char );

// entry_t* insert(entry_t* , int );

#endif