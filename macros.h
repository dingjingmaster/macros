#ifndef C_COMMON_STD_MACROS_H
#define C_COMMON_STD_MACROS_H
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#ifndef C_IN
#define C_IN
#endif

#ifndef C_OUT
#define C_OUT
#endif

#ifdef __GNUC__
#define C_GNUC_CHECK_VERSION(major, minor)                                      ((__GNUC__ > (major)) || ((__GNUC__ == (major)) && (__GNUC_MINOR__ >= (minor))))
#else
#define C_GNUC_CHECK_VERSION(major, minor)                                      0
#endif


// 检测 编译器 是否支持 c11 标准
#ifndef C_SUPPORTED_C11
#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 7
#define C_SUPPORTED_C11 1
#elif defined(__clang__) && __clang_major__ >= 3 && __clang_minor__ >= 0
#define C_SUPPORTED_C11 1
#else
#define C_SUPPORTED_C11 0
#endif
#endif

// 计算结构体中成员在结构体中的偏移位置
#ifndef C_STRUCT_OFFSET_OF
#define C_STRUCT_OFFSET_OF(structType, member)                                  offsetof(structType, member)
#endif

// 检查结构体大小是否符合预期
#ifndef C_STRUCT_SIZE_CHECK
#if C_SUPPORTED_C11
#define C_STRUCT_SIZE_CHECK(structType, expectedSize)                           static_assert(sizeof(structType) == expectedSize, "struct '"#structType"' size is wrong");
#else
#define C_STRUCT_SIZE_CHECK(structType, expectedSize)                           typedef char _macros_check_size##structType[(sizeof(structType) == expectedSize ? 1 : -1)];
#endif
#endif

// 检查类型大小是否符合预期
#ifndef C_TYPE_SIZE_CHECK
#define C_TYPE_SIZE_CHECK(typeT, sizeT)                                         C_STRUCT_SIZE_CHECK(typeT, sizeT)
#endif

// 定义 int 类型
#ifndef cint8
typedef signed char                                                             cint8;
C_TYPE_SIZE_CHECK(cint8, 1)
#endif

#ifndef cuint8
typedef unsigned char                                                           cuint8;
C_TYPE_SIZE_CHECK(cuint8, 1)
#endif

#ifndef cchar
typedef char                                                                    cchar;
C_TYPE_SIZE_CHECK(cchar, 1)
#endif

#ifndef cuchar
typedef unsigned char                                                           cuchar;
C_TYPE_SIZE_CHECK(cuchar, 1)
#endif

#ifndef cint16
typedef signed short                                                            cint16;
C_TYPE_SIZE_CHECK(cint16, 2)
#endif

#ifndef cuint16
typedef unsigned short                                                          cuint16;
C_TYPE_SIZE_CHECK(cuint16, 2)
#endif

#ifndef cint32
typedef signed int                                                              cint32;
C_TYPE_SIZE_CHECK(cint32, 4)
#endif

#ifndef cint
typedef signed int                                                              cint;
C_TYPE_SIZE_CHECK(cint, 4)
#endif

#ifndef cuint32
typedef unsigned int                                                            cuint32;
C_TYPE_SIZE_CHECK(cuint32, 4)
#endif

#ifndef cuint
typedef unsigned int                                                            cuint;
C_TYPE_SIZE_CHECK(cuint, 4)
#endif

#ifndef cint64
typedef signed long                                                             cint64;
C_TYPE_SIZE_CHECK(cint64, 8)
#endif

#ifndef cuint64
typedef unsigned long                                                           cuint64;
C_TYPE_SIZE_CHECK(cuint64, 8)
#endif

#ifndef cfloat
typedef float                                                                   cfloat;
C_TYPE_SIZE_CHECK(cfloat, 4)
#endif

#ifndef cdouble
typedef double                                                                  cdouble;
C_TYPE_SIZE_CHECK(cdouble, 8)
#endif

#ifndef cpointer
typedef void*                                                                   cpointer;
C_TYPE_SIZE_CHECK(cpointer, 8)
#endif

#undef cle16
typedef cuint16                                                                 cle16;

#undef cle32
typedef cuint32                                                                 cle32;

#undef cle64
typedef cuint64                                                                 cle64;

#ifndef C_INT8
#define C_INT8(x)                                                               ((cint8) x)
#endif

#ifndef C_UINT8
#define C_UINT8(x)                                                              ((cuint8) x)
#endif

