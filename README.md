# Projeto Filas-RU-AED1

Este projeto é uma implementação de um sistema de filas do Restaurante Universitário utilizando conceitos de Algoritmos e Estruturas de Dados 1.

## Estrutura de Pastas

- **src/**: Contém os arquivos fonte (.c) do projeto.
- **include/**: Contém os arquivos de cabeçalho (.h) do projeto.
- **build/**: Diretório onde os executáveis serão gerados após a compilação.
- **Makefile**: Configurações do Makefile para compilar o projeto.

Os arquivos dentro de `include` e `src` devem ser separados em subpastas com a descrição da feature como:
`src/objetos`

## Compilação

Certifique-se de que tenha o mingw32-make instalado no ambiente de trabalho.

1. Abra o terminal na raiz do projeto.
2. Execute o comando:
  ```sh
  mingw32-make
  ```

O executável e os arquivos objetos (.o) serão gerados na pasta `build/`. 

**Alternativamente** pode se compilar o projeto manualmente com o comando:
  ```bash
  g++ src/*.c -o build/restaurante
  ```

## Execução

Após a compilação, você pode executar o programa principal com o seguinte comando:

```sh
./build/restaurante.exe
```

## Limpeza

Para limpar os arquivos gerados pela compilação, execute:

```sh
make clean
```

## Contribuição

1. Crie uma branch para sua feature (`git checkout -b nova-feature`).
2. Commit suas mudanças (`git commit -m 'Adicionei uma nova feature'`).
3. Faça push para a branch (`git push origin nova-feature`).
4. Abra um Pull Request.

