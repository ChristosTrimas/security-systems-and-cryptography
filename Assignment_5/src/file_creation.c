#include "myLib.h"

void main(int argc, char *argv[])
{
	int i = 0;
	size_t bytes;
	FILE *file;
	int j = 0;

	int X = atoi(argv[1]);

	for(; i < X; i++)
	{
		char path[2048] = "";
		sprintf(path, "Userfiles/new_file_%d", i);
		file = fopen(path, "w+");

		if(file == NULL)
		{
			printf("fopen: error.\n");
		}

		else 
		{
			bytes = fwrite(path, strlen(path), 1, file);
			fclose(file);
		}
	} 
}