#ifndef C_INT16
#define C_INT16(x)                                                              ((cint16) x)
#endif

#ifndef C_UINT16
#define C_UINT16(x)                                                             ((cuint16) x)
#endif

#ifndef C_INT32
#define C_INT32(x)                                                              ((cint32) x)
#endif

#ifndef C_UINT32
#define C_UINT32(x)                                                             ((cuint32) x)
#endif

#ifndef C_INT64
#define C_INT64(x)                                                              ((cint64) x)
#endif

#ifndef C_UINT64
#define C_UINT64(x)                                                             ((cuint64) x)
#endif

#ifndef C_POINTER
#define C_POINTER(x)                                                            ((C_POINTER) x)
#endif

#ifndef C_INT64_CONSTANT
#define C_INT64_CONSTANT(val)                                                   (val##L)
#endif

#ifndef C_UINT64_CONSTANT
#define C_UINT64_CONSTANT(val)                                                  (val##L)
#endif

#ifndef C_INT8_MAX
#define C_INT8_MAX                                                              ((cint8) 0x7F)
#endif

#ifndef C_INT8_MIN
#define C_INT8_MIN                                                              ((cint8) (-C_INT8_MAX) - 1)
#endif

#ifndef C_UINT8_MAX
#define C_UINT8_MAX                                                             ((cuint8) 0xFF)
#endif

#ifndef C_UINT8_MIN
#define C_UINT8_MIN                                                             ((cuint8) 0x00)
#endif

#ifndef C_INT16_MAX
#define C_INT16_MAX                                                             ((cint16) 0x7FFF)
#endif

#ifndef C_INT16_MIN
#define C_INT16_MIN                                                             ((cint16) (-C_INT16_MAX) - 1)
#endif

#ifndef C_UINT16_MAX
#define C_UINT16_MAX                                                            ((cuint16) 0xFFFF)
#endif

#ifndef C_UINT16_MIN
#define C_UINT16_MIN                                                            ((cuint16) 0x0000)
#endif

#ifndef C_INT32_MAX
#define C_INT32_MAX                                                             ((cint32) 0x7FFFFFFF)
#endif

#ifndef C_INT32_MIN
#define C_INT32_MIN                                                             ((cint32) (-C_INT32_MAX) - 1)
#endif

#ifndef C_UINT32_MAX
#define C_UINT32_MAX                                                            ((cuint32) 0xFFFFFFFF)
#endif

#ifndef C_UINT32_MIN
#define C_UINT32_MIN                                                            ((cuint32) 0x00000000)
#endif

#ifndef C_INT64_MAX
#define C_INT64_MAX                                                             ((cint64) 0x7FFFFFFFFFFFFFFF)
#endif

#ifndef C_INT64_MIN
#define C_INT64_MIN                                                             ((cint64) (-C_INT64_MAX) - 1)
#endif

#ifndef C_UINT64_MAX
#define C_UINT64_MAX                                                            ((cuint64) 0xFFFFFFFFFFFFFFFF)
#endif

#ifndef C_UINT64_MIN
#define C_UINT64_MIN                                                            ((cuint64) 0x0000000000000000)
#endif

// 自然常数 e
#ifndef C_E
#define C_E                                                                     2.7182818284590452353602874713526624977572470937000
#endif

// log 以 e 为底 2 的对数
#ifndef C_LN_2
#define C_LN_2                                                                  0.69314718055994530941723212145817656807550013436026
#endif

// log 以 e 为底 10 的对数
#ifndef C_LN_10
#define C_LN_10                                                                 2.3025850929940456840179914546843642076011014886288
#endif

// pi
#ifndef C_PI
#define C_PI                                                                    3.1415926535897932384626433832795028841971693993751
#endif

// pi / 2
#ifndef C_PI_DIV_2
#define C_PI_DIV_2                                                              1.5707963267948966192313216916397514420985846996876
#endif

// pi / 4
#ifndef C_PI_DIV_4
#define C_PI_DIV_4                                                              0.78539816339744830961566084581987572104929234984378
#endif

// 根号 2 的结果
#ifndef C_SQRT_2
#define C_SQRT_2                                                                1.4142135623730950488016887242096980785696718753769
#endif

// 定义 bool 类型
#ifdef __cplusplus
#else
#ifndef bool
typedef int                                                                     bool;
#endif
#ifndef false
#define false                                                                   (0)
#endif
#ifndef true
#define true                                                                    (!false)
#endif
#endif

