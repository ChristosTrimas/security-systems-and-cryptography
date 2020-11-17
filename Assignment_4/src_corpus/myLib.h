#ifndef MY_LIB_H
#define MY_LIB_H

#include <time.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/md5.h>

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

#endif