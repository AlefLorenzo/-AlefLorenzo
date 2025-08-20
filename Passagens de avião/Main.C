#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_AVIOES 4
#define MAX_PASSAGEIROS 20
#define MAX_NOME 50
#define ASSENTOS_POR_AVIAO 44

// Estrutura para armazenar dados do passageiro
typedef struct {
    int id;
    char nome[MAX_NOME];
    int aviao_idx;
    int passagens_compradas;
} Passageiro;

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibir_linha() {
    printf("========================================\n");
}

void exibir_titulo(const char *titulo) {
    printf("\n");
    exibir_linha();
    printf("          %s\n", titulo);
    exibir_linha();
    printf("\n");
}

void exibir_mensagem_sucesso(const char *mensagem) {
    printf("\n");
    exibir_linha();
    printf(" ✓ %s\n", mensagem);
    exibir_linha();
    printf("\n");
}

void exibir_mensagem_erro(const char *mensagem) {
    printf("\n");
    exibir_linha();
    printf(" ✗ %s\n", mensagem);
    exibir_linha();
    printf("\n");
}

// Gerar ID único baseado no timestamp
int gerar_id_unico() {
    static int ultimo_id = 0;
    return ++ultimo_id;
}

// Cadastrar aviões
void cadastrar_aviao(int avioes[], int *total_avioes, int assentos_disponiveis[]) {
    if (*total_avioes >= MAX_AVIOES) {
        exibir_mensagem_erro("Limite de aviões atingido!");
        return;
    }

    exibir_titulo("CADASTRO DE AVIÃO");
    printf("✈ Digite o código do avião: ");
    scanf("%d", &avioes[*total_avioes]);
    limpa_buffer();

    assentos_disponiveis[*total_avioes] = ASSENTOS_POR_AVIAO;
    (*total_avioes)++;

    exibir_mensagem_sucesso("Avião cadastrado com sucesso!");
}

// Cadastrar passageiros
void cadastrar_passageiro(Passageiro passageiros[], int *total_passageiros, int avioes[], int total_avioes) {
    if (*total_passageiros >= MAX_PASSAGEIROS) {
        exibir_mensagem_erro("Limite de passageiros atingido!");
        return;
    }

    if (total_avioes == 0) {
        exibir_mensagem_erro("Nenhum avião cadastrado ainda!");
        return;
    }

    exibir_titulo("CADASTRO DE PASSAGEIRO");
    
    // Gerar ID único para o passageiro
    passageiros[*total_passageiros].id = gerar_id_unico();
    
    printf("👤 Digite o nome do passageiro: ");
    fgets(passageiros[*total_passageiros].nome, MAX_NOME, stdin);
    passageiros[*total_passageiros].nome[strcspn(passageiros[*total_passageiros].nome, "\n")] = '\0';

    exibir_titulo("AVIÕES DISPONÍVEIS");
    for (int i = 0; i < total_avioes; i++) {
        printf(" ✈ Avião código: %d\n", avioes[i]);
    }

    printf("\n✈ Digite o código do avião que deseja embarcar: ");
    int codigo;
    scanf("%d", &codigo);
    limpa_buffer();

    int aviao_encontrado = -1;
    for (int i = 0; i < total_avioes; i++) {
        if (avioes[i] == codigo) {
            aviao_encontrado = i;
            break;
        }
    }

    if (aviao_encontrado == -1) {
        exibir_mensagem_erro("Avião não encontrado!");
        return;
    }

    passageiros[*total_passageiros].aviao_idx = aviao_encontrado;
    passageiros[*total_passageiros].passagens_compradas = 0;
    (*total_passageiros)++;

    exibir_mensagem_sucesso("Passageiro cadastrado com sucesso!");
    printf("   ID do passageiro: %d\n", passageiros[*total_passageiros - 1].id);
}

