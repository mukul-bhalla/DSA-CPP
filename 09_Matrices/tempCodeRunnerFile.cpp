int Matrix::get(int i, int j)
{
    if (i != j)
        return 0;
    return A[i - 1];
}