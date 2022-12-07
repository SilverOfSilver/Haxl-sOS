typedef unsigned long size_t;


/* Define a data structure to represent a block of memory. */
struct memory_block {
    void* start;       /* Starting address of the block. */
    size_t size;       /* Size of the block, in bytes. */
    int is_allocated;  /* Flag indicating whether the block is allocated. */
    struct memory_block* left;   /* Pointer to the left child in the binary tree. */
    struct memory_block* right;  /* Pointer to the right child in the binary tree. */
};

/* Define the root of the binary tree to keep track of the available blocks of memory. */
struct memory_block* root;

/* Allocate a block of memory of at least the specified size. */
void* allocate_memory(size_t size)
{
    /* Traverse the binary tree, looking for a block that is large enough to satisfy the request. */
    struct memory_block* current = root;
    while (current != NULL)
    {
        /* If the current block is larger than the requested size, check its left child. */
        if (current->size > size)
        {
            current = current->left;
        }
        /* If the current block is the same size as the requested size, return it. */
        else if (current->size == size)
        {
            current->is_allocated = 1;
            return current->start;
        }
        /* If the current block is smaller than the requested size, check its right child. */
        else
        {
            current = current->right;
        }
    }

    /* If no suitable block was found, return NULL. */
    return NULL;
}

/* Free a block of memory and make it available for future allocation. */
void free_memory(void* ptr)
{
    /* Traverse the binary tree, looking for the block with the specified starting address. */
    struct memory_block* current = root;
    struct memory_block* parent = NULL;
    while (current != NULL && current->start != ptr)
    {
        parent = current;
        if (ptr < current->start)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    /* If no such block was found, return without doing anything. */
    if (current == NULL)
    {
        return;
    }

    /* Mark the block as available and insert it into the binary tree. */
    current->is_allocated = 0;
    if (parent == NULL)
    {
        root = current;
    }
    else if (current->start < parent->start)
    {
        parent->left = current;
    }
    else
    {
        parent->right = current;
    }
}
