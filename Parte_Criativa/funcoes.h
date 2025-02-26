#include "estruturas.h"
#ifndef FUNCOES_H
#define FUNCOES_H

// Início das funções 

void leString(char string[], int tamanho);

void criarPokemon(Pokemon pokemonNaDex, pokemonCapturado* pselvagem, int lvl, nature natures[25]);

void capturarPokemon(Pokebola pokeball[4], int* resultado, Pokemon pokemonNaDex, pokemonCapturado pselvagem, int qualpokebola);

void adicionarPokemonNaColecao(Colecao** colecaoDePokemons, int* totalPokesNaColecao, int numeroDePokemons, Pokemon* listaPokemon);

void listaPokemonsNaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon, int numeroDePokemons);

void pesquisaPorPokemonNaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon);

void alterarPokemonDaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon);

void excluirPokemonDaColecao(Colecao** colecaoDePokemons, int* totalPokesNaColecao);

void adicionarPokemonNaPokedex(Pokemon* listaPokemon, int* numeroDePokemons);

void excluirPokemonDaPokedex(Pokemon* listaPokemon, int* numeroDePokemons);

void listarPokemonsDaPokedex(Pokemon* listaPokemon, int numeroDePokemons);

void pesquisaPokemonNaPokedex(Pokemon* listaPokemon, int numeroDePokemons);

void alteraPokemonNaPokedex(Pokemon* listaPokemon, int numeroDePokemons);

void exportarPokemonParaCSV(Pokemon pokemon[], int tamanho, const char *nomeArquivo);

void exportarColecaoParaCSV(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon, const char *nomeArquivo);

void exportarMochilaParaCSV(Mochila* mochila, Pokemon* listaPokemon, int totalMochila, const char *nomeArquivo);

void tirarColecaoInserirMochila(int j, Colecao* colecaoDePokemons, int *totalPokeColecao);

void InserirNaMochila(Mochila* mochila, Colecao* colecaoDePokemons, int* totalPokesNaColecao, Pokemon* listaPokemon, int totalPokemons, int* totalMochila, pokemonCapturado pokemonASerInserido);

void ListaMochila(Mochila* mochila, Pokemon* listaPokemon, int TotalPokemons);

void ExcluirMochila(Mochila* mochila, Colecao* colecaoDePokemons, int* totalPokesNaColecao, int* totalMochila, Pokemon* listaPokemon, int totalPokemons);

void vetorDeNatures(nature natures[25]);

void vetorDePokebolas(Pokebola pokebolas[4]);

#endif
