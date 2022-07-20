int strToNum(const char c[], int res, int i)
{
    return (isdigit(c[i])) ? strToNum(c, 10 * res + (c[i] - '0'), i + 1) : res;
}

int strToNum(const char c[])
{
    return strToNum(c, 0, 0);
}