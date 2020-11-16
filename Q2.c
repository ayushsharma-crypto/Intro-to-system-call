#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
extern int errno;

#define bytes_per_read 400000

void print_permission(struct stat NewFile,struct stat OldFile,struct stat Directory)
{

    // Permission for NewFile.
	if( (NewFile.st_mode & S_IFMT) != S_IFREG )
	{
		write(1,"Not Valid NewFile\n",19);
        write(1,"\n",1);
	}
	else
	{
		if( NewFile.st_mode & S_IRUSR )
		{
			write(1,"User has read permissions on newfile: Yes\n",43);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has read permissions on newfile: No\n",42);
            write(1,"\n",1);
		}
		if( NewFile.st_mode & S_IWUSR )
		{
			write(1,"User has write permissions on newfile: Yes\n",44);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has write permissions on newfile: No\n",43);
            write(1,"\n",1);
		}

		if( NewFile.st_mode & S_IXUSR )
		{
			write(1,"User has execute permissions on newfile: Yes\n",46);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has execute permissions on newfile: No\n",45);
            write(1,"\n",1);
		}

		if( NewFile.st_mode & S_IRGRP )
		{
			write(1,"Group has read permissions on newfile: Yes\n",44);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has read permissions on newfile: No\n",43);
            write(1,"\n",1);
		}

		if( NewFile.st_mode & S_IWGRP )
		{
			write(1,"Group has write permissions on newfile: Yes\n",45);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has write permissions on newfile: No\n",44);
            write(1,"\n",1);
		}

		if( NewFile.st_mode & S_IXGRP )
		{
			write(1,"Group has execute permissions on newfile: Yes\n",47);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has execute permissions on newfile: No\n",46);
            write(1,"\n",1);
		}

		if( NewFile.st_mode & S_IROTH )
		{
			write(1,"Others has read permissions on newfile: Yes\n",45);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has read permissions on newfile: No\n",44);
            write(1,"\n",1);
		}

		if( NewFile.st_mode & S_IWOTH )
		{
			write(1,"Others has write permissions on newfile: Yes\n",46);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has write permissions on newfile: No\n",45);
            write(1,"\n",1);
		}

		if( NewFile.st_mode & S_IXOTH )
		{
			write(1,"Others has execute permissions on newfile: Yes\n",48);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has execute permissions on newfile: No\n",47);
            write(1,"\n",1);
		}                
	}


    // Permission for OldFile.
	if( (OldFile.st_mode & S_IFMT) != S_IFREG )
	{
		write(1,"Not Valid OldFile\n",19);
        write(1,"\n",1);

	}
	else
	{
		if( OldFile.st_mode & S_IRUSR )
		{
			write(1,"User has read permissions on oldfile: Yes\n",43);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has read permissions on oldfile: No\n",42);
            write(1,"\n",1);
		}
		if( OldFile.st_mode & S_IWUSR )
		{
			write(1,"User has write permissions on oldfile: Yes\n",44);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has write permissions on oldfile: No\n",43);
            write(1,"\n",1);
		}

		if( OldFile.st_mode & S_IXUSR )
		{
			write(1,"User has execute permissions on oldfile: Yes\n",46);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has execute permissions on oldfile: No\n",45);
            write(1,"\n",1);
		}

		if( OldFile.st_mode & S_IRGRP )
		{
			write(1,"Group has read permissions on oldfile: Yes\n",44);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has read permissions on oldfile: No\n",43);
            write(1,"\n",1);
		}

		if( OldFile.st_mode & S_IWGRP )
		{
			write(1,"Group has write permissions on oldfile: Yes\n",45);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has write permissions on oldfile: No\n",44);
            write(1,"\n",1);
		}

		if( OldFile.st_mode & S_IXGRP )
		{
			write(1,"Group has execute permissions on oldfile: Yes\n",47);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has execute permissions on oldfile: No\n",46);
            write(1,"\n",1);
		}

		if( OldFile.st_mode & S_IROTH )
		{
			write(1,"Others has read permissions on oldfile: Yes\n",45);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has read permissions on oldfile: No\n",44);
            write(1,"\n",1);
		}

		if( OldFile.st_mode & S_IWOTH )
		{
			write(1,"Others has write permissions on oldfile: Yes\n",46);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has write permissions on oldfile: No\n",45);
            write(1,"\n",1);
		}

		if( OldFile.st_mode & S_IXOTH )
		{
			write(1,"Others has execute permissions on oldfile: Yes\n",48);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has execute permissions on oldfile: No\n",47);
            write(1,"\n",1);
		}                
	}


    // Permission for Directory.
	if( (Directory.st_mode & S_IFMT) == S_IFDIR )
	{
		if( Directory.st_mode & S_IRUSR )
		{
			write(1,"User has read permissions on directory: Yes\n",45);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has read permissions on directory: No\n",44);
            write(1,"\n",1);
		}
		if( Directory.st_mode & S_IWUSR )
		{
			write(1,"User has write permissions on directory: Yes\n",46);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has write permissions on directory: No\n",45);
            write(1,"\n",1);
		}

		if( Directory.st_mode & S_IXUSR )
		{
			write(1,"User has execute permissions on directory: Yes\n",48);
            write(1,"\n",1);
		}
		else
		{
			write(1,"User has execute permissions on directory: No\n",47);
            write(1,"\n",1);
		}

		if( Directory.st_mode & S_IRGRP )
		{
			write(1,"Group has read permissions on directory: Yes\n",46);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has read permissions on directory: No\n",45);
            write(1,"\n",1);
		}

		if( Directory.st_mode & S_IWGRP )
		{
			write(1,"Group has write permissions on directory: Yes\n",47);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has write permissions on directory: No\n",46);
            write(1,"\n",1);
		}

		if( Directory.st_mode & S_IXGRP )
		{
			write(1,"Group has execute permissions on directory: Yes\n",49);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Group has execute permissions on directory: No\n",48);
            write(1,"\n",1);
		}

		if( Directory.st_mode & S_IROTH )
		{
			write(1,"Others has read permissions on directory: Yes\n",47);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has read permissions on directory: No\n",46);
            write(1,"\n",1);
		}

		if( Directory.st_mode & S_IWOTH )
		{
			write(1,"Others has write permissions on directory: Yes\n",48);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has write permissions on directory: No\n",47);
            write(1,"\n",1);
		}

		if( Directory.st_mode & S_IXOTH )
		{
			write(1,"Others has execute permissions on directory: Yes\n",50);
            write(1,"\n",1);
		}
		else
		{
			write(1,"Others has execute permissions on directory: No\n",49);
            write(1,"\n",1);
		}                
	}
}


