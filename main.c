//S VIBIN MICHAEL
//25036_012
//25/02/2026

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mp3.h"

int check_operation(char *arg)//here we are checking the operation 
{
    if(strcmp(arg,"-v")==0)
        return Op_view;
    else if(strcmp(arg,"-e")==0)
        return Op_edit;
    else if(strcmp(arg,"-h")==0)
        return Op_help;
    else
        return Op_invalid;
}

int main(int argc, char *argv[])
{
    if(argc < 2) //if the argv less that 2 print insuufucient
    {
        printf("ERROR : Insufficient arguments\n");
        printf("For Help ---> -h\n");
        return -1;
    }

    int op = check_operation(argv[1]);
    Details detail[6];

    if(op == Op_view)
    {
        if(argc < 3)
        {
            printf("Missing MP3 file\n");
            return 1;
        }
        reader_mp3(argv[2], detail);
    }
    else if(op == Op_edit) // op is equal to edit check argv is less 5
    {
        if(argc < 5)
        {
            printf("Missing edit arguments\n");
            return 1;
        }

        char *frame = option_frame(argv[2]);
        if(frame == NULL)
        {
            printf("Invalid tag option\n");
            return 1;
        }

        editor_mp3(frame, argv[3], argv[4]);
        remove(argv[4]);
        rename("temp.mp3", argv[4]);
    }
    else if(op == Op_help)
    {
        help();//if we give give wrong it wil go to help
    }
    else
    {
        printf("Invalid operation\n");
        printf("For Help ---> -h\n");
    }

    return 0;
}
