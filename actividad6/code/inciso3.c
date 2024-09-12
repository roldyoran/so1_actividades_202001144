#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Acción de ejemplo del hilo
    printf("Hilo ejecutándose en el proceso PID: %d\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread_id;

    // Primer fork
    pid = fork();

    if (pid == 0) {
        // Estamos en el proceso hijo
        // Segundo fork dentro del proceso hijo
        fork();

        // Crear un hilo dentro del proceso hijo
        pthread_create(&thread_id, NULL, thread_function, NULL);
        pthread_join(thread_id, NULL); // Esperar a que el hilo termine
    }

    // Tercer fork fuera del if
    fork();

    // Pausa para que los procesos no terminen inmediatamente
    sleep(1);

    return 0;
}
