#include "implementation.h"
#include <stdlib.h>
#include <stdio.h>

Record hashTable[TABLE_SIZE];

static int positiveModulo(int value, int divisor)
{
    int remainder = value % divisor;
    return remainder < 0 ? remainder + divisor : remainder;
}

int hashFunction(int key)
{
    return hashModulo(key, TABLE_SIZE);
}

Record *hashSearch(int key)
{
    for (int attempt = 0; attempt < TABLE_SIZE; attempt++)
    {
        int address = hashLinearProbing(key, attempt);

        if (!hashTable[address].occupied)
        {
            return NULL;
        }

        if (hashTable[address].key == key)
        {
            return &hashTable[address];
        }
    }

    return NULL;
}

// Collision resolution (open addressing)
int hashLinearProbing(int key, int attempt)
{
    if (attempt < 0)
    {
        return -1;
    }

    return positiveModulo(hashFunction(key) + attempt, TABLE_SIZE);
}

int hashQuadraticProbing(int key, int attempt)
{
    if (attempt < 0)
    {
        return -1;
    }

    long long offset = (long long)attempt * attempt;
    return (int)((hashFunction(key) + offset) % TABLE_SIZE);
}

int hashDoubleHashing(int key, int attempt)
{
    if (attempt < 0)
    {
        return -1;
    }

    int step = 1 + positiveModulo(key, TABLE_SIZE - 1);
    long long address = hashFunction(key) + (long long)attempt * step;
    return (int)(address % TABLE_SIZE);
}

// Hashing methods
int hashDirect(int key)
{
    return key;
}

int hashModulo(int key, int m)
{
    if (m <= 0)
    {
        return -1;
    }

    return positiveModulo(key, m);
}

int hashDigitExtraction(int key)
{
    char buf[7];
    snprintf(buf, sizeof(buf), "%06d", abs(key) % 1000000);
    char addr[4] = {buf[0], buf[2], buf[3], '\0'}; // 1 3 4. karakterler
    return atoi(addr);
}

int hashFoldShift(int key)
{ // 9 basamaklı örnek üzerinden
    key = abs(key);

    int chunk1 = key / 1000000;
    int chunk2 = (key / 1000) % 1000;
    int chunk3 = key % 1000;

    int sum = chunk1 + chunk2 + chunk3;

    return sum % 1000;
}
