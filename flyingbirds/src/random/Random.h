#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#define MODULUS    2147483647
#define MULTIPLIER 48271
#define CHECK      399268537
#define STREAMS    256
#define A256       22925
#define DEFAULT    123456789
#include <ctime>

class Random{

    private:
        static long seed[STREAMS];
        static int  stream;
        static int  initialized;

    public:
        Random();
        double calcRandom(void);
        void plantSeeds(long x);
        void putSeed(long x);
        void getSeed(long *x);
        void selectStream(int index);

};

#endif // RANDOM_H_INCLUDED
