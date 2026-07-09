#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mp3.h"

// convert little endian to big endian
void bigEndian(void *x, int s)
{
    char *ptr = (char *)x;
    for(int i=0;i<s/2;i++)
    {
        char t = ptr[i];
        ptr[i] = ptr[s-i-1];
        ptr[s-i-1] = t;
    }
}

void reader_mp3(char *filename, Details *detail)
{
    FILE *fp = fopen(filename,"rb");//we are reading in binary mode
    if(fp == NULL)
    {
        printf("Invalid file\n");
        return;
    }

    char header[4];
    fread(header,1,3,fp);
    header[3] = '\0';

    if(strcmp(header,"ID3") != 0)//here we are checking id3 is or not
    {
        printf("No ID3 tag found\n");
        fclose(fp);
        return;
    }

    fseek(fp,7,SEEK_CUR);

    int tag_count = 0;

    while(tag_count < 6)//here we are running only 6 times with size
    {
        char tag[5];//here we are reading tag details
        fread(tag,1,4,fp);
        tag[4] = '\0';

        int size;
        fread(&size,1,4,fp);
        bigEndian(&size,sizeof(size));

        fseek(fp,3,SEEK_CUR);

        char *info = (char *)malloc(size);
        fread(info,1,size-1,fp);
        info[size-1] = '\0';

        if(strcmp(tag,"TIT2")==0)
        {
            strcpy(detail[tag_count].tag,"TITLE");
            strcpy(detail[tag_count].info,info);
            tag_count++;
        }
        else if(strcmp(tag,"TYER")==0 || strcmp(tag,"TDRC")==0)
        {
            strcpy(detail[tag_count].tag,"YEAR");
            strcpy(detail[tag_count].info,info);
            tag_count++;
        }
        else if(strcmp(tag,"TPE1")==0)
        {
            strcpy(detail[tag_count].tag,"ARTIST");
            strcpy(detail[tag_count].info,info);
            tag_count++;
        }
        else if(strcmp(tag,"TALB")==0)
        {
            strcpy(detail[tag_count].tag,"ALBUM");
            strcpy(detail[tag_count].info,info);
            tag_count++;
        }
        else if(strcmp(tag,"TCON")==0)
        {
            strcpy(detail[tag_count].tag,"GENRE");
            strcpy(detail[tag_count].info,info);
            tag_count++;
        }
        else if(strcmp(tag,"COMM")==0)
        {
            strcpy(detail[tag_count].tag,"COMMENT");
            strcpy(detail[tag_count].info,info);
            tag_count++;
        }

        free(info);
    }

    printf("--------------------------------------------------------\n");
    printf("\t\tSong Information\n");
    printf("--------------------------------------------------------\n");

    for(int i=0;i<tag_count;i++)
        printf("%s - %s\n",detail[i].tag,detail[i].info);

    printf("--------------------------------------------------------\n");

    fclose(fp);
}
