
const unsigned char S_BOX[256] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

const unsigned char INV_S_BOX[256] = {
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};

const unsigned char Rcon[11] = {0x00, 0x01,  0x02,  0x04,  0x08,  0x10,  0x20,  0x40,  0x80, 0x1B, 0x36
};
const int KEY_SIZE = 16;        // Key size in bytes (128 bits)
const int N_r = 10;             // Number of rounds in AES
const int N_k = 4;              // Number of words in the key
bool isEncrypt = true;          // Encryption mode flag
const unsigned char paddingCharacter = '0'; // Padding character for data alignment
int currRound = 0;              // Tracks the current AES round
unsigned char words[44][4] = {}; // Expanded key schedule
unsigned char blocks[4][KEY_SIZE] = {}; // Data blocks for AES
unsigned char iv[KEY_SIZE + 1] = "eduards123456789"; // Initialization vector
unsigned char key[KEY_SIZE + 1] = {}; // AES key

// Function to add padding to input data for AES block size alignment
void addPadding(unsigned char*& buffer, int& length) {
    int originalLength = length;
    while (length % KEY_SIZE != 0) { // Extend to match AES block size
        length++;
    }

    unsigned char* newBuffer = new unsigned char[length];
    for (int i = 0; i < originalLength; i++) {
        newBuffer[i] = buffer[i]; // Copy original data
    }
    for (int i = originalLength; i < length; i++) {
        newBuffer[i] = paddingCharacter; // Add padding
    }

    delete[] buffer; // Free old buffer memory
    buffer = newBuffer;
}

// Rotates a word (4 bytes) one byte to the left (used in key schedule)
void rotWord(unsigned char word[]) {
    unsigned char temp = word[0];
    for (int i = 0; i < 3; i++) {
        word[i] = word[i + 1];
    }
    word[3] = temp;
}

// Substitutes bytes in a word using the S-Box (used in key schedule)
void subWord(unsigned char word[]) {
    for (int i = 0; i < N_k; i++) {
        word[i] = S_BOX[word[i]];
    }
}
// Generates round keys from the main key using the AES key schedule
void generateRoundKeys(unsigned char key[]){

    // Initialize the first 4 words of the key schedule using the input key
    for (int i = 0; i < 4; i++) {
        words[i][0] = key[4 * i];       // First byte of the i-th word
        words[i][1] = key[4 * i + 1];   // Second byte of the i-th word
        words[i][2] = key[4 * i + 2];   // Third byte of the i-th word
        words[i][3] = key[4 * i + 3];   // Fourth byte of the i-th word
    }

    // Generate the remaining words for the key schedule
    for (int i = 4; i < 44 ; i++){
        unsigned char temp[4] = {}; // Temporary array to store the previous word
        temp[0] = words[i-1][0];
        temp[1] = words[i-1][1];
        temp[2] = words[i-1][2];
        temp[3] = words[i-1][3];

        // Every 4th word undergoes transformations: rotate, substitute, and XOR with Rcon
        if(i % 4 == 0){
            rotWord(temp);                 // Rotate the word
            subWord(temp);                 // Substitute bytes using S-box
            temp[0] = temp[0]^Rcon[i/4];   // XOR with round constant
        }

        // Compute the current word by XORing with the word 4 steps before
        words[i][0] = words[i-4][0] ^ temp[0];
        words[i][1] = words[i-4][1] ^ temp[1];
        words[i][2] = words[i-4][2] ^ temp[2];
        words[i][3] = words[i-4][3] ^ temp[3];
    }
}

void addRoundKey(unsigned char state[]){

    if(isEncrypt){ // Encryption branch
        for(int i = 0; i<KEY_SIZE; i++){
            state[i] = state[i] ^ words[currRound*4][i]; // XOR state with the current round key
        }
        currRound++; // Move to the next round
    } else { // Decryption branch
        currRound--; // Move to the previous round
        for(int i = 0; i<KEY_SIZE; i++){
            state[i] = state[i] ^ words[currRound*4][i]; // XOR state with the current round key
        }
    }
}

void subBytes(unsigned char state[]){
    // Substitute each byte in the state using the S-box
    for (int i = 0; i < KEY_SIZE; i++) {
        state[i] = S_BOX[state[i]];
    }
}

