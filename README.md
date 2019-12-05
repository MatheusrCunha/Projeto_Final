### PROJETO_FINAL: ORDENAÇÃO COUNTING SORT

### Alunos:Matheus Rodrigues e Clóvis Kuhn

### Disciplina:Programação de Computadores 2

### Curso:Engenharia Eletrônica

### INSTITUTO FEDERAL DE SANTA CATARINA (Câmpus Florianópolis)


>### Objetivos do Projeto:
* Realizar a ordenação de dados.
* Calcular o tempo de cada ordenação.
* Escolher um arquivo .csv para efetuar a ordenação.

>### Desenvolvimento:

<p>  A ordenação por contagem inicialmente utiliza um vetor de inteiros, que estão em um intervalo de 1 a k, sendo k o maior elemento desse vetor. O objetivo da ordenação por contagem é determinar todos os numeros menores que k, e então colocar esse valor k na sua posição no vetor de saída.
    Para efetuar a ordenação por contagem e necessário seguir alguma regras impostas pelo algoritmo, o vetor original deve possuir somente elementos inteiros não negativos.
</>

![Representação do Algortmo](http://www.dsc.ufcg.edu.br/~abrantes/CursosAnteriores/ATAL2002/ATAL02_arquivos/Aula6/img46.png)
<p> A análise desse algortimo segue da seguinte forma, no primeito laço e no segundo laço o tempo de ordenação é dado por O(K), já o terceiro leva O(n), no fim o ultomo laço leva O(n).<br/>
No fim todo algoritmo possui um tempo de ordenação de O(n).
    Um ponto positivo dessa ordenação é ela ser estável, pois os elementos do vetor de entrada aparecem na mesma ordem no vetor de saída.
</br>
    
### Referências:

<[1]:http://www.dsc.ufcg.edu.br/~abrantes/CursosAnteriores/ATAL2002/ATAL02_arquivos/Aula6/>
<[2]:https://www.markdownguide.org/basic-syntax/><br/>
<[3]:https://www.kaggle.com/romainpessia/artificial-lunar-rocky-landscape-dataset#bounding_boxes.csv><br/>
<[4]:CORMEM, Thomas H.. ALGORITMOS TEORIA E PRÁTICA. 2. ed. Sao Paulo: EstÚdio Castellani, 2002. 934p.>
