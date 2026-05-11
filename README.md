## Application of Trees (Binary Search Tree)

### Scenario
Consider a **Phone Contact List** where each contact is identified by a unique **Name**.
* **New contact added** → Insert into BST
* **Scrolling through A-Z** → Inorder traversal
* **Deleting a contact** → Delete operation
A Binary Search Tree (BST) is used to ensure names are found instantly without checking every single entry in the phonebook.

### Justification
Binary Search Tree is chosen because:
* It maintains **alphabetical order** automatically.
* Allows **fast searching**, as it narrows down names by half at every step.
* Efficient for **dynamic lists** where people are added or removed frequently.
* Traversals provide structured outputs:
    * **Inorder** → Contacts displayed from A to Z.
    * **Preorder/Postorder** → Used for system backups and data structure analysis.

### Algorithm

**1. Insertion**
* Create a new contact node.
* If root is NULL → make new contact the root.
* Compare Name:
    * If alphabetically smaller → go to left subtree.
    * If alphabetically larger → go to right subtree.
* Repeat until correct empty position is found.
* Insert contact node.

**2. Inorder Traversal (LNR)**
* Traverse left subtree (A-M).
* Visit root.
* Traverse right subtree (N-Z).

**3. Preorder Traversal (NLR)**
* Visit root.
* Traverse left subtree.
* Traverse right subtree.

**4. Postorder Traversal (LRN)**
* Traverse left subtree.
* Traverse right subtree.
* Visit root.

**5. Deletion**
* Search for the name to be removed.
* Case handling:
    * **Leaf node** → delete directly.
    * **One child** → replace with the child contact.
    * **Two children** → replace with the inorder successor (the next name alphabetically).

###  Time Complexity

| Operation | Average Case | Worst Case |
| :--- | :--- | :--- |
| **Insertion** | $O(\log n)$ | $O(n)$ |
| **Deletion** | $O(\log n)$ | $O(n)$ |
| **Searching** | $O(\log n)$ | $O(n)$ |
| **Traversals** | $O(n)$ | $O(n)$ |

### Code
(Refer to BST-application.c uploaded in repository)
