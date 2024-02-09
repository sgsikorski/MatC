//enums for token types and for production types
typedef enum {
   // Expression tokens
   t_assi, t_id, t_literal, 
   
   // Number Arithmetic tokens
   t_add, t_sub, t_mul, t_div, t_mod, t_rshift, t_lshift, t_addadd, t_subsub,

   // Array Arithmetic tokens
   t_aadd, t_asub, t_amul, t_adiv,

   // Delimiter tokens
   t_lparen, t_rparen, t_lbrack, t_rbrack, t_lbrace, t_rbrace, 
   
   // Relational tokens 
   t_eq, t_neq, t_less, t_great, t_lesseq, t_greateq,
   
   // Conditional and Loop tokens
   t_if, t_elseif, t_else, t_for, t_while, t_switch, t_break, t_continue, t_return, t_case, t_default, 
      
   // Array/Pointer tokens
   t_comma, t_dot, t_pat, t_ampersand, t_arrow,

   // Control tokens
   t_semicolon, t_colon,

   // Logical tokens
   t_and, t_or, t_not,
    
   // Type tokens
   t_void, t_integer, t_float, t_double, t_char, t_string, t_boolean, 
              
   // EOF
   t_eof,

} token;

typedef enum {p_program, p_stmt_list, p_stmt, p_relation, p_expr, p_expr_tail, p_term, p_term_tail,
                 p_factor ,p_factor_tail, p_ao, p_mo, p_ro} production;

#define MAX_TOKEN_LEN 200
extern char token_image[MAX_TOKEN_LEN];

extern token scan();

