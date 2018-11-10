@echo off


rem  This program is designed for simplicity and compatibility: it works on Windows
rem  7 and Windows 10.
rem  It can be modified to provide additional functionality.
rem  It could be rewritten into Python, but then it can't run on school computers 
rem  without Python >:(   I can of course use something like py2exe, but then the
rem  program starts up way too long.
rem  It could be written in C++ or Rust. But this probably would be even more
rem  complex than writing this simple batch file.
rem  So just forgive me for writing this in batch.

rem  Thou art forgiven - the People

rem  Cool hack(s) used here:
rem  <nul set /p=TEXT  prints TEXT without trailing newline.


setlocal enabledelayedexpansion

rem Display help if requested
if "%1" == "/?" (
    goto :displayHelp
)

rem Parse positional arguments
if not "%1" == "" (
    set programExecutable=%1
    shift
) else (
    echo The 'programexecutable' argument is required.
    call :invalidUsage & exit /b -1
)
if not "%1" == "" (
    set testsFolder=%1
    shift
) else (
    echo The 'testsfolder' argument is required.
    call :invalidUsage & exit /b -1
)

rem Defaults for switches
set verboseMode=0
set abortOnWrongAnswer=0

rem Parse switches
:switchParsingLoop:
    if "%1" == "" (
        rem End of arguments
        goto :breakSwitchParsingLoop
    ) else if "%1" == "/?" (
        echo '/?' can be only used in 'SOLTEST /?'.
        call :invalidUsage: & exit /b -1
    ) else if /i "%1" == "/V" (
        set verboseMode=1
    ) else if /i "%1" == "/A" (
        set abortOnWrongAnswer=1
    ) else (
        echo Invalid switch '%1'. 1>&2
        call :invalidUsage & exit /b -1
    )
    shift
goto switchParsingLoop
:breakSwitchParsingLoop


rem Do actual work
rem Iterate through all *.in files in testsFolder
for /r %testsFolder% %%t in (*.in) do (

    rem inputFile is the current file in the loop, full path, e.g. C:\test0.in
    rem testName is a name of test displayed to user, file name with extension, e.g. test0.in
    rem To programOutputFile will be written output which program returns, full path, e.g. C:\test0.p.out
    rem expectedOutputFile should contain expected output, full path, e.g. C:\test0.out
    set inputFile="%%t"
    set testName=%%~nxt
    set programOutputFile="%%~dpnt.p.out"
    set expectedOutputFile="%%~dpnt.out"
    
    rem Print test name
    if not %verboseMode% == 1 (
        <nul set /p=!testName!: & rem (just to keep space at the end)
    ) else (
        echo --- !testName! ---
    )
    
    rem Run program executable
    %programExecutable% < !inputFile! > !programOutputFile!
    
    if not !errorlevel! == 0 (
        echo Program returned !errorlevel!.
    )
    
    rem Print program's and expected output
    if %verboseMode% == 1 (
        echo Program output:
        type !programOutputFile! & echo.
        if exist !expectedOutputFile! (
            echo Expected output:
            type !expectedOutputFile! & echo.
            <nul set /p=Result:
        )
    )
    
    if exist !expectedOutputFile! (
        rem Compare program's and expected output (ignore whitespace)
        fc /w !programOutputFile! !expectedOutputFile! > nul
        
        rem Now errorlevel contains information about comparison results
        if !errorlevel! == 0 (
            echo OK
        ) else if !errorLevel! == 1 (
            echo Wrong answer
            if !abortOnWrongAnswer! == 1 (
                echo Aborting.
                goto :eof
            )
        ) else (
            echo Error during comparing
        )
    ) else (
        echo No file with expected output
    )
)
    
rem Exit program
goto :eof


rem Displays help message    
:displayHelp
    echo Tests if program passes tests.
    echo.
    echo SOLTEST programexecutable testsfolder [/V]
    echo.
    echo programexecutable  Executable which is run
    echo testsfolder        Folder containing *.in files which are directed to program's
    echo                    standard input. May contain corresponding *.out files.
    echo.
    echo /V                 Verbose mode.
    echo                    More information is printed.
    echo.
    echo /A                 Abort on first wrong answer.
goto :eof

rem Displays invalid usage error message
:invalidUsage
    echo Invalid usage. Type 'SOLTEST /?' for help. 1>&2
goto :eof
