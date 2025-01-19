# Simulação de Placa com Raspberry Pi Pico

## Descrição
Este projeto demonstra o controle de LEDs RGB e um buzzer utilizando um teclado matricial 4x4 em uma Raspberry Pi Pico. Ele explora GPIOs e interação em tempo real para executar ações com base nas teclas pressionadas.

## Funcionalidades
- Acender LEDs RGB individualmente (vermelho, verde e azul).
- Sequência de iluminação com os LEDs.
- Acionar o buzzer por 2 segundos.
- Controle via teclado matricial 4x4.

## Estrutura do Projeto
### Arquivos Principais
- **SimulaçãoPlaca.c**: Implementação do código-fonte principal.
- **CMakeLists.txt**: Arquivo de configuração para compilação do projeto.

### Configurações de GPIOs
- **Pinos do Teclado Matricial (Keypad)**:
  - Linhas: 16, 17, 18, 19.
  - Colunas: 20, 4, 9, 8.
- **Pinos dos LEDs**:
  - Vermelho: 13.
  - Verde: 11.
  - Azul: 12.
- **Pino do Buzzer**:
  - 10 .

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
   - Pressione as teclas do teclado matricial para interagir com o sistema.

## Comandos
- `A`: Acende o LED vermelho.
- `B`: Acende o LED verde.
- `C`: Acende o LED azul.
- `D`: Inicia uma sequência de iluminação com os LEDs.
- `*`: Ativa o buzzer por 2 segundos.

## Observações
- Inclui debounce para evitar leituras incorretas no teclado matricial.
- As instruções são exibidas no console para auxiliar o usuário.

## Vídeo Explicativo
[Assista ao vídeo explicativo clicando aqui.](https://youtube.com/shorts/lx8Kyn2L46M?feature=share)

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

