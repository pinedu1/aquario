Controle de Aquário

Este projeto destina-se a controlar eletronicamente meu aquário.

A idéia e com uso do arduino, permitir:
a) Controlar as luzes
a.1) Acendendo as luzes automaticamente pela manhã, e na progressão do dia apagando progressivamente, utilizar-se da tabela do amanhecer anual, para simular o foto-período e evitando usar toda a potência das luzes de imediato, dividindo o dia em blocos de incidências de luz.
a.1.α) Amanhecer
a.1.β) Manhã
a.1.ɣ) Pleno
a.1.δ) Entardecer
a.1.ε) Crepúsculo
a.2) Implementar rotina para simular relâmpago
a.3) Implementar rotina para simular lua cheia, com núvens.
b) Painel LCD para exibição dos dados do aquário como:
b.1) Temperatura
b.2) PH
b.3) Data e Hora
b.4) Status do aquecedor
b.5) Alertas
c) Controle de temperatura
c.1) Com uso de sensor de temperatura a prova dágua, controlar os aquecedores de água
c.2) Como estamos em SBC, não há necessidade de implementar resfriamento de água
d) Controlar Bomba do filtro Canister
