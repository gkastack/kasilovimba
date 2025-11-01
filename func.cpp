void destroy(int**, size_t);

int** convert(const int* t, size_t n, const int* lns, size_t rows)
{
    int** result = nullptr;
    try 
    {
        result = new int*[rows];
        for (size_t i = 0; i < rows; i++)
            result[i] = new int[lns[i]];
        int count = 0;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < lns[i] && count < n; j++, count++)
                result[i][j] = t[count];
        }
        return result;
    }
    catch (std::bad_alloc& e)
    {
        std::cout << e.what() << '\n';
        if (result != nullptr)
            destroy(result, rows);
        return nullptr;
    }
}

void destroy(int** result, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        delete[] result[i];
    delete[] result;
}