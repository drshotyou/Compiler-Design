Instructions to run Project 1:
Run these commands in the following order:
1)flex scanner.l
2)cc lex.yy.c -ll
3)./a.out < "TestCase".p // Replace "TestCase" with the the test file you want to run. Example) ./a.out < Comments.p
			 // To save terminal output to text file I added &> testOutput.txt at the end of the command.