// Comprar passagem
void comprar_passagem(Passageiro passageiros[], int total_passageiros, int assentos_disponiveis[], int avioes[]) {
    exibir_titulo("COMPRA DE PASSAGEM");
    
    int id_passageiro;
    printf("🔍 Digite o ID do passageiro: ");
    scanf("%d", &id_passageiro);
    limpa_buffer();

    int index = -1;
    for (int i = 0; i < total_passageiros; i++) {
        if (passageiros[i].id == id_passageiro) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        exibir_mensagem_erro("Passageiro não encontrado!");
        return;
    }

    int aviao_idx = passageiros[index].aviao_idx;

    printf("🎫 Digite quantas passagens deseja comprar (máx 20): ");
    int qtd;
    scanf("%d", &qtd);
    limpa_buffer();

    if (qtd > 20 || qtd <= 0) {
        exibir_mensagem_erro("Quantidade inválida!");
        return;
    }

    if (assentos_disponiveis[aviao_idx] < qtd) {
        exibir_mensagem_erro("Assentos insuficientes.");
        printf("   Disponíveis: %d\n", assentos_disponiveis[aviao_idx]);
        return;
    }

    assentos_disponiveis[aviao_idx] -= qtd;
    passageiros[index].passagens_compradas += qtd;

    exibir_mensagem_sucesso("Compra realizada com sucesso!");
    printf("   🎫 Passagens compradas: %d\n", qtd);
}

// Consultar passageiro
void consultar_passageiro(Passageiro passageiros[], int total_passageiros, int avioes[]) {
    exibir_titulo("CONSULTA DE PASSAGEIRO");
    
    int opcao;
    printf("1. Buscar por ID\n");
    printf("2. Buscar por nome\n");
    printf("👉 Escolha uma opção: ");
    scanf("%d", &opcao);
    limpa_buffer();

    if (opcao == 1) {
        int id;
        printf("🔍 Digite o ID do passageiro: ");
        scanf("%d", &id);
        limpa_buffer();

        for (int i = 0; i < total_passageiros; i++) {
            if (passageiros[i].id == id) {
                exibir_titulo("INFORMAÇÕES DO PASSAGEIRO");
                printf(" 🆔 ID: %d\n", passageiros[i].id);
                printf(" 👤 Nome: %s\n", passageiros[i].nome);
                printf(" ✈ Avião: %d\n", avioes[passageiros[i].aviao_idx]);
                printf(" 🎫 Passagens compradas: %d\n", passageiros[i].passagens_compradas);
                return;
            }
        }
        exibir_mensagem_erro("Passageiro não encontrado.");
    } else if (opcao == 2) {
        char nome[MAX_NOME];
        printf("🔍 Digite o nome do passageiro: ");
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        bool encontrado = false;
        for (int i = 0; i < total_passageiros; i++) {
            if (strcmp(passageiros[i].nome, nome) == 0) {
                exibir_titulo("INFORMAÇÕES DO PASSAGEIRO");
                printf(" 🆔 ID: %d\n", passageiros[i].id);
                printf(" 👤 Nome: %s\n", passageiros[i].nome);
                printf(" ✈ Avião: %d\n", avioes[passageiros[i].aviao_idx]);
                printf(" 🎫 Passagens compradas: %d\n", passageiros[i].passagens_compradas);
                encontrado = true;
            }
        }
        if (!encontrado) {
            exibir_mensagem_erro("Passageiro não encontrado.");
        }
    } else {
        exibir_mensagem_erro("Opção inválida!");
    }
}

// Consultar avião
void consultar_aviao(int avioes[], int assentos_disponiveis[], int total_avioes) {
    exibir_titulo("CONSULTA DE AVIÃO");
    
    int codigo;
    printf("🔍 Digite o código do avião: ");
    scanf("%d", &codigo);
    limpa_buffer();

    for (int i = 0; i < total_avioes; i++) {
        if (avioes[i] == codigo) {
            exibir_titulo("INFORMAÇÕES DO AVIÃO");
            printf(" ✈ Código: %d\n", codigo);
            printf(" 💺 Assentos disponíveis: %d\n", assentos_disponiveis[i]);
            return;
        }
    }
    exibir_mensagem_erro("Avião não encontrado.");
}

