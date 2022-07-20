#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

unsigned StringLength(char *str);

char *StringAppend(char *src, char *append)
{
  char *result = malloc(StringLength(src) + StringLength(append) + 1);

  if (!result)
  {
    return NULL;
  }

  char *itr = result;

  while (*src)
  {
    *itr++ = *src++;
  }

  while (*append)
  {
    *itr++ = *append++;
  }

  *itr = 0;

  return result;
}

void StringCopy(char *to, char *from)
{
  while (*to && *from)
  {
    *to++ = *from++;
  }

  *to = 0;
}

unsigned StringLength(char *str)
{
  if (!str)
  {
    return 0;
  }

  char *tmp = str;

  while (*str++)
  {
  }

  return str - tmp - 1;
}

char *StringSubstring(char *str, int startIdx, int endIdx)
{
  if (!str)
  {
    return NULL;
  }

  unsigned length = StringLength(str);
  startIdx = (startIdx > 0 ? startIdx : 0);
  endIdx = (endIdx < length ? endIdx : length);
  unsigned substrLength = endIdx - startIdx;
  char *substring = malloc(substrLength + 1);

  for (int i = startIdx; i < endIdx; i++)
  {
    substring[i] = str[i];
  }

  substring[substrLength] = 0;

  return substring;
}

void StringToUpperCase(char *str)
{
  for (int i = 0; i < StringLength(str); i++)
  {
    char c = str[i];

    if (c >= 'a' && c <= 'z')
    {
      str[i] = 'A' + c - 'a';
    }
  }
}

void StringToLowerCase(char *str)
{
  for (int i = 0; i < StringLength(str); i++)
  {
    char c = str[i];

    if (c >= 'A' && c <= 'Z')
    {
      str[i] = 'a' + c - 'A';
    }
  }
}

void StringToggleCase(char *str)
{
  for (int i = 0; i < StringLength(str); i++)
  {
    char c = str[i];

    if (c >= 'a' && c <= 'z')
    {
      str[i] = 'A' + c - 'a';
    }

    if (c >= 'A' && c <= 'Z')
    {
      str[i] = 'a' + c - 'A';
    }
  }
}

int StringIsEqual(char *s1, char *s2)
{
  if (!s1 && !s2)
  {
    return 1;
  }

  int length = StringLength(s1);

  if (length != StringLength(s2))
  {
    return 0;
  }

  for (int i = 0; i < length; i++)
  {
    if (s1[i] != s2[i])
    {
      return 0;
    }
  }

  return 1;
}

/* Delete all c from c */
void StringRemoveAllCharacter(char *s, char c)
{
  int i, j;

  for (i = j = 0; s[i] != 0; i++)
  {
    if (s[i] == c)
    {
      s[j++] = s[i];
    }
  }

  s[j] = 0;
}

/* Reverse string s */
void reverse(char *s)
{
  int i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

// Returns a string representation of integer n in base b
char *itob(int n, int b)
{
  char *s = malloc(20);
  int i = 0;
  int sign = n;

  if (n < 0)
  {
    n = -n;
  }

  do
  {
    int digit = n % b;
    n = n / b;

    char c;

    /* To use digits for 0-9 and letters for 10+ */

    if (digit < 10)
    {
      c = '0' + digit;
    }
    else
    {
      c = 'A' + (digit - 10);
    }

    s[i++] = c;
  } while (n > 0);

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s);

  return s;
}

int main()
{
  // int numbers[] = {255, 80, 95, 12367, -9099};
  // for (int i = 0; i < 5; i++)
  // {
  //   char *hex_n = itob(numbers[i], 16);
  //   printf("%d: 0x%s\n", numbers[i], hex_n);
  //   free(hex_n);
  // }

  char c[100];
  // char *tmp;

  // StringCopy(c, "hello world");

  // printf("%s\n", c);
  // printf("Length(\"%s\"): %u\n", c, StringLength(c));

  // tmp = StringSubstring(c, 0, 4);
  // printf("StringSubstring(hello, world, 0, 4): %s\n", tmp);
  // free(tmp);

  // tmp = StringAppend(c, " aarya");
  // printf("append '%s' to '%s' -> '%s'", c, " aarya", tmp);
  // free(tmp);

  // assert(StringIsEqual("string", "string") == 1);
  // assert(StringIsEqual("string", "str") == 0);

  char s[20];
  StringCopy(s, "STRING");
  StringToLowerCase(s);
  assert(StringIsEqual("string", s));
  StringCopy(s, "cs240");
  StringToggleCase(s);
  printf("'%s'\n", s);

  StringCopy(s, "hello world\0");
  reverse(s);
  assert(StringIsEqual("dlrow olleh\0",s));

  return 0;
}