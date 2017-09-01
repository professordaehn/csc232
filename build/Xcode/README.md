# Xcode Project File Generation

We can use `cmake` to generate an Xcode project in the following manner. In the current directory, i.e., `build/Xcode` type the following (keeping in mind not to type the `$` as it represents the command-line prompt and not a command to type):

```bash
$ cmake -G "Xcode" ../..
```

You'll find a number of files created, and ultimately, an Xcode project in the current folder.
