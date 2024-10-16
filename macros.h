#ifndef C_COMMON_STD_MACROS_H
#define C_COMMON_STD_MACROS_H
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

// 检测 编译器 是否支持 c11 标准
#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 7
#define SUPPORTED_C11 1
#elif defined(__clang__) && __clang_major__ >= 3 && __clang_minor__ >= 0
#define SUPPORTED_C11 1
#else
#define SUPPORTED_C11 0
#endif

/**
 * @brief 计算结构体中成员在结构体中的偏移位置
 */
#define STRUCT_OFFSET_OF(structType, member)                                    offsetof(structType, member)

/**
 * @brief 检查结构体大小是否符合预期
 */
#if C11_SUPPORTED 
#define STRUCT_SIZE_CHECK(structType, expectedSize)                             static_assert(sizeof(structType) == expectedSize, "struct '"#structType"' size is wrong")
#else
#define STRUCT_SIZE_CHECK(structType, expectedSize)                             typedef char _macros_check_size##structType[(sizeof(structType) == expectedSize ? 1 : -1)];
#endif

#endif
