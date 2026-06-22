#include "sequential_list.h"

void printMenu() {
    printf("\n===== 顺序表操作菜单 =====\n");
    printf("1. 插入元素\n");
    printf("2. 删除元素\n");
    printf("3. 查找元素\n");
    printf("4. 获取元素\n");
    printf("5. 更新元素\n");
    printf("6. 获取表长度\n");
    printf("7. 打印所有元素\n");
    printf("8. 清空表\n");
    printf("0. 退出\n");
    printf("========================\n");
    printf("请选择操作 (0-8): ");
}

int main() {
    SequentialList* list = initList();
    
    if (list == NULL) {
        printf("顺序表创建失败!\n");
        return 1;
    }
    
    printf("顺序表已创建，最大容量: %d\n", MAX_SIZE);
    
    int choice;
    int pos, value;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                // 插入元素
                printf("请输入要插入的位置 (1-%d): ", list->length + 1);
                scanf("%d", &pos);
                printf("请输入要插入的值: ");
                scanf("%d", &value);
                
                if (insert(list, pos, value)) {
                    printf("✓ 插入成功!\n");
                } else {
                    printf("✗ 插入失败!\n");
                }
                break;
            }
            
            case 2: {
                // 删除元素
                printf("请输入要删除的位置 (1-%d): ", list->length);
                scanf("%d", &pos);
                
                if (deleteElement(list, pos)) {
                    printf("✓ 删除成功!\n");
                } else {
                    printf("✗ 删除失败!\n");
                }
                break;
            }
            
            case 3: {
                // 查找元素
                printf("请输入要查找的值: ");
                scanf("%d", &value);
                
                int position = search(list, value);
                if (position != -1) {
                    printf("✓ 找到了! 该元素在第 %d 个位置\n", position);
                } else {
                    printf("✗ 未找到该元素!\n");
                }
                break;
            }
            
            case 4: {
                // 获取元素
                printf("请输入要获取的位置 (1-%d): ", list->length);
                scanf("%d", &pos);
                
                if (getElement(list, pos, &value)) {
                    printf("✓ 位置 %d 的元素值为: %d\n", pos, value);
                } else {
                    printf("✗ 获取失败!\n");
                }
                break;
            }
            
            case 5: {
                // 更新元素
                printf("请输入要更新的位置 (1-%d): ", list->length);
                scanf("%d", &pos);
                printf("请输入新值: ");
                scanf("%d", &value);
                
                if (updateElement(list, pos, value)) {
                    printf("✓ 更新成功!\n");
                } else {
                    printf("✗ 更新失败!\n");
                }
                break;
            }
            
            case 6: {
                // 获取表长度
                printf("表的长度: %d\n", getLength(list));
                printf("表的容量: %d\n", MAX_SIZE);
                printf("剩余空间: %d\n", MAX_SIZE - getLength(list));
                break;
            }
            
            case 7: {
                // 打印所有元素
                printList(list);
                break;
            }
            
            case 8: {
                // 清空表
                clearList(list);
                printf("✓ 表已清空!\n");
                break;
            }
            
            case 0: {
                // 退出
                printf("感谢使用，再见!\n");
                freeList(list);
                return 0;
            }
            
            default: {
                printf("✗ 无效选择，请重试!\n");
            }
        }
    }
    
    return 0;
}
