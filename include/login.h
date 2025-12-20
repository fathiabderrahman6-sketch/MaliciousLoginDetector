#ifndef LOGIN_H
#define LOGIN_H

#define MAX_USERNAME 50
#define MAX_IP 40
#define MAX_STATUS 10
#define MAX_TIMESTAMP 30

// Structure représentant une tentative de login
typedef struct {
    char timestamp[MAX_TIMESTAMP];
    char username[MAX_USERNAME];
    char status[MAX_STATUS];     // "SUCCESS" ou "FAIL"
    char ip_address[MAX_IP];
} Login;

#endif
