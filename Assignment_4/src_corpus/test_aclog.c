#include "myLib.h"

int main() 
{
	int i;
	size_t bytes;
	FILE *file ;

	// fclose(file);
	char filenames[10][7] = {"file_0", "file_1", 
			"file_2", "file_3", "file_4",
			"file_5", "file_6", "file_7", 		
			"file_8", "file_9"};


	/* example source code */

	for (i = 0; i < 1; i++) {

		file = fopen(filenames[i], "w+");
		// if (file == NULL) 
		// 	continue;
		// else {
		// 	bytes = fwrite("Christos trimas", 50, 1, file);
		// 	fclose(file);
		// }

	}
	// fclose(file);



}
