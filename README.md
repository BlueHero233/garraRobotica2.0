## garraRobotica2.0
## Garra robótica controlada por controle de ps2 
A função desse repositorio serve como documentação detalhada do prototipo de garra robotica, para o acompanhamento e familiarização do grbl, como funcionam motores de passo, seus respectivos drivers, como esse codigo é escrito em arduino e como receber o input de um controle de ps2 para movimentar o braço

O braço é uma adaptação feita por *Jacky Le* originalmente por *daGHIZmo* no Thingiverse, que é baseado no braço articulado ABB IRB460
![ABB IRB460](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/de3d02c1-07e0-49a4-be0a-f1199ee107cb)

As alteraçoes incluem a substituição de servo motores MG995 por motores de passo NEMA 17 (42HS40), alem da adaptação da base para servir como eixo e o controle dos motores por um shield CNC V3 e drivers A4988
![Driver](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/fade96de-fefd-489c-bbb5-cf98203a58ac)

O codigo fonte funciona com a biblioteca grbl, um firmware universal open source para controle de eixos de cnc, impressoras 3d e braços articulados
O problema é que tanto a montagem, a lista de materiais e a operação do codigo é parcamente documentada, por isso estarei compilando e atulizando todas as informaçãoes possiveis neste repositorio ao decorrer do porjeto

### Lista de Materiais
- 1 Micro servo 9g SG90
- 3 Motores de passo NEMA 17 42HS40
- 1 Arduino Uno R3 (Mega?)
- 1 Shield CNC V3
- 1 Fonte 12V 3A DC
- 3 Drivers de motor de passo A4988
- 1 Controle para PS2 Sem Fio 2.4GHz
- 1 Parafuso Pan Head M6x25mm
- 1 Parafuso Pan Head M4x40mm
- 1 Parafuso Pan Head M4x30mm
- 5 Parafusos Pan Head M4x20mm
- 1 Haste Rosqueada M4x60mm
- 1 Haste Rosqueada M4x32mm
- 14 Parafusos Pan Head M3x20mm
- 1 Porca Sextavada Nylon M6
- 2 Porcas Sextavadas Nylon M3
- 9 Porcas Sextavadas Nylon M4
- 10 Esferas INOX 6mm
- 1 Rolamento 606zz
- 18 Ruelas lisas M4
- *3 limit switches

### Partes Imprimidas
As partes imprimidas estao inclusas no arquivo compactado *Partes*
Estao sendo imprimidas com 0.4mm Altura de Camada, 0.4mm Largura de Extrusão, 4 Paredes, 30% Preenchimento Cubico, 5 Camadas superior/inferior, Temperatura de Impressao 215°C, Material PLA, Velocidade 50mm/s
*É recomendado a opcao de Correções de malha "Maximum Travel Resolution 0.4 - 0.05" , 1.2mm Espessura camada superior/inferior, Direcao de linha Superior Inferior [0,90], Largura da Superficie Superior 0,12 e Quantidade de camadas 1*

### Limit Switches
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/657a3e3d-4c27-44f8-a140-e66b20c6d094)
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/fa8bcd61-e897-4dca-845d-7b8687408236)
![image](https://github.com/BlueHero233/garraRobotica2.0/assets/87818077/e15ffbc7-5ce9-410b-9724-3fcfbb4a5db3)

https://www.arduinoecia.com.br/driver-a4988-com-motor-de-passo-nema-17/
https://www.thingiverse.com/thing:1454048
http://www.eezyrobots.it/eba_mk2.html

https://www.youtube.com/watch?v=vRAaXrJJf6s
https://www.youtube.com/watch?v=P-hHQdp5Nng
https://www.youtube.com/watch?v=m-svr2s2QuY
https://www.youtube.com/watch?v=nsYRspG4WIY
https://www.youtube.com/watch?v=r4XTLiIXxPY
