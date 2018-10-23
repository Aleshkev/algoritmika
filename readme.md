# Algoritmika

It is a repository where I put most of my solutions for various competitive programming problems. Such repositories have become somewhat fashionable lately, and such fashion-forward person as I can't be left behind.

> First, spend two hours on a problem. \
> Only then, if you still don't know the solution, look for a hint.
>
> [...]
> If you look at someone else's code, you must analyze and understand it.
When you are sure you know how everything works, don't look at this code again and write your own from scratch.
>
> <cite>*— Mr Daniel Olkowski*

Please don't use these solutions for evil. Do not use them to cheat. Do not steal them without attribution (see [license](#license) slightly below).

Code quality varies from file to file, from line to line. Generally, files are formatted using Google style and I'm a fan of spaces in expressions like `a + b`, but I also usually use `typedef intmax_t I`, so it all kind of cancels out.
Please remember, programming contests are a different world from software engineering and 'good practices' are consistently and purposefully ignored.

Also, don't even suggest changing carefully thought-out variable names like `trevor`, `ardrev` or `tablitsa`.

## License

My code (all .cpp and .py files) are available under MIT License.

## Directory structure

Every contest I took part in has its own directory. I usually throw away all non-working solutions.

`archaic/` contains files copied from the mighty past (1 ≈ 2016/17; 2 ≈ 2016/17-school; 3 ≈ 2017/2018).

# Technicalities

## .vscode

After long battles with backward-progressive Code::Blocks "IDE", I switched to lightweight [VS Code](https://code.visualstudio.com). Unfortunately for me, setting it up wasn't as easy as one would hope.

So I wrote (mainly for future me) what I did, why, and what I may need to change in the future. The difficulty of setup is also the reason I decided to just put my `.vscode` folder in the repository, along with absolute paths to my compiler and debugger (the paths are standard installation directory of MinGW from Chocolatey).

But I like the resulting configuration, where I can just compile *any* C++ file immediately, and even debug it with the amazing VS Code debugging shell.

Problems with this configuration:
1. Files are recompiled, even if they didn't change from one run to the next.
2. To make program stop at the end of execution, `system("pause");` or breakpoint is needed. The problem with first option is that if executable is called with output redirected to file, "Press any key to continue. . ." will be saved too. Code::Blocks uses custom runner which inserts the pause after execution. Maybe it would be possible to create custom runner which also solves the first problem too?

### Files

1. `tasks.json`: build tasks.
Contains path to `gcc.exe`.
2. `launch.json`: launches debugger.
First, executes the `g++ debug` task, then launches debugger.
Contains path to `gdb.exe`.
3. `settings.json`:
sets `clang-format` style to `Google`.
Sets indentation style to 2 spaces (matching with Google style).
Enables autoformatting on save.
