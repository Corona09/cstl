#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

/**
 * 获取一个新的 string 对象
 */
String* newString() {
	String* str = (String*) malloc(1 * sizeof(String));
	str->capacity = DEFAULT_STRING_LEN;
	str->value = (char*) malloc(str->capacity * sizeof(char));
	str->length = 0;
	return str;
}

/**
 * 从 C 字符串构造 String
 */
String* newStringFromCharArray(const char* cStr) {
	String* str = (String*) malloc(1 * sizeof(String));
	str->length = strlen(cStr);
	str->capacity = str->length + DEFAULT_STRING_LEN;
	str->value = (char*) malloc(str->capacity * sizeof(char));
	strcpy(str->value, cStr);
	return str;
}

/**
 * 获取字符串长度
 */
int stringLen(String* str) {
	return str->length;
}

/**
 * 清空字符串
 * 但是不释放空间
 */
void stringClear(String* str) {
	memset(str->value, 0, str->capacity * sizeof(char));
	str->length = 0;
}

/**
 * 拼接一个字符串与一个字符
 * 返回新的
 */
void stringCat(String* str, char ch) {
	int len = stringLen(str);
	// 空间已满, 需要申请额外存储空间
	if (len + 1 == str->capacity) {
		int ncap = str->capacity + DEFAULT_STRING_LEN;
		str->value = (char*) realloc(str->value, ncap * sizeof(char));
		str->capacity = ncap;
	}
	str->value[len] = ch;
	str->value[len+1] = '\0';
	str->length ++;
	return;
}

/**
 * 比较两个字符串
 * 如果相同返回 0
 * 否则按字典序, str1 < str2 返回 -1
 *               str1 > str2 返回  1
 */
int stringCompare(String* str1, String* str2) {
	int cmpResult = strcmp(str1->value, str2->value);
	return cmpResult;
}
/**
 * 比较 String 与 C 风格字符串
 * 如果相同返回 0
 * 否则按字典序, str < cStr 返回 -1
 *               str > cStr 返回  1
 */
int stringCompareCStr(String* str, const char* cStr) {
	int cmpResult = strcmp(str->value, cStr);
	return cmpResult;
}

/**
 * 获取字符串中的一个字符
 */
char stringGetChar(String* str, int i) {
	if (i >= str->length || i < 0) {
		return -1;
	}
	return str->value[i];
}

/**
 * 将字符串转化为数字
 * 只做转化, 不做检查
 */
int string2Int(String* str) {
	if (str->length == 0) {
		return 0;
	}
	int value = 0;
	for (int i = 0; i < str->length; i++) {
		value = value * 10 + (stringGetChar(str, i) - (int)'0');
	}
	return value;
}

/**
 * 释放字符串所占空间
 */
void freeString(String* str) {
	free(str->value);
	free(str);
}

/**
 * 将字符串打印到文件
 * 用于调试
 */
void stringPrint(FILE* fp, String* str) {
	fprintf(fp, "%s", str->value);
}
