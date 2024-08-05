
# GPIO in C

Este projeto demonstra como configurar e utilizar os pinos GPIO em um Orange Pi utilizando a linguagem C.

## Pré-requisitos

Antes de começar, certifique-se de ter o seguinte instalado:

- Git
- Build-essential (compilador GCC e ferramentas de desenvolvimento)

Você pode instalar esses pacotes com o comando abaixo:

```bash
sudo apt-get update
sudo apt-get install git build-essential -y
```

## Instalação do WiringOP

O WiringOP é uma biblioteca necessária para manipulação dos GPIOs em dispositivos baseados em Allwinner, como o Orange Pi.

1. Clone o repositório WiringOP para o seu ambiente:
    ```bash
    git clone https://github.com/zhaolei/WiringOP.git -b h3
    ```

2. Navegue até o diretório clonado:
    ```bash
    cd WiringOP
    ```

3. Conceda permissões de execução ao script de build:
    ```bash
    sudo chmod +x ./build
    ```

4. Construa e instale a biblioteca:
    ```bash
    sudo ./build
    ```

## Compilando o Código

Para compilar o código C que utiliza a biblioteca WiringPi, utilize o seguinte comando:

```bash
gcc main.c -o main -lwiringPi -pthread
```

## Referência de Pinagem

Confira o guia de pinagem para entender a correspondência dos pinos GPIO:

[Guia de Pinagem GPIO](https://learn.sparkfun.com/tutorials/raspberry-gpio/gpio-pinout)

---

Sinta-se à vontade para contribuir com melhorias ou reportar problemas abrindo uma issue no repositório.

