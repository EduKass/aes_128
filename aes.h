#ifndef AES_H
#define AES_H

extern const int KEY_SIZE = 16;
extern unsigned char key[KEY_SIZE];
extern unsigned char iv[KEY_SIZE];
void cbcEncrypt(unsigned char* plaintext, unsigned char* ciphertext, int length, unsigned char* iv);
void cbcDecrypt(unsigned char* ciphertext, unsigned char* plaintext, int length, unsigned char* iv);
void addPadding(unsigned char*& buffer, int& size);
void generateRoundKeys(unsigned char key[]);

#endif
