#ifndef _C_SYNTAX_MAIN_H_
#define _C_SYNTAX_MAIN_H_

#define IDEN_MAXLEN 100 //the maximum length of the identifier's name

typedef enum _C_Token {
    ID,
    KEY,
    INT_CONS,
    CHAR_CONS,
    FLOAT_CONS,
    ENUM_CONS,
    STR
} C_TokenVal;

char *KeywordTable[] = {"auto", "double", "int", "struct", "break",
                           "else", "long", "switch", "case", "enum",
                           "register", "typedef", "char", "extern",
                           "return", "union", "const", "float", "short",
                           "unsigned", "continue", "for", "signed", "void",
                           "default", "goto", "sizeof", "volatile", "do",
                           "if", "static", "while"
};

typedef struct _iden {
    C_TokenVal val;
    char name[IDEN_MAXLEN];
} iden;

typedef struct _keyword {
int table_index;
} keyword;


#define STATE_id_keyword_OUT 0
#define STATE_id_keyword_IN 1


#endif
