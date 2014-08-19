/*
 * LOGGER.h
 *
 *  Created on: Aug 18, 2014
 *      Author: cvora
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#ifdef PIX_LOGGING_ENABLED
#define LOG(level, msg) Log::Logger::get_logger().log(level, msg)
#else
#define LOG(level, msg) (void) 0
#endif

#include <iostream>

namespace log4cpp
{
  class Category;
}

namespace Log
{
  /// Logging levels used by pix. Follows the same as for syslog, taken from
  /// RFC 5424. Comments added for ease of reading.
  /// @see http://en.wikipedia.org/wiki/Syslog.
  enum LogLevel
  {
    EMERG,  // System is unusable (e.g. multiple parts down)
    ALERT,  // System is unusable (e.g. single part down)
    CRIT,   // Failure in non-primary system (e.g. backup site down)
    ERROR,  // Non-urgent failures; relay to developers
    WARN,   // Not an error, but indicates error will occurr if nothing done.
    NOTICE, // Events that are unusual, but not error conditions.
    INFO,   // Normal operational messages. No action required.
    DEBUG,  // Information useful during development for debugging.
    NOTSET
  };

  class Logger final
  {
  public:
    static Logger& get_logger();

    void log(Log::LogLevel level, const std::string& msg);

  private: // functions
    Logger();
    Logger(const Logger&) =delete;
    Logger(Logger&) =delete;
    Logger& operator=(const Logger&) =delete;
    Logger& operator=(Logger&) =delete;

  private: // attributes
    log4cpp::Category& m_cpp_logger;
  };

}




#endif /* LOGGER_H_ */
