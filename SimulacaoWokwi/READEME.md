# Simulação Wokwi com Raspberry Pi Pico

## Descrição
Este projeto é uma simulação para controle de LEDs RGB e um buzzer utilizando um teclado matricial 4x4, implementado em uma Raspberry Pi Pico. Ele explora o uso de GPIOs para criar uma interface interativa e responsiva que executa comandos com base nas teclas pressionadas.

## Funcionalidades
- Controle de LEDs RGB com as cores:
  - Vermelho.
  - Verde.
  - Azul.
  - Todos simultaneamente.
- Emissão de som no buzzer por 2 segundos.
- Interação através de um teclado matricial 4x4.

## Estrutura do Projeto
### Arquivos Principais
- **SimulacaoWokwi.c**: Implementação do código-fonte principal.
- **CMakeLists.txt**: Arquivo de configuração para compilação do projeto.

### Configurações de GPIOs
- **Pinos do Teclado Matricial (Keypad)**:
  - Linhas: 8, 7, 6, 5.
  - Colunas: 4, 3, 2, 1.
- **Pinos dos LEDs**:
  - Vermelho: 13.
  - Verde: 11.
  - Azul: 12.
- **Pino do Buzzer**:
  - 21 .

## Instruções de Uso
1. **Montagem do Circuito**:
   - Conecte os LEDs, o buzzer e o teclado matricial conforme os pinos especificados no código.

2. **Configuração do Ambiente**:
   - Certifique-se de que o Raspberry Pi Pico SDK esteja instalado.
   - Use o CMake para compilar o projeto:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

3. **Execução do Programa**:
   - Carregue o arquivo binário gerado na Raspberry Pi Pico.
   - Interaja com o sistema pressionando as teclas do teclado matricial.

## Comandos
- `A`: Acende o LED vermelho.
- `B`: Acende o LED verde.
- `C`: Acende o LED azul.
- `D`: Acende todos os LEDs simultaneamente.
- `*`: Ativa o buzzer por 2 segundos.
- Qualquer outra tecla: Desliga os LEDs que estiverem acesos.

## Observações
- O programa inclui um mecanismo de debounce para evitar leituras incorretas.
- As instruções são exibidas no console para orientar o usuário.

## Vídeo Explicativo
[Assista ao vídeo explicativo clicando aqui.](https://youtu.be/8GTAyxUcUm8)

## Referências
- Documentação do Raspberry Pi Pico SDK.
- Simulador [Wokwi](https://wokwi.com/).

## Autores
Projeto desenvolvido por:
Thiago de Andrade Barros Machado - https://github.com/ThiagoMachado2
Pedro Henrique Ferreira Amorim da Silva - https://github.com/PedroHenriqueFAS
Matheus Gouveia de Deus Bastos - https://github.com/gouveiamdb
Naylane do Nascimento Ribeiro - https://github.com/naylane
Marcelo Barbosa de Almeida  - https://github.com/marcelofainor
Levi Silva Freitas - https://github.com/Lvi01
Alécio Vinicius Oliveira Silva - https://github.com/Al3ci0
Joel Junior Nunes Araujo - https://github.com/eijoeljunior289
Laiza Gordiano - https://github.com/laizagordiano

