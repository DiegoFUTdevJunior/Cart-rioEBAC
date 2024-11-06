#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro() //função responsável por cadastrar os usuários no sistema
{
	char arquivo[40]; //criando as STRINGs
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char cargo[40]; //final da criação de STRINGs
	
	printf("Digite o CPF a ser Cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s armazenando a escolha do usuário em uma STRING
	
	strcpy(arquivo, cpf); //responsável por copiar os valores de uma string para a outra
	
	FILE *file; //cria a pasta no banco de dados 
	file = fopen(arquivo, "w"); //passa o arquivo para pasta onde o sistema está localizado//usar o "W" para criar um novo arquivo
	fprintf(file, ".\nCPF:");
	fprintf(file, cpf); //salvar o valor da variável dentro do arquivo
	fclose(file); //fechando o arquivo
	
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nNome:");//atualizar o comando escrito dentro da STRING
	fclose(file); //fechando o arquivo
	
	printf("\nDigite o Nome a ser Cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, nome);//salvar o valor da variável dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nSobrenome:");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	printf("\nDigite o Sobrenome a ser Cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, sobrenome);//salvar o valor da variável dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nIdade:");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	printf("\nDigite a Idade a ser Cadastrada:");
	scanf("%s", idade);
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, idade);//salvar o valor da variável dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nCargo:");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	printf("\nDigite o Cargo a ser Cadastrado:");
	scanf("%s", cargo);
	printf("\n");
	
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, cargo);//salvar o valor da variável dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\n");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	system("pause");	
}

int consulta() //função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem de texto, sempre que for usar acento no printf, usar o setlocale
	
	char cpf[40];//criando as STRINGs
	char conteudo[200];
	
	
	printf("Digite o CPF a ser Consultado:");
	scanf("%s", cpf);//armazenando a escolha do usuário
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r"); //usamos o "R" quando o programa tem que ler(consultar) o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, CPF não cadastrado!\n\n");
	}
		
		printf("Essas são as informações do usuário:");
	
	while(fgets(conteudo, 200, file) != NULL) //esta salvando todas os arquivos da FILE, para a STRING conteúdo
	{
		printf("%s", conteudo);
		printf("\n");
	}
		system("pause");
		fclose(file);
		
		
}

int deletar() //função responsável por deletar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem de texto, sempre que for usar acento no printf, usar o setlocale
	
	char cpf[40]; //usar o char mesmo quando for numeros e melhor pois com gerenciamento de STRINGS ele funciona melhor
	
	printf("Digite o CPF a ser Deletado:");
	scanf("%s", cpf);//armazenando a escolha do usuário
	system("cls");//limpeza do programa após resposta do usuário
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	
	if(file == NULL)
	{
		printf("CPF Não Encontrado no Sistema.\n\n");
		system("pause");
	}
	else
 	{
 		fclose(file);
 		remove(cpf);
 		printf("CPF Deletado com Sucesso.\n\n");
		system("pause");
	 }
	
}

int main() //a função main é a responsável por armazenar o menu, pois é desse ponto que o usuário ativa as outras funções ou partes do programa
{
    int opcao=0; //definindo variáveis	
	int laco=1;
	
	for(laco=1;laco=1;)//criando um laço de repetição
	{
		system("cls"); //limpeza do programa após resposta do usuário
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem de texto
	    
	
		printf("\t### Cartório da EBAC ###\n\n"); //inicio do menu //o comando /n serve para pular linha, e o /t pra dar espaço no começo
		printf("Escolha a opção deseja no menu: \n\n");
		printf("\t1-Registrar nomes \n\n");
		printf("\t2-Consultar nomes \n\n");
		printf("\t3-Deletar nomes \n\n");
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //limpeza do programa após resposta do usuário
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1: //chamada de funções
		 	registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3: //fim da seleção
			deletar();
			break;
			
			default: 
			printf("Essa opção não está disponivel!\n"); 
			system("pause");//esperando a resposta do usuário
			break;
			
			
		}
	
	}
}			


