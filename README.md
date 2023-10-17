# Code Execution Procedure
1. Open the solution.cpp and go to the main() function.
2. write the file path in the string that is filename.
3. ( Example : string filename = "textfile.txt"; // enter the file name )
4. Now you can Execute the solution.cpp .

# Approach and Algorithm
we use **trie based approach**. because it is easy to visualize and effecient time complexity.
**algorithm:**      
step 1: Make the trie by reading character by character in whole words.     
step 2: Initialize the first_ans and second_ans.      
step 3: run wordBreak function for every words.        
1. `CHECK WORD IS COMPOUNDED OR NOT` - if the word lie in the trie and count ( count indecate how many part exist in the file.) is more then one. then we say that is complete compounded string.
 
2.  IF COMPOUNDED - 
                    (i)check current compounded word `length > then first_ans` ? If yes -- then second_ans = first_ans , first_ans = current compounded word.
                    (ii) check current compounded word length > then second_ans ? If yes -- then second_ans = current compounded word.
step 4: Return first_ans and second_ans.

# Results:       
1. Output for File: Input_02.txt
   `First Longest : ethylenediaminetetraacetates
   Second Longest : electroencephalographically`
2. Output for File: Input_01.txt
   `First Longest : ratcatdogcat
   Second Longest : catsdogcats`

        
        
