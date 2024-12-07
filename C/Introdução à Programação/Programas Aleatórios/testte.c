#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Constantes presentes
#define SUCESSO 0
#define ERRO 1
#define Tamanho_Maximo 100
#define NUM_MAX_CARACTERES_NOME_USUARIO (99 + 1)
#define NUM_MAX_CARACTERES_EMAIL (50 + 1)
#define NUM_MAX_CARACTERES_SENHA (50 + 1)
#define NUM_MAX_CARACTERES_ID (50 + 1)
#define MAX_IMAGENS (1000)
#define NUM_MAX_CARACTERES_LEGENDA (299 + 1)
#define NUM_MAX_CARACTERES_COMENTARIO (299 + 1)
// Tamanho do buffer para cada linha da imagem
#define BUFFER_TAMANHO 50000

// Tamanho máximo da linha de comando
#define LINHA_COMANDO 10000

// Limiar inferior que considera o download com sucesso
#define LIMIAR_INFERIOR_TAMANHO_IMAGEM 500

// Nome do executável da ferramenta de download e conversão da imagem
#ifdef __unix__
#define FERRAMENTA_IMAGEM "./ascii-image-converter.bin"
#else
#define FERRAMENTA_IMAGEM "ascii-image-converter.exe"
#endif

// Nome do arquivo de saída temporário da imagem
#define ARQUIVO_IMAGEM_TMP "ascii_art.txt"
// Falha ao carregar a imagem fornecida
#define ERRO_CARREGAR_IMAGEM 1

/* Constantes */

// Número de colunas da imagem
#define IMAGEM_NUMERO_COLUNAS 120

// Definição de imagem colorida
#define IMAGEM_COLORIDA true
// Definição de imagem preto/branco
#define IMAGEM_PRETO_BRANCO false
// Definição de imagem utilizada
#define MODO_IMAGEM IMAGEM_COLORIDA
// Define o tamanho máximo para a imagem
#define NUM_MAX_IMAGEM (999 + 1)
// Define o erro
#define USUARIO_INVALIDO -1

/**
 *  \brief Função principal.
 *
 *  \param [in] argc Número de argumentos.
 *  \param [in] argv Valores dos argumentos.
 *  \return Código de erro indicando o que aconteceu com o programa.
 */
/**
 *  \brief Função que carrega uma imagem informada na URL.
 *
 *  \param [in] colorido Define se a imagem será colorida.
 *  \param [in] largura Define a largura da imagem gerada.
 *  \return Endereço da estrutura com a imagem.
 *          Caso a imagem não tenha sido carregada corretamente, a função
 *          retornará NULL.
 */

/// Estrutura que representa uma imagem em Ascii
struct asciiImg_s
{
    uint8_t *bytes;
    int nBytes;
};
/// Tipo "Imagem ASCII"
typedef struct asciiImg_s asciiImg_t;
// Estrutura para o perfil
typedef struct perfil_s
{
    char ID[NUM_MAX_CARACTERES_ID];
    char nome_usuario[NUM_MAX_CARACTERES_NOME_USUARIO];
    char email[NUM_MAX_CARACTERES_EMAIL];
    char senha[NUM_MAX_CARACTERES_SENHA];
    char senha_confirmada[NUM_MAX_CARACTERES_SENHA];
    int numeroDePostagens;
} perfil_t;
// Estrutura para login
typedef struct login_s
{
    char ID_login[NUM_MAX_CARACTERES_ID];
    char nome_usuario_login[NUM_MAX_CARACTERES_NOME_USUARIO];
    char email_login[NUM_MAX_CARACTERES_EMAIL];
    char senha_login[NUM_MAX_CARACTERES_SENHA];
} login_t;

// Estrutura para comentarios
typedef struct comentario_s
{
    char id_comentario[NUM_MAX_CARACTERES_ID];
    char perfil_que_comentou[NUM_MAX_CARACTERES_ID];
    char mensagem[NUM_MAX_CARACTERES_COMENTARIO];
} comentario_t;

// Estrutura para curtidas
typedef struct curtida_s
{
    char id_curtida[NUM_MAX_CARACTERES_ID];
    bool curtida;
} curtida_t;

// Estrutura para posts
typedef struct posts_s
{
    char ID_post[NUM_MAX_CARACTERES_ID];
    asciiImg_t **img;
    char url[NUM_MAX_IMAGEM][MAX_IMAGENS];
    char legenda[NUM_MAX_CARACTERES_LEGENDA];
    comentario_t comentario;
    curtida_t curtidas;
    int num_imagens;
} posts_t;
// Estrutura análoga para matriz de ponteiros
typedef struct copia_post_s
{
    posts_t *ponteiro_post;
    int n_posts;

} copia_post_t;
// Função para tirar o '\n' das strings
void util_removeQuebraLinhaFinal(char dados[])
{
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n'))
    {
        dados[tamanho - 1] = '\0';
    }
}
void cadastro(perfil_t ** ponteiro_perfil, int * num_perfis){
    perfil_t perfis;
    printf ("Digite seu nome:\n");
    fgets (perfis.ID, NUM_MAX_CARACTERES_ID, stdin);
    util_removeQuebraLinhaFinal(perfis.ID);
    printf ("Digite seu email:\n");
    fgets (perfis.email, NUM_MAX_CARACTERES_EMAIL, stdin);
    util_removeQuebraLinhaFinal(perfis.email);
    printf ("Digite sua senha:\n");
    fgets (perfis.senha, NUM_MAX_CARACTERES_SENHA, stdin);
    util_removeQuebraLinhaFinal(perfis.senha);

    (*num_perfis)++;
    *ponteiro_perfil = realloc (*ponteiro_perfil,*num_perfis * sizeof (perfil_t));
    (*ponteiro_perfil)[*num_perfis - 1] = perfis;

}
int login(perfil_t * ponteiro_perfil,int num_perfis){
    
}