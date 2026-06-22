#include "sequential_list.h"

// 初始化顺序表
SequentialList* initList() {
    SequentialList* list = (SequentialList*)malloc(sizeof(SequentialList));
    if (list == NULL) {
        printf("内存分配失败!\n");
        return NULL;
    }
    list->length = 0;
    return list;
}

// 插入元素 (在位置pos插入元素value，pos从1开始)
bool insert(SequentialList* list, int pos, ElementType value) {
    if (list == NULL) {
        printf("顺序表不存在!\n");
        return false;
    }
    
    if (pos < 1 || pos > list->length + 1) {
        printf("插入位置非法! (有效范围: 1-%d)\n", list->length + 1);
        return false;
    }
    
    if (isFull(list)) {
        printf("顺序表已满，无法插入!\n");
        return false;
    }
    
    // 从后向前移动元素
    for (int i = list->length; i >= pos; i--) {
        list->data[i] = list->data[i - 1];
    }
    
    list->data[pos - 1] = value;
    list->length++;
    return true;
}

// 删除元素 (删除位置pos的元素)
bool delete(SequentialList* list, int pos) {
    if (list == NULL) {
        printf("顺序表不存在!\n");
        return false;
    }
    
    if (pos < 1 || pos > list->length) {
        printf("删除位置非法! (有效范围: 1-%d)\n", list->length);
        return false;
    }
    
    if (isEmpty(list)) {
        printf("顺序表为空，无法删除!\n");
        return false;
    }
    
    // 从前向后移动元素
    for (int i = pos - 1; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    
    list->length--;
    return true;
}

// 查找元素 (返回元素在表中的位置，从1开始；-1表示未找到)
int search(SequentialList* list, ElementType value) {
    if (list == NULL || isEmpty(list)) {
        return -1;
    }
    
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == value) {
            return i + 1;  // 返回位置（从1开始）
        }
    }
    
    return -1;  // 未找到
}

// 获取指定位置的元素
bool getElement(SequentialList* list, int pos, ElementType* value) {
    if (list == NULL) {
        printf("顺序表不存在!\n");
        return false;
    }
    
    if (pos < 1 || pos > list->length) {
        printf("位置非法! (有效范围: 1-%d)\n", list->length);
        return false;
    }
    
    *value = list->data[pos - 1];
    return true;
}

// 更新指定位置的元素
bool updateElement(SequentialList* list, int pos, ElementType value) {
    if (list == NULL) {
        printf("顺序表不存在!\n");
        return false;
    }
    
    if (pos < 1 || pos > list->length) {
        printf("位置非法! (有效范围: 1-%d)\n", list->length);
        return false;
    }
    
    list->data[pos - 1] = value;
    return true;
}

// 获取表的长度
int getLength(SequentialList* list) {
    if (list == NULL) return 0;
    return list->length;
}

// 判断表是否为空
bool isEmpty(SequentialList* list) {
    if (list == NULL) return true;
    return list->length == 0;
}

// 判断表是否已满
bool isFull(SequentialList* list) {
    if (list == NULL) return true;
    return list->length == MAX_SIZE;
}

// 清空表
void clearList(SequentialList* list) {
    if (list != NULL) {
        list->length = 0;
    }
}

// 打印表中所有元素
void printList(SequentialList* list) {
    if (list == NULL) {
        printf("顺序表不存在!\n");
        return;
    }
    
    if (isEmpty(list)) {
        printf("顺序表为空!\n");
        return;
    }
    
    printf("表中元素: ");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 释放表的内存
void freeList(SequentialList* list) {
    if (list != NULL) {
        free(list);
    }
}
