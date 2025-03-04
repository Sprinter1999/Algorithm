def rob(root):
    def dfs(node):
        if not node:
            return 0, 0
        
        # Recursively solve for the children of current node.
        with_left_child, without_left_child = dfs(node.left)
        with_right_child, without_right_child = dfs(node.right)

        # If we include this node in our sum,
        # then we cannot take its direct child nodes into account.
        with_current_node = node.val + without_left_child + without_right_child

        # Otherwise, we can choose to either include or exclude each child independently.
        without_current_node = max(without_left_child, with_left_child) + max(without_right_child, with_right_child)

        return with_current_node, without_current_node
    
    total_with_root, total_without_root = dfs(root)
    
    # The result will be maximum between including and excluding the root itself.
    return max(total_with_root, total_without_root)