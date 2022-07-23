/*
如果cur无左孩子，cur向右移动（cur=cur.right）
如果cur有左孩子，找到cur左子树上最右的节点，记为mostright
如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
如果mostright的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
*/

