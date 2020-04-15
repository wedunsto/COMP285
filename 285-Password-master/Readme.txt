Given requirements: Use provided code for permutations to create a password cracker. 

This program determines the hidden 
password encoded in the function pass. The password is at most made up of 
some given k unique numerical digits. The length of the password is given 
at runtime on the command line. The length of the password ,k, will be between 
2 and 10 inclusively. Your program must determine the correct password in 
10!/(10-k)! attempts in order to be evaluated as correct.




To link the object file pass.o to your 6.cpp program the following must 
be 
done.



Step 1: Compile your code (6.cpp) like so:

	g++ -c 6.cpp


Step 2: Link the two object files together:
	g++ pass.o 6.o


Step 3: ./a.out <integer>



Example 1: 
For the test driver above (6.cpp), the following example could be 
executed.


Input:
	
./a.out 123457


Output:

Incorrect password



Example 2:


Input:

./a.out 123456
Output:

Correct password 123456

See PasswordProgram.pdf for detailed description of the program algorithm. I created this file to help other students when I was a TA for this class the following semester.