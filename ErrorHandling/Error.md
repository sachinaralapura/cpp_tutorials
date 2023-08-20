## Introduction
   In the realm of development and programming, encountering errors is an integral aspect of our daily routine. The presence of errors within our code should not be misconstrued as a lack of expertise on our part
    One of the programmer’s a crucial duty involves anticipating and managing errors. The measure of a program's excellence often lies in its adept utilization of error-handling methodologies to effectively mitigate any conceivable issues. However, achieving this objective is undeniably challenging.

## Error Conditions

   Errors that occur at program runtime can seriously interrupt the normal flow of a program. Some common causes of errors are

- division by 0, or values that are too large or small for a type
- errors on file access, for example, file not found
- attempt to access an invalid address in main memory
- no memory available for dynamic allocation

## Traditional Error Handling
 
- errors in function calls are indicated by special return values
- global error variables or flags are set when errors occur, and then checked again later.

 If a function uses its return value to indicate errors, the return value the return value must be examined whenever the function is called, even if no error has occurred.

 In other words, you need to continually check for errors while a program is executing.
If you do happen to forget to check for errors, the consequences may be fatal.

---
## Exception Handling Concept

Exception handling is based on keeping
the normal functionality of the program separate from error handling.
The basic idea is
that errors occurring in one particular part of the program are reported to another part of
the program, known as the calling environment.

### The throw Statement
---

An exception that occurs is recorded to the calling environment by means of a throw
statement; this is why we also say that an exception has been thrown.

> Syntax: ``` throw fault; ```

_fault_ is an exception object that is thrown to the calling environment.

> example: ``` throw "string";  ```

## Exception Classes

Normally, you define your own exception classes to categorize exceptions.

```c++
class myError(){
    // information about error
}

int myFunc(int a , int b){
    if(a < b)
        throw "error a is less than b";   // throwing string object 

    if(a > b){
        myError errorObj;       // throwing object of class myError
        throw errorObj;
    }
}
```

An exception class need not contain data members or methods. Generally,
the exception class will contain members that provide more specific information on the
cause of the error.

Instead of creating a local exception object errorObj, a temporary object
can be created:

```c++ 
 throw Error();  // It is shorter
```

## EXCEPTION HANDLERS

After the error object is throw to calling environment , the exception needs to be handled , the part of the program that handle the error is refered to as _exception handler_
An exception handler catches the exception object
thrown to it and performs error handling.

Therefore two things to implement while handling exception
- part of the program that may throws error
- part that will handle or process various exception type
    
there are two keywords for this task **try and catch**

### try and catch block
---
The try block contains the code blocks that may produce similar type of 
error and exception can be thrown.
The catch block immediately follows the try block , _catch_ blo ck contains the defination of the **exception handler** , if there is no exception handler defined the
program will not simply enter an undefined state but will be orderly terminated by a call
to the standard function terminate().

    when a error statement is executed , a object of same type and same content is created and thrown as exception.

> example ``` throw "error" ;```
 
    In above case a new string object is created and same content , if the thrown statement is class type , the copy constructor is executed

After executing a handler, the program continues with the first statement following the catch blocks, unless the handler throws another exception or terminates the program. After completing exception handling, the exception object that was thrown is destroyed.

### Exception Specifications 
---
A programer must know what are the type of exception that a function may throw ,so that he or she will be able to handle errors 

The exceptions a function can throw can be stated in a so-called exception specification list when you declare a function.

> Example ```c++ int func(double) throw(BadIndex , OutofRange); ```

    If you just specify the empty exception specification list that is throw() , no exception are thrown. If there is no throw statement then any(all) exception are thrown.

##  DEFINING YOUR OWN ERROR CLASSES

The type of exception object thrown determines the which handler to execute , hence exception class does not need to have any members.

However exception classes contains data members , You can use the data members of error classes to rescue data threatened by an error
condition. For example, you can store data important for exception handling in an exception object.

**example**
```c++
#include <string>
#include <iostream>
using namespace std;
void check(int , int);
class MyError{
    private:
        string message;
    public:
        MyError( const string& s) : message(s) {}
        const string& getMessage() const {return message;}
};

int main(){
    int x, y;
    try{
        cout <<  "enter two number" << endl;
        cin >> x >> y;
        check(x ,y);
    }
    catch(MyError& error){
        cerr << error.getMessage();
    }
   
}

 void test(int x , int y ) throw (MyError){
        if( y == 0)
            throw MyError("Denominator cannot be zero");
    }
```

