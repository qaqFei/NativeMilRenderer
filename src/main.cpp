#define i128 long long
#define i64 long
#define i32 int
#define i16 short
#define i8 char
#define u128 unsigned long long
#define u64 unsigned long
#define u32 unsigned int
#define u16 unsigned short
#define u8 unsigned char
#define f128 long double
#define f64 double
#define f32 float
#define f16 float
#define NATIVE_MIL_RENDERER_VERSION 1

#include <cstdio>
#include <stdarg.h>

#include "json/json.h"

namespace Logger {
    void info(const char* format, ...) {
        printf("[INFO] ");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
    }

    void warn(const char* format, ...) {
        printf("[WARN] ");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
    }

    void error(const char* format, ...) {
        printf("[ERROR] ");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
    }

    void debug(const char* format, ...) {
        printf("[DEBUG] ");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
    }
}

int main(int argc, char** argv) {
    Logger::info("version: %d", NATIVE_MIL_RENDERER_VERSION);

    if (argc < 2) {
        Logger::error("Usage: %s <input file> <output file>", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    const char* string = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(string, root);
    if (parsingSuccessful) {
        Logger::info("name: %s", root["name"].asString().c_str());
        Logger::info("age: %d", root["age"].asInt());
        Logger::info("city: %s", root["city"].asString().c_str());
    } else {
        Logger::error("Failed to parse JSON");
    }

    Logger::info("input file: %s", input_file);
    Logger::info("output file: %s", output_file);

    return 0;
}
