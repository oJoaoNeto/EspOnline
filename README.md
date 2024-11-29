# Relatório de Aprendizagem: Uso de um FSR para Medição de Força



## Índice

1. [Introdução](#introdução)
2. [Plataformas Utilizadas](#plataformas-utilizadas)
3. [Início](#Inicio)
4. [Montagem do Circuito](#montagem-do-circuito)
5. [Funcionamento do Sensor FSR](#funcionamento-do-sensor-fsr)
6. [Limitações Identificadas](#limitações-identificadas)
7. [Tentativas de Solução](#tentativas-de-solução)
   1. [Calibração](#calibração)
   2. [Uso de Código do Fabricante](#uso-de-código-do-fabricante)
8. [Conclusão](#conclusão)
9. [Referências](#referências)

## Introdução
Este repositório documenta minha experiência de aprendizagem no uso de um **sensor FSR (Force-Sensitive Resistor)** para medir força utilizando um **ESP32**. O objetivo principal foi avaliar se o FSR pode ser empregado para medir força de forma mais detalhada.

## Plataformas Utilizadas

- **Tinkercad**: Inicialmente utilizado para simulação, mas sem suporte ao ESP32.
  
## Inicio
  Iniciei os estudos utilizando o **Tinkercad**, já que não tinha acesso a uma plataforma física no momento. No entanto, enfrentei uma limitação: o ESP32 não está disponível no Tinkercad, o que me levou a usar um **Arduino UNO R3** como alternativa. Também explorei outras plataformas, como **WOWKI**, mas elas não oferecem suporte ao FSR.

## Montagem do Circuito

Para começar, montei o circuito no Arduino UNO utilizando um resistor de **10 Ω**. Posteriormente, adaptei a montagem ao ESP32.



### Exemplo de Montagem no ESP32

Acesse um guia detalhado da montagem no ESP32:  
[Tutorial ESP32 com FSR](https://esp32io.com/tutorials/esp32-force-sensor).

## Funcionamento do Sensor FSR

O sensor FSR não fornece diretamente um valor de força ao controlador. Em vez disso, ele mede a força aplicada por meio da variação de tensão no circuito, gerando valores lógicos entre **0 e 1023**, proporcionais à tensão medida.

## Limitações Identificadas

1. **Precisão**: O sensor não é ideal para medições detalhadas de força, oferecendo apenas valores aproximados baseados na variação de tensão.
2. **Erro de Medição**: Margem de erro inicial de **~1 N**, com dificuldades em ler forças muito pequenas ou muito grandes com precisão.

## Tentativas de Solução

### Calibração

A calibração foi realizada para melhorar a precisão da leitura, reduzindo a margem de erro para **~0,15 N**. No entanto, essa solução não é a mais viável, pois exige recalibração a cada novo uso do sensor.

### Uso de Código do Fabricante

Testei o código fornecido pelo fabricante do FSR, que apesar de melhorar a precisão, ainda apresentava erros:
- Incapacidade de ler valores abaixo de **1 N** (erro corrigido parcialmente).
- Extrapolação de valores, com erros de até **1,5 N** em determinadas medições.

## Conclusão

Embora a calibração tenha melhorado a precisão do sensor FSR, ele ainda apresenta limitações significativas para medições precisas de força. O sensor é mais adequado para aplicações simples, como detectar a pressão aplicada (por exemplo, em sensores para pés), mas não é confiável para medições de força de alta precisão.

## Referências

- [Tutorial ESP32 com FSR](https://esp32io.com/tutorials/esp32-force-sensor)  
- [Stack Overflow: Unidade de Medida do FSR](https://stackoverflow.com/questions/61512292/what-is-the-unit-of-measure-for-the-pressure-data-i-collect-using-an-fsr-sesnor)
