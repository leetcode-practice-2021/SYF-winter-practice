//
// 146LRU缓存机制
// Created by 师域飞 on 2021/1/20.
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
//

/**
 * 运用你所掌握的数据结构，设计和实现一个LRU (最近最少使用) 缓存机制 。
y：

LRUCache(int capacity) 以正整数作为容量capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value)如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

链接：https://leetcode-cn.com/problems/lru-cache
 */

#include "iostream"
#include "vector"
#include <unordered_map>
#include "iterator"

using namespace std;

class LRUCache {
    unordered_map<int, int> cells;
    unordered_map<int, int> time;
    int length;
    int size;
public:
    LRUCache(int capacity) {
        length = capacity;
        for (int i = 0; i < length; ++i) {
            time[i] = 0;
        }
    }

    int get(int key) {
        if (cells.count(key) < 1)
            return -1;
        else {
            time[key]++;
            return cells[key];
        }
    }

    void put(int key, int value) {
        if (cells.count(key) > 0) {
            if (size < length) {
                cells[key] = value;
                size++;
            } else{
                int index=0;
                for(int i=0;i<length;i++){
                    if(time[index]<time[i])
                        index=i;
                }
                cells.erase(index);
                int i=0;
                auto it = cells.begin();
                for (; it != cells.end();it++,i++) {
                    if (i==index)
                        break;
                }
                cells.insert(it,{key,value});
            }
        } else if (size <= length) {
            cells.insert(cells.end(),{key,value});
            size++;
        }
    }
};

/**
 *
 * answer
 *
 * struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
 */