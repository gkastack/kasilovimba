#include <iostream>

int** create(size_t rows, size_t cols)
{
    int** mtx = new int*[rows];
    size_t count = 0;
    try
    {
        for (; count < rows; ++count)
            mtx[count] = new int[cols];
    }
    catch (const std::bad_alloc& e)
    {
        destroy(mtx, count);
        throw;
    }
}

void destroy(int** mtx, size_t count)
{
    for (size_t i = 0; i < count; ++i)
        delete[] mtx[i];
    delete[] mtx;
}

void construct(int** mtx, int init, size_t rows, size_t cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            mtx[i][j] = init;
    }
}

void input(int** mtx, size_t rows, size_t cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            std::cin >> mtx[i][j];
    }
}

int main()
{
    size_t rows, cols;
    std::cin << rows << cols;
    int** matrix = nullptr;
    try
    {
        matrix = create(rows, cols);
    }
    catch (const std::bad_alloc & e)
    {
        std::cerr << e.what();
        return 1;
    }
    construct(mtx, 2, rows, cols);
    destroy(matrix, rows);

}