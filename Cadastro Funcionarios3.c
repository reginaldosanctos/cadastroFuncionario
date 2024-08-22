#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>


struct Funcionario
{
	char nome[100];
	int idade;
	char sexo;
	char escolaridade[50];
	int num_dependentes;
	char bairro[100];
	char cidade[100];
	char horario_disponivel[50];
	char profissao[100];
};


void limparBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}


void cadastrarFuncionario(struct Funcionario *funcionarios, int *totalFuncionarios)
{
	if (*totalFuncionarios >= 100)
	{
		printf("Limite de funcionários atingido. Não é possível cadastrar mais.\n");
		return;
	}

	struct Funcionario novoFuncionario;

	printf("Digite o nome do funcionário: ");
	scanf(" %[^\n]", novoFuncionario.nome);
	novoFuncionario.nome[0] = toupper(novoFuncionario.nome[0]);
	printf("Digite a idade do funcionário: ");
	scanf("%d", &novoFuncionario.idade);
	limparBuffer();
	do
	{
		printf("Digite o sexo do funcionário (M/F): ");
		scanf(" %c", &novoFuncionario.sexo);
		novoFuncionario.sexo = toupper(novoFuncionario.sexo);
		limparBuffer();
	}
	while (novoFuncionario.sexo != 'M' && novoFuncionario.sexo != 'F');
	printf("Digite a escolaridade do funcionário (Superior/Medio/Fundamental): ");
	scanf(" %[^\n]", novoFuncionario.escolaridade);
	novoFuncionario.escolaridade[0] = toupper(novoFuncionario.escolaridade[0]);
	printf("Digite o número de dependentes do funcionário: ");
	scanf("%d", &novoFuncionario.num_dependentes);
	limparBuffer();
	printf("Digite o bairro do funcionário: ");
	scanf(" %[^\n]", novoFuncionario.bairro);
	novoFuncionario.bairro[0] = toupper(novoFuncionario.bairro[0]);
	limparBuffer();
	printf("Digite a cidade do funcionário: ");
	scanf(" %[^\n]", novoFuncionario.cidade);
	novoFuncionario.cidade[0] = toupper(novoFuncionario.cidade[0]);
	limparBuffer();
	printf("Digite a disponibilidade de horário do funcionário: ");
	scanf(" %[^\n]", novoFuncionario.horario_disponivel);
	novoFuncionario.horario_disponivel[0] = toupper(novoFuncionario.horario_disponivel[0]);
	limparBuffer();
	printf("Digite a profissão do funcionário: ");
	scanf(" %[^\n]", novoFuncionario.profissao);
	novoFuncionario.profissao[0] = toupper(novoFuncionario.profissao[0]);
	limparBuffer();
	funcionarios[*totalFuncionarios] = novoFuncionario;
	(*totalFuncionarios)++;
	printf("Funcionário cadastrado com sucesso!\n");
}


