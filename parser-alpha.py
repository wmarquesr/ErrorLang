#!/usr/bin/env python3

# Tokens
# ======

reserved = {
    'int': 'INT',
    'bool': 'BOOL',
    'string': 'STRING',
    'list': 'LIST',
    'void': 'VOID',
    'if': 'IF',
    'else': 'ELSE',
    'return': 'RETURN',
    'while': 'WHILE',
    'true': 'BOOL_LIT',
    'false': 'BOOL_LIT'
}

tokens = ['IDENTIFIER',
          'LPAREN', 'RPAREN',
          'LBRACE', 'RBRACE',
          'LBRACKET', 'RBRACKET',
          'ASSIGN_SIGN',
          'PLUS_SIGN', 'MINUS_SIGN', 'MULTIPLY_SIGN', 'DIVIDE_SIGN', 'MODULUS_SIGN',
          'EQUALS_SIGN', 'NEQUALS_SIGN', 'NEG_SIGN', 'AND', 'OR',
          'LT_SIGN', 'GT_SIGN', 'LTE_SIGN', 'GTE_SIGN',
          'INT_LIT', 'STR_LIT',
          'COMMA', 'SEMICOLON'
] + list(set(reserved.values()))

t_LPAREN        = r'\('
t_RPAREN        = r'\)'
t_LBRACE        = r'\{'
t_RBRACE        = r'\}'
t_LBRACKET      = r'\['
t_RBRACKET      = r'\]'
t_ASSIGN_SIGN   =  '='
t_PLUS_SIGN     = r'\+'
t_MINUS_SIGN    =  '-'
t_MULTIPLY_SIGN = r'\*'
t_DIVIDE_SIGN   =  '/'
t_MODULUS_SIGN  =  '%'
t_EQUALS_SIGN   =  '=='
t_NEQUALS_SIGN  =  '!='
t_NEG_SIGN      =  '!'
t_AND           =  '&&'
t_OR            = r'\|\|'
t_LT_SIGN       =  '<'
t_GT_SIGN       =  '>'
t_LTE_SIGN      =  '<='
t_GTE_SIGN      =  '>='
t_STR_LIT       = r'"[^"]*"'
t_COMMA         =  ','
t_SEMICOLON     =  ';'

def t_IDENTIFIER(t):
    r'[a-zA-Z_][a-zA-Z0-9_]*'
    t.type = reserved.get(t.value,'IDENTIFIER')
    return t

def t_INT_LIT(t):
    r'[0-9]+'
    t.value = int(t.value)
    return t

# Ignored characters
t_ignore = " \t"

import ply.lex as lex
lex.lex()

# Grammar
# =======

#precedence = (
##    ('left', 'IMPLIES', 'EQUALS'),
##    ('left', 'AND', 'OR'),
##    ('nonassoc', 'LPAREN', 'RPAREN', 'NOT'),
#)

# Problems (TODO):

# ERROR: Projetos/ErrorLang/parser-alpha.py:91: Symbol 'var_assign' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:93: Symbol 'cond_expr' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:94: Symbol 'loop_expr' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:106: Symbol 'type_expr' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:114: Symbol 'int_literal' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:115: Symbol 'bool_literal' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:116: Symbol 'list_literal' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:117: Symbol 'string_literal' used, but not defined as a token or a rule
# ERROR: Projetos/ErrorLang/parser-alpha.py:118: Symbol 'function_literal' used, but not defined as a token or a rule
# WARNING: Token 'LBRACE' defined, but not used
# WARNING: Token 'RBRACKET' defined, but not used
# WARNING: Token 'COMMA' defined, but not used
# WARNING: Token 'INT' defined, but not used
# WARNING: Token 'STR_LIT' defined, but not used
# WARNING: Token 'INT_LIT' defined, but not used
# WARNING: Token 'LBRACKET' defined, but not used
# WARNING: Token 'WHILE' defined, but not used
# WARNING: Token 'ELSE' defined, but not used
# WARNING: Token 'LIST' defined, but not used
# WARNING: Token 'OR' defined, but not used
# WARNING: Token 'VOID' defined, but not used
# WARNING: Token 'RBRACE' defined, but not used
# WARNING: Token 'RETURN' defined, but not used
# WARNING: Token 'BOOL' defined, but not used
# WARNING: Token 'BOOL_LIT' defined, but not used
# WARNING: Token 'AND' defined, but not used
# WARNING: Token 'IF' defined, but not used
# WARNING: Token 'ASSIGN_SIGN' defined, but not used
# WARNING: Token 'STRING' defined, but not used
# WARNING: There are 19 unused tokens
# ERROR: Infinite recursion detected for symbol 'args_expr'
# ERROR: Infinite recursion detected for symbol 'arg_expr'
# ERROR: Infinite recursion detected for symbol 'call_expr'
# ERROR: Infinite recursion detected for symbol 'var_decl'