// Listar passagens compradas
void listar_passagens(Passageiro passageiros[], int total_passageiros, int avioes[]) {
    exibir_titulo("PASSAGENS COMPRADAS");
    
    bool alguma = false;

    for (int i = 0; i < total_passageiros; i++) {
        if (passageiros[i].passagens_compradas > 0) {
            printf(" 🆔 ID: %d\n", passageiros[i].id);
            printf(" 👤 Passageiro: %s\n", passageiros[i].nome);
            printf(" ✈ Avião: %d\n", avioes[passageiros[i].aviao_idx]);
            printf(" 🎫 Passagens: %d\n", passageiros[i].passagens_compradas);
            printf("----------------------------------------\n");
            alguma = true;
        }
    }

    if (!alguma) {
        exibir_mensagem_erro("Nenhuma passagem comprada até agora.");
    }
}

// Remover passageiro
void remover_passageiro(Passageiro passageiros[], int *total_passageiros, int assentos_disponiveis[]) {
    exibir_titulo("REMOVER PASSAGEIRO");
    
    int id;
    printf("🔍 Digite o ID do passageiro a ser removido: ");
    scanf("%d", &id);
    limpa_buffer();

    int index = -1;
    for (int i = 0; i < *total_passageiros; i++) {
        if (passageiros[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        exibir_mensagem_erro("Passageiro não encontrado!");
        return;
    }

    // Devolver assentos ao avião se houver passagens compradas
    if (passageiros[index].passagens_compradas > 0) {
        assentos_disponiveis[passageiros[index].aviao_idx] += passageiros[index].passagens_compradas;
    }

    // Mover os passageiros restantes para preencher o espaço
    for (int i = index; i < *total_passageiros - 1; i++) {
        passageiros[i] = passageiros[i + 1];
    }

    (*total_passageiros)--;

    exibir_mensagem_sucesso("Passageiro removido com sucesso!");
}

void exibir_menu() {
    printf("\n");
    exibir_linha();
    printf("         ✈ COMPANHIA LATAM ✈\n");
    exibir_linha();
    printf("\n");
    printf(" 1. Cadastrar avião\n");
    printf(" 2. Cadastrar passageiro\n");
    printf(" 3. Comprar passagem\n");
    printf(" 4. Consultar passageiro\n");
    printf(" 5. Consultar avião\n");
    printf(" 6. Listar passagens compradas\n");
    printf(" 7. Remover passageiro\n");
    printf(" 8. Sair\n");
    printf("\n");
    exibir_linha();
    printf("👉 Escolha uma opção: ");
}

int main() {
    int opcao;
    int avioes[MAX_AVIOES];
    int total_avioes = 0;
    Passageiro passageiros[MAX_PASSAGEIROS];
    int total_passageiros = 0;
    int assentos_disponiveis[MAX_AVIOES];

    // Inicializar gerador de IDs
    srand(time(NULL));

    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpa_buffer();

        switch (opcao) {
            case 1:
                cadastrar_aviao(avioes, &total_avioes, assentos_disponiveis);
                break;
            case 2:
                cadastrar_passageiro(passageiros, &total_passageiros, avioes, total_avioes);
                break;
            case 3:
                comprar_passagem(passageiros, total_passageiros, assentos_disponiveis, avioes);
                break;
            case 4:
                consultar_passageiro(passageiros, total_passageiros, avioes);
                break;
            case 5:
                consultar_aviao(avioes, assentos_disponiveis, total_avioes);
                break;
            case 6:
                listar_passagens(passageiros, total_passageiros, avioes);
                break;
            case 7:
                remover_passageiro(passageiros, &total_passageiros, assentos_disponiveis);
                break;
            case 8:
                exibir_mensagem_sucesso("Saindo do sistema... Até logo!");
                break;
            default:
                exibir_mensagem_erro("Opção inválida!");
        }
    } while (opcao != 8);

    return 0;
}
