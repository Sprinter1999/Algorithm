class TrieNode:
    def __init__(self):
        self.word_ends = False
        self.children = [None] * 26

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root

        for c in word:
            pos = ord(c) - ord("a")
            if node.children[pos] is None:
                node.children[pos] = TrieNode()
            node = node.children[pos]
        
        node.word_ends = True


    def search(self, word: str) -> bool:
        node = self.root

        for c in word:
            if node is None:
                break
            node = node.children[ord(c)- ord("a")]
        
        return node is not None and node.word_ends

    def startsWith(self, prefix: str) -> bool:
        node = self.root

        for c in prefix:
            if node is None:
                break
            node = node.children[ord(c)- ord("a")]
        
        return node is not None
    
# Trie trie = new Trie();
# trie.insert("apple");
# trie.search("apple"); // true
# trie.search("app"); // false
# trie.startsWith("app"); // true
# trie.insert("app");
# trie.search("app"); // true


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)