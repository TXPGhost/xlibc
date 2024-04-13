#ifndef LOG_H
#define LOG_H

typedef enum {
    LLTrace = 0,
    LLInfo = 1,
    LLWarn = 2,
    LLError = 3,
} LogLevel;

void set_log_level(LogLevel level);
LogLevel get_log_level();

void trace(char* message);
void info(char* message);
void warn(char* message);
void error(char* message);

#endif
