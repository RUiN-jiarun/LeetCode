/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
    struct ListNode {   // 定义节点结构体
        int key;
        int val;
        ListNode* next;
        ListNode* pre;
    };
    ListNode* dummy;    // 双向链表的头
    int maxSize;        // 最大缓存数量
    int nodeNums;       // 当前缓存中的节点数量

    // 定义哈希表，key是int，val是节点
    unordered_map<int, ListNode*> hash;

public:
    LRUCache(int capacity) : maxSize(capacity), dummy(new ListNode) {
        // 构建双向链表
        dummy->next = dummy;
        dummy->pre = dummy;
        nodeNums = 0;
    }
    
    int get(int key) {
        // 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 
        if (hash.find(key) != hash.end()){
            // 找到对应节点，取出
            ListNode* node = hash[key];
            // 将node从当前位置移除
            node->pre->next = node->next;
            node->next->pre = node->pre;
            // 把node插到dummy的后面，也就是链表头部
            node->next = dummy->next;
            node->pre = dummy;
            dummy->next->pre = node;    // 令dummy后面节点的前面节点为node
            dummy->next = node;         // 令dummy的后面节点为node
            
            return node->val;
        }
        return -1;

    }
    
    void put(int key, int value) {
        // 如果关键字 key 已经存在，则变更其数据值 value
        if (hash.find(key) != hash.end()) {
            hash[key]->val = value;//键已经存在于哈希表中，那么需要更新这个键对应的节点的值
            get(key);
        }
        // 如果不存在，则向缓存中插入该组 key-value
        else {
            if (nodeNums < maxSize){    // 缓存没满
                nodeNums++;
                // 创建新节点
                ListNode* node = new ListNode;
                node->key = key;
                node->val = value;
                // 哈希表对应位置进行记录
                hash[key] = node;
                // 将新节点插到dummy后面，也就是链表头部
                node->next = dummy->next;
                node->pre = dummy;
                dummy->next->pre = node;
                dummy->next = node;
            } else {                    //缓存满了，删除此时链表末尾的节点
                // 取链表最后一个节点，即dummy的pre指针指向的节点
                ListNode* node = dummy->pre;
                hash.erase(node->key);  // 在哈希表中删除对应节点
                hash[key] = node;       // 在哈希表中添加新的键值对，其中 key 是缓存节点的键，node 则是新的节点。
				node->key=key;          // 更新 node 节点的键值为新的 key。	
				node->val=value;
                get(key);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

