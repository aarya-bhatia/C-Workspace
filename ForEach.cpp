void ForEach(const int values[], const int n, void (*func)(int))
{
    for (int i = 0; i < n; i++)
    {
        func(values[i]);
    }
}