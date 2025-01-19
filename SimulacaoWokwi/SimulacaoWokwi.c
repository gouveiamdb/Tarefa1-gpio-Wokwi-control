#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos do Keypad
#define ROW1 8
#define ROW2 7
#define ROW3 6
#define ROW4 5
#define COL1 4
#define COL2 3
#define COL3 2
#define COL4 1

#define BUZZER 21

// Definição dos pinos dos LEDs
#define LED_GREEN 11  // LED verde
#define LED_BLUE 12   // LED azul
#define LED_RED 13    // LED vermelho

// Mapeamento das teclas do Keypad
const char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};


// Função para configurar os GPIOs
void setup_gpio() {
    // Configurando as linhas (ROW) como saídas
    gpio_init(ROW1);
    gpio_init(ROW2);
    gpio_init(ROW3);
    gpio_init(ROW4);
    gpio_set_dir(ROW1, GPIO_OUT);
    gpio_set_dir(ROW2, GPIO_OUT);
    gpio_set_dir(ROW3, GPIO_OUT);
    gpio_set_dir(ROW4, GPIO_OUT);

    // Configurando as colunas (COL) como entradas com pull-up
    gpio_init(COL1);
    gpio_init(COL2);
    gpio_init(COL3);
    gpio_init(COL4);
    gpio_set_dir(COL1, GPIO_IN);
    gpio_set_dir(COL2, GPIO_IN);
    gpio_set_dir(COL3, GPIO_IN);
    gpio_set_dir(COL4, GPIO_IN);
    gpio_pull_up(COL1);
    gpio_pull_up(COL2);
    gpio_pull_up(COL3);
    gpio_pull_up(COL4);

    // Configuração dos pinos dos LEDs
gpio_init(LED_RED);
gpio_init(LED_GREEN);
gpio_init(LED_BLUE);
gpio_set_dir(LED_RED, GPIO_OUT);
gpio_set_dir(LED_GREEN, GPIO_OUT);
gpio_set_dir(LED_BLUE, GPIO_OUT);

// Inicializando LEDs apagados
gpio_put(LED_RED, 0);
gpio_put(LED_GREEN, 0);
gpio_put(LED_BLUE, 0);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Função para verificar qual tecla foi pressionada
char scan_keypad() {
    // Iterando pelas linhas
    for (int row = 0; row < 4; row++) {
        // Definir a linha atual como LOW e as outras como HIGH
        gpio_put(ROW1, row == 0 ? 0 : 1);
        gpio_put(ROW2, row == 1 ? 0 : 1);
        gpio_put(ROW3, row == 2 ? 0 : 1);
        gpio_put(ROW4, row == 3 ? 0 : 1);

        // Verificar cada coluna
        if (!gpio_get(COL1)) return keys[row][0];
        if (!gpio_get(COL2)) return keys[row][1];
        if (!gpio_get(COL3)) return keys[row][2];
        if (!gpio_get(COL4)) return keys[row][3];
    }
    // Retornar '\0' se nenhuma tecla for pressionada
    return '\0';
}

// Função para executar comandos com base na tecla pressionada
void execute_comando(char key) {

     // Desliga todos os LEDs antes de acionar o próximo
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);

    switch (key) {
       case 'A':
            // Ligar LED vermelho
            gpio_put(LED_RED, 1);
            break;

        case 'B':
            // Ligar LED verde
            gpio_put(LED_GREEN, 1);
            break;

        case 'C':
            // Ligar LED azul
            gpio_put(LED_BLUE, 1);
            break;

        case 'D':
            // Ligar todos os LEDs
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 1);
            gpio_put(LED_BLUE, 1);
            break;
            
        case '*':
            printf("Comando: Tocar buzzer por 2 segundos.\n");
            gpio_put(BUZZER, 1);  
            sleep_ms(2000);        
            gpio_put(BUZZER, 0);
            printf("Comando: Buzzer desligado.\n");
            printf("\n");
            break;

        default:
            printf("Comando: Sem comando associado a tecla %c.\n", key);
            printf("\n");
            break;
    }
}

void print_instructions() {
    printf("Essa simulação controla os LEDs RGB e um buzzer usando um teclado matricial 4x4.\n");
    printf("Aperte as seguintes teclas para controlar os dispositivos:\n");
    printf("  - Tecla 'A': Acende o LED vermelho.\n");
    printf("  - Tecla 'B': Acende o LED verde.\n");
    printf("  - Tecla 'C': Acende o LED azul.\n");
    printf("  - Tecla 'D': Acende todos os LEDs.\n");
    printf("  - Tecla '*': Emite som no buzzer.\n");
    

    printf("Esperando que uma tecla seja pressionada:\n");
    printf("\n");
}

int main() {
    // Inicializar o sistema padrão e configurar GPIOs
    stdio_init_all();
    setup_gpio();

    // Instruções iniciais sobre o programa
    print_instructions();

    while (1) {
        char key = scan_keypad();
        if (key != '\0') {  // Se uma tecla foi pressionada
            printf("Tecla pressionada: %c\n", key);
            execute_comando(key);
            sleep_ms(300);         // Debounce
        }

        sleep_ms(50); // Pequeno atraso para evitar leituras incorretas
    }
}