void listarFuncionariosFiltrados(struct Funcionario *funcionarios, int totalFuncionarios)
{
	if (totalFuncionarios == 0)
	{
		printf("Não há funcionários cadastrados.\n");
		return;
	}

	printf("\nFiltros:\n");
	printf("1. Filtrar por faixa etária\n");
	printf("2. Filtrar por sexo\n");
	printf("3. Filtrar por bairro\n");
	printf("4. Filtrar por cidade\n");
	printf("5. Filtrar por disponibilidade de horário\n");
	printf("Escolha uma opção: ");
	int filtro;
	scanf("%d", &filtro);
	limparBuffer();

	int contador = 0;

	switch (filtro)
	{
	case 1:
		printf("Digite a faixa etária desejada (exemplo: 25-40): ");
		int idadeMin, idadeMax;
		scanf("%d-%d", &idadeMin, &idadeMax);
		limparBuffer();
		for (int i = 0; i < totalFuncionarios; i++)
		{
			if (funcionarios[i].idade >= idadeMin && funcionarios[i].idade <= idadeMax)
			{
				if (contador == 0)
				{
					printf("\nAqui estão os resultados:\n\n");
				}
				printf("Nome: %s\n", funcionarios[i].nome);
				printf("Idade: %d\n", funcionarios[i].idade);
				printf("Sexo: %c\n", funcionarios[i].sexo);
				printf("Escolaridade: %s\n", funcionarios[i].escolaridade);
				printf("Número de Dependentes: %d\n", funcionarios[i].num_dependentes);
				printf("Bairro: %s\n", funcionarios[i].bairro);
				printf("Cidade: %s\n", funcionarios[i].cidade);
				printf("Horário Disponível: %s\n", funcionarios[i].horario_disponivel);
				printf("Profissão: %s\n\n", funcionarios[i].profissao);
				contador++;
			}
		}
		break;

	case 2:
		printf("Digite o sexo desejado (M/F): ");
		char sexoDesejado;
		scanf(" %c", &sexoDesejado);
		sexoDesejado = toupper(sexoDesejado);
		limparBuffer();
		for (int i = 0; i < totalFuncionarios; i++)
		{
			if (funcionarios[i].sexo == sexoDesejado)
			{
				if (contador == 0)
				{
					printf("\nAqui estão os resultados:\n\n");
				}
				printf("Nome: %s\n", funcionarios[i].nome);
				printf("Idade: %d\n", funcionarios[i].idade);
				printf("Sexo: %c\n", funcionarios[i].sexo);
				printf("Escolaridade: %s\n", funcionarios[i].escolaridade);
				printf("Número de Dependentes: %d\n", funcionarios[i].num_dependentes);
				printf("Bairro: %s\n", funcionarios[i].bairro);
				printf("Cidade: %s\n", funcionarios[i].cidade);
				printf("Horário Disponível: %s\n", funcionarios[i].horario_disponivel);
				printf("Profissão: %s\n\n", funcionarios[i].profissao);
				contador++;
			}
		}
		break;
	case 3:
		printf("Digite o bairro desejado: ");
		char bairroDesejado[100];
		scanf(" %[^\n]", bairroDesejado);
		for (int i = 0; i < totalFuncionarios; i++)
		{
			if (strcmp(funcionarios[i].bairro, bairroDesejado) == 0)
			{
				if (contador == 0)
				{
					printf("\nAqui estão os resultados:\n\n");
				}
				printf("Nome: %s\n", funcionarios[i].nome);
				printf("Idade: %d\n", funcionarios[i].idade);
				printf("Sexo: %c\n", funcionarios[i].sexo);
				printf("Escolaridade: %s\n", funcionarios[i].escolaridade);
				printf("Número de Dependentes: %d\n", funcionarios[i].num_dependentes);
				printf("Bairro: %s\n", funcionarios[i].bairro);
				printf("Cidade: %s\n", funcionarios[i].cidade);
				printf("Horário Disponível: %s\n", funcionarios[i].horario_disponivel);
				printf("Profissão: %s\n\n", funcionarios[i].profissao);
				contador++;
			}
		}
		break;
	case 4:
		printf("Digite a cidade desejada: ");
		char cidadeDesejada[100];
		scanf(" %[^\n]", cidadeDesejada);
		for (int i = 0; i < totalFuncionarios; i++)
		{
			if (strcmp(funcionarios[i].cidade, cidadeDesejada) == 0)
			{
				if (contador == 0)
				{
					printf("\nAqui estão os resultados:\n\n");
				}
				printf("Nome: %s\n", funcionarios[i].nome);
				printf("Idade: %d\n", funcionarios[i].idade);
				printf("Sexo: %c\n", funcionarios[i].sexo);
				printf("Escolaridade: %s\n", funcionarios[i].escolaridade);
				printf("Número de Dependentes: %d\n", funcionarios[i].num_dependentes);
				printf("Bairro: %s\n", funcionarios[i].bairro);
				printf("Cidade: %s\n", funcionarios[i].cidade);
				printf("Horário Disponível: %s\n", funcionarios[i].horario_disponivel);
				printf("Profissão: %s\n\n", funcionarios[i].profissao);
				contador++;
			}
		}
		break;
	case 5:
		printf("Digite a disponibilidade de horário desejada: ");
		char horarioDesejado[50];
		scanf(" %[^\n]", horarioDesejado);
		for (int i = 0; i < totalFuncionarios; i++)
		{
			if (strcmp(funcionarios[i].horario_disponivel, horarioDesejado) == 0)
			{
				if (contador == 0)
				{
					printf("\nAqui estão os resultados:\n\n");
				}
				printf("Nome: %s\n", funcionarios[i].nome);
				printf("Idade: %d\n", funcionarios[i].idade);
				printf("Sexo: %c\n", funcionarios[i].sexo);
				printf("Escolaridade: %s\n", funcionarios[i].escolaridade);
				printf("Número de Dependentes: %d\n", funcionarios[i].num_dependentes);
				printf("Bairro: %s\n", funcionarios[i].bairro);
				printf("Cidade: %s\n", funcionarios[i].cidade);
				printf("Horário Disponível: %s\n", funcionarios[i].horario_disponivel);
				printf("Profissão: %s\n\n", funcionarios[i].profissao);
				contador++;
			}
		}
		break;
	default:
		printf("Opção inválida. Tente novamente.\n");
	}
	if (contador == 0)
	{
		printf("0 resultados\n");
	}
}