/**
 * @brief 函数可见性，gcc可见性分为以下几种情况(__attribute__((visibility(""))))：
 *  1. default：默认可见（函数在程序的任何地方可见）
 *  2. hidden：隐藏可见性。函数在链接时候不可见，对于外部链接的符号，将无法从其它目标文件中引用
 *  3. protected：受保护可见。函数在链接时候可见，但只能被其所在的目标文件或具有相同共享库的目标文件引用
 */
#undef C_SYMBOL_EXPORT
#undef C_SYMBOL_IMPORT
#undef C_SYMBOL_HIDDEN
#undef C_SYMBOL_PROTECTED
#if (defined(_WIN32) || defined(__CYGWIN__))
#define C_SYMBOL_EXPORT __declspec(dllexport)
#define C_SYMBOL_IMPORT __declspec(dllimport)
#define C_SYMBOL_HIDDEN
#define C_SYMBOL_PROTECTED
#elif __GNUC__ >= 4
#define C_SYMBOL_IMPORT
#define C_SYMBOL_HIDDEN     __attribute__((visibility("hidden")))
#define C_SYMBOL_EXPORT     __attribute__((visibility("default")))
#define C_SYMBOL_PROTECTED  __attribute__((visibility("protected")))
#else
#define C_SYMBOL_EXPORT
#define C_SYMBOL_IMPORT
#define C_SYMBOL_HIDDEN
#define C_SYMBOL_PROTECTED
#endif

// __func__
#ifndef C_STRFUNC
#if defined (__GNUC__) && defined (__cplusplus)
#define C_STRFUNC                                                               ((const char*) (__PRETTY_FUNCTION__))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#define C_STRFUNC                                                               ((const char*) (__func__))
#elif defined (__GNUC__) || (defined(_MSC_VER) && (_MSC_VER > 1300))
#define C_STRFUNC                                                               ((const char*) (__FUNCTION__))
#else
#define C_STRFUNC                                                               ((const char*) ("???"))
#endif
#endif

// __LINE__
#ifndef C_LINE
#define C_LINE                                                                  (__LINE__)
#endif

// extern "c"
#undef C_BEGIN_EXTERN_C
#undef C_END_EXTERN_C
#ifdef  __cplusplus
#define C_BEGIN_EXTERN_C                                                        extern "C" {
#define C_END_EXTERN_C                                                          }
#else
#define C_BEGIN_EXTERN_C
#define C_END_EXTERN_C
#endif

// do {} while (0);
#undef C_STMT_START
#undef C_STMT_END
#define C_STMT_START  do {
#if defined (_MSC_VER) && (_MSC_VER >= 1500)
#define C_STMT_END \
    __pragma(warning(push)) \
    __pragma(warning(disable:4127)) \
    } while(0) \
    __pragma(warning(pop))
#else
#define C_STMT_END    } while (0)
#endif

#if C_GNUC_CHECK_VERSION(2, 0) && defined(__OPTIMIZE__)
#define C_LIKELY(expr) (__builtin_expect(!!(expr), 1))
#define C_UNLIKELY(expr) (__builtin_expect(!!(expr), 0))
#else
#define C_LIKELY(expr) (expr)
#define C_UNLIKELY(expr) (expr)
#endif

#undef C_MAX
#define C_MAX(a, b)                                                             (((a) > (b)) ? (a) : (b))

#undef C_MIN
#define C_MIN(a, b)                                                             (((a) < (b)) ? (a) : (b))

#undef C_ABS
#define C_ABS(a)                                                                (((a) < 0) ? -(a) : (a))

#undef C_N_ELEMENTS
#define C_N_ELEMENTS(arr)                                                       (sizeof(arr) / sizeof((arr)[0]))

#undef C_ASCII_IS_SPACE
#undef C_ASCII_IS_UPPER
#undef C_ASCII_IS_LOWER
#undef C_ASCII_IS_ALPHA
#undef C_ASCII_TO_UPPER
#undef C_ASCII_TO_LOWER

#define C_ASCII_IS_UPPER(c)                                                     ((c) >= 'A' && (c) <= 'Z')
#define C_ASCII_IS_LOWER(c)                                                     ((c) >= 'a' && (c) <= 'z')
#define C_ASCII_IS_ALPHA(c)                                                     (C_ASCII_IS_UPPER (c) || C_ASCII_IS_LOWER(c))
#define C_ASCII_TO_UPPER(c)                                                     (C_ASCII_IS_LOWER (c) ? (c) - 'a' + 'A' : (c))
#define C_ASCII_TO_LOWER(c)                                                     (C_ASCII_IS_UPPER (c) ? (c) - 'A' + 'a' : (c))
#define C_ASCII_IS_SPACE(c)                                                     ((c) == ' ' || (c) == '\f' || (c) == '\n' || (c) == '\r' || (c) == '\t' || (c) == '\v')