void shiftRows(unsigned char state[]){
    // Perform row shifting for AES

    // Rotate the second row left by 1 position
    unsigned char temp = state[1];
    for (int i = 1; i < KEY_SIZE; i=i+N_k) {
        if(i==13) break;  // Stop rotation at the last column
        state[i] = state[i + N_k];
    }
    state[13] = temp;

    // Swap bytes in the third row
    temp = state[2];
    state[2] = state[10];
    state[10] = temp;
    temp = state[6];
    state[6] = state[14];
    state[14] = temp;

    // Rotate the fourth row right by 1 position
    temp = state[15];
    for (int i = 15; i > 0; i=i-N_k) {
        if (i==3) break; // Stop rotation at the first column
        state[i] = state[i - N_k];
    }
    state[3] = temp;
}

unsigned char GF_Mul02(unsigned char a) {
    unsigned char h = a >> 7; // Check if high bit is set
    unsigned char result = a << 1; // Left shift by 1 (multiply by 2)
    result ^= h * 0x1B; // XOR with 0x1B if high bit is set
    return result;
}

unsigned char GF_Mul03(unsigned char a) {
    return GF_Mul02(a) ^ a; // 02 * a XOR a = 03 * a
}

unsigned char GF_Mul09(unsigned char a) {
    return GF_Mul02(GF_Mul02(GF_Mul02(a))) ^ a; // 02 * (02 * (02 * a)) XOR a
}

unsigned char GF_Mul0B(unsigned char a) {
    return GF_Mul02(GF_Mul02(GF_Mul02(a)) ^ a) ^ a; // 02 * (02 * (02 * a XOR a)) XOR a
}

unsigned char GF_Mul0D(unsigned char a) {
    return GF_Mul02(GF_Mul02(a ^ GF_Mul02(a))) ^ a; // 02 * (02 * (a XOR (02 * a))) XOR a
}

unsigned char GF_Mul0E(unsigned char a) {
    return GF_Mul02(GF_Mul02(GF_Mul02(a) ^ a) ^ a); // 02 * (02 * (02 * a XOR a) XOR a)
}

void mixColumns(unsigned char state[]) {
    unsigned char temp[4];

    for (int i = 0; i < 4; i++) {
        // Extract each column (4 bytes per column)
        temp[0] = state[i * 4 + 0];
        temp[1] = state[i * 4 + 1];
        temp[2] = state[i * 4 + 2];
        temp[3] = state[i * 4 + 3];

        // Perform the MixColumns transformation for each byte
        state[i * 4 + 0] = GF_Mul02(temp[0]) ^ GF_Mul03(temp[1]) ^ temp[2] ^ temp[3];
        state[i * 4 + 1] = temp[0] ^ GF_Mul02(temp[1]) ^ GF_Mul03(temp[2]) ^ temp[3];
        state[i * 4 + 2] = temp[0] ^ temp[1] ^ GF_Mul02(temp[2]) ^ GF_Mul03(temp[3]);
        state[i * 4 + 3] = GF_Mul03(temp[0]) ^ temp[1] ^ temp[2] ^ GF_Mul02(temp[3]);
    }
}

void encrypt(unsigned char state[]){
    isEncrypt = true; // Set the encryption flag to true
    addRoundKey(state); // Apply the initial round key

    // Perform N_r rounds of AES encryption
    for(int i = 0; i < N_r; i++){
        subBytes(state);      // Substitute bytes using the S-box
        shiftRows(state);     // Perform row shifting
        if (i < 9){           // Skip mixColumns in the final round
            mixColumns(state); // Mix columns for diffusion
        }
        addRoundKey(state);   // Apply the round key
    }
}

void inverseShiftRows(unsigned char state[]){
    // Perform inverse row shifting for AES

    // Rotate the second row right by 1 position
    unsigned char temp = state[13];
    for (int i = 13; i > 0; i=i-N_k) {
        if(i==1) break; // Stop rotation at the first column
        state[i] = state[i - N_k];
    }
    state[1] = temp;

    // Swap bytes in the third row
    temp = state[2];
    state[2] = state[10];
    state[10] = temp;
    temp = state[6];
    state[6] = state[14];
    state[14] = temp;

    // Rotate the fourth row left by 1 position
    temp = state[3];
    for (int i = 3; i < KEY_SIZE; i=i+N_k) {
        if(i==15) break; // Stop rotation at the last column
        state[i] = state[i + N_k];
    }
    state[15] = temp;
}

void inverseSubBytes(unsigned char state[]){
    // Substitute each byte in the state using the inverse S-box
    for (int i = 0; i < KEY_SIZE; i++) {
        state[i] = INV_S_BOX[state[i]];
    }
}

