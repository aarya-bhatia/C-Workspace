#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#define MAXVAL 100 /* maximum depth of val stack */

#define BUFFSIZE 10

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

char buf[BUFFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */


int get_op(char []);
void push(double);
double pop(void);

int get_ch(void);
void unget_ch(int);

/* reverse polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while((type = get_op(s)) != EOF) {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            push(-pop() + pop());
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0) {
                push(pop() /op2);
            }
            else {
                printf("[ERROR] division by 0\n");
            }
            break;
        case '\n':
            printf("\t%.8f\n", pop());
            break;
        default: 
            printf("[ERROR] unknown command %c\n", type);
            break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f) {
    if(sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("[ERROR]: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) {
    if(sp > 0) {
        return val[--sp];
    }
    else {
        printf("[ERROR]: stack empty \n");
        return 0.0;
    }
}

/* get a possibly pushed back character */
int get_ch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character bac on input */
void unget_ch(int c) {
    if(bufp >= BUFFSIZE) {
        printf("[ERROR]: buffer is full");
    }
    else {
        buf[bufp++] = c;
    }
}

/* getop: get next operator or numeric operand */
int get_op(char s[]) {
    int i,c;

    while((s[0] = c = get_ch()) == ' ' || c == '\t');

    s[1] = '\0';
    if(!isdigit(c) && c != '.') { return c; } /* not a number */

    i=0;
    if(isdigit(c)) {
        while(isdigit(s[++i]=c=get_ch())); /* collect integer part */
    }

    if(c == '.') {
        while(isdigit(s[++i]=c=get_ch())); /* collect fractional part */
    }

    s[i] = '\0';

    if(c != EOF) {
        unget_ch(c); /* read an extra character */
    }

    return NUMBER; /* signal */
}
