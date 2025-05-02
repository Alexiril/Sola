@echo off
setlocal
set platf=x64
set conf=Release
set target=Build
set dir=%~dp0
set parallel=/m
set verbose=/nologo /v:m /clp:summary
set kill=
set do_pgo=
set pgo_job=-m test --pgo
set UseTIER2=
set Py_OutDir=%dir%/../artifacts
set IncludeTkinter=false

:CheckOpts
if "%~1"=="-c" (set conf=%2) & shift & shift & goto CheckOpts
if "%~1"=="-p" (set platf=%2) & shift & shift & goto CheckOpts
if "%~1"=="-r" (set target=Rebuild) & shift & goto CheckOpts
if "%~1"=="-t" (set target=%2) & shift & shift & goto CheckOpts
if "%~1"=="-d" (set conf=Debug) & shift & goto CheckOpts
if "%~1"=="-m" (set parallel=/m) & shift & goto CheckOpts
if "%~1"=="-M" (set parallel=) & shift & goto CheckOpts
if "%~1"=="-v" (set verbose=/v:n) & shift & goto CheckOpts
if "%~1"=="-vv" (set verbose=/v:d /ds) & shift & goto CheckOpts
if "%~1"=="-q" (set verbose=/v:q /nologo /clp:summary) & shift & goto CheckOpts
if "%~1"=="-k" (set kill=true) & shift & goto CheckOpts
if "%~1"=="--pgo" (set do_pgo=true) & shift & goto CheckOpts
if "%~1"=="--pgo-job" (set do_pgo=true) & (set pgo_job=%~2) & shift & shift & goto CheckOpts
if "%~1"=="--disable-gil" (set UseDisableGil=true) & shift & goto CheckOpts
if "%~1"=="--test-marker" (set UseTestMarker=true) & shift & goto CheckOpts
if "%~1"=="--regen" (set Regen=true) & shift & goto CheckOpts
if "%~1"=="--experimental-jit" (set UseJIT=true) & (set UseTIER2=1) & shift & goto CheckOpts
if "%~1"=="--experimental-jit-off" (set UseJIT=true) & (set UseTIER2=3) & shift & goto CheckOpts
if "%~1"=="--experimental-jit-interpreter" (set UseTIER2=4) & shift & goto CheckOpts
if "%~1"=="--experimental-jit-interpreter-off" (set UseTIER2=6) & shift & goto CheckOpts
if "%~1"=="--without-remote-debug" (set DisableRemoteDebug=true) & shift & goto CheckOpts
if "%~1"=="--pystats" (set PyStats=1) & shift & goto CheckOpts
if "%~1"=="--tail-call-interp" (set UseTailCallInterp=true) & shift & goto CheckOpts
rem These use the actual property names used by MSBuild.  We could just let
rem them in through the environment, but we specify them on the command line
rem anyway for visibility so set defaults after this
if "%~1"=="-e" (set IncludeExternals=true) & shift & goto CheckOpts
if "%~1"=="-E" (set IncludeExternals=false) & shift & goto CheckOpts
if "%~1"=="--no-ctypes" (set IncludeCTypes=false) & shift & goto CheckOpts
if "%~1"=="--no-ssl" (set IncludeSSL=false) & shift & goto CheckOpts

if "%IncludeExternals%"=="" set IncludeExternals=true
if "%IncludeCTypes%"=="" set IncludeCTypes=true
if "%IncludeSSL%"=="" set IncludeSSL=true

if "%IncludeExternals%"=="true" call "%dir%get_externals.bat"

if "%do_pgo%" EQU "true" if "%platf%" EQU "x64" (
    if "%PROCESSOR_ARCHITEW6432%" NEQ "AMD64" if "%PROCESSOR_ARCHITECTURE%" NEQ "AMD64" (
        echo.ERROR: Cannot cross-compile with PGO 
        echo.       32bit operating system detected. Ensure your PROCESSOR_ARCHITECTURE
        echo.       and PROCESSOR_ARCHITEW6432 environment variables are correct.
        exit /b 1 
    )
)

if not exist "%GIT%" where git > "%TEMP%\git.loc" 2> nul && set /P GIT= < "%TEMP%\git.loc" & del "%TEMP%\git.loc"
if exist "%GIT%" set GITProperty=/p:GIT="%GIT%"
if not exist "%GIT%" echo Cannot find Git on PATH & set GITProperty=

call "%dir%find_python.bat" %PYTHON%
if ERRORLEVEL 1 (echo Cannot locate python.exe on PATH or as PYTHON variable & exit /b 3)
set PythonForBuild=%PYTHON%

rem Display the current build version information
call "%dir%find_msbuild.bat" %MSBUILD%
if ERRORLEVEL 1 (echo Cannot locate MSBuild.exe on PATH or as MSBUILD variable & exit /b 2)
%MSBUILD% "%dir%pythoncore.vcxproj" /t:ShowVersionInfo /v:m /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
if ERRORLEVEL 1 exit /b 3

if "%do_pgo%"=="true" (
    set conf=PGInstrument
    call :Build %1 %2 %3 %4 %5 %6 %7 %8 %9
)
rem %VARS% are evaluated eagerly, which would lose the ERRORLEVEL
rem value if we didn't split it out here.
if "%do_pgo%"=="true" if ERRORLEVEL 1 exit /B %ERRORLEVEL%
if "%do_pgo%"=="true" (
    del /s "%dir%\*.pgc"
    del /s "%dir%\..\Lib\*.pyc"
    echo on
    call "%dir%\..\python.bat" %pgo_job%
    @echo off
    call :Kill
    set conf=PGUpdate
    set target=Build
)

:Build
rem Call on MSBuild to do the work, echo the command.
rem Passing %1-9 is not the preferred option, but argument parsing in
rem batch is, shall we say, "lackluster"
echo on
%MSBUILD% "%dir%pcbuild_min.proj" /t:%target% %parallel% %verbose%^
 /p:Configuration=%conf% /p:Platform=%platf%^
 /p:IncludeExternals=%IncludeExternals%^
 /p:IncludeCTypes=%IncludeCTypes%^
 /p:IncludeSSL=%IncludeSSL% /p:IncludeTkinter=%IncludeTkinter%^
 /p:DisableGil=%UseDisableGil%^
 /p:UseTestMarker=%UseTestMarker% %GITProperty%^
 /p:UseJIT=%UseJIT%^
 /p:UseTIER2=%UseTIER2%^
 /p:PyStats=%PyStats%^
 /p:UseTailCallInterp=%UseTailCallInterp%^
 /p:DisableRemoteDebug=%DisableRemoteDebug%^
 %1 %2 %3 %4 %5 %6 %7 %8 %9

@echo off
exit /b %ERRORLEVEL%