void salvarFuncionarios(struct Funcionario *funcionarios, int totalFuncionarios, const char *nomeArquivo)
{
	FILE *arquivo = fopen(nomeArquivo, "w");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
	}

	for (int i = 0; i < totalFuncionarios; i++)
	{
		fprintf(arquivo, "%s;%d;%c;%s;%d;%s;%s;%s;%s\n",
				funcionarios[i].nome,
				funcionarios[i].idade,
				funcionarios[i].sexo,
				funcionarios[i].escolaridade,
				funcionarios[i].num_dependentes,
				funcionarios[i].bairro,
				funcionarios[i].cidade,
				funcionarios[i].horario_disponivel,
				funcionarios[i].profissao);
	}

	fclose(arquivo);
	printf("Funcionários salvos com sucesso em %s.\n", nomeArquivo);
}


void lerFuncionarios(struct Funcionario *funcionarios, int *totalFuncionarios, const char *nomeArquivo)
{
	FILE *arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return;
	}

	*totalFuncionarios = 0;
	while (fscanf(arquivo, " %99[^;];%d;%c;%49[^;];%d;%99[^;];%99[^;];%49[^;];%99[^\n]\n",
				  funcionarios[*totalFuncionarios].nome,
				  &funcionarios[*totalFuncionarios].idade,
				  &funcionarios[*totalFuncionarios].sexo,
				  funcionarios[*totalFuncionarios].escolaridade,
				  &funcionarios[*totalFuncionarios].num_dependentes,
				  funcionarios[*totalFuncionarios].bairro,
				  funcionarios[*totalFuncionarios].cidade,
				  funcionarios[*totalFuncionarios].horario_disponivel,
				  funcionarios[*totalFuncionarios].profissao) == 9)
	{
		(*totalFuncionarios)++;
	}

	fclose(arquivo);
	printf("Funcionários carregados com sucesso de %s.\n", nomeArquivo);
}


int main()
{
	setlocale(LC_ALL, "");
	struct Funcionario funcionarios[100];
	int totalFuncionarios = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const char *nomeArquivo = "funcionarios.txt";


	lerFuncionarios(funcionarios, &totalFuncionarios, nomeArquivo);

	int opcao;
	do
	{
		SetConsoleTextAttribute(hConsole, 32);
		printf("\nMenu:\n");
		SetConsoleTextAttribute(hConsole, 15);
		printf("1. Cadastrar funcionário\n");
		printf("2. Listar funcionários\n");
		printf("3. Salvar funcionários\n");
		printf("4. Carregar funcionários\n");
		printf("5. Sair\n");
		SetConsoleTextAttribute(hConsole, 10);
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		limparBuffer();

		switch (opcao)
		{
		case 1:
			cadastrarFuncionario(funcionarios, &totalFuncionarios);
			break;
		case 2:
			listarFuncionariosFiltrados(funcionarios, totalFuncionarios);
			break;
		case 3:
			salvarFuncionarios(funcionarios, totalFuncionarios, nomeArquivo);
			break;
		case 4:
			lerFuncionarios(funcionarios, &totalFuncionarios, nomeArquivo);
			break;
		case 5:
			printf("Encerrando o programa. Obrigado!\n");
			break;
		default:
			printf("Opção inválida. Tente novamente.\n");
		}

	}
	while (opcao != 5);

	return 0;
}
