#pragma once
#include <iostream>
#include <string>
#include <chrono>

enum class LogLevel {
    INFO,
    DBG,
    WARNING,
    ERROR
};

double getLogTime();
void Log(LogLevel level, const char* file, int line, const char* function, const char* format, ...);

#define LOG_INFO(...)  Log(LogLevel::INFO, __FILE_NAME__, __LINE__, __func__, __VA_ARGS__)
#define LOG_DBG(...)   Log(LogLevel::DBG, __FILE_NAME__, __LINE__, __func__, __VA_ARGS__)
#define LOG_WARN(...)  Log(LogLevel::WARNING, __FILE_NAME__, __LINE__, __func__, __VA_ARGS__)
#define LOG_ERROR(...) Log(LogLevel::ERROR, __FILE_NAME__, __LINE__, __func__, __VA_ARGS__)
