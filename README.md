# Student-Management-System
This project is a C program that manages student records for a course. It allows for the creation of new student records, setting student grades, calculating and displaying averages, and displaying students within a specified average grade interval.

## Features

- Create new student records.
- Set grades for students.
- Calculate and display the average grade of a student.
- Display the average grades of all students.
- Display students with average grades within a specified interval.

## Usage

### Compiling the Code

To compile the code, use the following command:

```sh
gcc -o student_management student_management.c
```

### Running the Program

Run the compiled program using:

```sh
./student_management
```

### Program Flow

1. The program starts by initializing a course with predefined course name and code.
2. The user is presented with a menu of options to manage student records:
   - Create a new student
   - Set grades for a student
   - Find and display the average grade of a student
   - Display the average grades of all students
   - Display students with average grades within a specified interval
   - Exit the program

## Example

Here's an example of how the program works:

1. When prompted, choose an option from the menu by entering the corresponding number.
2. Follow the prompts to input student information, set grades, or display averages.
3. The program will perform the requested action and display relevant information.

## Code Overview

### Structures

- `Student`: Stores individual student information including name, last name, student ID, grades, and average.
- `Course`: Stores course information including course name, course code, current student count, and an array of students.

### Functions

- `createNewStudent`: Prompts the user to enter new student information and adds the student to the course.
- `findStudentByID`: Searches for a student by ID and returns a pointer to the student record.
- `setGradeOfStudent`: Prompts the user to enter grades for a student and updates the student's record.
- `findAndDisplayAverage`: Calculates and displays the average grade for a student.
- `displayAverageOfAllStudents`: Displays the average grades of all students in the course.
- `displayAverageOfStudentsInInterval`: Displays students whose average grades fall within a specified interval.
