#ifndef CAESAR_H
#define CAESAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char text_cipher(const char c, unsigned int shift);

char cipher_text(const char c, unsigned int shift);

void encode_line(char *src, unsigned int shift);

void decode_line(char *src, unsigned int shift);

unsigned int encode_to_file(char *dest, char *src, unsigned int max_len, unsigned int shift);

unsigned int decode_to_file(char *dest, char *src, unsigned int max_len, unsigned int shift);

#endif