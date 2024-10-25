# Mineração de Dados em Transporte Público

Este projeto busca formatar e analisar um dataset de fluxo de usuários de transporte público, visando a construção de um conjunto de dados útil para aplicações de aprendizado de máquina focadas em saúde pública. O dataset final apresenta registros históricos de viagens, incluindo informações sobre estações de entrada e saída, horários e dias da semana, extraídas de dados brutos encontrados em repositórios na Web. Esta análise tem como objetivo investigar a probabilidade e o risco de infecção por doenças transmissíveis em ambientes de transporte, considerando o fluxo e a concentração de passageiros em determinadas condições.

## Objetivos

### Objetivo Geral
- Gerar um dataset consistente sobre o fluxo de usuários de transporte público, permitindo a análise do comportamento de uso e a modelagem de risco de infecção.

### Objetivos Específicos
1. Criar um dataset formatado e livre de inconsistências, em formato CSV, a partir de dados brutos.
2. Realizar uma pesquisa bibliográfica sobre técnicas de integração de dados, aprendizado de máquina e modelos de propagação de vírus.
3. Levantar e explorar repositórios de dados brutos sobre transporte público.
4. Desenvolver programas para integração, tratamento e validação dos dados.
5. Realizar experimentos que validem o dataset para as aplicações propostas.

## Metodologia

O trabalho envolveu as seguintes etapas:
1. **Coleta de Dados**: Seleção de dados sobre transporte público de grandes cidades, focando em viagens registradas com informações de estações de entrada e saída, horários e dias.
2. **Filtragem de Dados**: Tratamento para remoção de inconsistências e registros incompletos. Para este projeto, os dados foram filtrados para registros mínimos consistentes relacionados a sistemas de metrô.
3. **Interpolação de Percursos**: Uso de grafos para gerar percursos prováveis entre estações, interpolando horários nas estações intermediárias com base nos horários de entrada e saída.
4. **Geração do Dataset Final**: O dataset final inclui percursos completos, horários interpolados e permite filtros por estação e horários específicos.

## Resultados

A análise resultou em um dataset que pode ser utilizado para modelagem de comportamento de usuários em transporte público e cálculo de risco de infecção. Este dataset permite:
- Análise de concentração de passageiros em intervalos específicos de tempo em estações, o que é essencial para avaliar o risco de contaminação em ambientes fechados.
- Predição de comportamentos de viagem e encontros entre usuários com base nas estações de origem e destino, dia da semana e horário.

## Conclusão e Trabalhos Futuros

O dataset gerado é fundamental para a modelagem de risco de infecção em sistemas de transporte público. Através de técnicas de aprendizado de máquina, este conjunto de dados poderá contribuir para a análise preditiva de risco e a tomada de decisões para intervenções de saúde pública.

**Trabalhos Futuros**:
1. Ajuste do dataset para experimentos de aprendizado de máquina voltados ao cálculo de parâmetros de risco de contaminação.
2. Investigações adicionais em outras cidades, utilizando a mesma metodologia para dados de transporte público ou registros de telefonia móvel.

Para detalhes técnicos e implementações, consulte o [Relatório do Projeto](https://github.com/gabrielborralhogomes/Mineracao-de-dados-de-transporte-publico/blob/main/Relatorio.pdf).
