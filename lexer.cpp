#include <iostream>
#include "lexer.h"
#include "string.h"

using namespace std;

char token_image[MAX_TOKEN_LEN];

token scan(){
    char c = ' ';
    int i = 0;
    // Skip any whitespace
    while (isspace(c))
        c = getchar();

    if (c == EOF) return t_eof;

    // Match Identifier, Condition and Loop, Type
    if (isalpha(c)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
        do {
            token_image[i++] = c;
            c = getchar();
        } while (isalpha(c) || isdigit(c) || c == '_');
        token_image[i] = '\0';
        if (!strcmp(token_image, "if")) return t_if;
        else if (!strcmp(token_image, "elseif")) return t_elseif;
        else if (!strcmp(token_image, "else")) return t_else;
        else if (!strcmp(token_image, "for")) return t_for;
        else if (!strcmp(token_image, "while")) return t_while;
        else if (!strcmp(token_image, "switch")) return t_switch;
        else if (!strcmp(token_image, "break")) return t_break;
        else if (!strcmp(token_image, "continue")) return t_continue;
        else if (!strcmp(token_image, "return")) return t_return;
        else if (!strcmp(token_image, "case")) return t_case;
        else if (!strcmp(token_image, "default")) return t_default;
        else if (!strcmp(token_image, "void")) return t_void;
        else if (!strcmp(token_image, "integer")) return t_integer;
        else if (!strcmp(token_image, "float")) return t_float;
        else if (!strcmp(token_image, "double")) return t_double;
        else if (!strcmp(token_image, "char")) return t_char;
        else if (!strcmp(token_image, "string")) return t_string;
        else if (!strcmp(token_image, "boolean")) return t_boolean;
        else return t_id;
    } else if (isdigit(c)) { // number: [0-9]+
        do {
            token_image[i++] = c;
            c = getchar();
        } while (isdigit(c));
        token_image[i] = '\0';
        return t_literal;
    } else switch (c) {
        case '+': 
            c = getchar();
            if (c== '+'){
                return t_addadd;
            } else{
                ungetc(c, stdin);
                return t_add;
            }
        case '-': 
            c = getchar();
            if (c== '-'){
                return t_subsub;
            } 
            else if (c=='>'){
                return t_arrow;
            }
            else{
                ungetc(c, stdin);
                return t_sub;
            }
        case '*': return t_mul;
        case '/': return t_div;
        case '%': return t_mod;

        case '(': return t_lparen;
        case ')': return t_rparen;
        case '{': return t_lbrace;
        case '}': return t_rbrace;
        case '[': return t_lbrack;
        case ']': return t_rbrack;
        case ',': return t_comma;

        case '.':
            c = getchar();
            if (c == '+'){
                return t_aadd;
            }
            else if (c == '-'){
                return t_asub;
            }
            else if (c == '*'){
                return t_amul;
            }
            else if (c == '/'){
                return t_adiv;
            }
            else {
                ungetc(c, stdin);
                return t_dot;
            }

        case '=': 
            c = getchar();
            if (c == '=') {
                return t_eq;
            } 
            
            else {
                ungetc(c, stdin);
                return t_assi;
            }

        case '!':
            c = getchar();
            if (c == '=') {
                return t_neq;
            } else {
                ungetc(c, stdin);
                return t_not;
            }
        case '<':
            c = getchar();
            if (c == '=') {
                return t_lesseq;
            }
            else if (c == '<') {
                return t_lshift;
            } 
            else {
                ungetc(c, stdin);
                return t_less;
            }
        case '>':
            c = getchar();
            if (c == '=') {
                return t_greateq;
            }
            else if (c == '>') {
                return t_rshift;
            } 
            else {
                ungetc(c, stdin);
                return t_great;
            }
        case ':': return t_colon;
        case ';': return t_semicolon;
        case '&': 
            c = getchar();
            if (c=='&')
                return t_and;
            else{
                ungetc(c, stdin);
                return t_ampersand;
            }
        case '|': 
            c = getchar();
            if (c=='|')
                return t_or;
            else{
                ungetc(c, stdin);
                return t_eof;
            }
        case '@': return t_pat;
        case EOF: return t_eof;
        default: return t_eof;
    }
}