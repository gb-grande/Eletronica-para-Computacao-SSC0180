# FonteEletronica
Este trabalho, referente à disciplina Eletrônica para Computação(ICMC-USP), consiste no projeto e montagem de uma fonte de tensão ajustável entre 3V a 12V com capacidade de 100mA.

Adotou-se como parametros da entrada: Corrente alternada com 127V de tensao e 60Hz de frequencia.

| Apresentação da Fonte | Cálculo do Ripple |
| --- | --- |
| <video src="https://user-images.githubusercontent.com/24720405/178084118-f01fbc68-67f3-4e2c-8ba8-4f21347edacc.mp4" style="max-width: 730px;"></video> | <video src="https://user-images.githubusercontent.com/24720405/178084461-28b8bc12-fb25-4542-be41-ac9ad6f14883.mp4" style="max-width: 730px;"></video> |

| Componente | Preço |
| --- | --- |
| Transformador | R$28,99 |
| Diodo 1n4007 x4 | R$0,20 * 4 = R$0,80 |
| Capacitor 680uF 25v | R$5,78 |
| Resistor 1kΩ | R$0,07 |
| Resistor 750Ω | R$0,07 |
| Resistor 2k2Ω | R$0,07 |
| Potenciômetro Linear 5kΩ | R$7,00 |
| Diodo Zener 13v | R$0,48 |
| transistor NPN BC337-40 | R$0,69 |
| LED | R$0,50 |
| ***TOTAL*** | ***R$44,45*** |

## Ficha Tecnica
### Transformador: 
Componente elétrico responsável por trasformar a tensão elétrica de entrada em valores mais adequados para uma determinada aplicação, utilizando-se de bobinas e dos princípios eletromagnéticos da Lei de Faraday-Lenz. No projeto, optou-se por um transformador comercial capaz de modificar uma entrada de 127V para aproximadamente 24v.
### Diodos:
Componentes eletricos com a caracteristica de selecionar um sentido unico para a passagem de corrente eletrica. No projeto, sao utilizados na construcao de uma ponte de diodos, dispositivo retificador de tensao por possibilitar o aproveitamento de ambos os ciclos da corrente alternada de origem.
### Resistores:
Componentes eletricos dotados de valores fixos de resistencia responsáveis por garantir a manutencao da corrente no circuito em valores adequados para o funcionamento adequado de cada um dos componentes presentes no circuito.
### Capacitor:
Componente elétrico capaz de armazenar pequenas quantidades de cargas elétricas, fornecendo corrente continua caso a tensão interna encontre-se superior à externa. Para obter um ripple inferior a 10%, seria necessário um capacitor de pelo menos 370uF (explicação no vídeo). No projeto, usamos um de 680uF.
### Potenciômetro:
Componente elétrico dotado de resistência variável, ou seja, capaz de regular a passagem de corrente e consequentemente modificar os valores de tensao do circuito. No projeto, foi utilizado para possibilitar a selecao dos valores de tensao entre 3V a 12V,  conforme descrito nas especificacoes.
### Diodo Zener:
Variacao do diodo tradicional caracterizado por permitir corrente eletrica somente sob a influencia de tensao superior a sua tensao de trabalho especificada pelo fabricante, limitando assim a voltagem maxima permitida pelo circuito. No projeto, foi utilizado para garantir valores de tensao maxima inferiores a 13V, com um espaço para erros do máximo de 12V.
### Transistor:
Componente elétrico capaz de trocar ou amplificar sinais e potencia eletrica. No projeto, foi utilizado na regulagem da corrente eletrica no circuito, para evitar desperdício de corrente no Diodo Zener.

## Funcionamento:
### Transformacao:
Nesta etapa, os sinais eletricos da entrada(corrente alternada com 127V de tensao e 60Hz de frequencia) tem sua DDP reduzida pelo transformador para valores proximos a 24V, sendo mantidas as demais caracteristicas de onda.
### Retificacao:
Nesta etapa, os sinais eletricos em corrente alternada(provenientes da etapa de transformacao) sao retificados para um sinal contiuamente positivo pela acao da ponte de diodos. Nesta estrutura, a disposicao geometrica dos diodos no circuito ora permite ora bloqueia a passagem de corrente eletrica, de modo a definir, durante ambos os ciclos da onda, um sentido unico para o fluxo de eletrons. O resultado do procedimento e uma reflexao completa dos valores negativos de tensao em relacao ao eixo das abcissas.
### Filtragem: 
Nesta etapa, os sinais eletricos arredondados pela caracteristica senoidal dos valores de entrada sao aproximados para valores continuos pela acao do capacitor eletrolitico. Tal estrutura, apos ser carregada brevemente durante os periodos de voltagem maxima, supre com libercao de corrente eletrica os momentos de diminuicao na voltagem de entrada, de modo a simular uma saida de tensao continua, sendo suas imperfeicoes parametrizadas pelo ripple.
### Regulagem:
Nesta etapa, os sinais eletricos ja trabalhados pelas etapas anteriores sao submentidos a uma maior establizacao e linearizacao em funcao da acao complementar entre o diodo Zener e o transistor, de modo que a saida do sistema configure uma tensao fixa e constante, a despeito de ligeiras imperfeicoes de processos anteriores ou mesmo da presenca de ruido por flutuacoes de corrente e temperatura. Finalmente, ativa-se o potenciometro para regular o valor de saida entre os especificados 3V e 12V.

[Circuito no Falstad](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcA2aAOMB2ALGXyEw1sESQFJyRsBmcgUwFowwAoAN3DACYVKXe3NGijgQyfmkrSo0BKwDuXXmAngAnCrWRFykEJFhN+4VFYAVDYNMG+o7LKJpkmTSSE1ITkd2jdsQghoNDg4kOrqIoyYsLhB6gg0NMhoFAgITHiyEeqsACYgNAhalNhw+pA+4AByZZDY+YXF+gjI1OXclfo1dQ0Fng6dIkUl3WC1cH2F9RXDzdytYxP1uraqlCN2Okp1s9RSe9tNgoubtkdnNlciFzND0w6bt4-N2AdPrABO5NiDmLykF68SjcTo6ADG+xBXTeG2a0lgcBcORRqIihV8qgSQk6YHCSBgcDYOwO90Bh10sOOPyBZiU5PuEh8XR0NAcAC96AA7eifZh0fjQTB4EYYTQYeDcJiYUQqAWsdniLo0TpKnw2ECcnl8sA0XRMjGUA0fJTG5rkj6qAG-PYM-7dPL0ABmAEMAK4AGwALowPfQChAZIS2N8DYyugs2pRMBRWABzKHUqn4URHMNdTDECmmiOLFwnKOsL0gGMFktZyOiCDMdR+SCgoiQZBEIoIdSyYXYBL-DA8TSYZAOPGUR2uz1er7ie2bfOG2XwfXT5pm4H664l+aLNO5tph0w6LAOWeV2cq-jkeCyRAgABK9AAzgBLe9el1c8H0XSZwYZitlOnln8vDfg8ZjfCBAyAdS-CdF+WYzkuq4APZNOIjztOiqowMC4CsEAA)
![Circuito](https://user-images.githubusercontent.com/24720405/177338743-613116f9-f731-4138-b668-0798a2461214.png)
Esquemático no EAGLE
![Esquemático no EAGLE](https://i.imgur.com/f2UnJjM.png)
Board no EAGLE
![Board no EAGLE](https://i.imgur.com/IOnTe4q.png)



