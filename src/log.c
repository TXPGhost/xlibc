#include "log.h"
#include <stdio.h>
#include <string.h>

#define __FILENAME__                                                           \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define CLEAR "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GRAY "\033[90m"

LogLevel global_log_level = LLInfo;

void set_log_level(LogLevel level) {
    global_log_level = level;
}

LogLevel get_log_level() {
    return global_log_level;
}

void log_print(FILE* file, char* message, char* level) {
    fprintf(file,
            "%s " GRAY "[" BLUE "%s" GRAY "@" BLUE "%s" GRAY ":" BLUE "%d" GRAY
            "] " CLEAR "%s\n",
            level, __func__, __FILENAME__, __LINE__, message);
}

void trace(char* message) {
    if (global_log_level <= LLTrace) {
        log_print(stdout, message,
                  GRAY "[" CYAN BOLD "TRACE" CLEAR GRAY "]" CLEAR);
    }
}

void info(char* message) {
    if (global_log_level <= LLInfo) {
        log_print(stdout, message,
                  GRAY "[" GREEN BOLD "INFO" CLEAR GRAY "] " CLEAR);
    }
}
void warn(char* message) {
    if (global_log_level <= LLWarn) {
        log_print(stderr, message,
                  GRAY "[" YELLOW BOLD "WARN" CLEAR GRAY "] " CLEAR);
    }
}
void error(char* message) {

    if (global_log_level <= LLError) {
        log_print(stderr, message,
                  GRAY "[" RED BOLD "ERROR" CLEAR GRAY "]" CLEAR);
    }
}
