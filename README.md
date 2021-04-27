# fila
Projeto acadêmico do 2º semestre: Simulação de Filas

    Objetivo:
O objetivo deste projeto é implementar um programa de simulação de filas e comparar os números obtidos nessa simulação. O programa deve conter um projeto básico obrigatório e outras funcionalidades opcionais, num total de até 10 pontos.

    Projeto Básico(5,0 pontos)
Implementar um programa que simule
-n ( 1 servidores atendendo n filas, sendo um servidor por fila
O valor n pode ser fixado a priori. A taxa de chegada dos clientes na fila e o tempo de atendimento dos servidores poderão ser configurados Ao final da simulação, deve ser apresentado um relatório com as informações sobre tempo de espera de clientes e tamanho das filas, além de outros dados que o grupo considerar relevantes

    Opcional 1
Permitir que o usuário especifique o número de servidores ( entre 1 e 100 ) 

    Opcional 2
Implementar uma interface simples na qual se consiga ver, em tempo real, o tempo atual da simulação, a fila com cada cliente, o tempo de entrada de cada cliente na fila e o tempo de cada cliente dentro da fila. Os grupos que decidirem por este opcional podem limitar o número máximo de clientes na fila ou de atendentes para facilitar o projeto da interface.

    Opcional 3
Implementar dois grupos de filas um deles com uma fila atendida por vários servidores, e o outro grupo com um servidor por fila.

    Opcional 4
Permitir que o usuário especifique um tempo de atendimento diferente para cada atendente. Diferentes atendentes podem ter tempos de atendimento diferentes, indicando que alguns são mais ágeis que outros ou que estão associados a filas cujos serviços demandam menos tempo.

    Opcional 5
Permitir que o usuário indique a entrada na fila de um cliente especial (por exemplo, idoso ou gestante) que deve ser atendido diretamente pelo próximo servidor livre, ou em uma fila especial. Esse cliente poderá ser inserido aleatoriamente ou através do teclado

    Opcional 6
Permitir que novos servidores sejam inseridos e/ou removidos durante a execução do sistema. No caso de remoção, os clientes que estiverem na fila deverão ser remanejados para outras filas

    Opcional 7
A chegada de clientes nas filas e o tempo de atendimento dos servidores não terão tempo fixo. Elas deverão adotar distribuição de Poison ou Normal (Gaussiana)

    Opcional 8
A execução do sistema poderá ser acelerada. Assim, em um tempo curto (3 segundos, por exemplo), seria possível conhecer a performance do sistema (tempos de espera, etc) caso fosse operado por várias horas
