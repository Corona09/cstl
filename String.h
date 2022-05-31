#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRING_H_F1QA9YBR_E32B5D59_8A3B_4E21_8F18_3F1320AB9C0C
#define STRING_H_F1QA9YBR_E32B5D59_8A3B_4E21_8F18_3F1320AB9C0C

#define DEFAULT_STRING_LEN 5

/**
 * 自定义 string 类型
 */
typedef struct String {
	char* value;
	int length;
	int capacity;
} String;

/**
 * 构造一个新的 String
 */
String* newString();

/**
 * 从 C 字符串构造 String
 */
String* newStringFromCharArray(const char*);

/**
 * 获取字符串长度
 */
int stringLen(String* str);

/**
 * 清空字符串
 */
void stringClear(String* str);

/**
 * 拼接一个字符串与一个字符
 */
void stringCat(String* str, char ch);

/**
 * 比较两个字符串
 * 如果相同返回 0
 * 否则按字典序, str1 < str2 返回 -1
 *               str1 > str2 返回  1
 */
int stringCompare(String* str1, String* str2);

/**
 * 比较 String 与 C 风格字符串
 * 如果相同返回 0
 * 否则按字典序, str < cStr 返回 -1
 *               str > cStr 返回  1
 */
int stringCompareCStr(String* str, const char* cStr);

/**
 * 获取字符串中的一个字符
 */
char stringGetChar(String* str, int i);

/**
 * 将字符串转化为数字
 * 只做转化, 不做检查
 */
int string2Int(String* str);

/**
 * 释放字符串所占空间
 */
void freeString(String* str);

/**
 * 将字符串打印到文件
 * 用于调试
 */
void stringPrint(FILE* fp, String* str);

#endif /* end of include guard: STRING_H_F1QA9YBR */
