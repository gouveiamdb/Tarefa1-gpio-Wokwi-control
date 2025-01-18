#include "pico/stdlib.h"
#include <stdio.h>

// Defina os pinos GPIO para as linhas e colunas
#define ROW_1 16
#define ROW_2 17
#define ROW_3 18
#define ROW_4 19
#define COL_1 20
#define COL_2 4
#define COL_3 9
#define COL_4 8

// Mapeamento do teclado
char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Função para inicializar os GPIOs
void init_keypad() {
    // Configure as linhas como saída
    gpio_init(ROW_1);
    gpio_init(ROW_2);
    gpio_init(ROW_3);
    gpio_init(ROW_4);
    gpio_set_dir(ROW_1, GPIO_OUT);
    gpio_set_dir(ROW_2, GPIO_OUT);
    gpio_set_dir(ROW_3, GPIO_OUT);
    gpio_set_dir(ROW_4, GPIO_OUT);

    // Configure as colunas como entrada com pull-down
    gpio_init(COL_1);
    gpio_init(COL_2);
    gpio_init(COL_3);
    gpio_init(COL_4);
    gpio_set_dir(COL_1, GPIO_IN);
    gpio_set_dir(COL_2, GPIO_IN);
    gpio_set_dir(COL_3, GPIO_IN);
    gpio_set_dir(COL_4, GPIO_IN);
    gpio_pull_down(COL_1);
    gpio_pull_down(COL_2);
    gpio_pull_down(COL_3);
    gpio_pull_down(COL_4);
}

// Função para digitalizar o teclado
char scan_keypad() {
    uint8_t rows[] = {ROW_1, ROW_2, ROW_3, ROW_4};
    uint8_t cols[] = {COL_1, COL_2, COL_3, COL_4};

    for (int i = 0; i < 4; i++) {
        // Ativar a linha atual
        gpio_put(rows[i], 1);
        sleep_us(10);  // Um pequeno delay para estabilizar a linha

        for (int j = 0; j < 4; j++) {
            // Verificar se a coluna está ativa
            if (gpio_get(cols[j])) {
                gpio_put(rows[i], 0);  // Desativar a linha
                return keys[i][j];    // Retornar a tecla pressionada
            }
        }
        gpio_put(rows[i], 0);  // Desativar a linha
    }
    return '\0';  // Nenhuma tecla pressionada
}

int main() {
    stdio_init_all();  // Inicializar saída padrão (USB/Serial)
    init_keypad();     // Inicializar o teclado

    printf("Pressione uma tecla no teclado matricial.\n");

    while (1) {
        char key = scan_keypad();
        if (key != '\0') {  // Se uma tecla foi pressionada
            printf("Tecla pressionada: %c\n", key);
            sleep_ms(300);  // Debounce
        }
    }

    return 0;
}
