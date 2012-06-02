/** ==========================================================================
* 2011 by KjellKod.cc. This is PUBLIC DOMAIN to use at your own risk and comes
* with no warranties. This code is yours to share, use and modify with no
* strings attached and no restrictions or obligations.
* ============================================================================*/

#include "g2logworker.h"
#include "g2log.h"
#include <iomanip>
#include <thread>

namespace
{
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
	const std::string path_to_log_file = "./";
#else
	const std::string path_to_log_file = "/tmp/";
#endif
}

int main(int argc, char** argv)
{
  double pi_d = 3.1415926535897932384626433832795;
  float pi_f = 3.1415926535897932384626433832795f;


  g2LogWorker logger(argv[0], path_to_log_file);
  g2::initializeLogging(&logger);
  std::cout << "*** This is an example of g2log " << std::endl;
  std::cout << "*** It WILL exit by a FATAL trigger in the end" << std::endl;
  std::cout << "*** Please see the generated log and compare to " << std::endl;
  std::cout << "***    the code at g2log/test_example/main.cpp" << std::endl;
  std::cout << "\n*** Log file: [" << logger.logFileName() << "]\n\n" << std::endl;

  LOGF(INFO, "Hi log %d", 123);
  LOG(INFO) << "Test SLOG INFO";
  LOG(DEBUG) << "Test SLOG DEBUG";
  LOG(INFO) << "one: " << 1;
  LOG(INFO) << "two: " << 2;
  LOG(INFO) << "one and two: " << 1 << " and " << 2;
  LOG(DEBUG) << "float 2.14: " << 1000/2.14f;
  LOG(DEBUG) << "pi double: " << pi_d;
  LOG(DEBUG) << "pi float: " << pi_f;
  LOG(DEBUG) << "pi float (width 10): " << std::setprecision(10) << pi_f;
  LOGF(INFO, "pi float printf:%f", pi_f);

  //
  // START: LOG Entris that were in the article
  //
  //LOG(UNKNOWN_LEVEL) << "This log attempt will cause a compiler error";
  LOG(INFO) << "Simple to use with streaming syntax, easy as abc or " << 123;
  LOGF(WARNING, "Printf-style syntax is also %s", "available");
  LOG_IF(INFO, (1 < 2)) << "If true this text will be logged";
  LOGF_IF(INFO, (1<2), "if %d<%d : then this text will be logged", 1,2);
  LOG_IF(FATAL, (2>3)) << "This message should NOT throw";
  LOGF(DEBUG, "This API is popular with some %s", "programmers");
  LOGF_IF(DEBUG, (1<2), "If true, then this %s will be logged", "message");
  {
    // OK --- on Ubunti this WILL get a compiler warning
    // On windows it'll probably crash  std::cout << "\n\n***** Be ready on Windows this example will 'abort' " << std::endl;
  std::cout << "\n\n***** Be ready this last example may 'abort' if on Windows/Linux_gcc4.7 " << std::endl << std::flush;
  std::cout << "************************************************************\n\n" << std::endl << std::flush;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  const std::string logging = "logging";
  LOGF(DEBUG, "ILLEGAL PRINTF_SYNTAX EXAMPLE. WILL GENERATE compiler warning.\n\nbadly formatted message:[Printf-type %s is the number 1 for many %s]", logging.c_str());
  }


  std::cout << "\n\n***** Be ready this last example will trigger 'abort' " << std::endl;
  std::cout << "************************************************************\n\n" << std::endl;
  CHECK(1<2) << "SHOULD NOT SEE THIS MESSAGE";
  CHECK(1>2) << "Test to see if contract works: onetwothree: " << 123 << ". This should be at the end of the log, and will exit this example";
}