int main(int argc,char **argv)
{
	if(argc < 4)
	{
		write(1,"Not enough files and directory passed as argument\n",51);
		return 0;
	}
	else if(argc > 4)
	{
		write(1,"Irrelevant arguments passed, expected two files and one directory\n",67);
		return 0;
	}


	struct stat NewFile,OldFile,Directory;

    stat(argv[1],&NewFile);
    stat(argv[2],&OldFile);
    stat(argv[3],&Directory);

	if( (Directory.st_mode & S_IFMT) == S_IFDIR )
    {
        write(1,"Directory is created: Yes\n",27);
        write(1,"\n",1);
    }
    else
    {
        write(1,"Directory is created: No\n",26);
        write(1,"\n",1);        
    }

    //opening the newfile
    int fd_newfile = open(argv[1],O_RDONLY);
    if(fd_newfile < 0)
    {
        perror("NewFile");
    }
    //opening the oldfile
    int fd_oldfile = open(argv[2],O_RDONLY);
    if(fd_oldfile < 0)
    {
        perror("OldFile");
    }


    int newfile_size = lseek(fd_newfile,0,SEEK_END); // New file size.
    int oldfile_size = lseek(fd_oldfile,0,SEEK_END); // Old file size.

    // printf("newfile size = %d Oldfile size= %d\n",newfile_size,oldfile_size);

    if(newfile_size < 0)
    {
        perror("NewFile Size");
    }
    if(oldfile_size < 0)
    {
        perror("OldFile Size");
    }
    if(newfile_size != oldfile_size)
    {
        write(1,"Whether file contents are reversed in newfile: No\n\n",52);
    }
    else
    {
        char newfile_chunk_array[bytes_per_read+2]; //Array for storing the read bytes from newfile.
        char newfile_chunk_reverse_array[bytes_per_read+2]; //Array for storing the read bytes from newfile and reverse it.
        char oldfile_chunk_array[bytes_per_read+2]; //Array for storing the read bytes from oldfile in reverse order.

        int pointer_newfile = ( (newfile_size-1) / bytes_per_read ) * bytes_per_read; // pointer_newfile is the byte from where to start reading of fd_source.
        int length_of_chunk = newfile_size - pointer_newfile;                         // length_of_chunk is the size chunk that has to be read in 1 round.

        lseek(fd_oldfile,0,SEEK_SET);                                      // start of the target file.
        lseek(fd_newfile,pointer_newfile,SEEK_SET);                        // Repositioning to byte from where to start reading of fd_source.

        // For progress bar.
        int number_of_loops = (newfile_size - 1) / bytes_per_read;
        if ( (newfile_size - 1) % bytes_per_read != 0 )
        {
            number_of_loops++;
        }

        int flag =1;
        int loop_number =1;
        char complete[100];
        while(flag)
        {
			//Reading newfile.
            int szn = read(fd_newfile, newfile_chunk_array,length_of_chunk);
            if(szn < 0)
            {
                perror("Reading NewFile");
                break;
            }

            // Reversing the read byte
            for(int i=0,j=length_of_chunk-1;i<length_of_chunk;i++,j--)
            {
                newfile_chunk_reverse_array[i] = newfile_chunk_array[j];
            }
            newfile_chunk_reverse_array[length_of_chunk]='\0';

			// Reading oldfile.
            int szo = read(fd_oldfile, oldfile_chunk_array,length_of_chunk);
            if(szo < 0)
            {
                perror("Reading OldFile");
                break;
            }


			// Checking of reversal .
            for(int i=0;i<length_of_chunk;i++)
            {
                if(newfile_chunk_reverse_array[i] != oldfile_chunk_array[i])
                {
                    printf("i =%d ",i);
                    flag = 0;
                    break;
                }
            }

            // Checking for next loop if valid i.e. a chunk of data is still 
            // present in newfile or not.
            if(lseek(fd_newfile, 0,SEEK_CUR) - bytes_per_read - length_of_chunk < 0)
            {break;}

            lseek(fd_newfile,-bytes_per_read-length_of_chunk,SEEK_CUR);
            length_of_chunk = bytes_per_read;

            // Printing the progress in the percentage format.
            sprintf(complete,"Percentage of the file checked %0.2f %% .....\r",(float)(loop_number*100)/number_of_loops);
            write(1,complete,48);
            loop_number++;
        }     
        
        if(flag==0)
        {
            write(1,"Whether file contents are reversed in newfile: No\n\n",52);
        }
        else
        {
            write(1,"Whether file contents are reversed in newfile: Yes\n\n",53);
        }
        
                
    }
    

    //Printing permission of newfile , oldfile and directory provided.
    print_permission(NewFile,OldFile,Directory);

	return 0;
}
