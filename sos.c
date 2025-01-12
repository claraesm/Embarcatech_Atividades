//ATIVIDADE PARA DESENVOLVER UM CODIGO MORSE "SOS" USANDO A BITDOGLAB

#include <stdbool.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// GPIO para o LED (pino no qual o led está conectado)
#define LED 12         // Pino 12

// Define os tempos em milissegundos que foi determinado na tarefa
#define DOT_TIME 200       // Tempo de duração do Ponto 0,2 segundos
#define DASH_TIME 800      // Tempo de duração do Traço 0,8 segundos
#define GAP_TIME 125       // Intervalo de 0,125 segundos entre pontos e traços
#define LETTER_TIME 250    // Intervalo de 0,25 segundos entre letras
#define CYCLE_TIME 3000    // Intervalo de 3 segundos entre os ciclos do sinal SOS

int main() {
    gpio_init(LED); // Inicializa o GPIO
    gpio_set_dir(LED, GPIO_OUT); // Configura o pino como saída
    while (1) {
        send_sos(); // Executa o ciclo do SOS
    }
    return 0;
}

// Função configurada para acender o LED
void led_on() {
    gpio_put(LED, true);
}

// Função configurada para apagar o LED
void led_off() {
    gpio_put(LED, false);
}

// Função para gerar um ponto ou traço
void morse(uint32_t duration) {
    led_on();
    sleep_ms(duration); // espera pelo tempo especificado
    led_off();
    sleep_ms(GAP_TIME); // configurando o delay entre os sinais
}


void send_sos() { // Função principal para o sinal SOS
    // Sinal S (ponto, ponto, ponto)
    for (int i = 0; i < 3; i++) {
        morse(DOT_TIME); // LED HIGH por 0,2 segundos
    }
    sleep_ms(LETTER_TIME); // delay entre letras

    // Sinal O (traço, traço, traço)
    for (int i = 0; i < 3; i++) {
        morse(DASH_TIME); // LED HIGH por 0,8 segundos
    }
    sleep_ms(LETTER_TIME); // delay entre letras

    // Sinal S (ponto, ponto, ponto)
    for (int i = 0; i < 3; i++) {
        morse(DOT_TIME); // LED HIGH por 0,2 segundos
    }
    sleep_ms(CYCLE_TIME); // delay entre ciclos
}



