I had to manually copy output and pase it to the .txt files as outputting to a file with &> "textfile".txt would result in a segmentation fault.
If you output to them you will delete the outputs I am pasting there! 
Those files are: test00-type-error-in-array.txt
                 test02-uninitialized-var.txt
                 test-array-dim-error_3.txt
                 test-array-index_error_3.txt
                 test-duplicate2.txt
                 test-undeclared_2.txt
                 test-uninitialized_2.txt

To compiler all files use ./build.sh
ignore the warnings, it still works
to parse the files use ./parse "testFile".p &> "testFile".txt
As previously mentioned on the listed files &> "testFile".txt results 
in a segmentation fault so please look at the output  from running ./parse "testFile".p 

                 