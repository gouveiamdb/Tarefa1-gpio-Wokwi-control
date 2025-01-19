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

// Definição dos pinos do Buzze
#define BUZZER 21

// Definição dos pinos dos LEDs
#define LED_GREEN 11  
#define LED_BLUE 12   
#define LED_RED 13    

/**
 * @brief Mapeamento das teclas do Keypad
 * 
 * A matriz de teclas representa a organização do teclado matricial 4x4.
 */
const char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};


/**
 * @brief Configura os GPIOs para o teclado matricial, LEDs e buzzer.
 * 
 * Configura as linhas (ROW) como saídas e as colunas (COL) como entradas com pull-up.
 * Além de configurar os pinos dos LEDs e do buzzer como saídas.
 */
void setup_gpio();


/**
 * @brief Verifica qual tecla foi pressionada no teclado matricial.
 * 
 * Itera pelas linhas e verifica se alguma coluna foi pressionada.
 * 
 * @return O caractere da tecla pressionada ou '\0' se nenhuma tecla for pressionada.
 */
char scan_keypad();


/**
 * @brief Executa comandos baseados na tecla pressionada.
 * 
 * Executa comandos para acender os LEDs e emitir som no buzzer.
 * Além de imprimir mensagens no console para informar o comando executado.
 *
 * @param key A tecla pressionada.
 */
void execute_comando(char key);


/**
 * @brief Exibe as instruções iniciais do programa.
 * 
 * Exibe as instruções para o usuário sobre como controlar os LEDs e o buzzer.
 * E o que cada tecla do teclado matricial faz.
 */
void print_instructions();


/**
 * @brief Função principal do programa.
 * 
 * Inicializa os GPIOs, exibe instruções e monitora as teclas pressionadas para executar comandos.
 * Fazendo uso das funções de controle dos LEDs e do buzzer.
 * 
 * @return Retorna 0 em caso de execução bem-sucedida.
 */
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

// Implementações das funções
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

    // Configuração do buzzer
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

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

void execute_comando(char key) {
    // Desliga todos os LEDs antes de acionar o próximo
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);

    switch (key) {
       case 'A':
            // Ligar LED vermelho
            printf("Comando: Led vermelho ligado.\n");
            printf("\n");
            gpio_put(LED_RED, 1);
            break;

        case 'B':
            // Ligar LED verde
            printf("Comando: Led verde ligado.\n");
            printf("\n");
            gpio_put(LED_GREEN, 1);
            break;

        case 'C':
            // Ligar LED azul
            printf("Comando: Led azul ligado.\n");
            printf("\n");
            gpio_put(LED_BLUE, 1);
            break;

        case 'D':
            // Ligar todos os LEDs
            printf("Comando: Todos os LEDs sendo ligados.\n");
            printf("\n");
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
            printf("Comando: Desligando todos os LEDs.\n");
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
    printf("  - Qualquer outra tecla: Desliga os LEDs que estão acesos.\n");
    printf("Esperando que uma tecla seja pressionada:\n");
    printf("\n");
}
