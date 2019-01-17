### How to setup the working CLISP's working folder

This is going to be the folder in which you will have your .lisp files. If you do not set the working folder, you will have to put your scripts in the directory in which you installed CLISP.

This is the script that you have to put inside your desired working folder. Save it as a .bat file and open it. Assuming you have CLISP version 2.49 installed in C:\clisp-2.49, you can just copy the script. Otherwise, modify the script to point to the installation directory.

```batch
C:\clisp-2.49\clisp -B "C:\clisp-2.49" -M "C:\clisp-2.49\base\lispinit.mem" 
```

