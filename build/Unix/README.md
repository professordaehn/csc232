# Unix Makefile Generation

We can use `cmake` to generate Unix Makefiles in the following manner. In the current directory, i.e., `build/Unix` type the following (keeping in mind not to type the `$` as it represents the command-line prompt and not a command to type):

```bash
$ cmake -G "Unix Makefiles" ../..
```

You'll find a number of files created, and ultimately, a Makefile in the current folder that can be used to build our executables.