void inverseMixColumns(unsigned char state[]){
    unsigned char temp[4];

    for (int i = 0; i < 4; i++) {
        // Extract each column (4 bytes per column)
        temp[0] = state[i * 4 + 0];
        temp[1] = state[i * 4 + 1];
        temp[2] = state[i * 4 + 2];
        temp[3] = state[i * 4 + 3];

        // Perform the inverse MixColumns transformation for each byte
        state[i * 4 + 0] = GF_Mul0E(temp[0]) ^ GF_Mul0B(temp[1]) ^ GF_Mul0D(temp[2]) ^ GF_Mul09(temp[3]);
        state[i * 4 + 1] = GF_Mul09(temp[0]) ^ GF_Mul0E(temp[1]) ^ GF_Mul0B(temp[2]) ^ GF_Mul0D(temp[3]);
        state[i * 4 + 2] = GF_Mul0D(temp[0]) ^ GF_Mul09(temp[1]) ^ GF_Mul0E(temp[2]) ^ GF_Mul0B(temp[3]);
        state[i * 4 + 3] = GF_Mul0B(temp[0]) ^ GF_Mul0D(temp[1]) ^ GF_Mul09(temp[2]) ^ GF_Mul0E(temp[3]);
    }
}

void decrypt(unsigned char state[]){
    isEncrypt = false;
    addRoundKey(state);
    for(int i = N_r - 1; i >= 0; i--){
        inverseShiftRows(state);
        inverseSubBytes(state);
        addRoundKey(state);
        if (i > 0){
            inverseMixColumns(state);
        }
    }

}

void cbcEncrypt(unsigned char* plaintext, unsigned char* ciphertext, int length, unsigned char* iv) {
    int numberOfBlocks = length / KEY_SIZE;
    int count = 0;
    unsigned char previousBlock[KEY_SIZE] = {};

    for (int i = 0; i < KEY_SIZE; i++) {
        previousBlock[i] = iv[i];
    }

    // Process each block
    for (int i = 0; i < numberOfBlocks; i++) {
        unsigned char currentBlock[KEY_SIZE] = {};  // Temporary block for current plaintext block

        // Copy the current block from plaintext
        for (int j = 0; j < KEY_SIZE; j++) {
            currentBlock[j] = plaintext[count++];
        }

        // XOR the current plaintext block with the previous ciphertext block (or IV for the first block)
        for (int j = 0; j < KEY_SIZE; j++) {
            currentBlock[j] ^= previousBlock[j];  // XOR with previous block (IV for first block)
        }

        // Encrypt the XORed block
        currRound = 0;
        encrypt(currentBlock);  // Your AES encryption function

        // Store the encrypted block into ciphertext
        for (int j = 0; j < KEY_SIZE; j++) {
            ciphertext[i * KEY_SIZE + j] = currentBlock[j];
        }

        // Update the previous block with the current encrypted block
        for (int j = 0; j < KEY_SIZE; j++) {
            previousBlock[j] = currentBlock[j];
        }
    }
}

void cbcDecrypt(unsigned char* ciphertext, unsigned char* plaintext, int length, unsigned char* iv) {
    int numberOfBlocks = length / KEY_SIZE;
    int count = 0;
    unsigned char previousBlock[KEY_SIZE] = {};  // Stores the previous ciphertext block

    // Initialize the previous block to the IV for the first block
    for (int i = 0; i < KEY_SIZE; i++) {
        previousBlock[i] = iv[i];
    }

    // Process each block
    for (int i = 0; i < numberOfBlocks; i++) {
        unsigned char currentBlock[KEY_SIZE] = {};  // Temporary block for current ciphertext block

        // Copy the current block from ciphertext
        for (int j = 0; j < KEY_SIZE; j++) {
            currentBlock[j] = ciphertext[count++];
        }

        // Decrypt the current block using AES decryption
        currRound = 11;
        decrypt(currentBlock);  // Your AES decryption function

        // XOR the decrypted block with the previous ciphertext block (or IV for the first block)
        for (int j = 0; j < KEY_SIZE; j++) {
            currentBlock[j] ^= previousBlock[j];  // XOR with previous block (IV for first block)
        }

        // Store the decrypted block into plaintext
        for (int j = 0; j < KEY_SIZE; j++) {
            plaintext[i * KEY_SIZE + j] = currentBlock[j];
        }

        // Update the previous block with the current ciphertext block for the next iteration
        for (int j = 0; j < KEY_SIZE; j++) {
            previousBlock[j] = ciphertext[i * KEY_SIZE + j];  // Store current ciphertext for next block
        }
    }
}

