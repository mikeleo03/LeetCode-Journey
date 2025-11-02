class LRUNode {
    constructor(
        public key: number,
        public value: number,
        public prev: LRUNode | null = null,
        public next: LRUNode | null = null
    ) {}
}

class LRUCache {
    private capacity: number
    private cache: Map<number, LRUNode>
    private head: LRUNode
    private tail: LRUNode

    constructor(capacity: number) {
        this.capacity = capacity
        this.cache = new Map<number, LRUNode>()
        this.head = new LRUNode(-1, -1)
        this.tail = new LRUNode(-1, -1)
        this.head.next = this.tail
        this.tail.prev = this.head
    }

    moveToHead(node: LRUNode): void {
        this.removeNode(node)
        this.addToHead(node)
    }

    addToHead(node: LRUNode): void {
        node.prev = this.head
        node.next = this.head.next
        this.head.next!.prev = node
        this.head.next = node
    }

    removeNode(node: LRUNode): void {
        node.prev!.next = node.next
        node.next!.prev = node.prev
    }

    removeTail(): LRUNode {
        const lastNode = this.tail.prev! 
        this.removeNode(lastNode)
        return lastNode
    }

    get(key: number): number {
        const node = this.cache.get(key);
        if (!node) return -1;
        this.moveToHead(node);
        return node.value;
    }

    put(key: number, value: number): void {
        const node = this.cache.get(key)

        if (node) {
            node.value = value
            this.moveToHead(node)
            return
        }

        if (this.cache.size >= this.capacity) {
            const value = this.removeTail()
            this.cache.delete(value.key)
        }

        const newNode = new LRUNode(key, value)
        this.cache.set(key, newNode)
        this.addToHead(newNode)
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */