<h1>*README.md*<h1/>

# Custom printf Implementation
A C function that replicates the behavior of the standard ‘printf’ function

## Project description

This project consists of creating our own version of the printf function. We utilize variadic functions to handle multiple arguments, allowing the function to accept a dynamic number of inputs.

The process begins with creating a printf.c file, where we implement the core of our custom printf function. This function is responsible for processing the format string and handling different specifiers.

Then, we create a separate file for auxiliary functions, where we handle each specifier individually. Each specifier is processed and printed correctly, allowing our custom printf to replicate the behavior of the standard printf.

### Technical documentation

Variadic functions

It allow reciving a large amount of arguments. It is defined in the library <stdarg.h>

Structure:

- ‘va_list’ : defines a list of arguments
- ‘va_start’ : initializes the arguments list
- ‘va_arg’ : Finds the next argument from the list
- ‘va_end’ : It resets the list after processing

#### Return Value

The _printf function returns:

• The total number of characters printed, excluding the null character (\0).
• -1 if an error occurs, such as a NULL pointer in the format string.

![Beige_and_Pink_Modern_Business_Process_Flowchart_Diagram](https://github.com/user-attachments/assets/1169162b-41b2-421c-9117-32883673c92d)

##### Files description

printf.c : 

- Contains the main implementation of _printf.
- Processes the format string and calls helper functions for each format specifier.

aux_functions.c :

- Includes helper functions to process and convert input arguments (like characters, strings, integers, etc.).

main.c :

- • Test program that validates the functionality of _printf.

main.h : 

- Header file containing function declarations and necessary macros.

###### Valid specifiers

%c : prints a single character

%s : prints a string

%d / s : prints integer (decimal, negative, etc)

%% : prints %

######## Autors

Aylin Pintos
Owen Matusevicius
