#pragma once

void LogMessage(const char* level, const char* format, ...);

#define LOG_INFO(fmt, ...) LogMessage("INFO", fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) LogMessage("ERROR", fmt, ##__VA_ARGS__)