def p_expr(p):
    '''
    expr : algo_expr
    '''
    p[0] = p[1]

def p_algo_expr(p):
    '''
    algo_expr : var_decl
              | var_assign
              | value_expr
              | cond_expr
              | loop_expr
    '''
    p[0] = p[1]

def p_var_decl(p):
    '''
    var_decl : arg_expr SEMICOLON
    '''
    p[0] = ('VAR_DECL', p[1])

def p_arg_expr(p):
    '''
    arg_expr : type_expr identifier_expr
    '''
    p[0] = ('ARG', p[1], p[2])

def p_value_expr(p):
    '''
    value_expr : LPAREN value_expr RPAREN
               | identifier_expr
               | int_literal
               | bool_literal
               | list_literal
               | string_literal
               | function_literal
               | plus_expr
               | minus_expr
               | multiply_expr
               | divide_expr
               | modulus_expr
               | lt_expr
               | gt_expr
               | lte_expr
               | gte_expr
               | equals_expr
               | nequals_expr
               | neg_expr
               | call_expr
    '''
    p[0] = p[1]

def p_identifier_expr(p):
    '''
    identifier_expr : IDENTIFIER
    '''
    p[0] = ('IDENTIFIER', p[1])

def p_plus_expr(p):
    '''
    plus_expr : value_expr PLUS_SIGN value_expr
    '''
    p[0] = ('PLUS', p[1], p[3])

def p_minus_expr(p):
    '''
    minus_expr : value_expr MINUS_SIGN value_expr
    '''
    p[0] = ('MINUS', p[1], p[3])

def p_multiply_expr(p):
    '''
    multiply_expr : value_expr MULTIPLY_SIGN value_expr
    '''
    p[0] = ('MULTIPLY', p[1], p[3])

def p_divide_expr(p):
    '''
    divide_expr : value_expr DIVIDE_SIGN value_expr
    '''
    p[0] = ('DIVIDE', p[1], p[3])

def p_modulus_expr(p):
    '''
    modulus_expr : value_expr MODULUS_SIGN value_expr
    '''
    p[0] = ('MODULUS', p[1], p[3])

def p_lt_expr(p):
    '''
    lt_expr : value_expr LT_SIGN value_expr
    '''
    p[0] = ('LT', p[1], p[3])

def p_gt_expr(p):
    '''
    gt_expr : value_expr GT_SIGN value_expr
    '''
    p[0] = ('GT', p[1], p[3])

def p_lte_expr(p):
    '''
    lte_expr : value_expr LTE_SIGN value_expr
    '''
    p[0] = ('LTE', p[1], p[3])

def p_gte_expr(p):
    '''
    gte_expr : value_expr GTE_SIGN value_expr
    '''
    p[0] = ('GTE', p[1], p[3])

def p_equals_expr(p):
    '''
    equals_expr : value_expr EQUALS_SIGN value_expr
    '''
    p[0] = ('EQUALS', p[1], p[3])

def p_nequals_expr(p):
    '''
    nequals_expr : value_expr NEQUALS_SIGN value_expr
    '''
    p[0] = ('NEQUALS', p[1], p[3])

# TODO: suspeito. só pega o mais a esquerda?
def p_neg_expr(p):
    '''
    neg_expr : NEG_SIGN value_expr
    '''
    p[0] = ('NEG', p[2])

# TODO: não sei se especifiquei corretamente
# TODO: fazer para um argumento e zero argumentos?
def p_args_expr(p):
    '''
    args_expr : args_expr COMMA arg_expr
    '''
    p[0] = ('ARGS', p[1][1] + p[3])

# TODO: não sei se especifiquei corretamente
def p_call_expr(p):
    '''
    call_expr : identifier_expr LPAREN args_expr RPAREN
    '''
    p[0] = ('CALL', p[1], p[3])

import ply.yacc as yacc
yacc.yacc()

# compiler
