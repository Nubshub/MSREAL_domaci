

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


FILE* fp;

void menu();
void file_open_r();
void file_open_w();
void file_close();

int main()
{
	char izbor;
	char string[100];
	int len;
	
	while(1)
	{
		menu();
		scanf("%c",&izbor);
		
		switch(izbor)
		{
			case '1':
				
				puts("Upisite broj u formatu 0bxxxxxxxx");
				scanf("%s",string);
				
				file_open_w();
				fprintf(fp,"%s\n",string);
				file_close();
				
				break;
			case '2':
				puts("Koliko brojeva zelite da procitate iz bafera?");
				scanf("%s",string);
				
				file_open_w();
				fprintf(fp,"num=%s\n",string);
				file_close();
				
				file_open_r();
				
				fscanf(fp, "%s",string);
				printf("%s\n",string);   //ispisuje samo jednu vrednost!
				file_close();
				break;
			case '3':
				exit(0);
				break;
		}
	}		
	

	return 0;
}

void menu()
{
	puts("1: Upisi u FIFO bafer");
	puts("2: Pricitaj iz FIFO bafera");
	puts("3: Izadji");
}

void file_open_r()
{
	fp = fopen("/dev/fifo", "r");
	if(fp == NULL)
	{
		puts("Cannot open /dev/fifo");
	}

}

void file_open_w()
{
	fp = fopen("/dev/fifo", "w");
	if(fp == NULL)
	{
		puts("Cannot open /dev/fifo");
	}

}

void file_close()
{
	if(fclose(fp))
	{
		puts("Cannot close /dev/fifo");
	}

}
