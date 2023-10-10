bool isEqual(BiTree A, BiTree B)
{
    if (A != NULL && B != NULL)
    {
        if (A -> data != B -> data)
        return false;
    }
    else if (A == NULL && B == NULL)
        return true;
    else
        return false;
    
return isEqual(A -> lchild, B -> lchild) && 
        isEqual(A -> rchild, B -> rchild);
}