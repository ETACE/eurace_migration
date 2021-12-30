#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main (void)
{




		FILE * file;
		char c = '\0';
		char buffer[100000];
		int index = 0;
		int in_messages = 0;
		int in_message = 0;
		int in_name = 0;

		char name;


		buffer[0] = '\0';

		/* Open file */
		if((file = fopen("/home/pharting/workspace/Paper_Joe/Labour_UNIBI/model.xml", "r"))==NULL)
		{

			exit(0);
		}
		printf("Reading environment data from: %s\n", location);
		/* Keep reading file until EOF */
		while(c != (char)EOF)
		{

			printf("%c",c);
			/* Get the next char from the file */
			c = (char)fgetc(file);
			if(c == '>')
			{
				buffer[index] = '\0';
				if(strcmp(buffer, "messages") == 0) in_messages = 1;
				if(strcmp(buffer, "/in_messages") == 0) in_messages = 0;
				if(strcmp(buffer, "message") == 0) in_message = 1;
				if(strcmp(buffer, "/message") == 0) in_message = 0;
				if(strcmp(buffer, "name") == 0) in_name = 1;
				if(strcmp(buffer, "/name") == 0) in_name = 0;

				index = 0;
				buffer[index] = '\0';
			}
			else if(c == '<')
			{
				buffer[index] = '\0';
				if(in_message == 1 && in_name==1 )
				{

					name = buffer;


					printf("%s", name);

				}
				index = 0;
				buffer[index] = '\0';
			}
			else
			{
				buffer[index] = c;
				if(index < 999) index++;
			}
		}
		/* Close file */
		(void)fclose(file);

		return 0;
	}

