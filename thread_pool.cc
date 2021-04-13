#define 


struct NWORKER {
    pthread_t thread;
    struct NWORKER* prev;
    struct NWORKER* next;
};

struct NJOB {
    void (*func)(struct NJOB *job);
    void *user_data;

    struct NJOB *prev;
    struct NJOB *next;
};

struct NMANAGER {
    struct NWORKER *worker;
    struct NJOB *job;
};