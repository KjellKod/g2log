#ifndef CRASH_HANDLER_H_
#define CRASH_HANDLER_H_

#include <string>
#include <csignal>

namespace g2
{

// PRIVATE-INTERNAL  API
namespace internal
{
/** \return signal_name. Ref: signum.h and \ref installSignalHandler */
std::string signalName(int signal_number);

/** Re-"throw" a fatal signal, previously caught. This will exit the application
  * This is an internal only function. Do not use it elsewhere. It is triggered
  * from g2log, LogWorker after flushing messages to file */
void exitWithDefaultSignalHandler(int signal_number);
} // end g2::interal


// PUBLIC API:
/** Install signal handler that catches FATAL C-runtime or OS signals
    SIGABRT  ABORT (ANSI), abnormal termination
    SIGFPE   Floating point exception (ANSI): http://en.wikipedia.org/wiki/SIGFPE
    SIGILL   ILlegal instruction (ANSI)
    SIGSEGV  Segmentation violation i.e. illegal memory reference
    SIGTERM  TERMINATION (ANSI) */
void installSignalHandler();
}

#endif // CRASH_HANDLER_H_