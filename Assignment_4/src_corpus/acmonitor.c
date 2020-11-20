#include "myLib.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct entry {

	char* id; /* user id (positive integer) */
	char* access_type; /* access type values [0-2] */
	char action_denied; /* is action denied values [0-1] */

	char* date; /* file access date */
	char* time; /* file access time */

	char *file; /* filename (string) */
	char *fingerprint; /* file fingerprint */

	struct entry* next;
};

struct usersActivity{
	char* id;
	int count;
	struct filesAccessed *head;

	struct usersActivity* next;
};

struct filesAccessed{
	char* filename;
	struct filesAccessed* next;
};

struct entry* UserList;
struct filesAccessed* activityList;

void
usage(void)
{
	printf(
	       "\n"
	       "usage:\n"
	       "\t./monitor \n"
		   "Options:\n"
		   "-m, Prints malicious users\n"
		   "-i <filename>, Prints table of users that modified "
		   "the file <filename> and the number of modifications\n"
		   "-h, Help message\n\n"
		   );

	exit(1);
}

void insertUser(struct entry** userList, char* id, char* filename, char* date, char* time, char* access_type, int action_denied, char* hash)
{
	struct entry* newNode = NULL;
	struct entry* prev = *userList;
	
	newNode = malloc(sizeof(struct entry));
	
	if(newNode == NULL)
	{
		fprintf(stdout, "Failed to allocate memory.\n");
		exit(0);
	}

	newNode->id = malloc(strlen(id) * sizeof(char));
	strcpy(newNode->id, id);
	
	newNode->file = malloc(sizeof(char) * strlen(filename));
	strcpy(newNode->file, filename);
	
	newNode->date = malloc(sizeof(char) * strlen(date));
	strcpy(newNode->date, date);
	
	newNode->time = malloc(sizeof(char) * strlen(filename));
	strcpy(newNode->time, time);
	
	newNode->access_type = malloc(sizeof(char) * strlen(access_type));
	
	strcpy(newNode->access_type, access_type);
	
	// newNode->action_denied = malloc(sizeof(char) * strlen(action_denied));
	// strcpy(newNode->action_denied, action_denied);
	newNode->action_denied = action_denied;
	
	newNode->fingerprint = malloc(sizeof(char) * strlen(hash));
	strcpy(newNode->fingerprint, hash);
	
	newNode->next = *userList;
	*userList = newNode;
}

void inserAct(struct usersActivity** useActList, char* id)
{
	struct usersActivity* newNode = NULL;

	newNode = malloc(sizeof(struct usersActivity));

	if(newNode == NULL)
	{
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(0);
	}

	strcpy(newNode->id, id);

	newNode->head = NULL;
	newNode->count = 1;
	newNode->next = *useActList;
	*useActList = newNode;
}

void insertFile(struct filesAccessed** fileList, char* filename)
{
	struct filesAccessed* newNode = NULL;

	newNode = malloc(sizeof(struct filesAccessed));

	if(newNode == NULL)
	{
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(0);
	}

	strcpy(newNode->filename, filename);

	newNode->next = *fileList;
	*fileList = newNode;
}

void printUser(struct entry* userList)
{
	while(userList != NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%c\t%s\n", userList->id, userList->file, userList->date, userList->time, userList->access_type, userList->action_denied, userList->fingerprint);
		userList = userList->next;
	}
}

void list_unauthorized_accesses(struct entry* UserList)
{
	struct entry* tmp = UserList;
	int counter = 0;
	printUser(tmp);
	while(tmp != NULL && !(strcmp(tmp->id, tmp->next->id)))
	{
		// printf(" action denied%c\n", tmp->action_denied);
		if(tmp->action_denied == '1' )
		{
			counter++;
			// printf("counter = %d\n", counter);
		}
		if(counter == 7)
		{
			printf("User %s, is malicious.\n",tmp->id);
			counter = 0;
		}
		// printf("counter = %d\n", counter);
		if(tmp->next == NULL)
		{
			break;
		}else{
			tmp = tmp->next;
		}
		// printf(" action denied%d\n", tmp->action_denied);
	}

	return;
}


void list_file_modifications(FILE *log, char *file_to_scan)
{

	/* add your code here */
	/* ... */
	/* ... */
	/* ... */
	/* ... */

	return;

}

int main(int argc, char *argv[])
{

	int ch;
	char* logName;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	char action;

	FILE *log;
	UserList = NULL;
	activityList = NULL;
	if (argc < 2)
		usage();

	log = fopen("./file_logging.log", "r");
	if (log == NULL) {
		printf("Error opening log file \"%s\"\n", "./log");
		return 1;
	}

	while(read = (getline(&line, &len, log)) != -1)
	{
		char* str[6];
		char* pch;
		pch = strtok(line, "\t");
		int j = 0;

		while(pch != NULL)
		{
			if(j == 5)
			{
				action = *pch;
				j++;
			}
			else
			{
				str[j] = pch;
				pch = strtok(NULL, "\t");
				j++;
			}
		}

		insertUser(&UserList,str[0],str[1],str[2],str[3],str[4],action,str[5]);
		// printUser(UserList);
		// printf("next\n");
		// printf("%ld\n",read);
	}
	// printf("perasa\n");

	while ((ch = getopt(argc, argv, "hi:m")) != -1) {
		switch (ch) {		
		case 'i':
			list_file_modifications(log, optarg);
			break;
		case 'm':
			list_unauthorized_accesses(UserList);
			break;
		default:
			usage();
		}

	}

	fclose(log);
	argc -= optind;
	argv += optind;	
	
	return 0;
}
