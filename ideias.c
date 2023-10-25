/*
Primeiramente, dupliquem o DataFelipe.C e coloquem DataJao.c e DataCaio.c para mexer, pra evitar que um sobresaia o outro ou dê algum erro

1) Definir o sistema de nível de Treinador
A gente definiu que o jogador vai ter um nivel, e é esse nivel que vai desbloquar areas mais avançadas para ele explorar
Então primeiro de tudo tem que fazer um comando/sistema para criar um treinador quando começar o jogo
> Definir o nome
> Genero
> E nivel 1
Para ganhar xp vai da imaginação de quem for fazer essa parte, pode fazer que ganha um valor X de experiencia ao derrotar pokemons e treinadores, onde x é definido por uma formula
Lembrando também da ideia que a gente teve da universidade com quiz e outras coisas pra ganhar esse xp!
Cuidado com o sistema de balanceamento, podem ver o código do jogo do muriel como ele define a velocidade do personagem com base no nivel

2) Economia
Quem for fazer essa parte vai precisar criar uma Pokemoeda e colocar ela no struct do Jogador
E ai é criar métodos de como ganhar (derrotar treinadores, aventuras, história, jogos, etc)
A moeda vai ser essencial para comprar frutas e pokebolas

3) Pokedoca e Pokecentro (Ou outro nome top tbm)
A Pokédoca vai ser a loja onde o jogador vai poder comprar as pokébolas, frutas e outros itens a se pensar
Cada área/cidade vai ter itens diferente, quanto maior o nivel do treinador e mais avançada a cidade, maior quantidade de itens
Por exemplo, na primeira cidade não faz sentido o jogador ter acesso a outras pokébolas além da mais comumzona, e depois ganhando acesso a comprar as outras que serão mais caras
O Pokecentro vai ser uma área onde você pode curar seus pokemons pra vida maxima e acessar o sistema de coleção

4) Frutas / Suplementos
Nessa parte seria preciso criar as frutas, quais vão dar pra plantar, quais não vão, o que cada uma faz (cura pokemon, boost de atack e etc)
Deve ser definido como conseguir
Também tem os suplementos, no arquivo de texto com as ideias a gente falou de uma academia para upar as EVs (explicado no meu código),
mas pode ser fruta também

5) Sistema de coleção e mochila
O jogador só pode carregar 6 pokemons, o resto, ficará em um sistema de coleção que poderá ser acessado em algum lugar (provavelmente o pokecentro)
Esse sistema deverá armazenar o pokemon, bem como seu nivel e tudo que ele for
A mochila vai ser o que vai carregar os 6 pokemons pra lá e pra ca, onde você pode interagir em qualquer lugar

6) Música
Vai precisar de música se for jogar o jogo no linux, o bom é que da pra fazer pelo virtual machine e ai é criatividade e ajuda do chatgpt talvez?

7) Ideias que precisam de conteudo da sala:
Ao sair do programa, todos os dados devem ser salvos em arquivos binários no HD e recarregados novamente ao iniciar. Caso os arquivos não existam, eles devem ser 
criados e uma mensagem de boas vindas deve ser apresentada ao usuário;
O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por vírgula);
//// Texto copiado e colado do arquivo do muriel, pra fazer essas duas coisas ai é vendo as proximas aulas

8) Raylib
Raylib vai ser preciso para o menu, botoes e etc, é essencial pra ver a progressão do jogo e seria legar começar por ele

Por enquanto penso nisso, sei que algumas coisas podem parecer chatas, mas temos que lembrar que é um trabalho de faculdade, não iria ser 100% legal e facil de se fazer
bora pra cima!


Obs: Como salvar código no github
-> Seleciona no github na esquerda 1 linha de cada vez e commit to main
-> Depois, la em cima, push to origin
pronto



Anotações:
https://github.com/veekun/pokedex/blob/master/pokedex/data/csv/pokemon_species.csv
Obter: Id, numero para qual pokemon evolui e ?
Definir numero base para evolução 1 e 2 
*/

