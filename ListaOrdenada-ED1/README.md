## Atividade Lista Sequencial com alocação dinâmica
Se a lista encher, o tamanho alocado é dobrado.
Se a lista estiver usando apenas 25% da sua capacidade, o tamanho é reduzido pela metade, com um mínimo de 50 espaços.

### Mudanças no código
* Alterei a forma como o array é acessado na estrutura. Agora, o array é referenciado por um ponteiro que guarda o endereço do primeiro elemento.
* Adicionei um novo membro na estrutura da lista que guarda o tamanho alocado do array.
* Criei duas funções responsáveis por aumentar e diminuir o tamanho do array quando necessário.
* Modifiquei as funções de adicionar e remover itens para checar as condições descritas no início e executar as funções de aumento e redução do array.
* Também modifiquei o funcionamento da função de tamanhoEmBytes, que agora retorna todo o valor alocado em bytes.
