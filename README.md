# process-creation-assignment (April 2023)

### Operating Systems Assignment  
  
  Karena Qian  
  Assignment #1 - Process creation  
  CSC 3350  
  April 14, 2023

 
## Command Line Execution Commands

### Running main program with ‘Karena Qian – simpleSleep.c’:  
  
  ```
  gcc -g -Wall -Wextra -o sleepy ‘Karena Qian – simpleSleep.c’  
  gcc 'Karena Qian - Process Creation.c' -o createProcess  
  ./createProcess ./sleepy [an integer from 4-10]
```


### Running main program with ‘Karena Qian - loops.c’:

```
gcc ‘Karena Qian - loops.c’ -o loops
gcc 'Karena Qian - Process Creation.c' -o createProcess
./createProcess ./loops [an integer] [an integer]
```

### Running main program with ‘Karena Qian - hardcodedSleep.c’:

```
gcc ‘Karena Qian - hardcodedSleep.c’ -o hardsleep
gcc 'Karena Qian - Process Creation.c' -o createProcess
./createProcess ./hardsleep
```

 
## ‘Karena Qian – Process Creation.txt’ Sample Execution Output
```
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
sleep program called with argument 10
Executing ./sleepy with fork, exec, and wait....
Finished executing
Executing ./sleepy with only system.....
Finished executing
Time of fork(), exec(), and wait(): 10000.00
Time of system(): 10000.00
```
The execution times are very much equal, probably because both methods have around the same time complexity, and that there isn’t much difference between the two, besides one being manual and the other being automatic.

 
## Assignment Reflections

### A.	What was the most difficult thing for you in this assignment? You can list more than one if you would like.

One of the most difficult things for me in this assignment was figuring out how to add a space between two words in C. While writing the system() method in the main program, I discovered that the function can only take in a single string command, nothing else. After I successfully finished the basic hard-coded implementation, I decided to go for the extra credit, which meant I had to figure out how to put the command line arguments together into a single valid command line command I can pass into system(). Eventually, through a post on StackOverflow, I was able to come up with a reliable way to concatenate words together with spaces using memset() and strncat(). 

### B.	What are 2 learning you took away from this assignment?

The biggest thing I learned from this assignment was how to use the function memset() to add spaces to words in C. Another big thing I learned from this assignment was how to implement command line inputs into my program through argc and argv. It was my first time using those parameters. 


 
## References
- Cameron, A. M. (n.d.). Lecture04 – process api v2 [PowerPoint slides]. Canvas. https://canvas.spu.edu/courses/59709/files/3860244?module_item_id=924366 
- CPlusPlus. (n.d.) <ctime> (time.h). https://cplusplus.com/reference/ctime/ 
- DomHofman. (2021, October 9). In parameter in argv[]. [Online forum post]. StackOverflow. https://stackoverflow.com/questions/69505884/int-parameter-in-argv 
- Fawcett, A. (2020, December 18). How to concatenate strings in c: A five minute guide. Educative. https://www.educative.io/blog/concatenate-string-c 
- GeeksforGeeks. (2023, March 11). Command line arguments in c/c++. https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/ 
- GeeksforGeeks. (2021, June 28). Memset() in c with examples. https://www.geeksforgeeks.org/memset-c-example/ 
- Kameleshjoshi18. (2023, March 6). Sleep() function in c. GeeksforGeeks. https://www.geeksforgeeks.org/sleep-function-in-c/ 
- SomethingSomething. (2014, February 18). C: How to append/concatenate ‘x’ spaces to a string. [Online forum post]. StackOverflow. - -https://stackoverflow.com/questions/21855807/c-how-to-append-concatenate-x-spaces-to-a-string 
- Upendra Bartwal,. (2022, August 24). Generating random number in a range in c. GeeksforGeeks. https://www.geeksforgeeks.org/generating-random-number-range-c/ 
