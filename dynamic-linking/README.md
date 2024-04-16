O propósito deste estudo foi entender como as bibliotecas em C são linkadas de forma dinâmica.

Para isso foi criado um programa `main.c` que declara duas funções `add(int, int)` e `sub(int, int)`. Estas funções não são implementadas pelo programa, pois representam funções comuns que são normalmente necessárias a outros executáveis.

A implementação se encontra na pasta `math` onde temos o código que implementa para mós estas funções.

Se tentarmos compilar nosso programa usando `gcc main.c`, seremos interrompidos com um erro nos alertando da ausência da implementação das funções que declaramos.

Antes de usarmos a biblioteca `math`, precisamos a compilar e criar o objeto que será utilizado. Podemos fazer isso com o comando `gcc -fpic -shared math.c -o libmath.so` o formato do arquivo de saída deve te o prefixo `lib` e a extensão `.so` para ser compreendido como biblioteca compartilhada. As flags `-fpic` e `-shared` servem para dizer que o código deve ser idependente de posição e que o arquivo gerado é uma bliblioteca compartilhada, respectivamente.

Agora temos o nosso objeto `libmath.so` e podemos compilar nosso programa e gerar o arquivo objeto. Isso é feito através do comando `gcc -c main.c -o main.o` a flag `-c` diz ao gcc que não queremos executar a etapa de linkagem do programa ainda, já que isso será feito em um passo posterior.

Com o nosso arquivo `main.o` preprocessado, compilado e montado, podemos realizar a linkagem com a nossa bilbioteca e gerar o executável final. Para isso usamos o comando `gcc -o main main.o -lmath -L$(pwd)/math` onde dizemos ao gcc que queremos linkar a biblioteca `math` através da flag `-lmath` (observe que não incluimos o `lib` e nem o `.so`), também precisamos dizer ao gcc onde encontrar a nossa biblioteca `-L$(pwd)/math` onde `$(pwd)` consiste na pasta atual e `/math` é a pasta da nossa biblitoeca.

Por fim temos como resultado nosso executável `./main`. Mas calma aí, se tentarmos executar vamos ter um erro, pois não especificamos onde essa biblioteca está no momento da execução, para isso podemos setar a variável de ambiente `LD_LIBRARY_PATH` com a pasta onde nosso arquivo `libmath.so` está.

Para executar então, executamos `LD_LIBRARY_PATH=./math ./main`. E por fim obtemos o resultado da execução:

```text
1+1=2
1-1=0
```

Espero que tenha gostado! :D