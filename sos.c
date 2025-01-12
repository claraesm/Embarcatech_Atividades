
// Inclui definições de tipos inteiros de tamanho fixo.
#include <stdint.h>

// Inclui suporte para o tipo booleano (bool), que permite trabalhar com valores true e false.
#include <stdbool.h>

// Inclui funções específicas para controle de GPIO no RP2040.
// Permite inicializar pinos, definir direção (entrada/saída) e manipular os valores dos pinos.
#include "hardware/gpio.h"

// Inclui funções padrão do SDK do Raspberry Pi Pico, como temporizações (sleep_ms) 
#include "pico/stdlib.h"

// Define os tempos em milissegundos
#define DOT_TIME 200       // Tempo de duração do Ponto 0,2 segundos
#define DASH_TIME 800      // Tempo de duração do Traço 0,8 segundos
#define GAP_TIME 125       // Intervalo de 0,125 segundos entre pontos e traços
#define LETTER_TIME 250    // Intervalo de 0,25 segundos entre letras
#define CYCLE_TIME 3000    // Intervalo de 3 segundos entre os ciclos do sinal SOS

// GPIO para o LED
#define LED_PIN 12         // Pino 12

// Função para acender o LED
void led_on() {
    gpio_put(LED_PIN, true);
}

// Função para apagar o LED
void led_off() {
    gpio_put(LED_PIN, false);
}

// Função para gerar um ponto ou traço
void morse_signal(uint32_t duration) {
    led_on();
    sleep_ms(duration); // Espera pelo tempo especificado
    led_off();
    sleep_ms(GAP_TIME); // Intervalo entre sinais
}

// Função principal para o sinal SOS
void send_sos() {
    // Sinal S (ponto, ponto, ponto)
    for (int i = 0; i < 3; i++) {
        morse_signal(DOT_TIME); // Acende o LED por 0,2 segundos
    }
    sleep_ms(LETTER_TIME); // Intervalo entre letras

    // Sinal O (traço, traço, traço)
    for (int i = 0; i < 3; i++) {
        morse_signal(DASH_TIME); // Acende o LED por 0,8 segundos
    }
    sleep_ms(LETTER_TIME); // Intervalo entre letras

    // Sinal S (ponto, ponto, ponto)
    for (int i = 0; i < 3; i++) {
        morse_signal(DOT_TIME); // Acende o LED por 0,2 segundos
    }
    sleep_ms(CYCLE_TIME); // Intervalo entre ciclos
}

// Função principal
int main() {
    gpio_init(LED_PIN); // Inicializa o GPIO
    gpio_set_dir(LED_PIN, GPIO_OUT); // Configura o pino como saída
    while (1) {
        send_sos(); // Executa o ciclo do SOS
    }
    return 0;
}

