#include <stdio.h>

#define ALLOCSIZE 1000 /* Size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = &allocbuf[0]; /* next free position */

/* return pointer to n characters */
char *alloc(int n) { 
    /* if theres enough space */
    if(allocbuf + ALLOCSIZE - allocp > n) {
        allocp += n;
        return allocp - n; /* old p */
    }
    return NULL; /* out of space */
}

/* free storage pointed by p */
void afree(char *p) {
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

/**
 * returns the length of string s
 */
int strlen1(char *s) {
    int i;
    for(i = 0; *s != '\0'; s++) {
        i++;
    }
    return i;
}

/**
 * copy string t to s; array subscript
 */
void strcpy1(char *s, char *t) {
    int i = 0;
    while((s[i] = t[i]) != '\0') {i++;}
}

/**
 * copy string to to s; pointers
 */
void strcpy2(char *s, char *t) {
    while((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void strcpy3(char *s, char *t) {
    while((*s++ = *t++) != '\0');
}

/**
 * returns <0 if s<t, 0 if s=t, >0 if s>t lex
 */
int strcmp1(char *s, char *t) {
    int i;
    for(i=0; s[i] == t[i]; i++){
        if(s[i] == '\0') return 0;
    }
    return s[i]-t[i];
}

int strcmp2(char *s, char *t) {
    for(; *s == *t; s++, t++){
        if(*s == '\0') return 0;
    }
    return *s-*t;
}

/** copies t to the end of s */
int strcat1(char *s, char *t) {
    int i = 0, j = 0;
    while(s[i] != '\0') { i++; } /* find end of s */
    while((s[i++] = t[j++]) != '\0'); /* copy t */
}

/** copies t to the end of s */
int strcat2(char *s, char *t) {
    while(*s != '\0') { s++; } /* find end of s */
    while((*s++ = *t++) != '\0'); /* copy t */
}

int main(){
}
