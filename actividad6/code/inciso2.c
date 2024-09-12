#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();  // Crea un nuevo proceso hijo

    if (pid < 0) {
        // Si `fork()` falla, imprimimos un error
        perror("El Fork Fallo");
        return 1;
    }

    if (pid == 0) {
        // Este bloque es ejecutado por el proceso hijo
        printf("Proceso hijo (PID: %d) finalizando...\n", getpid());
        exit(0);  // El proceso hijo termina inmediatamente
    } else {
        // Este bloque es ejecutado por el proceso padre
        printf("Proceso padre (PID: %d) ha creado un proceso hijo (PID: %d)\n", getpid(), pid);

        // El proceso padre espera 60 segundos antes de llamar a `wait()`, dejando al proceso hijo como zombie
        sleep(60);

        // Después de 60 segundos, el proceso padre finalmente espera al hijo (recolectando el estado final del proceso hijo)
        wait(NULL);

        printf("Proceso hijo (PID: %d) ha sido recolectado y ya no es zombie.\n", pid);
    }

    return 0;
}
