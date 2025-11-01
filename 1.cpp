#include <iostream>

int** create(size_t rows, size_t cols)
{
    int** mtx = new int*[rows];
    size_t count = 0;
    try
    {
        for (; count < rows; count++)
            mtx[count] = new int[cols];
    }
    catch (const std::bad_alloc& e)
    {
        destroy(mtx, count);
    }
}

void destroy(int** mtx, size_t count)
{
    for (size_t i = 0; i < count; i++)
        delete[] mtx[i];
    delete[] mtx;
}

int main()
{
    int** matrix = nullptr;
    try
    {
        matrix = create(5, 5);
    }
    catch (const std::bad_alloc & e)
    {
        std::cerr << e.what();
        return 1;
    }
    destroy(matrix, 5);
}