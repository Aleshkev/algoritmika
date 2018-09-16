# About

It is a repository where I put most of my solutions for various competetive programming problems. Such repositories became somewhat fashionable lately, and such fashion-forward person as I can't be left behind.

> First spend two hours on a problem. \
> Only then, if you still don't know the solution, you can look for a hint.
>
> [...]
> If you look at someone's code, you must analyze it and understand it.
When you are sure you know how everything works, write it from scratch, without looking at this code again.
>
> <cite>— Mr Daniel Olkowski

Please don't use these solutions for evil. I publish these in hope of bettering the humankind, not enabling someone to cheat.

Code quality varies from file to file, from line to line. Generally, files are formatted using Google style and I'm a fan of spaces in expressions like `a + b`, but I also usually use `typedef intmax_t I`, so it all kind of cancels out.

Also, don't even suggest changing carefully thought-out variable names like `trevor`, `ardrev` or `tablitsa`.

## License

My code (all .cpp and .py files) are available under MIT License.

# Technicalities

## .vscode

After long battles with backward-progressive Code::Blocks "IDE", I switched to lightweight [VS Code](https://code.visualstudio.com). Unfortunately for me, setting it up wasn't as easy as one would hope.

So I wrote (mainly for future me) what I did, why, and what I may need to change in the future. The difficulty of setup is also the reason I decided to just put my `.vscode` folder in the repository, along with absolute paths to my compiler and debugger (the paths are standard installation directory of MinGW from Chocolatey).

But I like the resulting configuration, where I can just compile *any* C++ file immediately, and even debug it with the amazing VS Code debugging shell.

Problems with this configuration:
1. Files are recompiled, even if they didn't change from one run to the next.
2. To make program stop at the end of execution, `system("pause");` or breakpoint is needed. The problem with first option is that if executable is called with output redirected to file, "Press any key to continue. . ." will be saved too. Code::Blocks uses custom runner which inserts the pause after execution. Maybe it would be possible to create custom runner which also solves the first problem too?

### Files

`tasks.json`: build tasks.
Contains path to `gcc.exe`.

`launch.json`: launches debugger.
First, executes the `g++ debug` task, then launches debugger.
Contains path to `gdb.exe`.

`settings.json`:
sets `clang-format` style to `Google`.
Sets indentation style to 2 spaces (matching with Google style).
Enables autoformatting on save.
