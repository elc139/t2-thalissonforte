Programação Paralela Multithread
======================================
<div align="right"> Programação Paralela - ELC139</div>

Nome: <b>Thalisson Forte</b><br>


PThreads
-----------------------------
1. *Explique como se encontram implementadas as 4 etapas de projeto: particionamento, comunicação, aglomeração, mapeamento:*
    - asdasds ads asd asd asd as

2. *Considerando o tempo (em microssegundos) mostrado na saída do programa, qual foi a aceleração (speedup) com o uso de threads?*
    - O teste foi feito variando a quantidade de threads e adaptando o tamanho do teste para padronizar o resultado e realizar a comparação (resultados no arquivo [results.csv](https://github.com/elc139/t2-thalissonforte/blob/master/results.csv)).<br><br>
      - Primeiro teste:<br>
      <p>1 thread / 2 threads = 14090460 / 7846754 = 1.7957
      <p>1 thread / 4 threads = 14090460 / 6943146 = 2.0294
      <p>1 thread / 8 threads = 14090460 / 6623463 = 2.1273
       
       - Segundo teste:<br>
      <p>1 thread / 2 threads = 28716697 / 15919209 = 1.8039
      <p>1 thread / 4 threads = 28716697 / 13139057 = 2.1856
      <p>1 thread / 8 threads = 28716697 / 12968190 = 2.2144
    
3. *A aceleração se sustenta para outros tamanhos de vetores, números de threads e repetições?*
    - A aceleração teve uma leve diferença com o crescimento da quantidade de repetições mas se manteve com valores bem próximos aos encontrados nos primeiros testes
    
      - Terceiro teste:<br>
      <p>1 thread / 2 threads = 56116618 / 30437132 = 1.8436
      <p>1 thread / 4 threads = 56116618 / 25509057 = 2.1998
      <p>1 thread / 8 threads = 56116618 / 25268175 = 2.2208

4. *Elabore um gráfico/tabela de aceleração a partir dos dados obtidos no exercício anterior.*
  - No eixo X o número de threads e no eixo Y a aceleração respectiva com base no tempo de apenas 1 thread
    <div align="center"><img src="https://raw.githubusercontent.com/elc139/t2-thalissonforte/master/TabelaDados.png"></div>

5. Explique as diferenças entre pthreads_dotprod.c e pthreads_dotprod2.c. Com as linhas removidas, o programa está correto?
    - O código apresentado em `pthreads_dotprod.c` possui a técnica de exclusão mútua sobre a variável `dotdata.c` já que ambas as threads podem realizar operações sobre aquela área de forma simultanea, podendo incorrer em erro. Porém, ainda assim, o código apresentado em `threads_dotprod2.c` segue sendo válido já que essa mesma variável não é utilizada para outros fins a não ser de exibição no final de toda a execução. E também, o incremento feito nessa variável não depende da ordem das threads para ser contabilizada, o que mantém o código correto.


OpenMP
-----------------------------

A partir do programa `pthreads_dotprod.c` foi desenvolvido o programa `omp_dotprod.c`. Os respectivos tempos de execução se encontram no arquivo [results.csv](https://github.com/elc139/t2-thalissonforte/blob/master/results.csv). Abaixo a relação de aceleração entre 1 e mais threads:<br><br>

- Primeiro teste:<br>
      <p>1 thread / 2 threads = 17230187 / 9352278 = 1.8423
      <p>1 thread / 4 threads = 17230187 / 9091313 = 1.8952
      <p>1 thread / 8 threads = 17230187 / 9170108 = 1.8789
       
- Segundo teste:<br>
      <p>1 thread / 2 threads = 40176823 / 20129256 = 1.9959
      <p>1 thread / 4 threads = 40176823 / 18717602 = 2.1464
      <p>1 thread / 8 threads = 40176823 / 19268960 = 2.0850

- Terceiro teste:<br>
      <p>1 thread / 2 threads = 69891939 / 37811266 = 1.8484
      <p>1 thread / 4 threads = 69891939 / 36691284 = 1.9048
      <p>1 thread / 8 threads = 69891939 / 36890741 = 1.8945


### Referências
- Acer. Datasheet. https://www.acer.com/datasheets/2015/4876/E5-573G/NX.G5RAL.005.html.
- Top500. DGX SuperPOD. https://www.top500.org/system/179691.
- Intel. Processador Intel Core i5 5200U. https://ark.intel.com/content/www/br/pt/ark/products/85212/intel-core-i5-5200u-processor-3m-cache-up-to-2-70-ghz.html.
- LO4D. Linpack LinX. https://linx.en.lo4d.com/windows.
