#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
extern int errno;

#define bytes_per_read 4000000

int main(int argc,char **argv)
{

    if( argc < 2)
    {
        write(1,"No file path provided",22);
        return 0;
    }
    else if (argc > 2)
    {
        write(1,"Wrong number of arguments, Extra args.",39);
        return 0;
    }

    //Extracting filename from the path provided.
    int len = 0,strt,k=0;
    for(int i=0;argv[1][i]!='\0';i++)
    {
        len++;
    }
    strt = len;
    for(int i=len-1; argv[1][i]!= '/' && i >= 0;i--)
    {
        strt--;
    }

    char filename[100]; // As the name suggest it contains filename.
    for(int i=strt;i<len;i++)
    {
        filename[k++]=argv[1][i];
    }

    // Making target file path.
    char target_file_name[112] = "Assignment/";
    for(int i=11;i<11+k;i++)
    {
        target_file_name[i] = filename[i-11];
    }

    // Accessing file provided.
    int fd_source = open(argv[1],O_RDONLY),szr;
    if(fd_source < 0)                                                // Error Handling
    {
        perror("Source File");
        return 0;
    }

    // Checking For Assignment directory whether present or not.
    // If not then creating it.
    int direc = open("Assignment",O_DIRECTORY);
    if (direc < 0)
    {
        mkdir("Assignment", 0700);     // Giving read,write and execute permission to the user who created it.
    }
    else
    {
        int user_perm = chmod("Assignment", 0700);  // Giving read,write and execute permission to the user who created it.
        if(user_perm < 0)
        {
            perror("Assignment Directory");
            return 0;
        }
    }

    // Opening the target file.
    int fd_target = open(target_file_name,O_WRONLY | O_CREAT, 0600); // Giving read and write permission to the user who created the file.
    if(fd_target < 0)                                                // Error Handling
    {
        perror("Target File");
        return 0;
    }



    char Read_once[bytes_per_read+2];       // Array for storing the read byte.
    char Read_reverse[bytes_per_read+2];    // Array for storing the reverse of read byte.


    // filesize is the size of source file.
    int filesize = lseek(fd_source, 0, SEEK_END);
    if(filesize < 0)                                                   // Error Handling.
    {
        perror("Source File Size not valid");
        return 0;
    }

    int Initiate = ((filesize - 1) / bytes_per_read) * bytes_per_read;    // Initiate is the byte from where to start reading of fd_source.
    int length_of_chunk = filesize - Initiate;                            // length_of_chunk is the size chunk that has to be read in 1 round.


    // For progress bar.
    int number_of_loops = (filesize - 1) / bytes_per_read;
    if ( (filesize - 1) % bytes_per_read != 0 )
    {
        number_of_loops++;
    }

    
    // Reposition the file descriptor offsets.
    lseek(fd_target, 0, SEEK_SET);         // start of the target file.
    lseek(fd_source,Initiate,SEEK_SET);    // Repositioning to byte from where to start reading of fd_source.


    // Main Loop.
    int loop_number =1;
    char show[100];
    while(1)
    {
        int szr = read(fd_source, Read_once, length_of_chunk);
        if(szr < 0)                                                  //Error Handeling.
        {
            perror("Reading Source File");
            return 0;
        }

        // Reversing the read byte
        for(int i=0,j=length_of_chunk-1;i<length_of_chunk;i++,j--)
        {
            Read_reverse[i]=Read_once[j];
        }
        Read_reverse[length_of_chunk]='\0';

        // Writing in the target file.
        int szw = write(fd_target, Read_reverse, length_of_chunk);
        if(szw < 0)                                                  //Error Handeling.
        {
            perror("Writing Target File");
            return 0;
        }


        // Printing the progress in the percentage format.
        sprintf(show,"Percentage of the file written  %0.2f %% .....\r",(float)(loop_number*100)/number_of_loops);
        write(1,show,48);
        loop_number++;

        // Checking for next loop if valid i.e. a chunk of data is still 
        // present in source file or not.
        if(lseek(fd_source, 0,SEEK_CUR) - bytes_per_read - length_of_chunk < 0)
        {break;}

        lseek(fd_source,-bytes_per_read-length_of_chunk,SEEK_CUR);
        length_of_chunk = bytes_per_read;

    }
    write(1,"\n",1);

    //Closing all the opened files and directory.
    close(fd_source);
    close(fd_target);
    return 0;
}