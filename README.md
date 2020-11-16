		


# Please refer Assignment pdf for main problem

		Assumptions in Question 1:-

		* Executible file assumes two argument: 1- ./a.out  2- FilePath
		  otherwise it will show error message.

		* 'Assignment' Directory will be created where you will run the 
		  code. If it is already present convert it's permission to 
		  read, write, and execute permissions for the user .
		  For Groups and Others there will be no permission .

		* Percentage of file written on console will be in numerical format.
		  Also it overwrite each time.

		* New file will be named same as file provided with permission 
		  as follow : 
		  read and write permissions for the user who created it and for 
		  groups and others no permission is granted.

		* for one read cycle program takes atmost 4mb (say 4000000) of chunk 
		  data to reverse it and write on the new target file in the 'Assignment'
		  directory.

		* Basic error handeling has been done.


		Assumptions in Question 2:-

		* Executible file assumes four argument in order:
		  1- ./a.out  2- New FilePath
		  3- Old Filepath 4_ Directory
		  otherwise it will show error message.

		* 'stat' function has been used to check for file/directory permission.

		* for one read cycle program takes atmost 0.4mb (say 400000) of chunk 
		  data to reverse it and write on the new target file in the 'Assignment'
		  directory.

		* Percentage of file checked on console will be in numerical format.
		  Also it overwrite each time and removed after completion.

		* Basic error handeling has been done.
