*2021 Update*

While you are free to use g2log I am mainly keeping it here as an archived open source repo. Most of the community has moved to G3log and I recommend you do to. 
I am not planning to address issues for g2log. 


**2015 Update:**
If you need more flexibility, custom formatting, writing your own loggins sinks, etc then you should try out g3log. 
G3log is the successor of g2log. G3log can be found at [https://github.com/KjellKod/g3log](https://github.com/KjellKod/g3log)

**2016 Update:**
Please note that for Windows you need VS 2013 or newer.
Ref: [VS 2012](https://bitbucket.org/KjellKod/g2log/issues/11/error)



EXAMPLE USAGE OF G2LOG
=======================
Optional to use either streaming or printf-like syntax
    LOG(INFO) << "As Easy as ABC or " << 123;
    or 
    LOGF(WARNING, "Printf-style syntax is also %s", "available");


Conditional logging
    int less = 1; int more = 2
    LOG_IF(INFO, (less<more)) <<"If the condition was true, then this text will be logged";
    
    // or with printf-like syntax
    LOGF_IF(INFO, (less<more), "if %d<%d then this text will be logged", less,more);


Design-by-Contract
CHECK(false) will trigger a "fatal" message. It will be logged, and then the 
application will exit.

    CHECK(less != more); // not FATAL
    CHECK(less > more) << "CHECK(false) triggers a FATAL message");




WHAT IS G2LOG?
====================
In depth information can be found at 
http://www.codeproject.com/Articles/288827/g2log-An-efficient-asynchronous-logger-using-Cplus



Or just read the short summary below:
-------------------------------------

G2log is an asynchronous, "crash safe" logger and design-by-contract library. 
What this means in practice is that 

1. All the slow I/O disk access is done in a background thread. This ensures that the
 other parts of the software can immediately continue with their work after making a
 log entry. 

2. g2log provides logging, Design-by-Contract [#CHECK], and flush of log to file at
 shutdown. Buffered logs will be written to file before the application shuts down.

3. It is thread safe, so using it from multiple threads is completely fine. 

4. It is CRASH SAFE, in that it will catch certain fatal signals, so if your application  
 crashes due to, say a segmentation fault, SIGSEGV,  or some other fatal
 signals it will  log and save to file this crash and all previously buffered log
 entries before exiting.

 
5. It is cross platform. For now, tested on Windows7/MSVC and Ubuntu/gcc/clang. 

6. On Ubuntu a caught fatal signal will generate a stack dump to the log. This is
 not yet available on Windows due to the platforms complexity when traversing the
 stack. Stack dump on Windows will be released later and a beta is available on
 request. 

7. G2log is used in commercial products as well as hobby projects since early 2011.
The code is given for free as public domain. This gives the option to change, use,
 and do whatever with it, no strings attached.

8. The stable version of g2log is available at https://bitbucket.org/KjellKod/g2log
   G3log is the recommended logger in the "g2log-g3log" family. https://github.com/KjellKod/g3log
   G2log is kept alive here at bitbucket due to a demand for a logger in an environent where 
   the latest compiler support for C++11 and newer is available. 





LATEST CHANGES
=====================
2013, Sept 24th
 * Added support for Clang. Tested on Linux, not OSX.

2012, Oct 14th
* Complete threadsafe use of localtime for timestamp. (see code: g2time)
* Runtime change of filename, request of filename. (see code g2logwoker g2future)
* Tested on 

    x86 Windows7: Visual Studio 2012 Desktop Express
    x86 Ubuntu 11.04:  gcc 4.7.3
    x64 Ubuntu 12...: gcc 4.7.2
    x64 Windows7: Visual Studio 2012 Professional
    NOTE: It does NOT work with "Visual Studio 11 Beta" (not as C++11 compliant 
    as VS2012)



HOW TO BUILD
===================
This g2log is a snapshot from KjellKod repository. 
It contains what is needed to build example, unit test and performance test of g2log. 

justthread C++11 thread library is no longer needed. 
* On Windows it is enough to  use Visual Studio 11  (2012). 
* On Linux it is enough to use gcc or some fairly recent version of clang.


If you want to integrate g2log in your own software you need the files under 
g2log/src



BUILDING g2log: 
-----------
The default is to build an example binary 'g2log-FATAL'
I suggest you start with that, run it and view the created log also.

If you are interested in the performance or unit tests then you can 
enable the creation of them in the g2log/CMakeLists.txt file. See that file for 
more details

--- Building on Linux ---

    cd g2log
    mkdir build
    cd build 
    cmake ..
    make

--- Building on Linux/Clang ----

    cd g2log
    mkdir build_clang
    cd build_clang
    cmake -DCMAKE_CXX_COMPILER=clang++ ..
    make


--- Building on Windows ---
Please use the Visual Studio 11 (2012) command prompt "Developer command prompt"

    cd g2log
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 11" ..
    msbuild g2log_by_kjellkod.sln /p:Configuration=Release
  
-- Test the test exectutable with 

    (windows) Release\g2log-FATAL.exe 
    or (Linux) ./g2log-FATAL


      
CONTENTS
===========================
3rdParty -- gtest, glog. 
-----------------------
gtest is needed for the unit tests. 
glog is only needed if you want to run the glog vs g2log comparison tests

gtest is enabled as a DEFAULT option in the CmakeFiles.txt file. If the unit test
is not important for you then just DISABLE that option.  By default the gtest zipped
 library must be UNPACKED before it is used (compilation)

gtest IS included by the CMake and you don't need to do install or compile it in
 any other way than through the g2log cmake setup.

Google's glog is not included and must be installed ONLY IF you want to run the comparison tests


FEEDBACK
=========================
It gives me a boost to know that people and companies out there use g2log. If you use it
feel free to drop me a line. 

If you like it (or not) it would be nice with some feedback. That way I can 
improve g2log. If you have  ANY questions or problems please do not hesitate in contacting me on my blog 
http://kjellkod.wordpress.com/2011/11/17/kjellkods-g2log-vs-googles-glog-are-asynchronous-loggers-taking-over/
or at <Hedstrom at KjellKod dot cc>

Good luck :)

Cheers
Kjell (a.k.a. KjellKod)
