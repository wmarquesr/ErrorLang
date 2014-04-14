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

# gramar

import ply.yacc as yacc
yacc.yacc()

# compiler
