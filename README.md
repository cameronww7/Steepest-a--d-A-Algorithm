# Steepest-a--d-A-Algorithm
Assignment #1

Total Score: 100

Due date: 6/20

This assignment can be completed either individually or by a team with up to 5 members.

---------------------------------------------------------------------------------------------------------------------

Objectives: Implementing a steepest-ascent/-descent hill-climbing algorithm and A* algorithm

to solve the 8-puzzle problem.

---------------------------------------------------------------------------------------------------------------------

Required Tasks

1. Implement two heuristic algorithms, a steepest-ascent/descent hill-climbing and A*

algorithm using three heuristic functions, two heuristics discussed in class (counting # of

tiles out of place and measuring the distance of those tiles out of place) and another one

from your own heuristic (e.g., combination of the above two heuristics or other non-trivial

one). The acceptable programming language includes C/C++, Java, Python (version 3.4.3 or

higher), or C#. Your programs will be tested by providing an arbitrarily chosen initial and

target tile configurations stored in a text file called “in.txt” as shown below. There is exactly

one blank space between each tile. DO NOT ask entering the initial and target data or any

parameter.

2 8 3

1 6 4

7 x 5

1 2 3

4 5 6

7 8 x

When the driver program called “hw1” is executed, the program must produce a report file

called “out.txt” with information including at least the name of algorithm, name of heuristic,

number of steps, and at least five boards for each row showing the move for each step as

illustrated below until it finds a solution or reaches the max number of steps, 100.

Algorithm: Steepest-descent hill-climbing

Heuristic function: CountingTilesOutOfPlace()

Number of steps: 4

x 1 3 1 x 3 1 2 3 1 2 3 1 2 3

4 2 5 4 2 5 4 x 5 4 5 x 4 5 6

7 8 6 7 8 6 7 8 6 7 8 6 7 8 x

Note: If your program cannot find a solution in 100 steps, write a message “Unable to find a

solution”.

Tip: When a hill-climbing algorithm reaches a local maxima, make a random decision to get out

of it.

2

2. Properly modularize your program clearly separating it into different modules (classes or

packages) including at least the driver program called “hw1”.

To separate modules for data structures, algorithms, heuristic functions, and reporting

functions for easier modification or maintenance, consider using proper design patterns such

as “adaptor pattern” and “strategy pattern” which allow changes of a module with no or

least change of other modules.

In addition, document your program properly naming and commenting each module and

functions so that one can easily understand its purpose.

Note: Write a README file for detailed instructions on how to compile and run your

program. DO NOT require me to download an unusual version of compiler or tool to test

your program. I am not able to compile, execute, or test your program, you will receive the

minimum score of this assignment, only considering the effort.

3. Write a brief report in Word format including all of the followings:

(a) Your name or a list of member names, contact email address(s), the percentage

contribution to this assignment if it was completed by a team. If a team cannot reach a

consensus on the individual contribution, include the individual’s claimed percent

contribution with a brief description on specific tasks performed. (b) A brief description on

how your program is modularized. (c) A brief description on how to compile and run your

program. (d) the summary results of your program including the number of steps needed to

find a solution for each algorithm and heuristic function, and effectiveness or quality of each

heuristic function (e) optionally references specifying the source of the program if some

portion or all of the program was reused (or copied) from other people’s code.

Warning: Although the code reuse is allowed for this assignment, copying code from other

person or team in this class is strictly prohibited. Any one or team violated this rule will

receive ZERO score from this assignment.

How to submit this assignment

• Zip/compress both your report and program files into ONE file and submit the zipped

file to Titanium by the due date. I strongly recommend you to write the report in Word

format so that I can provide my feedback directly in the report. If a PDF format of report

is submitted, no feedback will be provided.

• Submit only ONE report or file from each team to Titanium.

Grading criteria

• Grade will be based on the quality of the report and program. The level of quality can be


A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
evaluated by the level of understanding on the related subjects, requirements, and writing.
