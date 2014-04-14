#!/usr/bin/env python3

tokens = ['IDENTIFIER',
          'LPAREN', 'RPAREN',
          'LBRACE', 'RBRACE',
          'LBRACKET', 'RBRACKET',
          'ASSIGN_SIGN'
          'PLUS_SIGN', 'MINUS_SIGN', 'MULTIPLY_SIGN', 'DIVIDE_SIGN', 'MODULUS_SIGN',
          'EQUALS_SIGN', 'DIFF_SIGN', 'NEG_SIGN', 'AND', 'OR'
          'LT_SIGN', 'GT_SIGN', 'LTE_SIGN', 'GTE_SIGN',
          'INT_LIT', 'BOOL_LIT', 'LIST_LIT', 'STR_LIT',
          'COMMA', 'SEMICOLON']

reserved = {
          'int': 'INT',
          'bool': 'BOOL',
          'string': 'STRING',
          'list': 'LIST',
          'void': 'VOID',
          'if': 'IF',
          'else if': 'ELSE_IF',
          'else': 'ELSE',
          'return': 'RETURN',
          'while': 'WHILE'}

import ply.lex as lex
lex.lex()

# gramar

import ply.yacc as yacc
yacc.yacc()

# compiler
