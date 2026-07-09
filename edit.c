#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mp3.h"

char* option_frame(char *opt)//here we are chcking our argv is what type
{
    if(strcmp(opt,"-t")==0) return "TIT2";
    else if(strcmp(opt,"-a")==0) return "TPE1";
    else if(strcmp(opt,"-A")==0) return "TALB";
    else if(strcmp(opt,"-y")==0) return "TYER";
    else if(strcmp(opt,"-c")==0) return "COMM";
    else if(strcmp(opt,"-g")==0) return "TCON";
    return NULL;
}

void editor_mp3(char *tag_name, char *new_info, char *filename)
{
    FILE *fp = fopen(filename,"rb"); //here we are reading in binary mode
    if(fp == NULL)
    {
        printf("Invalid file\n");
        return;
    }

    FILE *tp = fopen("temp.mp3","wb");//here we are opening the temp file
    if(tp == NULL)
    {
        printf("Temp file error\n");
        return;
    }

    char header[10];//in that we are copying first 10 bytes to temp file
    fread(header,1,10,fp);
    fwrite(header,1,10,tp);

    while(1) // we are running the loop
    {
        char tag[5];
        fread(tag,1,4,fp);
        tag[4] = '\0';

        unsigned int size;
        fread(&size,1,4,fp);
        bigEndian(&size,sizeof(size));

        char flag[3];
        fread(flag,1,3,fp);

        char *info = (char *)malloc(size);
        fread(info,1,size-1,fp);
        info[size-1] = '\0';

        if(strcmp(tag, tag_name) == 0)
        {
            fwrite(tag_name,1,4,tp);

            unsigned int len = strlen(new_info);
            unsigned int new_size = len + 1;
            bigEndian(&new_size,sizeof(int));

            fwrite(&new_size,1,4,tp);
            fwrite(flag,1,3,tp);
            fwrite(new_info,1,len,tp);

            printf("Edited tag %s successfully\n", tag_name);
            free(info);
            break;
        }
        else
        {
            fwrite(tag,1,4,tp);
            unsigned int new_size = size + 1;
            bigEndian(&new_size,sizeof(int));
            fwrite(&new_size,1,4,tp);
            fwrite(flag,1,3,tp);
            fwrite(info,1,size,tp);
        }

        free(info);
    }

    char buf[100000];
    int n;
    while((n = fread(buf,1,100000,fp)) > 0)
        fwrite(buf,1,n,tp);

    fclose(fp);
    fclose(tp);
}
void help()//if we give wrong input it will go to this function help
{
    printf("\n================ MP3 TAG EDITOR ================\n");
    printf("Usage:\n\n");

    printf("1) View MP3 Tag Details:\n");
    printf("   ./mp3 -v <file_name.mp3>\n\n");

    printf("2) Edit MP3 Tag Details:\n");
    printf("   ./mp3 -e <tag> <new_info> <file_name.mp3>\n\n");

    printf("Available Tags:\n");
    printf("   -t  Title\n");
    printf("   -a  Artist\n");
    printf("   -A  Album\n");
    printf("   -y  Year\n");
    printf("   -c  Comment\n");
    printf("   -g  Genre\n\n");
    printf("================================================\n\n");
}
