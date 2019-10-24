# Algoritmika

It is a repository where I put most of my solutions for various competitive programming problems. Such repositories have become somewhat fashionable lately, and such fashion-forward person as I can't be left behind.

> First, spend two hours on a problem. \
> Only then, if you still don't know the solution, look for a hint.
>
> [...]
> If you look at someone else's code, you must analyze and understand it.
> When you are sure you know how everything works, don't look at this code again and write your own from scratch.
>
> <cite>_— Mr Daniel Olkowski_

Please don't use these solutions for evil. Do not use them to cheat. Do not steal them without attribution (see [license](#license) slightly below).

Code quality varies from file to file, from line to line. Generally, files are formatted using Google style and I'm a fan of spaces in expressions like `a + b`, but I also usually use `typedef intmax_t I` and the likes, so it all kind of cancels out. Please remember, programming contests are a different world from software engineering and 'good practices' are consistently and purposefully ignored.

## Notes

Sometimes you may encounter a file with my notes, usually `notes.md` (English) or `notatki.md` (Polish). Please treat them like something written very quickly. Sometimes I just outright lie there to confuse a very specific person I have in mind. Have fun!

## Directory structure

Every contest I took part in has its own directory. I usually throw away all non-working solutions, but some may be left.

`archive/` contains files copied from the mighty past (1 ≈ 2016/17; 2 ≈ 2016/17-school; 3 ≈ 2017/2018).

## License

My code (all .cpp and .py files, .tex files unless otherwise noted) are available under MIT License.

## .vscode technicalities

After long battles with backward-progressive Code::Blocks "IDE", I switched to lightweight [VS Code](https://code.visualstudio.com). Unfortunately for me, setting it up wasn't as easy as one would hope.

The difficulty of setup is the reason I decided to just put my `.vscode` folder in the repository.

But I like the resulting configuration, where I can just compile _any_ C++ file immediately, and even debug it with the amazing VS Code debugging experience.

Problems with this configuration:

1. Files are recompiled, even if they didn't change from one run to the next.
2. To make program stop at the end of execution, `system("pause");` or breakpoint is needed. The problem with first option is that if executable is called with output redirected to file, "Press any key to continue. . ." will be saved too. The second option won't allow to, well, press any key to close the window; Ctrl+C or Alt+F4 will just raise an error in debugger. Code::Blocks uses custom runner which inserts the pause after execution. Maybe it would be possible to create custom runner which also solves the first problem too?

To solve the second problem I created my `cpp-template.cpp` which compiles with `system("pause")` if `UNITEST` is defined. The fix was intended to be temporary, but I haven't yet found a better solution.

An argument could be made that I need to enable `cout.flush()` on my machine anyway, so an `#if` would be convenient anyway and inserting `system("pause")` there is so easy and understandable that it never is a problem. But a custom runner could also flush stdout. Also, maybe I could just disable `sync_with_stdio` only if I'm sure I won't need the output flushed.

I don't know how to create a "custom runner". If someone knows, or has a better solution to all of the above, please let me know.
