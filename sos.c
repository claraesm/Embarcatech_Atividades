#include <stdbool.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definição do pino ao qual o LED está conectado
#define LED 12

// Definição dos tempos (em milissegundos) conforme especificado
#define TEMPO_PONTO 200       // Duração do ponto (0,2 segundos)
#define TEMPO_TRACO 800       // Duração do traço (0,8 segundos)

// Função principal
int main() {
    // Configura o pino do LED como saída
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    // Transmite continuamente o código SOS
    while (true) {
        // Envia a letra S (três pontos)
        for (int i = 0; i < 3; i++) {
            emitir_sinal_morse(TEMPO_PONTO);
        }
        sleep_ms(250); // Intervalo entre letras (0,25 segundos)

        // Envia a letra O (três traços)
        for (int i = 0; i < 3; i++) {
            emitir_sinal_morse(TEMPO_TRACO);
        }
        sleep_ms(250); // Intervalo entre letras (0,25 segundos)

        // Envia a letra S (três pontos)
        for (int i = 0; i < 3; i++) {
            emitir_sinal_morse(TEMPO_PONTO);
        }
        sleep_ms(3000); // Intervalo entre ciclos de transmissão (3 segundos)
    }

    return 0;
}

// Liga o LED
void acender_led() {
    gpio_put(LED, true);
}

// Desliga o LED
void apagar_led() {
    gpio_put(LED, false);
}

// Emite um sinal Morse (ponto ou traço)
void emitir_sinal_morse(uint32_t duracao) {
    acender_led();           // Liga o LED
    sleep_ms(duracao);       // Mantém o LED aceso pelo tempo definido
    apagar_led();            // Desliga o LED
    sleep_ms(125);           // Intervalo entre sinais (0,125 segundos)
}
