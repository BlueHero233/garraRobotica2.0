## garraRobotica2.0
## Garra robótica controlada por controle de ps2 
A função desse repositorio serve como documentação detalhada do prototipo de garra robotica, como funcionam motores de passo, seus respectivos drivers, como esse codigo é escrito em arduino e como receber o input de um controle de ps2 para movimentar o braço

O braço é uma adaptação feita por *Jacky Le* originalmente por *daGHIZmo* no Thingiverse, que é baseado no braço articulado ABB IRB460
![ABB IRB460](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/de3d02c1-07e0-49a4-be0a-f1199ee107cb)

As alteraçoes incluem a substituição de servo motores MG995 por motores de passo NEMA 17 (42HS40), alem da adaptação da base para servir como eixo e o controle dos motores por um shield CNC V3 e drivers A4988, no nosso caso, nao podemos utilizar o shield pela limitacao de pinos utilizaveis, um breadboard pequeno será utilizado em troca
![Driver](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/fade96de-fefd-489c-bbb5-cf98203a58ac)

O codigo fonte funciona com a biblioteca AccelStepper, que vai controlar a direcao de cada braço dado o movimento analogico dos joysticks do controle.
E a biblioteca PsxNewLib, talque a p2slib master do Bill Porter nao funcionou em dois controles diferentes é esta deprecada a anos
O problema é que tanto a montagem, a lista de materiais e a operação do codigo é parcamente documentada, por isso estarei compilando e atulizando todas as informaçãoes possiveis neste repositorio ao decorrer do porjeto

### Lista de Materiais
- 1 Micro servo 9g SG90
- 3 Motores de passo NEMA 17 42HS40
- 1 Arduino Uno R3
- 1 Protoboard 400 Pontos
- 1 Fonte 12V 3A DC
- 3 Drivers de motor de passo A4988
- 1 Controle para PS2 Sem Fio 2.4GHz
- 1 Parafuso Maquina M6x25mm
- 1 Parafuso Maquina M3x30mm
- 1 Parafuso Maquina M3x25mm
- 6 Parafusos Maquina M3x20mm
- 1 Parafuso Maquina 1/8x2pol
- 1 Parafuso Maquina 1/8x1 1/2pol
- 2 Parafusos Allen M3x40mm
- 1 Parafuso M2,5x12mm
- 1 Porca Sextavada M2,5
- 10 Porcas Sextavadas M3
- 1 Porca Sextavada Travante M6
- 10 Esferas INOX 6mm
- *1 Rolamento 606zz
- 21 Ruelas lisas M3
- 3 limit switches
- 
### Partes Imprimidas
As partes imprimidas estao inclusas no arquivo compactado *Partes*
Estao sendo imprimidas com 0.4mm Altura de Camada, 0.4mm Largura de Extrusão, 4 Paredes, 30% Preenchimento Cubico, 5 Camadas superior/inferior, Temperatura de Impressao 215°C, Material PLA, Velocidade 50mm/s
*É recomendado a opcao de Correções de malha "Maximum Travel Resolution 0.4 - 0.05" , 1.2mm Espessura camada superior/inferior, Direcao de linha Superior Inferior [0,90], Largura da Superficie Superior 0,12 e Quantidade de camadas 1*

### Limit Switches
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/657a3e3d-4c27-44f8-a140-e66b20c6d094)
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/fa8bcd61-e897-4dca-845d-7b8687408236)
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/e15ffbc7-5ce9-410b-9724-3fcfbb4a5db3)

### Controle PS2
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/b3732631-9a10-4f62-85f7-056e1779e9f9)
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/06726c2c-2e81-4f99-a468-65765b527c02)

### A4988
**ATENCAO** Os drivers a4988 possuem um potenciometro, que deve ser manualmente ajustado para limitar a corrente que sera enviada para o motor, ela pode ser lida com um multimetro, negativo no GND e positivo no potenciometro, a leitura deve ser em volts e igual a Imax * 8 * Rcs
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/cfe7fdf1-a19e-4ab4-ae43-654d263139ce)

Imax é a corrente maxima do respectivo motor e Rcs é a resistencia interna do proprio driver 
![driver-motor-passo-a4988-3](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/e63104f2-378e-4e6a-bdc8-badcfe2ef021)

https://www.arduinoecia.com.br/driver-a4988-com-motor-de-passo-nema-17/
https://www.thingiverse.com/thing:1454048
http://www.eezyrobots.it/eba_mk2.html
https://github.com/SukkoPera/PsxNewLib

https://www.youtube.com/watch?v=vRAaXrJJf6s
https://www.youtube.com/watch?v=P-hHQdp5Nng
https://www.youtube.com/watch?v=m-svr2s2QuY
https://www.youtube.com/watch?v=nsYRspG4WIY
https://www.youtube.com/watch?v=r4XTLiIXxPY