#undef C_FREE
#undef C_FREE_FUNC
#undef C_BREAK_IF_FAIL
#undef C_BREAK_IF_NULL
#undef C_RETURN_IF_FAIL
#undef C_RETURN_VAL_IF_FAIL

#define C_BREAK_IF_OK(x)														if (x) { break; }
#define C_BREAK_IF_FAIL(x)                                                      if (!(x)) { break; }
#define C_BREAK_IF_NULL(x)                                                      if ((x) == NULL) { break; }
#define C_RETURN_IF_OK(ck)														C_STMT_START if ((ck)) { return; } C_STMT_END
#define C_RETURN_IF_FAIL(ck)                                                    C_STMT_START if (!(ck)) { return; } C_STMT_END
#define C_RETURN_VAL_IF_OK(ck, val)                                             C_STMT_START if ((ck)) { return (val); } C_STMT_END
#define C_RETURN_VAL_IF_FAIL(ck, val)                                           C_STMT_START if (!(ck)) { return (val); } C_STMT_END
#define C_FREE_FUNC(x, f, ...)                                                  C_STMT_START if ((x)) { f (x, ##__VA_ARGS__); x = NULL; } C_STMT_END


#undef C_ALIGN_TO
#define C_ALIGN_TO(n, align) ({                         \
    typeof (n) __ret;                                   \
    if ((n) % (align)) {                                \
        __ret = ((n) & (~((align) - 1))) + (align);     \
    }                                                   \
    else {                                              \
        __ret = (n);                                    \
    }                                                   \
})

static inline cint64 c_strlen (const char* str)
{
	C_RETURN_VAL_IF_FAIL(str, 0);

	int idx = 0;
	for (idx = 0; '\0' != str[idx]; ++idx);

	return idx;
}

static inline int c_strcmp (const char* str1, const char* str2)
{
	C_RETURN_VAL_IF_OK(str1 && !str2, 1);
	C_RETURN_VAL_IF_OK(!str1 && str2, -1);
	C_RETURN_VAL_IF_OK(!str1 && !str2, 0);
	
	int idx = 0;
	for (idx = 0; str1[idx] && str2[idx]; ++idx) {
		int res = str1[idx] - str2[idx];
		if (0 == res) {
			continue;
		}
		return res;
	}

	C_RETURN_VAL_IF_OK(!str1[idx] && !str2[idx], 0);
	C_RETURN_VAL_IF_OK(!str1[idx], -1);

	// !str2[idx]
	return 1;
}

static inline int c_strncmp (const char* str1, const char* str2, cuint64 len)
{
	C_RETURN_VAL_IF_OK(str1 && !str2, 1);
	C_RETURN_VAL_IF_OK(!str1 && str2, -1);
	C_RETURN_VAL_IF_OK(!str1 && !str2, 0);

	int idx = 0;
	for (idx = 0; str1[idx] && str2[idx] && idx < len; ++idx) {
		int res = str1[idx] - str2[idx];
		if (0 == res) {
			continue;
		}
		return res;
	}

	C_RETURN_VAL_IF_OK((idx >= len), (str1[idx - 1] - str2[idx - 1]));

	C_RETURN_VAL_IF_OK(!str1[idx] && !str2[idx], 0);
	C_RETURN_VAL_IF_OK(!str1[idx], -1);

	return 1;
}

static inline bool c_str_has_prefix (const char* str, const char* prefix)
{
	C_RETURN_VAL_IF_FAIL(str, false);
	C_RETURN_VAL_IF_FAIL(prefix, false);

	return (0 == c_strncmp(str, prefix, c_strlen(prefix)));
}

static inline bool c_str_has_suffix (const char* str, const char* suffix)
{
	C_RETURN_VAL_IF_FAIL(str, false);
	C_RETURN_VAL_IF_FAIL(suffix, false);

	cuint64 strLen = c_strlen(str);
	cuint64 sufLen = c_strlen(suffix);

	C_RETURN_VAL_IF_OK(strLen < sufLen, false);

	return (0 == c_strcmp(str + strLen - sufLen, suffix));
}

#endif
