## Atividade Lista Sequencial com alocacao dinamica
Se a lista encher, o tamanho alocado e dobrado.
Se a lista estiver usando apenas 25% da sua capacidade, o tamanho e reduzido pela metade, com um minimo de 50 espacos.

### Mudancas no codigo
* Alterei a forma como o array e acessado na estrutura, agora, o array e referenciado por um ponteiro que guarda o endereco do primeiro elemento
* Adicionei um novo membro na estrutura da lista que guarda o tamanho alocado do array
* Criei duas funcoes responsaveis por aumentar e diminuir o tamanho do array quando necessario
* Modifiquei as funcoes de adicionar e remover itens para checar as condicoes descritas no inicio e executar as funcoes de aumento e reducao do array
* Tambem modifiquei o funcionamento da funcao de tamanhoEmBytes, que agora retorna todo o valor alocado em bytes
