typedef struct
{
    int key;
    char name[50];
    int occupied; // is the slot empty?
} Record;

int hashFunction(int key);
Record *hashSearch(int key);

// Hashing methods
int hashDirect(int key);
int hashModulo(int key, int m);
int hashDigitExtraction(int key);
int hashFoldShift(int key);
// collision resolution : pseudorandom, linear probe, quadratic probe, pseudorandom probe, double hashing, linkedlist, bucket