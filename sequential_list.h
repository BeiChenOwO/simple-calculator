#ifndef SEQUENTIAL_LIST_H
#define SEQUENTIAL_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef int ElementType;

typedef struct {
    ElementType data[MAX_SIZE];
    int length;
} SequentialList;

// 初始化顺序表
SequentialList* initList();

// 插入元素 (在位置pos插入元素value)
bool insert(SequentialList* list, int pos, ElementType value);

// 删除元素 (删除位置pos的元素)
bool delete(SequentialList* list, int pos);

// 查找元素 (返回元素在表中的位置，从1开始)
int search(SequentialList* list, ElementType value);

// 获取指定位置的元素
bool getElement(SequentialList* list, int pos, ElementType* value);

// 更新指定位置的元素
bool updateElement(SequentialList* list, int pos, ElementType value);

// 获取表的长度
int getLength(SequentialList* list);

// 判断表是否为空
bool isEmpty(SequentialList* list);

// 判断表是否已满
bool isFull(SequentialList* list);

// 清空表
void clearList(SequentialList* list);

// 打印表中所有元素
void printList(SequentialList* list);

// 释放表的内存
void freeList(SequentialList* list);

#endif
